#include <iostream>
#include <fstream>

using namespace std;

enum Gender {Male, Female, Other};

class Course {
    public:
    string code;
    string title;
    int creditValue;

    private:
    char grade;
};

class Student {
    public:
    string firstName;
    string secondName;
    string fullName;
    string matricule;
    Gender gender;
    Course courses[20];

    Student(string fname, string sname, string mat, Gender gen, string pass){
        firstName = fname;
        secondName = sname;
        matricule = mat;
        gender =  gen;
        fullName = fname + " " + sname;
        setPassword(pass);

        // writing data to file
        ofstream studentsInfo;
        studentsInfo.open("data/students_info.csv", ios::app);

        if(!studentsInfo.is_open()){
            cout << "Error adding student\n";
            exit(1);
        }

        studentsInfo << fullName << "," << matricule << "," << gender << "," << password << endl;
        studentsInfo.close();
    }

    void setPassword(string pass){
        password = pass;
    };

    string getPassword(string pass){
        return password;
    }

    private:
    string password;
    float GPA;

};

int main()
{
    Student first("Mbah", "Lesky", "UBa21PB015", Male, "12345");
    return 0;
}
