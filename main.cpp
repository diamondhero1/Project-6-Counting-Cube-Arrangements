//
// Created by fowle on 9/29/2023.
//


#include "cubes.h"
#include "tower.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void generator() {
    tower *tow[100];
    bool eq = 1;
    for (int i = 0; i < 100; i++) {
        tow[i] = new tower(new cube(), new cube(), new cube());
    }
    //initialize total number of towers passed (s)
    int s = 1;
    //initialize baseTower to match
    tower baseTower = tower(new cube(), new cube(), new cube());

    //loop to generate all towers and add unique values to array (maximum 100)
    for (int y = 0; y <= 6; y++) {
        //used to create all possible firstCube cube objects
        for (int z = 0; z <= 6; z++) {
            //used to create all possible secondCube cube objects
            for (int x = 0; x <= 6; x++) {
                cube * firstCube;
                if (y == 0) {
                    firstCube = new cube();
                }
                if (y == 1 || y == 2) {
                    firstCube = new tunnel(y);
                }
                if (y > 2) {
                    firstCube = new room(y);
                }
                cube * secondCube;
                if (z == 0) {
                    secondCube = new cube();
                }
                if (z == 1 || z == 2) {
                    secondCube = new tunnel(z);
                }
                if (z > 2) {
                    secondCube = new room(z);
                }
                //create all possible thirdCube cube objects
                cube * thirdCube;
                if (x == 0) {
                    thirdCube = new cube();
                }
                if (x == 1 || x == 2) {
                    thirdCube = new tunnel(x);
                }
                if (x > 2) {
                    thirdCube = new room(x);
                }
                //create tower based on cubes
                tower *generatorTower;
                generatorTower = new tower(firstCube, secondCube, thirdCube);
                //iterate until array element i is either equal to generator Tower or insertable
                int i = 1;
                while (i <= s) {
                    //duplicate conditional
                    if (tow[i]->Equals(*generatorTower)) {
                        break;
                    }
                        //insertable conditional
                    else if (tow[i]->Equals(baseTower)){
                        //insert tower
                        tow[i] = generatorTower;
                        s++;
                        break;
                    }
                    //iterate i
                    i++;
                }
            }
        }
    }

    cout << "Tower " << 0 << ": ";
    tow[0]->showtower();
    for (int m = 1; m < s; m++) {
        if (tow[m] != nullptr && !tow[m]->Equals(baseTower)) {
            cout << "Tower " << m << ": ";
            tow[m]->showtower();
        }
    }
    cout << endl << "the total number of unique towers is " << s << endl;
}

tower * userTower(cube* cubes[]){
    //create 3 cube pointers that will store user input in a second


    //take user input for each
    //!!! this currently does not account for invalid user inputs
    for (int i = 0; i < 3; i++) {
        cout << "Enter cube data: Cube, Room, Tunnel, & Direction: N, E, S, W. Format example: C. RN. TEW." << endl;
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
    /*cube* cubes[3];
    userTower(cubes);
    tower input1 = tower(cubes[0],cubes[1],cubes[2]);
    input1.showtower();
    cube* cubes2[3];
    userTower(cubes2);
    tower input2 = tower( cubes2[0], cubes2[1], cubes2[2]);

    cout << input1.Equals(input2) << endl;*/
    generator();
}

