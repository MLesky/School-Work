#include "headers/student.h"
#include "headers/course.h"
#include "headers/option.h"

using namespace std;

int main(){
  Student newStud("", "", "", Other, "");
  newStud = addStudent();
  newStud.registerDepartmentalCourses();
  newStud.recordMarks();

  /*
    bool isContinue;
    int task;
    Student newStud = NULL;
    Course newCourse;

    do {
      cout << "|-------------------------------------------------------------------------------------|\n";
      cout << "|----------------------------------Student Management---------------------------------|\n";
      cout << "| 1. Add new Student      2. Register Student's Courses     3. Record Student's Marks |\n";
      cout << "|                                                                                     |\n";
      cout << "|                                4. Add new course                                    |\n";
      cout << "|                                                                                     |\n";
      cout << "|                         5. Add courses under department                             |\n";
      cout << "|-------------------------------------------------------------------------------------|\n";
      cout << "|                                                                                     |\n";
      cout << "|     6. View All Students         7. View All Courses        8. View All options     |\n";
      cout << "|              9. Search Student                          10. Search Course           |\n";
      cout << "|-------------------------------------------------------------------------------------|\n\n";

      cout << "Select tasks: ";
      cin >> task;

      swicth (task){
        case 1:
                cout << "******ADDING STUDENT******\n";
                newStud = addStudent();
                cout << "Student added successfully";
                break;
        case 2:
                cout << "*****Registering Courses*****\n"
                if(newStud == NULL){
                  cout << "Please add a student before registering courses\n"
                } else {
                  newStud.registerDepartmentalCourses();
                  cout << "Courses Registered Successfully\n"
                }
                break;
        case 3:
                cout << "*****Recording Marks*****\n"
                if(newStud == NULL){
                  cout << "Please add a student before registering courses\n"
                } else {
                  newStud.recordMarks();
                  cout << "Courses Registered Successfully\n"
                }
                break;
        case 4:
                cout << "*****Adding new Course*****\n"
              //  newCourse = addCourse();
                cout << "Course added Successfully\n"
                break;
        case 5:
                cout << "*****Adding departmental courses*****\n"
                if(newStud == NULL){
                  cout << "Please add a student before registering courses\n"
                } else {
                  newStud.recordMarks();
                  cout << "Courses Registered Successfull\n"
                }
                break;


        }
        char choice;
        cout << "Do you want to continue (y/n): ";
        cin >> choice;
        isContinue = (choice == 'N' || choice == 'n') ? false : true;
      } while (isContinue);
    */
    return 0;
}
