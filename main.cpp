// Created by fowle on 9/29/2023.
// Modified by ya boi

#include "cubes.h"
#include "tower.h"
#include <iostream>
using namespace std;

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
    for (int y = 0; y <= 6; y++) {
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
        for (int z = 0; z <= 6; z++) {
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
            for (int x = 0; x <= 6; x++) {
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
                while (i < 100) {
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
    for (int m = 1; m < 100; m++) {
        if (tow[m] != nullptr && !tow[m]->Equals(baseTower)) {
            cout << "Tower " << m << ": ";
            tow[m]->showtower();
        }
    }
    cout << endl << "the total number of unique towers is " << s << endl;
}

int main() {

    generator();

}
