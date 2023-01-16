#include <iostream>

using namespace std;

// factorial function
int factorial(int num){
    int fact = 1, i;
    for (i = num; i > 0; i--){
        fact *= i;
    }
    return fact;
}

int main(){
    int num ;
    do {
        cout << "Enter a positive number: ";
        cin >> num;
    } while (num < 0);
    cout << "The factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}