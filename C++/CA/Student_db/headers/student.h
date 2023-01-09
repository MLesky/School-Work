#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>

using namespace std;

enum Gender {Male, Female, Other};

string genderPrint(Gender gender){
    switch(gender){
        case 0: return "Male";
        case 1: return "Female";
        case 2: return "Other";
        default: return "Invalid";
    }
}

class Student {
    public:
    string firstName;
    string secondName;
    string fullName;
    string matricule;
    Gender gender;
    string option;

    Student(string fname, string sname, string mat, Gender gen, string optCode, string pass){
        firstName = fname;
        secondName = sname;
        matricule = mat;
        gender =  gen;
        fullName = fname + " " + sname;
        option = optCode;
        setPassword(pass);

        // writing data to file
        ofstream studentsInfo, studentData;
        studentsInfo.open("data/students_info.csv", ios::app);
        studentData.open("students/" + matricule + ".csv");
        if(!studentsInfo.is_open() || !studentData.is_open()){
            cout << "Error adding student\n";
            exit(1);
        }

        studentsInfo << firstName << "," << secondName << "," << matricule << "," << genderPrint(gender) << "," << password << endl;
        studentsInfo.close();

        studentData << "Name: " << fullName << endl;
        studentData << "Matricule: " << matricule << endl;
        studentData << "Gender: " << genderPrint(gender) << endl;
        studentData << "Option: " << option << endl << endl;
        studentData.close();
 
        cout << fullName << " Successfully Added\n";
    }

    void setPassword(string pass){
        password = pass;
    };

    string getPassword(string pass){
        return password;
    }

     void registerDepartmentalCourses(){

        // openning the file containing courses
        ifstream optionCourses;
        ofstream studentCourses;
        optionCourses.open("options/" + option + ".csv");
        studentCourses.open("students/" + matricule + ".csv", ios::app);

        if(!optionCourses.is_open() || !studentCourses.is_open()){
            cout << "Error registering courses\n";
            exit(1);
        }

        // storing the courses in a list and registering under the student
        string course[1000];
        int i = 0, j, k;
        while(getline(optionCourses, course[i])){
            if(i < 4) continue;
            studentCourses << course[i];
            i++;
        }

        cout << "registered courses";
        studentCourses.close();
        optionCourses.close();

    }

    private:
    string password;
    float GPA;

};
#endif