#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

class Student {
private:
    string  studentID;
    string  firstName;
    string  lastName;
    string  emailAddress;
    int     age;
    int     days_array[3];
    degprog degree;
public:
    // CONSRUCTORS
    Student();
    Student(string  stID, string  stFirst, string  stLast, string  stEmail, int     stAge, int     stDays1, int     stDays2, int     stDays3, degprog stDegree);
    // SET FUNCTIONS
    void setID(string studID);
    void setFirst(string firstN);
    void setLast(string lastN);
    void setEmail(string emailA);
    void setAge(int studAge);
    void setDaysArray(int numDays1, int numDays2, int numDays3);
    void setDegree(degprog studDegree);
    // GET FUNCTIONS
    string  getID();
    string  getFirst();
    string  getLast();
    string  getEmail();
    int     getAge();
    int*    getDaysArray();
    degprog getDegree();
    // PRINT FUNCTIONS
    void printID();
    void printFirst();
    void printLast();
    void printEmail();
    void printAge();
    void printNumDays();
    void printDeg();
    void print();
    // DESTRUCTOR
    ~Student();
};

#endif
