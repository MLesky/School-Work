#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

enum Gender {Male, Female, Other};

string genderPrint(Gender gender){
    switch(gender){
        case 0: return "Male";
        case 1: return "Female";
        case 2: return "Other";
        default: exit(1);
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

    Student(string fname, string sname, string mat, Gender gen, string optCode){
        firstName = fname;
        secondName = sname;
        matricule = mat;
        gender =  gen;
        fullName = fname + " " + sname;
        option = optCode;

        // writing data to file
        ofstream studentsInfo, studentData;
        studentsInfo.open("data/students_info.csv", ios::app);
        if(!studentsInfo.is_open()){
            cout << "Error adding student\n";
            exit(1);
        }

        studentsInfo << firstName << "," << secondName << "," << matricule << "," << genderPrint(gender) << option << "," << endl;
        studentsInfo.close();

        cout << fullName << " Successfully Added\n";
    }

    void registerDepartmentalCourses(){

        // openning the file containing courses
        ifstream optionCourses;
        ofstream studentCourses;
        optionCourses.open("options/" + option + ".csv");
        studentCourses.open("students_courses/" + matricule + ".csv", ios::out);

        if(!optionCourses.is_open() || !studentCourses.is_open()){
            cout << "Error registering courses\n";
            exit(1);
        }

        // storing the courses in a list and registering under the student
        string course[1000];
        int i = 0, j;
        while(getline(optionCourses, course[i])){
            i++;
        }

        for (j = 3; j<i; j++){
            studentCourses << course[j] << endl;
        }

        cout << "registered courses\n";
        studentCourses.close();
        optionCourses.close();

    }

    void recordMarks(){
        ifstream studentCourses;
        ofstream studentMarks;
        studentCourses.open("students_courses/" + matricule + ".csv");
        studentMarks.open("students_marks/" + matricule + ".csv", ios::out);
        if(!studentCourses.is_open() || !studentMarks.is_open()){
            cout << "Error recording marks";
            exit(1);
        }

        string course;
        int cv;
        float caMark = 0, examMark = 0, examtemp, catemp, totalMark;
        while(getline(studentCourses, course)){

            cout << "Enter marks for ";
            int i;
            for (i = 0; i < course.length() - 1; i++){
                if(course[i] == ','){ 
                    i++; 
                    break;
                }
            }

            for (; i < course.length(); i++){
                cout << course[i];
                if(course[i] == ',') break;
            }

            cout << "\nCA Marks: ";
            cin >> catemp;
            cout << "Exam Mark: ";
            cin >> examtemp;

            examMark += examtemp;
            caMark += catemp;
            cv = (int)course[course.length() - 1];

            studentMarks << course << "," << catemp << "," << examtemp << endl;
            cout << "Marks uploaded" << endl;
        }
    }

    private:
    float GPA;

};

void addStudent(){
    string fname, sname, matricule, option;
    int optionChoice, genderChoice;
    Gender gender;

    // getting data from user

    cout << "|-----------------------------------------------------------------------|" << endl;
    cout << "|************************** Student Database ***************************|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|\t 1. SWE\t\t2.CNSM \t  \t 3.EEE \t\t 4.EPE\t\t|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|******************************* Options *******************************|" << endl;
    cout << "|-----------------------------------------------------------------------|" << endl << endl;

    do {
        cout << "Select an option: ";
        cin >> optionChoice;

        switch (optionChoice)
        {
        case 1:
            option = "SWE";
            break;
        case 2:
            option = "CNSM";
            break;
        case 3:
            option = "EEE";
            break;
        case 4:
            option = "EPE";
            break;
        default:
            break;
        }
    } while(optionChoice >= 5);

    cout << "Enter student's first name: ";
    cin >> fname;

    cout << "Enter student's second name: ";
    cin >> sname;

    cout << "Enter student's matricule: ";
    cin >> matricule;

    cout << "1. Male\n" << "2. Female\n" << "3. Other\n";

    do {
        cout << "Select gender: ";
        cin >> genderChoice;

        switch (genderChoice)
        {
        case 1:
            gender = Male;
            break;
        case 2:
            gender = Female;
            break;
        case 3:
            gender = Other;
            break;
        }
    } while(genderChoice > 3);

    Student newStudent(fname, sname, matricule, gender, option);

}
#endif
