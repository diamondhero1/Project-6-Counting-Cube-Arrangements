//
// Created by izzie on 10/19/2023.
// I am not at all certain that this is correct code. This is a "first draft" to get my ideas down and in a place where y'all can work with it.
//

#ifndef PROJECT_6_COUNTING_CUBE_ARRANGEMENTS_TOWER_H
#define PROJECT_6_COUNTING_CUBE_ARRANGEMENTS_TOWER_H

#include "cubes.h"

class tower {
public:
    //constructor. puts the 3 passed cubes into the arrangement[] private data.
    tower(cube *c1, cube *c2, cube *c3);
    //Code question: Is this how you do it such that the cubes are able to also be rooms or tunnels, since room & tunnel inherit cube?

    //vertically flips tower by swapping order of 1st and 3rd item in the array
    void verticalFlip();

    //rotates tower 90 degrees by rotating each cube in it (calling the rotation function for all 3 cubes)
    void rotate90();

    //rotates tower 180 degrees
    void rotate180();

    //rotates tower 270 degrees
    void rotate270();

    //  i think there should be a function here that checks this tower's equality to another tower
    //  by doing all the types of rotations and seeing if there's ever an equality. the parameter would be another tower that we're comparing to,
    //  and would return T/F depending on the outcome of each check?

    void printtower();

private:
    //this is an array of each cubes. [0] = bottom. [1] = middle. [2] = top.
    cube *arrangement[3];
};


#endif //PROJECT_6_COUNTING_CUBE_ARRANGEMENTS_TOWER_H