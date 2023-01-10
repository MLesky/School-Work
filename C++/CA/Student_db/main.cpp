#include "headers/student.h"
#include "headers/course.h"
#include "headers/option.h"

using namespace std;

int main(){
  Student newStud("Mbah", "Lesky", "UBa21PB015", Male, "SWE");
  newStud.registerDepartmentalCourses();
  newStud.recordMarks();
    return 0;
}
