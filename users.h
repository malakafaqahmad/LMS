#pragma once
#include "generic.h"
using namespace std;


class Teacher {
public:
	Person person;
	float salary;
	Department dept;
	int alottedCoursesIndexes[10];
	int alottedCoursesCount = 0;
};

class Student {
public:
	Person person;
	int rollNumber;
	Department dept;
	Grade grades;
};

class Admin {
	Person person;
	float salary;

};

class Course {
public:
	string courseName;
	string courseCode;
	Teacher teacher;
	Student enrolledStudents[120];
	Student droppedStudents[120];
	Student gradedStudents[120];


	int studentsLength = 0;
};