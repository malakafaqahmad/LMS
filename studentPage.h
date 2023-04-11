#pragma once
#include "headersLib.h"
#include "backEnd.h"

int studentIndex = 0;
Student* LoggedInStudent;


void displayLoginPage();

void displayStudentPage();
void displayLoggedInPage();
void enrollInCourse();
void showEnrolledCourses();
void seeGrades();
void showDroppedCourses();
void showCompletedCourses();



void displayCourseTeachers() {
	system("CLS");
	cout << "*** Your Teachers : ***";
	cout << " #" << endl;
	int count = 0;

	for (int i = 0; i < backend.coursesLength; i++)
	{
		for (int j = 0; j < backend.studentsLength; j++)
		{
			int studentsRoll = backend.currentCourses[i].enrolledStudents[j].rollNumber;

			if (studentsRoll == LoggedInStudent->rollNumber)
			{
				cout << count + 1 << "    " << backend.currentCourses[i].courseCode << " : " << backend.currentCourses[i].teacher.person.name << endl;

			}
		}
	}

	if (count <= 0)
	{
		cout << "No Courses that you are enrolled in ! " << endl;
	}


	cout << "Press any key and enter to go back: ";
	char x;
	cin >> x;
	displayLoggedInPage();
}

void displayallStudents() {
	cout << "** Students on System : **" << endl;
	for (int i = 0; i < backend.studentsLength; i++)
	{
		Student currStudent = backend.currentStudents[i];
		cout << i + 1 << ". " << currStudent.person.name << " Reg: " << currStudent.rollNumber << endl;
	}
}

void checkDetails() {
	system("CLS");
	cout << "***** Student Details *****" << endl;

	cout << " Name: " << LoggedInStudent->person.name << endl;
	cout << " Age: " << LoggedInStudent->person.age << endl;
	cout << " City: " << LoggedInStudent->person.address.city << endl;
	cout << " Roll Number: " << LoggedInStudent->rollNumber << endl << endl;

	cout << " Press any key and enter to exit and go back : ";
	char x;
	cin >> x;

	displayLoggedInPage();

}

void displayLoggedInPage() {
	system("CLS");


	cout
		<< endl << "-*******  GIKI LMS Login *******-" <<
		endl << "     ---  Welcome Student  ---" << endl

		<< endl << "  *Student Actions*" << endl << endl
		<< "  1. Check Details " << endl
		<< "  2. Enroll In Course" << endl
		<< "  3. See Grades" << endl
		<< "  4. See Teachers List" << endl
		<< "  5. See Enrolled Courses" << endl
		<< "  6. See Dropped Courses" << endl
		<< "  7. See Completed Courses" << endl;


	cout << endl << " Select option (-1 to go back to login) : ";
	int choice = 0;
	cin >> choice;

	switch (choice)
	{
	case 1:
		checkDetails();
		break;
	case 2:
		enrollInCourse();
		break;
	case 3:
		seeGrades();
		break;
	case 4:
		displayCourseTeachers();
		break;
	case 5:
		showEnrolledCourses();

		break;
	case 6:
		showDroppedCourses();
		break;
	case 7:
		showCompletedCourses();
		break;
	case -1:
		displayLoginPage();
		break;
	default:
		break;
	}
}

void displayStudentPage() {
	system("CLS");

	displayallStudents();
	cout << "Which student are you? (Enter Index ) : ";
	cin >> studentIndex;
	LoggedInStudent = &(backend.currentStudents[studentIndex - 1]);

	displayLoggedInPage();

}


void enrollInCourse() {
	system("CLS");
	displayCourses(0, displayLoggedInPage);
	cout << endl << "Select Course To Enroll In : ";
	int x;
	cin >> x;

	backend.currentCourses[x - 1].enrolledStudents[backend.currentCourses[x - 1].studentsLength] = *LoggedInStudent;
	backend.currentCourses[x - 1].studentsLength++;

	cout << "Successfully Enrolled , press any key and enter to go back: ";
	char y;
	cin >> y;
	displayLoggedInPage();
}

void showEnrolledCourses() {
	system("CLS");
	cout << "*** Enrolled Courses ***";
	cout << " #" << endl;
	int count = 0;

	for (int i = 0; i < backend.coursesLength; i++)
	{
		for (int j = 0; j < backend.studentsLength; j++)
		{
			int studentsRoll = backend.currentCourses[i].enrolledStudents[j].rollNumber;

			if (studentsRoll == LoggedInStudent->rollNumber)
			{
				cout << count + 1 << "    " << backend.currentCourses[i].courseCode << endl;

			}
		}
	}

	if (count <= 0)
	{
		cout << "No Courses that you are enrolled in ! " << endl;
	}


	cout << "Press any key and enter to go back: ";
	char x;
	cin >> x;
	displayLoggedInPage();
}
void showDroppedCourses() {
	system("CLS");
	cout << "*** Dropped Courses ***";
	cout << " #" << endl;
	int count = 0;

	for (int i = 0; i < backend.coursesLength; i++)
	{
		for (int j = 0; j < backend.studentsLength; j++)
		{
			int studentsRoll = backend.currentCourses[i].droppedStudents[j].rollNumber;

			if (studentsRoll == LoggedInStudent->rollNumber)
			{
				cout << count + 1 << "    " << backend.currentCourses[i].courseCode << endl;

			}
		}
	}

	if (count <= 0)
	{
		cout << "No Courses that you dropped  ! " << endl;
	}


	cout << "Press any key and enter to go back: ";
	char x;
	cin >> x;
	displayLoggedInPage();
}

void showCompletedCourses() {
	system("CLS");
	cout << "*** Completed Courses ***";
	cout << " #" << endl;
	int count = 0;

	for (int i = 0; i < backend.coursesLength; i++)
	{
		for (int j = 0; j < backend.studentsLength; j++)
		{
			int studentsRoll = backend.currentCourses[i].gradedStudents[j].rollNumber;

			if (studentsRoll == LoggedInStudent->rollNumber)
			{
				cout << count + 1 << "    " << backend.currentCourses[i].courseCode << endl;

			}
		}
	}

	if (count <= 0)
	{
		cout << "No Courses that you Completed  ! " << endl;
	}


	cout << "Press any key and enter to go back: ";
	char x;
	cin >> x;
	displayLoggedInPage();
}

void seeGrades() {
	system("CLS");
	cout << "*** Your Grades ***" << endl;
	int count = 0;
	for (int i = 0; i < backend.coursesLength; i++)
	{
		for (int j = 0; j < backend.studentsLength; j++)
		{
			int studentsRoll = backend.currentCourses[i].enrolledStudents[j].rollNumber;

			if (studentsRoll == LoggedInStudent->rollNumber)
			{
				cout << count + 1 << "    " << backend.currentCourses[i].courseCode << " Grade : " << backend.currentCourses[i].enrolledStudents[j].grades.marks << endl;

			}
		}
	}

	cout << "";








}