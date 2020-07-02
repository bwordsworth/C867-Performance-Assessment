#include "student.h"
#include <iostream>
#include <string>
using namespace std;

// CONSTRUCTORS
Student::Student() {
    studentID         = "No ID";
    firstName         = "First";
    lastName          = "Last";
    emailAddress      = "Email";
    age               = -1;
    int days_array[3] = {0, 1, 2};
    degree            = UNASSIGNED;
}

Student::Student(string  stID, string  stFirst, string  stLast, string  stEmail, int     stAge, int     stDays1, int     stDays2, int     stDays3, degprog stDegree) {
    studentID     = stID;
    firstName     = stFirst;
    lastName      = stLast;
    emailAddress  = stEmail;
    age           = stAge;
    days_array[0] = stDays1;
    days_array[1] = stDays2;
    days_array[2] = stDays3;
    degree        = stDegree;
}

// SET FUNCTIONS
void Student::setID(string studID) {
    studentID = studID;
}

void Student::setFirst(string firstN) {
    firstName = firstN;
}

void Student::setLast(string lastN) {
    lastName = lastN;
}

void Student::setEmail(string emailA) {
    emailAddress = emailA;
}

void Student::setAge(int studAge) {
    age = studAge;
}

void Student::setDaysArray(int numDays1, int numDays2, int numDays3) {
    days_array[0] = numDays1;
    days_array[1] = numDays2;
    days_array[2] = numDays3;
}

void Student::setDegree(degprog studDegree) {
    degree = studDegree;
}

// GET FUNCTIONS
string Student::getID() {
    return studentID;
}

string Student::getFirst(){
    return firstName;
}

string Student::getLast(){
    return lastName;
}

string Student::getEmail(){
    return emailAddress;
}

int Student::getAge(){
    return age;
}

int* Student::getDaysArray() {
    return days_array;
}

degprog Student::getDegree() {
    return degree;
}

// PRINT FUNCTIONS
void Student::printID() {
    cout << "Student ID: " << studentID << endl;
}

void Student::printFirst() {
    cout << "First Name: " << firstName << endl;
}

void Student::printLast() {
    cout << "Last Name: " << lastName << endl;
}

void Student::printEmail() {
    cout << "Email Address: " << emailAddress << endl;
}

void Student::printAge() {
    cout << "Age: " << age << endl;
}

void Student::printNumDays() {
    cout << "Number of Days to Complete Each Course: "
         << days_array[0] << " " << days_array[1] << " " << days_array[2] << endl;
}

void Student::printDeg() {
    cout << "Degree: " << degree << endl;
}

void Student::print() {
    printID();
    printFirst();
    printLast();
    printEmail();
    printAge();
    printNumDays();
    printDeg();
}

Student::~Student() {

}