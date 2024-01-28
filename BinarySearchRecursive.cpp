#include <stdio.h>
#include <iostream>
using namespace std;


int findNumber(int *numberList, int l, int r, int number){
    int mid = (l + r) / 2;
    int foundIndex = -1;

    if(l != r){
        if(number < numberList[mid]){
            foundIndex = findNumber(numberList, l, --mid, number);
        }
        else if(number > numberList[mid]){
            foundIndex = findNumber(numberList, ++mid, r, number);
        }
        else if(number == numberList[mid]){
            foundIndex = mid;
        }
    }
    else{ //base case when only lefts one number to compare
        if(number == numberList[mid]){
            foundIndex = mid;
        }
    }

    return foundIndex;
}


int main(void){
    int numberList[9] = {5, 6, 11, 15, 21, 25, 26, 43, 50};
    int listSize = sizeof(numberList) / sizeof(numberList[0]) - 1;

    int foundIndex = findNumber(numberList, 0, listSize, 15);

    if(foundIndex == -1){
        cout << "The number is not in the list\n";
    }
    else{
        cout << "The number is in the index: " << foundIndex << "\n";
    }

    return 0;
}