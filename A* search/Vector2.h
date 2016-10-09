//
//  Vector2.h
//  A* search
//
//  Created by 郑昊 on 2016-10-07.
//  Copyright © 2016 haozheng. All rights reserved.
//

#pragma once

struct Vector2{
    int x, y, z;
    Vector2(){};
    Vector2(int x_coord, int y_coord, int z_coord):x(x_coord), y(y_coord), z(z_coord){}
};