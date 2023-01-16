#include <iostream>
#include <string>
using namespace std;

string letters = "abcdefghijklmnopqrstuvwxyz";
int count = 0;

string genIDs(int pos[], bool checkend){
    
    string ids = to_string(pos[0]) + to_string(pos[1]) + letters[pos[2]] + letters[pos[3]] + ",  ";

    pos[3]++;
    if (pos[3] == 26){
        pos[2]++;
        pos[3] = 0;
    }

    if (pos[2] == 26){
        pos[1]++;
        pos[2] = 0;
        pos[3] = 0;
    }

    if (pos[1] == 10){
        pos[0]++;
        pos[1] = 0;
        pos[2] = 0;
        pos[3] = 0;
    } 

    count++;

    if (pos[0] == 10){
        return ids;
    }
    
    cout << ids <<"\t";
    return ids + genIDs(pos, checkend);
};

int main() {
    int positions[] = {0,0,0,0};
    string ids = genIDs(positions, false);
    cout << ids << endl << "---------------------\n";
    cout << "there are " << count << " number of ids";
    return 0;
}