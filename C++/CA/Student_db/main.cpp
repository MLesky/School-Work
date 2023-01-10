#include "headers/student.h"
#include "headers/course.h"
#include "headers/option.h"

using namespace std;

int main(){
  Student stud("John", "Doe", "UBa20pb789", Male, "SWE");
  stud.registerDepartmentalCourses();
  stud.recordMarks();
    return 0;
}
