/*
C867 - Scripting and Programing Applications
Programming Language: C++
Derrick A. Koehn
Student ID: 001297115
*/
#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "degree.h"


class Student {
public:
	//mutator functions
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	void SetAge(int stu_age);
	void SetDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3);
	
	
	//accessor functions
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	DegreeProgram GetDegreeProgram();
	int GetAge();
	int* GetDaysToComplete();
	
	//print function
	void Print();
	
	//constructors
	Student(string student_ID, string first_name, string last_name, string email_address, int stu_age, int time_to_complete1, int time_to_complete2, int time_to_complete3, DegreeProgram degree_program);
	Student();

	//destructor
	~Student();

private:
	//the class's private data members
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	DegreeProgram degreeProgram;
	int age;
	int daysToComplete[3];
};