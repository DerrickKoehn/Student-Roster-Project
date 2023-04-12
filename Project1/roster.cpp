/*
C867 - Scripting and Programing Applications
Programming Language: C++
Derrick A. Koehn
Student ID: 001297115
*/
#pragma once
#include "roster.h"
#include <iostream>
#include <sstream>


//constructor
Roster::Roster() {
	classRosterArray[0] = nullptr;
	classRosterArray[1] = nullptr;
	classRosterArray[2] = nullptr;
	classRosterArray[3] = nullptr;
	classRosterArray[4] = nullptr;
}

//destructor
Roster::~Roster() { //fixme ask about destructors for both classes
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		delete classRosterArray[i];
	}
}

//public functions
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram );
			break;
		}
		
	}
}

void Roster::remove(string studentID) {
	bool successfullyRemoved = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && studentID == classRosterArray[i]->GetStudentID()) {
			cout << "Removing student with StudentID A3..." << endl;
			classRosterArray[i] = nullptr;
			successfullyRemoved = true;
		}
	}
	if (!successfullyRemoved) {
		cout << "A student with ID A3 was not found.";
	}
}

void Roster::printAll() {
	cout << "Printing all students..." << endl;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			int lengthOfArray = 3;
			int total = 0;
			int average = 0;
			int * tempInt = classRosterArray[i]->GetDaysToComplete();
			for (i = 0; i < lengthOfArray; i++) {
				total += tempInt[i];
			}
		average = total / lengthOfArray;
			

		cout << "Average Days in Class for StudentID " << studentID << ": " << average << endl;
		break;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << endl;
	cout << "Printing all students in the Software degree program..." << endl;
		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				classRosterArray[i]->Print();
			}
		}

}

void Roster::printInvalidEmails() {
	cout << endl;
	cout << "Printing invalid emails..." << endl;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		string emailAddress = classRosterArray[i]->GetEmailAddress();
		bool testsNotPassed = false;
		size_t find = emailAddress.find(".");
		if (find != string::npos) {
			find = emailAddress.find("@");
			if (find != string::npos) {
				find = emailAddress.find(" ");
				if (find == string::npos) {
					testsNotPassed = true;
				}
			}
		}
		if (!testsNotPassed) {
			cout << "Student " << classRosterArray[i]->GetStudentID() << " has an invalid email: " << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
}