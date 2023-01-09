#include <iostream>

using namespace std;

// function to get a positive floating number
float getPositiveFloat(){
    float value;
    do {
        cin >> value;
    } while(value < 0);
    return value;
}

int main(){
    float R, V, I;

    cout << "Enter Voltage (V): ";
    V = getPositiveFloat();

    cout << "Enter Current (I): ";
    I = getPositiveFloat();

    R = V/I;

    cout << "R = " << R << endl;
}