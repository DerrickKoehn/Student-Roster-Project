/*
C867 - Scripting and Programing Applications
Programming Language: C++
Derrick A. Koehn
Student ID: 001297115
*/
#include "roster.h"
#include <iostream>
#include <sstream>
#include<string>
#include "degree.h"


int main() {
	cout << "C867 - Scripting and Programming Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Derrick A. Koehn" << endl;
	cout << "Student ID: 001297115" << endl << endl;
	
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	"A5,Derrick,Koehn,dkoehn2@wgu.edu,22,50,58,40,SOFTWARE" };
	
	
	Roster classRoster;

	//loop that parses strings and adds each to classRoster as student objects
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string subStr;
		istringstream dataStream(studentData[i]);
		getline(dataStream, subStr, ',');
		string studentID = subStr;
		getline(dataStream, subStr, ',');
		string firstName = subStr;
		getline(dataStream, subStr, ',');
		string lastName = subStr;
		getline(dataStream, subStr, ',');
		string email = subStr;
		getline(dataStream, subStr, ',');
		int age = stoi(subStr);
		getline(dataStream, subStr, ',');
		int daysInCourse1 = stoi(subStr);
		getline(dataStream, subStr, ',');
		int daysInCourse2 = stoi(subStr);
		getline(dataStream, subStr, ',');
		int daysInCourse3 = stoi(subStr);
		getline(dataStream, subStr, ',');
		DegreeProgram degreeProgram;
		if (subStr == "SOFTWARE") {degreeProgram = SOFTWARE;}
		if (subStr == "NETWORK") { degreeProgram = NETWORK;}
		if (subStr == "SECURITY") { degreeProgram = SECURITY;}
		
		classRoster.add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram );
	}

	//calls a function that prints each student object in classRoster
	classRoster.printAll();

	//calls a function that prints all invalid email addresses.
	classRoster.printInvalidEmails();

	// prints the average days per course for each student
	cout << endl;
	cout << "Printing average time per class for each student..." << endl;
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[0]); i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	
	// prints all students in degree program Software
	classRoster.printByDegreeProgram(SOFTWARE);

	//removes a student object from roster
	cout << endl;
	classRoster.remove("A3");

	//print all again to demonstrate that deletion took place
	cout << endl;
	classRoster.printAll();

	//attempts to remove the student again & prints a custom error message to console.
	cout << endl;
	classRoster.remove("A3");
	
}