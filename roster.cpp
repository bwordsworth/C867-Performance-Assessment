#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

degprog Roster::returnDegree(string stDeg) {
    if (stDeg == "NETWORK") {
        return NETWORK;
    }
    else if (stDeg == "SECURITY") {
        return SECURITY;
    }
    else {
        return SOFTWARE;
    }
}

void Roster::add(int whereArray, string studID, string firstN, string lastN, string emailA, int studAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, degprog studDegree) {
    classRosterArray[whereArray] = new Student(studID, firstN, lastN, emailA, studAge, daysInCourse1, daysInCourse2, daysInCourse3, studDegree);
}

void Roster::remove(string studID) {
    bool removed = false;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (classRosterArray[i]->getID() == studID) {
            classRosterArray[i]->~Student();
            removed = true;
            cout << "Successfully removed student: " << studID << endl;
        }
    }
    if (!removed) {
        cout << "The student, " << studID << ", was not found." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        classRosterArray[i]->print();
        cout << endl;
    }
}

void Roster::printAverageDaysInCourse(string studID) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (classRosterArray[i]->getID() == studID) {
            double sum;
            sum = classRosterArray[i]->getDaysArray()[0];
            sum += classRosterArray[i]->getDaysArray()[1];
            sum += classRosterArray[i]->getDaysArray()[2];
            sum = sum / 3;
            cout << "Student " << studID << ": " << sum << " days" << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    bool validEmail = true;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        string checkEmail = classRosterArray[i]->getEmail();
        if (checkEmail.find("@") == string::npos) {
            validEmail = false;
        }
        if (checkEmail.find(".") == string::npos) {
            validEmail = false;
        }
        if (checkEmail.find(" ") == string::npos) {
            validEmail = false;
        }
        if (!validEmail) {
            cout << "Email address, " << checkEmail << ", is invalid." << endl;
        }
    }
}

void Roster::printByDegreeProgram(degprog studDegree) {
    cout << "Students in the " << getEnumString(studDegree) << " Program: " << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (classRosterArray[i]->getDegree() == studDegree) {
            classRosterArray[i]->print();
            cout << endl;
        }
    }
}

string Roster::getEnumString(degprog studDegree) {
    switch (studDegree) {
        case NETWORK:
            return "NETWORK";
        case SECURITY:
            return "SECURITY";
        case SOFTWARE:
            return "SOFTWARE";
        default:
            return "INCORRECT VALUE ENTERED";
    }
}

Roster::~Roster(){

}
