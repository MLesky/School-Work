#include <iostream>

using namespace std;

string sentenceCase(string text){
    int i;

    // capitallise the first letter
    text[0] = toupper(text[0]);


    // capitallise the first letter of each word
    for(i = 0; i < text.length() - 1; i++){
        if(text[i] == ' '){
            text[i+1] = toupper(text[i+1]);
        }
    }

    return text;
}

int main(){
    
    return 0;
}