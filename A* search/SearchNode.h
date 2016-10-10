//
//  SearchNode.h
//  A* search
//
//  Created by 郑昊 on 2016-10-07.
//  Copyright © 2016 haozheng. All rights reserved.
//
#pragma once
#include <math.h>
#include <cstdlib>
#define map_size 18


class SearchNode {
public:
    int n_xcoord, n_ycoord; // the node's x-coordinate and y-coordinate
    int n_id; // the node's id(position in the map
    int G; // the node's movement costs
    int H;  // Heuristic costs
    SearchNode* parent; // set the pointer pointing to the parent of the node
    
    SearchNode(){ // default constructor
        parent = NULL;
    }
    
    SearchNode(int x, int y, SearchNode* nodeparent=0){ //parameterized constructor
        n_xcoord = x;
        n_ycoord = y;
        parent = nodeparent;
        n_id = y*map_size + x;
        G = 0;
        H = 0;
      }
    //get the total cost of the node
    int GetF(){
        return G+H;
    }
    
    // get the H cost(use Manhattan distance )
    int GetH(SearchNode *targetnode){
        int x = std::abs(this->n_xcoord - targetnode->n_xcoord);
        int y = std::abs(this->n_ycoord - targetnode->n_ycoord);
        return x+y;
            
    }
    
    
    
};


