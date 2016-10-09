//
//  main.cpp
//  A* search
//
//  Created by 郑昊 on 2016-10-07.
//  Copyright © 2016 haozheng. All rights reserved.
//

#include <iostream>
#include "Astarsearch.h"
#include "SearchNode.h"
#include "Vector2.h"
#include <cstdlib>
#include <vector>
using namespace std;



int main() {
    
    cout<<"Welcome to my world!"<<endl;
    // get the user input for the start position and the goal position
    int start_x, start_y;
    int goal_x, goal_y;
    cout<<"Please enter the start position and goal position(range 0-17)"<<endl;
    cout<<"The start position: "<<endl;
    cin>>start_x>>start_y;
    cout<<"The goal position: "<< endl;
    cin>>goal_x>>goal_y;
    
    //create two vector2 objects to initialize A star search
    
    Vector2 start(start_x, start_y, 0);
    Vector2 goal(goal_x, goal_y, 0);
    
    //create the PathSearch object, then
    //start the A star search
    PathSearch wtf;
    wtf.SearchPath(start, goal);
    
    Vector2 hold;
    hold = wtf.NextPathPosi();
    cout << hold.x << "  " << hold.y;
    
    cout << "\nThe world map"<<endl;
    //create the world map
    int map[18][18];
    for (int n=0; n<18; n++) {
        for (int m=0; m<18; m++) {
            map[n][m] = 0;
        }
    }
    
    //hard code the block node
    //9 means the node is a block
    map[5][7] = 7;
    map[6][7] = 7;
    map[7][7] = 7;
    map[8][7] = 7;
    map[9][7] = 7;
    map[13][10] = 7;
    map[13][11] = 7;
    map[13][12] = 7;
    map[13][13] = 7;
    map[13][14] = 7;
    map[13][15] = 7;
    map[12][15] = 7;
    
    //output the map
    for (int n=17; n>=0; n--) {
        for (int m=0; m<18; m++) {
            cout<<map[n][m]<<"   ";
        }
        cout<<endl;
    }
    
    cout<< endl;
    cout<< "showing the path" << endl;
    
    // first get the size of the n_StartToGoal
    int size = wtf.size_StartToGoal();
    //then get each passed node and push them into the map
    for (int i=0; i<size; i++) {
        int x1, y1;
        //get the x y coordinate of the passed node
        x1 = wtf.get_StartToGoal()[i]->x;
        y1 = wtf.get_StartToGoal()[i]->y;
        //update the map
        map[y1][x1] = 1;
        
    }
    
    cout << endl;
    //output the map
    for (int n=17; n>=0; n--) {
        for (int m=0; m<18; m++) {
            cout<<map[n][m]<<"   ";
        }
        cout<<endl;
    }

    
    return 0;



}
