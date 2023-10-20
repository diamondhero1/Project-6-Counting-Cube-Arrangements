//
// Created by Christopher Lee on 10/19/23.
//
#include "tower.h"
using namespace std;
#include <iostream>;

tower::tower(cube c1, cube c2, cube c3){
    arrangement[0] = c1;
    arrangement[1] = c2;
    arrangement[2] = c3;
}
//Code question: Is this how you do it such that the cubes are able to also be rooms or tunnels, since room & tunnel inherit cube?

//vertically flips tower by swapping order of 1st and 3rd item in the array
void tower::verticalFlip(){
    cube temp = arrangement[0];
    arrangement[0] = arrangement[2];
    arrangement[0] = temp;
}

//rotates tower 90 degrees by rotating each cube in it (calling the rotation function for all 3 cubes)
void tower::rotate90(){
    for (int i = 0; i <= 2; ++i) {
        arrangement[i].rotate90();
    }
}

//rotates tower 180 degrees
void tower::rotate180(){
    for (int i = 0; i <= 2; ++i) {
        arrangement[i].rotate90();
        arrangement[i].rotate90();
    }
}

//rotates tower 270 degrees
void tower::rotate270(){
    for (int i = 0; i <= 2; ++i) {
        arrangement[i].rotate90();
        arrangement[i].rotate90();
        arrangement[i].rotate90();
    }
}

void tower::printtower(){
    cout << arrangement[0].getDirection();
    cout << ", ";
    cout << arrangement[1].getDirection();
    cout << ", ";
    cout << arrangement[2].getDirection();
    cout << "." << endl;
}