#include <iostream>

using namespace std;

// factorial function
int factorial(int num){
    if (num == 1 || num == 0){
        return 1;
    }
    return num * factorial(num - 1);
}

int main(){
    int num ;
    do {
        cout << "Enter a positive number: ";
        cin >> num;
    } while (num < 0);
    cout << "The factorial of " << num << " is " << factorial(num);
    return 0;
}