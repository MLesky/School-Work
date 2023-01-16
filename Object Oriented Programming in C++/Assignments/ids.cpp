#include <iostream>
#include <string>

using namespace std;

string generateID(string letters, string digits){
    int i, j, k, l;
    string id;
    string all_ids;

    // first digit
    for (i = 0; i < 10; i++)
        // second digit
        for (j = 0; j < 10; j++)
            // First letter
            for (k = 0; k < letters.length(); k++)
                // Second letter
                for (l = 0; l < letters.length(); l++)
                    all_ids += to_string(i) + to_string(j) + letters[k] + letters[l] + ",";
    return all_ids;
}

int main(){
    string possible_ids = generateID("abcdefghijklmnopqrstuvwxyz", "0123456789");
    int i, count = 0;
    for (i = 0; i < possible_ids.length(); i++){
        if (possible_ids[i+4] == ','){
                cout << "\t";
                count++;
        }
        cout << possible_ids[i];
    }

    cout << "\n-------------------------- \nThere are " << count << " possible ids" << endl;
    return 0;
}

// Mbah Lesky
