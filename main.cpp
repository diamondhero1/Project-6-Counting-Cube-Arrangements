//
// Created by fowle on 9/29/2023.
//


#include "cubes.h"
#include "tower.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

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

    cout << "Input for first tower\n";
    userT1 = userTower();
    cout << "Input for second tower\n";
    userT2 = userTower();
    cout << "Does tower 1 equal tower 2? " << userT1.Equals(userT2) << endl;
}


//function to take user input to make a single tower. returns a new tower
//TO DO: RUN THIS CODE IM NOT SURE IF IT'S RIGHT OR NOT LOL. Specifically, check if the pointer syntax is correct, and if the polymorphism stuff with cubes[] and passing the values of cubes[] to a tower constructor is correct
tower userTower(){
    //create 3 cube pointers that will store user input in a second
    cube* cubes[3];
    
    //take user input for each
    //!!! this currently does not account for invalid user inputs
    for (int i = 0; i < 3; i++){
        cout << "Enter cube data: Cube, Room, Tunnel, & Direction: N, E, S, W. Format example: C. R NW. T W. T N << endl;
        string userInput;
        cin >> userInput;

        //process user input into a new cube/room/tunnel
        if userInput[0] == "C"{
        cube newc;
        cubes[i] = &newc;
        }   

        elif userInput[0] == "R" {
            if (userInput[2] == "N"){
            room newr = room(3);
            }
            elif (userInput[2] == "E"){
            room newr = room(4);
            }
            elif (userInput[2] == "S"){
            room newr = room(5);
            }
            elif (userInput[2] == "W"){
            room newr = room(6);
            }
            cubes[i] = &newr;
        }

        elif userInput[0] == "T" {
            if (userInput[2] == "N" || userInput[2] == "S"){
            tunnel newt = tunnel(1);
            }
            else{
            tunnel newt = tunnel(2);
            }
            cubes[i] = &newt;
        }
    }

    //
    tower newtower(cubes[0], cubes[1], cubes[2]);
    return newtower
    
}

