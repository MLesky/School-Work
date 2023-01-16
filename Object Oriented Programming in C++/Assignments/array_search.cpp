#include <iostream>

using namespace std;

int searchArray(int array[], int length, int value){
    int i;

    for (i = 0; i < length; i++){
        if(value == array[i])
            return i+1;
    }
    return -1;
}

int main(){
    int myArray[] = {23, 67, 0, 9, 6, 102, 17};
    int value = 102;
    cout << "Enter a value: " << value << endl;
    int pos = searchArray(myArray, 7, value);
    (pos == -1) ?  cout << "Not Found\n" : cout << "Found at " << pos << endl;
    return 0;
}