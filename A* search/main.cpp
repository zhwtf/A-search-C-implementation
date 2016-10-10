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
    
    
    
    
    // validate the user's input
    do {
        cout<<"\nPlease enter the start position and goal position(range 0-17)"<<endl;
        cout << "\nSince there are some blocks you may hit, you will re-enter the points if you hit the block." << endl;
        cout << endl;
        cout<<"The start position(use white space between x and y coordinates): "<< endl;
        cin>>start_x>>start_y;
        cout<<"The goal position(use white space between x and y coordinates): "<< endl;
        cin>>goal_x>>goal_y;

    } while ((start_x==7&&start_y==5) || (start_x==7&&start_y==6) || (start_x==7&&start_y==7) || (start_x==7&&start_y==8) || (start_x==7&&start_y==9) || (start_x==10&&start_y==13) || (start_x==11&&start_y==13) || (start_x==12&&start_y==13) || (start_x==13&&start_y==13) || (start_x==14&&start_y==13) || (start_x==15&&start_y==13) || (start_x==15&&start_y==12) || (goal_x==7&&goal_y==5) || (goal_x==7&&goal_y==6) || (goal_x==7&&goal_y==7) || (goal_x==7&&goal_y==8) || (goal_x==7&&goal_y==9) || (goal_x==10&&goal_y==13) || (goal_x==11&&goal_y==13) || (goal_x==12&&goal_y==13) || (goal_x==13&&goal_y==13) || (goal_x==14&&goal_y==13) || (goal_x==15&&goal_y==13) || (goal_x==15&&goal_y==12) || start_x > 17 || start_x < 0 || start_y >17 || start_y < 0 || goal_x>17 || goal_x < 0 || goal_y > 17 || goal_y < 0);
    
    //create two vector2 objects to initialize A star search
    Vector2 start(start_x, start_y, 0);
    Vector2 goal(goal_x, goal_y, 0);
    
    //create the PathSearch object, then
    //start the A star search
    PathSearch wtf;
    wtf.SearchPath(start, goal);
    
    
    cout << "\nThe world map"<<endl;
    //create the world map
    string map[18][18];
    for (int n=0; n<18; n++) {
        for (int m=0; m<18; m++) {
            map[n][m] = ".";
        }
    }
    
    //hard code the block node
    //9 means the node is a block
    map[5][7] = "|";
    map[6][7] = "|";
    map[7][7] = "|";
    map[8][7] = "|";
    map[9][7] = "|";
    map[13][10] = "-";
    map[13][11] = "-";
    map[13][12] = "-";
    map[13][13] = "-";
    map[13][14] = "-";
    map[13][15] = "-";
    map[12][15] = "|";
    
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
    cout << endl;
    //then get each passed node and push them into the map
    for (int i=0; i<size; i++) {
        int x1, y1;
        //get the x y coordinate of the passed node
        x1 = wtf.get_StartToGoal()[i]->x;
        y1 = wtf.get_StartToGoal()[i]->y;
        //update the map
        map[y1][x1] = "*";
        
    }
    
    cout << endl;
    //output the map
    for (int n=17; n>=0; n--) {
        for (int m=0; m<18; m++) {
            cout<<map[n][m]<<"   ";
        }
        cout<<endl;
    }

    // output the length of the shortest path
    cout << "\nThe length of the shortest path are: " << size-1 << endl;
    
    // output the points passed
    cout << "\nThe passed nodes are (from start to goal): " << endl;
    for (int i = size-1; i >=0 ; i--) {
        cout << "(" << wtf.get_StartToGoal()[i]->x << ", " << wtf.get_StartToGoal()[i]->y << ") ";
    }
    cout << endl;
    
    //output the total number of nodes placed on the fringe
    cout << "\nThe total number of nodes placed on the fringe are: " << wtf.get_frontier() << endl;
    
    
    
    
    //Part 2
    cout << "\n\n\nPart 2\n\n";
    
    do {
        cout<<"\nPlease enter the start position and goal position again(range 0-17)"<<endl;
        cout << "\nSince there are some blocks you may hit, you will re-enter the points if you hit the block." << endl;
        cout << endl;
        cout<<"The start position(use white space between x and y coordinates): "<< endl;
        cin>>start_x>>start_y;
        cout<<"The goal position(use white space between x and y coordinates): "<< endl;
        cin>>goal_x>>goal_y;
        
    } while ((start_x==7&&start_y==5) || (start_x==7&&start_y==6) || (start_x==7&&start_y==7) || (start_x==7&&start_y==8) || (start_x==7&&start_y==9) || (start_x==10&&start_y==13) || (start_x==11&&start_y==13) || (start_x==12&&start_y==13) || (start_x==13&&start_y==13) || (start_x==14&&start_y==13) || (start_x==15&&start_y==13) || (start_x==15&&start_y==12) || (goal_x==7&&goal_y==5) || (goal_x==7&&goal_y==6) || (goal_x==7&&goal_y==7) || (goal_x==7&&goal_y==8) || (goal_x==7&&goal_y==9) || (goal_x==10&&goal_y==13) || (goal_x==11&&goal_y==13) || (goal_x==12&&goal_y==13) || (goal_x==13&&goal_y==13) || (goal_x==14&&goal_y==13) || (goal_x==15&&goal_y==13) || (goal_x==15&&goal_y==12) || start_x > 17 || start_x < 0 || start_y >17 || start_y < 0 || goal_x>17 || goal_x < 0 || goal_y > 17 || goal_y < 0);
    
    
    for (int n=0; n<18; n++) {
        for (int m=0; m<18; m++) {
            map[n][m] = ".";
        }
    }
    
    //hard code the block node
    //9 means the node is a block
    map[5][7] = "|";
    map[6][7] = "|";
    map[7][7] = "|";
    map[8][7] = "|";
    map[9][7] = "|";
    map[13][10] = "-";
    map[13][11] = "-";
    map[13][12] = "-";
    map[13][13] = "-";
    map[13][14] = "-";
    map[13][15] = "-";
    map[12][15] = "|";
    
    map[12][5] = "a";
    map[12][12] = "b";
    map[5][5] = "c";
    map[5][12] = "d";
    
    //output the map
    for (int n=17; n>=0; n--) {
        for (int m=0; m<18; m++) {
            cout<<map[n][m]<<"   ";
        }
        cout<<endl;
    }

    PathSearch second;
    Vector2 start2(start_x, start_y, 0);
    Vector2 goal2(goal_x, goal_y, 0);
    second.SearchPath(start2, goal2);
    int origin_frontier = second.get_frontier();
    cout << "The frontiers from the original method: "<< origin_frontier << endl;
    // create the vector2 for the 4 points
    Vector2 a_point(5, 12, 0);
    Vector2 b_point(12, 12, 0);
    Vector2 c_point(5, 5, 0);
    Vector2 d_point(12, 5, 0);
    
    //create 8 objects and compare them
    PathSearch startToa, startTob, startToc, startTod;
    PathSearch goalToa, goalTob, goalToc, goalTod;
    
    //find the shortest path among start2 to a,b c  d
    //create a array to hold the size of 4 path(startToa, startTob, startToc, startTod)
    int start_to_landmark[4];
    startToa.SearchPath(start2, a_point);
    // get the size
    int sta_a_size = startToa.size_StartToGoal();
    start_to_landmark[0] = sta_a_size;
    
    //copy the same process for b c d
    startTob.SearchPath(start2, b_point);
    // get the size
    // for start to mark b
    int sta_b_size = startTob.size_StartToGoal();
    start_to_landmark[1] = sta_b_size;
    
    // for start to mark c
    startToc.SearchPath(start2, c_point);
    // get the size
    int sta_c_size = startToc.size_StartToGoal();
    start_to_landmark[2] = sta_c_size;
    
    // for start to mark d
    startTod.SearchPath(start2, d_point);
    // get the size
    int sta_d_size = startTod.size_StartToGoal();
    start_to_landmark[3] = sta_d_size;
    
    // find the shortest one
    // get the right index
    int temp1 = 99999;
    int index2 = 0;
    for (int i = 0; i < 4; i++) {
        if (start_to_landmark[i] < temp1) {
            temp1 = start_to_landmark[i];
            index2 = i;
        }
    }
    
    //use an array to hold the 4 search path objects and retrieve the target
    PathSearch array1[] = {startToa, startTob, startToc, startTod};
    //get the frontier(start to landmark)
    int start_frontier = array1[index2].get_frontier();
    
    
    
    //now for goal to 4 marks
    //find the shortest path among goal2 to a,b c  d
    //create a array to hold the size of 4 path(goalToa, goalTob, goalToc, goalTod)
    int goal_to_landmark[4];
    // search the goal to landmark a
    goalToa.SearchPath(goal2, a_point);
    // get the size
    int goal_a_size = goalToa.size_StartToGoal();
    goal_to_landmark[0] = goal_a_size;
    
    
    //copy the same process for goal to b, c, d
    //search the goal to landmark b
    goalTob.SearchPath(goal2, b_point);
    // get the size and put it into the array
    goal_to_landmark[1] = goalTob.size_StartToGoal();
    
    
    //search the goal to landmark c
    goalToc.SearchPath(goal2, c_point);
    // get the size and put it into the array
    goal_to_landmark[2] = goalToc.size_StartToGoal();
    
    //search the goal to landmark d
    goalTod.SearchPath(goal2, d_point);
    // get the size and put it into the array
    goal_to_landmark[3] = goalTod.size_StartToGoal();

    
    // find the shortest one
    // get the right index
    int temp2 = 99999;
    int index3 = 0;
    for (int i = 0; i < 4; i++) {
        if (goal_to_landmark[i] < temp2) {
            temp2 = goal_to_landmark[i];
            index3 = i;
        }
    }
    
    //use an array to hold the 4 search path objects and retrieve the target
    PathSearch array2[] = {goalToa, goalTob, goalToc, goalTod};
    //get the frontier(goal to landmark)
    int goal_frontier = array2[index3].get_frontier();
    
    //set 2 arrays to hold 4 landmarks
    Vector2 array_marks[] = {a_point, b_point, c_point, d_point};
    
    if ((goal_frontier + start_frontier) <= origin_frontier) {
        //this means using landmark is more efficient
        //we choose to use the landmark
        //then get each passed node and push them into the map
        // for start2 to target landmark
        for (int i=0; i<temp1; i++) {
            int x2, y2;
            //get the x y coordinate of the passed node
            x2 = array1[index2].get_StartToGoal()[i]->x;
            y2 = array1[index2].get_StartToGoal()[i]->y;
            //update the map
            map[y2][x2] = "*";
            
        }
        
        // for goal2 to target landmark
        for (int i=0; i<temp2; i++) {
            int x3, y3;
            //get the x y coordinate of the passed node
            x3 = array2[index3].get_StartToGoal()[i]->x;
            y3 = array2[index3].get_StartToGoal()[i]->y;
            //update the map
            map[y3][x3] = "*";
            
        }
        
        //update the two landmarks path
        //create the object to find the path between the 2 landmarks
        PathSearch landmarks;
        landmarks.SearchPath(array_marks[index2], array_marks[index3]);
        // get the size
        int size4 = landmarks.size_StartToGoal();
        cout << endl;
        //then get each passed node and push them into the map
        for (int i=0; i<size4; i++) {
            int x4, y4;
            //get the x y coordinate of the passed node
            x4 = landmarks.get_StartToGoal()[i]->x;
            y4 = landmarks.get_StartToGoal()[i]->y;
            //update the map
            map[y4][x4] = "*";
            
        }
    cout << "\nThe frontiers from the second method: ";
        int all = array1[index2].get_frontier() + array2[index3].get_frontier();
        cout << all << endl;

        

    }
    else{// the original method is better
        //putput the map
        int size5 = second.size_StartToGoal();
        cout << endl;
        //then get each passed node and push them into the map
        for (int i=0; i<size5; i++) {
            int x5, y5;
            //get the x y coordinate of the passed node
            x5 = second.get_StartToGoal()[i]->x;
            y5 = second.get_StartToGoal()[i]->y;
            //update the map
            map[y5][x5] = "*";
            
        }
     cout << "The frontiers from the original method: "<< origin_frontier << endl;
    }


    //output the map
    for (int n=17; n>=0; n--) {
        for (int m=0; m<18; m++) {
            cout<<map[n][m]<<"   ";
        }
        cout<<endl;
    }
    
    cout << "\nThe frontiers from the second method: " << goal_frontier + start_frontier << endl;

    
    return 0;



}
