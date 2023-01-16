#include <iostream>

using namespace std;

class MyString {
    public: 
    string value;

    // empty constructor
    MyString(){}

    // + operator overload
    // use to add two objects together to produce one
    MyString operator+(MyString another){
        MyString result;
        result.value = this->value + another.value;
        return result;
    }

};

int main(){
    MyString firstname;
    MyString secondname;
    firstname.value = "Mbah";
    secondname.value = "Lesky";
    MyString fullname = firstname + secondname;
    
 //   MyString fullname = firstname + secondname;
    cout << firstname.value << " + " << secondname.value << " = " << fullname.value << endl;
    return 0;
}