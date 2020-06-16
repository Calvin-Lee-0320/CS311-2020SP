// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  coursenumber = -1;  // cannot be 0 because 0 is a valid course number
  coursename = "";
    term = "";
    professorfirstname = "";
    professorlastname = "";
    grade = "";
    unit =-1;
}

// initializing constructor to create an el_t object
el_t::el_t(int acoursenumber, string acoursename, string aterm, string agrade, string aproffirstname, string aproflastname, int aunit)
{
   coursenumber= acoursenumber;
  coursename = acoursename;
    term = aterm;
    professorfirstname = aproffirstname;
    professorlastname = aproflastname;
    grade = agrade;
    unit = aunit;
}

// overload == for search based on the course number part only
bool el_t::operator==(el_t OtherOne)
{
  if (coursenumber == OtherOne.coursenumber) return true; else return false;
}

// overload != for search based on the course number part only
bool el_t::operator!=(el_t OtherOne)
{
  if (coursenumber != OtherOne.coursenumber) return true; else return false;
}

// overload cout
ostream& operator<<(ostream& os, const el_t& E)
{
    os << E.coursenumber << "|Course Name: " << E.coursename << "|Term: " << E.term << "|Professor: " << E.professorfirstname << " " << E.professorlastname << "|Grade: " << E.grade << "|Unit: " << E.unit;
  return os;
}

