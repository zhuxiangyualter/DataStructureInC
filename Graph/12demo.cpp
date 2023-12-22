#include <iostream>
#include <vector>
using namespace std;
enum class Location { SOUTH, NORTH };

void printState(Location farmer, Location wolf, Location goat, Location cabbage) {
    cout << "农民: " << (farmer == Location::SOUTH ? "南" : "北") << ", ";
    cout << "狼: " << (wolf == Location::SOUTH ? "南" : "北") << ", ";
    cout << "山羊: " << (goat == Location::SOUTH ? "南" : "北") << ", ";
    cout << "白菜: " << (cabbage == Location::SOUTH ? "南" : "北") << endl;
}

bool isSafe(Location farmer, Location wolf, Location goat, Location cabbage) {
    // 如果农夫不在一侧，而狼和山羊在同一侧，或者山羊和白菜在同一侧，返回false
    if ((farmer != wolf && farmer == goat) || (farmer != goat && farmer == cabbage)) {
        return false;
    }
    return true;
}

void crossRiver(Location& farmer, Location& wolf, Location& goat, Location& cabbage) {
    // 农夫带着一个物品过河，将物品从南岸移动到北岸或从北岸移动到南岸
    if (farmer == Location::SOUTH) {
        farmer = Location::NORTH;
    } else {
        farmer = Location::SOUTH;
    }
}

void solvePuzzle() {
    Location farmer = Location::SOUTH;
    Location wolf = Location::SOUTH;
    Location goat = Location::SOUTH;
    Location cabbage = Location::SOUTH;

    cout << "初始状态:" << endl;
    printState(farmer, wolf, goat, cabbage);

    // 农夫将羊带到北岸
    crossRiver(farmer, wolf, goat, cabbage);
    goat = farmer;
    cout << "移动羊到北面:" << endl;
    printState(farmer, wolf, goat, cabbage);

    // 农夫将狼带到北岸，然后将羊带回南岸
    crossRiver(farmer, wolf, goat, cabbage);
    wolf = farmer;
    cout << "移动狼到背面:" << endl;
    printState(farmer, wolf, goat, cabbage);

    crossRiver(farmer, wolf, goat, cabbage);
    goat = farmer;
    cout << "移动山羊到南面:" << endl;
    printState(farmer, wolf, goat, cabbage);

    // 农夫将白菜带到北岸，然后将狼带回南岸
    crossRiver(farmer, wolf, goat, cabbage);
    cabbage = farmer;
    cout << "移动白菜到北面:" << endl;
    printState(farmer, wolf, goat, cabbage);

    crossRiver(farmer, wolf, goat, cabbage);
    wolf = farmer;
    cout << "移动狼到南面:" << endl;
    printState(farmer, wolf, goat, cabbage);

    // 农夫将羊带到北岸
    crossRiver(farmer, wolf, goat, cabbage);
    goat = farmer;
    cout << "移动山羊到北边:" << endl;
    printState(farmer, wolf, goat, cabbage);
}

int main() {
    solvePuzzle();

    return 0;
}