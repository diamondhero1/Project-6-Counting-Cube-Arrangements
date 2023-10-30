//
// Created by fowle on 9/29/2023.
//


#include "cubes.h"
#include "tower.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

tower * userTower(cube* cubes[]){
    //create 3 cube pointers that will store user input in a second


    //take user input for each
    //!!! this currently does not account for invalid user inputs
    for (int i = 0; i < 3; i++) {
        cout << "Enter cube data: Cube, Room, Tunnel, & Direction: N, E, S, W. Format example: C. R N. T EW." << endl;
        string userInput;
        cin >> userInput;

        //process user input into a new cube/room/tunnel
        if (userInput[0] == 'C') {
            cubes[i] = new cube();
        }

        else if (userInput[0] == 'R') {
            if (userInput[1] == 'N') {
                cubes[i] = new room(3);
            } else if (userInput[1] == 'E') {
                cubes[i] = new room(4);
            } else if (userInput[1] == 'S') {
                cubes[i] = new room(5);
            } else if (userInput[1] == 'W') {
                cubes[i] = new room(6);
            }
        }

        else if (userInput[0] == 'T') {
            if (userInput[1] == 'N' || userInput[1] == 'S') {
                cubes[i] = new tunnel(1);
            } else {
                cubes[i] = new tunnel(2);
            }
        }
    }
    //
    tower newTower = tower(cubes[0], cubes[1], cubes[2]);
    newTower.showtower();
    return &newTower;

}

int main() {
    cube c1 = cube();
    tunnel t1 = tunnel(1);
    room r1 = room(3);
    tower tower1 = tower(&c1, &t1, &r1);
    tower1.printtower();
    tower1.verticalFlip();
    tower1.printtower();

    cube c2 = cube();
    tunnel t2 = tunnel(2);
    room r2 = room(4);
    tower tower2 = tower(&r2, &t2, &c2);
    cout << tower1.Equals(tower2) << endl;
    tower1.showtower();
    cube* cubes[3];
    userTower(cubes);
    tower input1 = tower(cubes[0],cubes[1],cubes[2]);
    input1.showtower();
    cube* cubes2[3];
    userTower(cubes2);
    tower input2 = tower( cubes2[0], cubes2[1], cubes2[2]);

    cout << input1.Equals(input2) << endl;

}

