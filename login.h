#pragma once
#include "headersLib.h"
#include "adminPage.h"
#include "teacherPage.h"
#include "studentPage.h"


void displayStudentPage();
void displayLoginPage();

enum UserType {
	ADMIN, STUDENT, TEACHER
};

UserType userType;

void displayLoginPage() {  // checks the user type and assigns it accordingly
	system("CLS");

	int selection;
	cout
		<< endl << "-******* GIKI LMS Login *******-" << endl
		<< setw(18) << "1. Admin" << setw(20) << endl
		<< setw(20) << "2. Student" << setw(20) << endl
		<< setw(20) << "3. Teacher" << setw(20) << endl << endl
		<< "Enter the option 1-3 : ";
	cin >> selection;

	switch (selection)
	{
	case 1:
		userType = ADMIN;
		break;
	case 2:
		userType = STUDENT;
		break;
	case 3:
		userType = TEACHER;
		break;
	default:
		system("CLS");
		cout << endl << "Error: Invalid Selection retry: " << endl;
		displayLoginPage();

		break;
	}

	if (userType == ADMIN)
	{
		displayAdminPage();
	}
	else if (userType == TEACHER) {
		displayTeacherPage();
	}
	else {
		displayStudentPage();
	}
}





