#pragma once
#include "student.h"
#include <iostream>
/*
C867 - Scripting and Programing Applications
Programming Language: C++
Derrick A. Koehn
Student ID: 001297115
*/
#include <string>
#include "degree.h"

class Roster {
public:
	// data members
	
	Student* classRosterArray[5];
	

	//constructor
	Roster();
	

	//destructor
	~Roster();
	
	//public functions
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);

	
	

};

