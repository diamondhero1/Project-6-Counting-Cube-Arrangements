// Created by fowle on 9/29/2023.
// Modified by ya boi

#include "cubes.h"
#include "tower.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;




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
    //newTower.showtower();
    return &newTower;

}


void generator() {
    tower *tow[100];
    for (int i = 0; i < 100; i++) {
        tow[i] = new tower(new cube(), new cube(), new cube());
    }
    //initialize total number of towers passed (s)
    int s = 1;
    //initialize baseTower to match
    tower baseTower = tower(new cube(), new cube(), new cube());
    //loop to generate all towers and add unique values to array (maximum 100)

    int ununiqueNum = 1;
    int failNum = 0;
    for (int y = 0; y <= 6; y++) {

        for (int z = 0; z <= 6; z++) {

            for (int x = 0; x <= 6; x++) {
                //create all possible firstCube cube objects
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

                //create all possible secondCube cube objects
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

                /*
                bool foundEqual = false;
                int index = 0;
                while (!foundEqual and index < s){
                    //cout << index << endl;
                    if (generatorTower->Equals(*(tow[index]))){
                        foundEqual = true;
                        //cout << "Found equal at index " << index << endl;
                    }
                    index++;
                }
                if (!foundEqual){
                    tow[s] = generatorTower;
                    s++;
                }
                */

                ununiqueNum++;
                cout << "Ununique tower " << ununiqueNum << endl;
                int i = 1;
                while (i < 100) {
                    //duplicate conditional
                    if (tow[i]->Equals(*generatorTower)) {
                        failNum++;
                        cout << "Fail number: " << failNum << endl;
                        break;
                    }
                        //insertable conditional
                    else if (tow[i]->Equals(baseTower)){
                        //insert tower
                        tow[i] = generatorTower;
                        s++;
                        cout << "Unique Tower Number " << s << endl;
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
    for (int m = 1; m < 100; m++) {
        if (tow[m] != nullptr && !tow[m]->Equals(baseTower)) {
            cout << "Tower " << m << ": ";
            tow[m]->showtower();
        }
    }
    cout << endl << "the total number of unique towers is " << s << endl;




    //---------- new code starts here:
    bool quit = false;
    int numFound = 0;
    do{
        int userinput;
        cout << "Enter a user input tower? 1/0";
        cin >> userinput;
        if (userinput == 1){ //user says go again
            //make a tower based on user specifications
            cube* cubes[3];
            userTower(cubes);
            tower input1 = tower(cubes[0],cubes[1],cubes[2]);

            //check if the new tower exists in the generator's list
            bool isIn = false;
            int i = 0;
            while (i < s) {
                if (tow[i]->Equals(input1)) {
                    isIn = true;
                    break;
                }
                //iterate i
                i++;
            }

            //print out result of the checking
            if (isIn){
                numFound++;
                cout << "Tower is inside Generator List. Num found is equal to " << numFound << endl;
            }
            else{
                cout << "Tower is not inside Generator List." << endl;
            }
        }

        else{ // user did not say to go again
            quit = true;
        }
    }while (!quit);
}


int main() {

    generator();



}
