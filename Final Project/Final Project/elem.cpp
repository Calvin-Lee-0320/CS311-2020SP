// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
    term = "";
    courseName = "";
    grade = "";
    unit = 0;
    profName = "";
    courseNumber = 0;
}

// initializing constructor to create an el_t object
el_t::el_t(string aterm, string acourseName, string agrade, double aunit, string aprofName, int acourseNumber)
{
    term = aterm;
    courseName = acourseName;
    grade = agrade;
    unit = aunit;
    profName = aprofName;
    courseNumber = acourseNumber;
}

// overload == for search based on the course number part only
bool el_t::operator==(el_t OtherOne)
{
  if (courseNumber == OtherOne.courseNumber) return true; else return false;
}

// overload != for search based on the course number part only
bool el_t::operator!=(el_t OtherOne)
{
  if (courseNumber != OtherOne.courseNumber) return true; else return false;
}

// overload cout
ostream& operator<<(ostream& os, const el_t& E)
{
    os << E.courseNumber << " | " << E.term << " | " << E.courseName << " | " << E.grade << " | " << E.unit << " | " << E.profName ;
  return os;
}

