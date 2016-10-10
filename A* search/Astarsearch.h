//
//  Astarsearch.hpp
//  A* search
//
//  Created by 郑昊 on 2016-10-07.
//  Copyright © 2016 haozheng. All rights reserved.
//

#pragma once
#include <vector>
#include "Vector2.h"
#include "SearchNode.h"

class PathSearch{
public:
    //create the constructor and destructor
    PathSearch();
    ~PathSearch(){};
    
    void SearchPath(Vector2 currentPosi, Vector2 targetPosi);
    
    
    
    // create three clear function
    // there are 3 vectors to hold the nodes
    void clearOpenList(){
        n_OpenList.clear();
    }
    void clearCloseList(){
        n_CloseList.clear();
    }
    void clearStartToGoal(){
        n_StartToGoal.clear();
    }
    
    int size_StartToGoal();
    
    std::vector<Vector2*> get_StartToGoal();
    int get_frontier();
    
    bool n_initialized;
    bool n_foundGoal;
    
private:
    // set the start node and goal node
    void SetStartAndGoal(SearchNode start, SearchNode goal);
    
    // function to find the neighbour nodes???
    // check the current node if it's in the openlist???
    void PathOpened(int x, int y, int cost, SearchNode *parent);
    
    SearchNode *GetNextNode();// get the next available node in the list??
    
    void ContinuePath(); // search the map and expand the node to find the target???
    
    // set 2 pointers pointing to the start and goal nodes
    SearchNode *n_startNode;
    SearchNode *n_goalNode;
    
    // create the vector with type SearchNode pointers
    // set the openlist, closelist, and starttogoallist(the shortest path list)
    std::vector<SearchNode*> n_OpenList;
    
    std::vector<SearchNode*> n_CloseList;
    
    std::vector<Vector2*> n_StartToGoal;
};


