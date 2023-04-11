#pragma once

#include "headersLib.h"

struct BackEnd {
	Student s1, s2, s3; // demo students
	Course c1, c2; // demo Courses;
	Course currentCourses[100];
	Student currentStudents[100];
	Teacher currentTeachers[50];
	int studentsLength = 0;
	int teacherLength = 0;
	int coursesLength = 0;
};


static BackEnd backend;

void displayCourses(int);

void displayCourses(int fullMenu, void func()) {

	if (fullMenu)
	{
		system("CLS");
	}
	cout << "  Available Courses : " << endl;
	cout << " # " << " CourseCode " << " Course Name ";

	for (int i = 0; i < backend.coursesLength; i++)
	{
		Course currCourse = backend.currentCourses[i];
		cout << endl << " " << i + 1 << ". " << currCourse.courseCode << "   " << currCourse.courseName << endl;
	}
	if (fullMenu)
	{
		cout << endl << "Enter any digit/aphabet and Enter to go back: ";
		char x;
		cin >> x;
		func();

	}

}

void setupDemoStudents() {
	backend.s1.rollNumber = 100;
	backend.s1.grades.marks = 100;
	backend.s1.dept = AI;
	backend.s1.person.name = "Demo Student 1";
	backend.s1.person.age = 100;
	backend.s1.person.eduLevel = Bachlors;
	backend.s1.person.address.city = "Demo City";
	backend.s1.person.address.state = "Demo State";
	backend.s1.person.address.zipCode = 1003;

	backend.s2.rollNumber = 1900;
	backend.s2.grades.marks = 50;
	backend.s2.dept = SE;
	backend.s2.person.name = "Demo Student 2";
	backend.s2.person.age = 100;
	backend.s2.person.eduLevel = Bachlors;
	backend.s2.person.address.city = "Demo Address 1";
	backend.s2.person.address.state = "Demo State 2";
	backend.s2.person.address.zipCode = 12003;

	backend.currentStudents[0] = backend.s1;
	backend.currentStudents[1] = backend.s2;

	backend.studentsLength = 2;


	backend.c1.courseCode = "MT102";
	backend.c1.courseName = "Demo1";

	backend.c2.courseCode = "CS102";
	backend.c2.courseName = "Demo2";

	backend.coursesLength = 2;

	backend.currentCourses[0] = backend.c1;
	backend.currentCourses[1] = backend.c2;


	backend.currentCourses[0].enrolledStudents[0] = backend.s1;
	backend.currentCourses[0].studentsLength++;

	backend.currentCourses[0].enrolledStudents[1] = backend.s2;
	backend.currentCourses[0].studentsLength++;


	backend.currentCourses[1].enrolledStudents[0] = backend.s1;
	backend.currentCourses[1].studentsLength++;

	backend.currentTeachers[0].person.name = "Demo Teacher 1";
	backend.currentTeachers[0].dept = AI;
	backend.currentTeachers[0].alottedCoursesCount = 1;
	backend.currentTeachers[0].alottedCoursesIndexes[0] = 0;
	backend.currentTeachers[0].salary = 10;
	backend.currentTeachers[0].person.age = 100;

	backend.teacherLength = 1;


}
