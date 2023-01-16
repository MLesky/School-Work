#include<iostream>
#include<string>
using namespace std;

//defining structure (initializing structure 'department')
struct student {
    string first_name;
    string last_name;
    int roll_number;
    double cgpa;
    int course_id[10];
} students[110];

int number_of_students = 0;

/*//defining structure (initializing structure 'department')
struct department{
string dep_id;
string dep_name;
string options;
int number;-
};*/

//defining add student method
void addStudentDetails()
{

    cout<<"Enter the new student details\n";

    cout<<"Enter the Roll Number of the student\n";
    int roll_no;
    cin>>roll_no;

    for(int i = 0; i < number_of_students; i++)
    {
       if(students[i].roll_number == roll_no)
       {
          cout << " Student with the given roll number already exists in the database\n";
          return;
       }
    }
    cout<<"Enter the first name of the student\n";
    cin>>students[number_of_students].first_name;

    cout<<"Enter the last name of the student\n";
    cin>>students[number_of_students].last_name;

    students[number_of_students].roll_number = roll_no;

    cout<<"Enter the CGPA of the student\n";
    cin>>students[number_of_students].cgpa;

    cout<<"Enter the course ID of each course in which the student is enrolled in\n";
    for (int i = 0; i < 5; i++) {
        cin>>students[number_of_students].course_id[i];
    }
     number_of_students++;
}

//defining find student by roll number
void findStudentByRollNumber()
{
    int roll_no;
    cout<<"Enter the Roll Number of the student\n";
    cin>>roll_no;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {
        if (roll_no == students[i].roll_number) {
            found = true;

            cout<<"The Students Details are:\n";

            cout<<"The First name is " << students[i].first_name << "\n";
            cout<<"The Last name is " << students[i].last_name << "\n";
            cout<<"The CGPA is " << students[i].cgpa << "\n";
            cout<<"The course ID of each course\n";

            for (int j = 0; j < 5; j++) {
                cout << students[i].course_id[j] << " ";
            }

            break;
      }
    }

    if(!found)
       cout<<"no such student with the given roll number\n";
}

//defining find total number of students method
void findTotalStudents()
{
    cout<<"The total number Students are "<< number_of_students <<"\n";
    cout<<"You can have maximum of 110 students in the database\n";
}

//defining delete by roll number method
void deleteStudentByRollNumber()
{
    int roll_no;
    cout<<"Enter the Roll Number that you want to delete\n";
    cin>>roll_no;

    bool found=false;
    for (int i = 0; i < number_of_students; i++) {
        if (roll_no == students[i].roll_number) {
            found = true;
            for (int j = i; j < 109; j++)
                students[j] = students[j + 1];
            number_of_students--;
        }
    }

    if(found){
       cout<<"The Roll Number is removed Successfully\n";
    }
    else{
       cout<<"Roll number not found in the database\n";
    }

}


//defining update student details method
void updateStudentDetails()
{

    cout<<"Enter the roll number whose details you want to update\n";
    int roll_no;
    cin>>roll_no;

    bool found=false;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].roll_number == roll_no) {

            found=true;
            cout<< "1. update first name\n"
                   "2. update last name\n"
                   "3. update roll number.\n"
                   "4. update CGPA\n"
                   "5. update courses\n";

            int choice;
            cin>>choice;

            switch(choice) {
            case 1:
                cout<<"Enter the new first name\n";
                cin>>students[i].first_name;
                break;

            case 2:
                cout<<"Enter the new last name\n";
                cin>>students[i].last_name;
                break;

            case 3:
                cout<<"Enter the new roll number\n";
                cin>>students[i].roll_number;
                break;

            case 4:
                cout<<"Enter the new CGPA\n";
                cin>>students[i].cgpa;
                break;

            case 5:
                cout<<"Enter the new courses \n";
                cin>>students[i].course_id[0]>>
                    students[i].course_id[1]>> students[i].course_id[2]>>
                    students[i].course_id[3]>>students[i].course_id[4];
                break;

        }
     }
   }

   if(found){
     cout<<"Details updated successfully.\n";
   }
   else{
     cout<<"Student not found in the database.\n";
   }
}


//defining main method
int main()
{
    int choice;
    while (true) {
        cout<<"Choices of the tasks that you want to perform\n";

        cout<<"1.Add new Student to the database\n";

        cout<<"2. Search Student by Roll Number\n";

        cout<<"3. Count Total number of Students\n";

        cout<<"4. Delete the Student by Roll Number\n";

        cout<<"5. Update Student Details by Roll Number\n";

        cout<<"6. Exit the program\n";

        cout<<"Enter your choice\n";
        cin>>choice;

        switch (choice) {
        case 1:
            addStudentDetails();
            break;

        case 2:
            findStudentByRollNumber();
            break;

        case 3:
            findTotalStudents();
            break;

        case 4:
            deleteStudentByRollNumber();
            break;

        case 5:
            updateStudentDetails();
            break;

        case 6:
            exit(0);
            break;
        }
    }

    return 0;
}



