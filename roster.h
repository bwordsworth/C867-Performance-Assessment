#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 5;
const int dataFields = 9;

class Roster {
private:
public:
    Student* classRosterArray[ARRAY_SIZE] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    void add(int     whereArray, string  studID, string  firstN, string  lastN, string  emailA, int     studAge, int     daysInCourse1, int     daysInCourse2, int     daysInCourse3, degprog studDegree);
    degprog returnDegree(string stDeg);
    void remove(string studID);
    void printAll();
    void printAverageDaysInCourse(string studID);
    void printInvalidEmails();
    void printByDegreeProgram(degprog studDegree);
    string getEnumString(degprog studDegree);
    ~Roster();
};

#endif
