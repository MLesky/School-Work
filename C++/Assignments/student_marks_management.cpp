#include <iostream>

using namespace std;

enum Gender {Male, Female, Other};

struct Course {
    string code;
    string title;
    string lecturer;
    int creditValue;

    private:
    float caMark;
    float examMark;
    float totalMark;
};

class Student {
    private:
    float GPA; 

    public:
    string firstName;
    string secondName;
    string fullName;
    string matricule;
    Gender gender;
    Course courses[23];

    Student(string fname, string sname, string id, Gender gen) {
        firstName = fname;
        secondName = sname;
        matricule = id;
        gender = gen;
        fullName = firstName + " " + secondName;
    //    courses = {""};
        setGPA(0.0);
    };

    void setGPA(float gpa){
        GPA = gpa;
    }

    float getGPA(){
        return GPA;
    }
};

int main() {
    Student one("Mbah", "Lesky", "Uba21pb015", Male);
    cout << one.getGPA();
    return 0;
}