//
//  Astarsearch.cpp
//  A* search
//
//  Created by 郑昊 on 2016-10-07.
//  Copyright © 2016 haozheng. All rights reserved.
//
#include <iostream>
#include "Astarsearch.h"
using namespace std;

PathSearch::PathSearch(){
    n_initialized = false;
    n_foundGoal = false;
}

// destructor?

void PathSearch::SearchPath(Vector2 currentPosi, Vector2 targetPosi){
    // if not initialized, then delete all the elements in the lists
    
    if(!n_initialized){
        for (int i = 0; i < n_OpenList.size(); i++) {
            delete n_OpenList[i];
        }
        n_OpenList.clear();
        
        for (int i = 0; i < n_CloseList.size(); i++) {
            delete n_CloseList[i];
        }
        n_CloseList.clear();
        
        for (int i = 0; n_StartToGoal.size(); i++) {
            delete n_StartToGoal[i];
        }
        n_StartToGoal.clear();
        
        // Initialize start
        SearchNode start;
        start.n_xcoord = currentPosi.x;
        start.n_ycoord = currentPosi.y;
        
        // Initialize goal
        SearchNode goal;
        goal.n_xcoord = targetPosi.x;
        goal.n_ycoord = targetPosi.y;
        
        // set the start and goal node
        SetStartAndGoal(start, goal);
        n_initialized = true;
    }
    
    // if has initialized, we continue our path search
    if(n_initialized){
        ContinuePath();
    }
}

void PathSearch::SetStartAndGoal(SearchNode start, SearchNode goal)
{
    n_startNode = new SearchNode(start.n_xcoord, start.n_ycoord, NULL);
    n_goalNode = new SearchNode(goal.n_xcoord, goal.n_ycoord, &goal);//parent of goal node??? goal->parent???
    
    // set G and H of the start node
    n_startNode->G = 0;
    n_startNode->H = n_startNode->GetH(n_goalNode);
    n_startNode->parent = NULL;
    
    n_OpenList.push_back(n_startNode);
    
    
}

//find the next node in the list
SearchNode* PathSearch::GetNextNode(){
    int bestF = 9999999;
    int NodeIndex = -1;
    SearchNode* NextNode = NULL;
    
    // find the node with smallest F
    
    for (int i = 0; i < n_OpenList.size(); i++) {
        if (n_OpenList[i]->GetF() < bestF) {
            bestF = n_OpenList[i]->GetF();
            NodeIndex = i;
        }
    }
    
    // find the next node and push it to the closelist, then remove it from the openlist
    if (NodeIndex >= 0) {
        NextNode = n_OpenList[NodeIndex];
        n_CloseList.push_back(NextNode);
        n_OpenList.erase(n_OpenList.begin() + NodeIndex);
    }
    return NextNode;
}
void PathSearch::PathOpened(int x, int y, int cost, SearchNode *parent){
    /*if (node_blocked){
     return;}
     */
    
    
    int id = y * map_size + x;
    // if the node is in the closelist, then we just return
    for (int i = 0; i < n_CloseList.size(); i++) {
        if (id == n_CloseList[i]->n_id) {
            return;
        }
    }
    
    // test if the node is out of the boundary
    if (x > 17 || x < 0 || y > 17 || y < 0) {
        return;
    }
    
    // test if the node's x and y coordinate make the block node
    // add block nodes to the CloseList, then return
    if (id == 97 || id == 115 || id == 133 || id == 151 || id == 169 || id == 244 || id == 245 || id == 246 || id == 247 || id == 248 || id == 249 || id == 231) {
        //SearchNode* blocknode = new SearchNode(x, y, parent);
        //n_CloseList.push_back(blocknode);
        return;
    }
    
    // else create a pointer pointing to the new node and set the G and H
    SearchNode* newChild = new SearchNode(x, y, parent);
    newChild->G = cost;
    newChild->H = newChild->GetH(n_goalNode);//??? wrong??? = newChild->getH(n_goalNode)??????
    
    // then check if the new node is in the OpenList
    // if the new node is in the OpenList
    for (int i = 0; i < n_OpenList.size(); i++) {
        if (id == n_OpenList[i]->n_id) {
            int newF = newChild->G + n_OpenList[i]->H;
            //??? wrong??? remove the + cost
            if (n_OpenList[i]->GetF() > newF) {
                //if the newF is smaller, then we update the F value
                n_OpenList[i]->G = newChild->G;
                n_OpenList[i]->parent = parent;//??? newChild?????wtf???
                return;
            }
            else{// if F value is not better
                delete newChild;
                return;
            }
            
        }
    }
    
    // the new node is not in the OpenList or if we have just updated its F
    // then we just push it to the OpenList
    n_OpenList.push_back(newChild);
}

void PathSearch::ContinuePath(){
    // if the OpenList is empty, then we are done,just return
    if (n_OpenList.empty()) {
        return;
    }
    
    //else get the node with the smallest F value in the openlist using the
    //GetNextNode() function
    SearchNode* currentNode = GetNextNode();
    
    if (currentNode->n_id == n_goalNode->n_id) {
        //???????wtf????
        n_goalNode->parent = currentNode->parent;
        SearchNode* getPath;
        // find the path from the goal to the start node
        for (getPath = n_goalNode; getPath != NULL; getPath = getPath->parent) {
            n_StartToGoal.push_back(new Vector2(getPath->n_xcoord, getPath->n_ycoord, 0));
        }
        n_foundGoal = true;
        return;
    }
    
    //else we don't find the goal, then we find the current node's neighbour in the 4 direction
    else{
        // rightnode
        PathOpened(currentNode->n_xcoord + 1, currentNode->n_ycoord, currentNode->G + 10, currentNode);
        
        // uppernode
        PathOpened(currentNode->n_xcoord, currentNode->n_ycoord + 1, currentNode->G + 10, currentNode);
        
        // leftnode
        PathOpened(currentNode->n_xcoord - 1, currentNode->n_ycoord, currentNode->G + 10, currentNode);
        
        // downnode
        PathOpened(currentNode->n_xcoord, currentNode->n_ycoord - 1, currentNode->G + 10, currentNode);
        
        //wtf???? has done this in the getNext function!!!!
        for (int i = 0; i < n_OpenList.size(); i++) {
            if (currentNode->n_id == n_OpenList[i]->n_id) {
                n_OpenList.erase(n_OpenList.begin() + i);
            }
        }
    }
    //recursively call the function until found the goal
    ContinuePath();
}



int PathSearch::size_StartToGoal()
{
    int size = n_StartToGoal.size();
    return size;
    
}

std::vector<Vector2*> PathSearch::get_StartToGoal(){
    return n_StartToGoal;
}

// get the total numbers of the expanded nodes
int PathSearch::get_frontier(){
    int num = n_OpenList.size() + n_CloseList.size();
    return num;
}
