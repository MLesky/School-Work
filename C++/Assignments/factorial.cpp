#include <iostream>

using namespace std;

int factorial(int n){
	int i, fact = 1;
	for(i = n; i > 0; i--){
		fact *= i;
	}
	
	return fact;
}
	
int main() {
	int num;
	cout << "Enter a positive number: ";
	cin >> num;
	cout << "Factorial of " << num << " is " << factorial(num);
	return 0;
}
