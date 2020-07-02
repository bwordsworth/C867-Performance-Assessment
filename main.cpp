#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {

    cout << "Course Title: C867" << endl << "Language Used: C++" << endl << "Student ID: 001337634" << endl << "Name: Brett Thorpe" << endl << endl;

    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Brett,Thorpe,brettcthorpe@gmail.com,29,14,10,20,SOFTWARE"
    };

    Roster classRoster;

    for (int i = 0; i < ARRAY_SIZE; ++i) {

        istringstream inSS(studentData[i]);
        string commaSepString;
        string stagingArray[dataFields];

        int j = 0;
        degprog stDegree;

        while (getline(inSS, commaSepString, ',')) {
            stagingArray[j] = commaSepString;
            j++;
        }

        if (stagingArray[8] == "SECURITY") {
            stDegree = SECURITY;
        }
        else if (stagingArray[8] == "NETWORK") {
            stDegree = NETWORK;
        }
        else if (stagingArray[8] == "SOFTWARE") {
            stDegree = SOFTWARE;
        }
        else {
            stDegree = UNASSIGNED;
        }

        classRoster.add(i, stagingArray[0], stagingArray[1], stagingArray[2], stagingArray[3], stoi(stagingArray[4]), stoi(stagingArray[5]), stoi(stagingArray[6]), stoi(stagingArray[7]), stDegree);
    }

    cout << "Student Roster: " << endl;
    classRoster.printAll();

    cout << endl << "Invalid Emails: " << endl;
    classRoster.printInvalidEmails();

    cout << endl << "Average Days to Complete per Student: " << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
    }

    cout << endl << "Print Students By Degree Program: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << endl << "Remove Student By Student ID: " << endl;
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    classRoster.~Roster();

    return 0;

}
