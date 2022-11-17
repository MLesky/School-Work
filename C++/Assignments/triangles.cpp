#include <iostream>
using namespace std;

void pyramid(int height){
    int i, j, k;

    cout << "PYRAMID\n----------------\n\t ";

    for (i = 0; i < height; i++)
        cout << i+1 << " ";

    cout << "\n\n";

    for (i = 0; i < height; i++){
        cout << i+1 << "\t"; 
        for (k = height - i - 1; k > 0; k--)
            cout << " ";
        for (j = 0; j <= i; j++) 
            cout << "* ";
        cout << endl;
    }
    cout << "\n\n";
}

void rightAngle(int height){
    int i, j;

    cout << "RIGHT ANGLE\n----------------\n\t ";

    for (i = 0; i < height; i++)
        cout << i+1 << " ";

    cout << "\n\n";

    for (i = 0; i < height; i++){
        cout << i+1 << "\t";
        for (j = 0; j <= i; j++)
            cout << " *";
        cout << endl;
    }
    cout << "\n\n";
}

void halfDiamond(int radius){
    int i, j, k;

    cout << "HALF DIAMOND\n----------------\n\t ";

    for (i = 0; i < radius; i++)
        cout << i+1 << " ";

    cout << "\n\n";

    for (i = 0; i < radius; i++){
        cout << i+1 << "\t";
        for(k =  radius - i - 1; k > 0; k--)
            cout << "  ";

        for(j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
    int count = i;
    for (i = radius - 2; i >= 0; i--){
        cout << ++count << "\t";
        for(k = 1; k < radius - i; k++)
            cout << "  ";

        for(j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
    cout << "\n\n";
}

int main(){
    int height = 9;

    
    pyramid(height);
    rightAngle(height);
    halfDiamond(height/2);
}
