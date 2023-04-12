/*
C867 - Scripting and Programing Applications
Programming Language: C++
Derrick A. Koehn
Student ID: 001297115
*/
#pragma once
#include "student.h"

// Constructors
Student::Student(string student_ID, string first_name, string last_name, string email_address, int stu_age, int time_to_complete1,int time_to_complete2, int time_to_complete3, DegreeProgram degree_program) {
	studentID = student_ID;
	firstName = first_name;
	lastName = last_name;
	emailAddress = email_address;
	age = stu_age;
	daysToComplete[0] = time_to_complete1;
	daysToComplete[1] = time_to_complete2;
	daysToComplete[2] = time_to_complete3;
	degreeProgram = degree_program;
	return;
}
Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = -1;
	daysToComplete[0] = -1;
	daysToComplete[1] = -1;
	daysToComplete[2] = -1;
	degreeProgram = SOFTWARE;
}

//Destructor
Student::~Student() {
}

//mutators for each variable in class student
void Student::SetStudentID(string student_ID) {
	studentID = student_ID;
}

void Student::SetFirstName(string first_Name){
	firstName = first_Name;
}

void Student::SetLastName(string last_Name) {
	lastName = last_Name;
}

void Student::SetEmailAddress(string email_address) {
	emailAddress = email_address;
}

void Student::SetDegreeProgram(DegreeProgram degree_program) {
	degreeProgram = degree_program;
}

void Student::SetAge(int stu_age) {
	age = stu_age;
}

void Student::SetDaysToComplete(int time_to_complete1, int time_to_complete2, int time_to_complete3) {
	daysToComplete[0] = time_to_complete1;
	daysToComplete[1] = time_to_complete2;
	daysToComplete[2] = time_to_complete3;
}

//accessors for each variable in class student
string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysToComplete() {
	return daysToComplete;
}


//function prints student object.
void Student::Print() {
	cout << "Student ID: " << this->studentID << '\t';
	cout << "First Name: " << this->firstName << '\t';
	cout << "Last Name: " << this->lastName << '\t';
	cout << "Age: " << this->age << '\t';
	cout << "Days In Course: " << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << '\t';
	cout << "Degree Program: " << degreeProgramStrings[this->GetDegreeProgram()] << endl;
}

