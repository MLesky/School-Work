#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <fstream>

using namespace std;

class Course {
    public:
    string code;
    string title;
    int creditValue;

    Course(string id, string name, int cv){
        code = id;
        title = name;
        creditValue = cv;

         // writing data to file
        ofstream coursesInfo;
        coursesInfo.open("data/courses_info.csv", ios::app);

        if(!coursesInfo.is_open()){
            cout << "Error adding course\n";
            exit(1);
        }

        coursesInfo << code << "," << title << "," << creditValue << endl;
        coursesInfo.close();

        cout << title << " Successfully Added\n";
    }

    private:
    float ca_marks;
    float exam_marks;
    float total_marks;
    char grade;
    float GPA;
};
#endif