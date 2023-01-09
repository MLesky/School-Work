#include "headers/student.h"
#include "headers/course.h"
#include "headers/option.h"

using namespace std;

int main(){
    Student first("Mbah", "Lesky", "UBa21PB015", Male, "SWE", "12345");
  //  Course test("cen2101", "Chemistry", 6);
  //  Option ghs("SWE", "Software", "COLTECH");
    first.registerDepartmentalCourses();
    return 0;
}