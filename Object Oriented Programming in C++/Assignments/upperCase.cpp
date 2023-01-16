#include <iostream>

using namespace std;

string upperCase(string text){

    // capitallise the whole text
    int i;
    for(i = 0; i < text.length(); i++){
        text[i] = toupper(text[i]);
    }

    return text;
}

string sentenceCase(string text){

    // capitallise the first letter
    text[0] = toupper(text[0]);

    // capitallise the first letter of each word
    int i;
    for(i = 0; i < text.length() - 1; i++){
        if(text[i] == ' '){
            text[i+1] = toupper(text[i+1]);
        }
    }

    return text;
}


int main(){
    string sentence = "my name is mbah lesky";
    string name = "mbah lesky";

    cout << "\"" << name << "\"" << " in upper case is " << "\"" << upperCase(name) << "\"\n";
    cout << "\"" << sentence << "\"" << " in sentence case is " << "\"" << sentenceCase(sentence) << "\"\n";
    return 0;
}