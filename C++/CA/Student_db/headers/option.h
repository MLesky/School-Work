#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Option {
    public:
    string abbrev;
    string name;
    string school;

    Option(string abb, string title, string faculty){
        abbrev = abb;
        name = title;
        school = faculty;

        // writing data to file
        ofstream optionsInfo, optionFile;
        optionsInfo.open("data/options_info.csv", ios::app);
        optionFile.open("options/" + abbrev + ".csv");

        if(!optionsInfo.is_open() || !optionFile.is_open()){
            cout << "Error adding option\n";
            exit(1);
        }

        optionsInfo << abbrev << "," << name << "," << school << endl;
        optionsInfo.close();

        optionFile << "Name: " << name << "(" << abbrev << ")" << endl;
        optionFile << "School: " << school << endl << endl;
        optionFile.close();

        cout << name << " Successfully Added\n";
    }

    void addDepartmentalCourse(){

        // openning the file containing courses
        ifstream coursesInfo;
        coursesInfo.open("data/courses_info.csv");

        if(!coursesInfo.is_open()){
            cout << "Error adding course\n";
            exit(1);
        }

        // storing the courses in a list
        string course[1000];
        int i = 0, j, k;
        while(getline(coursesInfo, course[i])){
            i++;
        }

        for (j = 0; j < i; j++){
            cout << j+1 << ": ";
            for (k = 0; k < course[j].length(); k++){
                if (course[j][k] == ','){
                    cout << "-";
                    continue;
                }
                cout << course[j][k];
            }
            cout << endl;
        }

        // selecting courses
        cout << "Enter the number(s) of the courses you want to register\n" << "Seperated them with a spaces\n" << "Hit enter when you are done: ";
        int choices[i];
        j = 0;
        do {
            cin >> choices[j];
            j++;
        } while (getchar() != '\n');

        // registering courses under the option
        // openning the file containing courses
        ofstream optionData;
        optionData.open("options/" + abbrev + ".csv", ios::app);

        if(!optionData.is_open()){
            cout << "Some Error occured\n";
            exit(1);
        }
        for (k = 0; k < j-1; k++){
            optionData << course[choices[k]-1] << endl;
        }

        cout << "added courses";
        optionData.close();

    }

};
#endif