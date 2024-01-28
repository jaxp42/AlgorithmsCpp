#include <stdio.h>
#include <iostream>
using namespace std;


int findNumber(int *numberList, int listSize, int number){
    int l = 0; //left position in the array
    int r = listSize; //right position in the array
    int foundIndex = -1;

    while(l <= r && foundIndex == -1){
        int mid = (l + r) / 2;

        if(number < numberList[mid]){
            r = mid -1;
        }
        else if(number > numberList[mid]){
            l = mid + 1;
        }
        else if(number == numberList[mid]){
            foundIndex = mid;
        }
    }

    return foundIndex;
}


int main(void){
    int numberList[9] = {5, 6, 11, 15, 21, 25, 26, 43, 50};
    int listSize = sizeof(numberList) / sizeof(numberList[0]) - 1;

    int foundIndex = findNumber(numberList, listSize, 50);

    if(foundIndex == -1){
        cout << "The number is not in the list\n";
    }
    else{
        cout << "The number is in the index: " << foundIndex << "\n";
    }

    return 0;
}

