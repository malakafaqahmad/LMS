#pragma once
#include "headersLib.h"
#include "backEnd.h"
#include <algorithm>  // for std::sort
#include <vector>


int teacherIndex = 0;
Teacher* LoggedInTeacher;



void displayTeacherLoggedInPage();
void showAssignedCourses(int);


union selection {
	char currSelection = 0;
};

selection unionSel;

bool compareStudentsByMarks(const Student& s1, const Student& s2) {
	return s1.grades.marks > s2.grades.marks;
}

void displayStudentsByMarks(const Student std[], int n) {
	vector<Student> students(std, std + n);

	sort(students.begin(), students.end(), compareStudentsByMarks);

	for (const auto& student : students) {
		std::cout << student.person.name
			<< " (" << student.rollNumber << ") - " << student.grades.marks << " marks\n";
	}
}

void seeStudentsByGrades()
{
	system("CLS");
	cout << "** Top Student **" << endl;
	showAssignedCourses(1);
	cout << endl << "Select In Which course you want to see Top Student ";
	int sel;
	cin >> sel;

	int index = LoggedInTeacher->alottedCoursesIndexes[sel - 1];
	Course* SelCourse = &backend.currentCourses[index];

	displayStudentsByMarks(SelCourse->enrolledStudents, SelCourse->studentsLength);


	cout << endl << "Top go back press any key and enter: ";
	cin >> unionSel.currSelection;
	displayTeacherLoggedInPage();


}
void seeTopStudentInCourse() {
	system("CLS");

	cout << "** Top Student **" << endl;
	showAssignedCourses(1);
	cout << endl << "Select In Which course you want to see Top Student ";
	int sel;
	cin >> sel;

	int index = LoggedInTeacher->alottedCoursesIndexes[sel - 1];
	Course* SelCourse = &backend.currentCourses[index];

	int highestMarks = -10000;
	Student topStudent;

	for (int i = 0; i < SelCourse->studentsLength; i++)
	{
		if (SelCourse->enrolledStudents[i].grades.marks > highestMarks) {
			topStudent = SelCourse->enrolledStudents[i];
			highestMarks = SelCourse->enrolledStudents[i].grades.marks;
		}

	}

	cout << endl << "The Top Student in this class is : Roll : " << topStudent.rollNumber << endl << " ,Name: " << topStudent.person.name;

	char t;
	cout << endl << "To go back press any key and enter: ";
	cin >> t;
	displayLoginPage();


}


void gradeStudents() {
	system("CLS");

	cout << "** Grade Students **" << endl;
	showAssignedCourses(1);
	cout << endl << "Select In Which course you want to Grade students ";
	int sel;
	cin >> sel;

	int index = LoggedInTeacher->alottedCoursesIndexes[sel - 1];
	Course* SelCourse = &backend.currentCourses[index];

	int count = 0;

	for (int i = 0; i < SelCourse->studentsLength; i++)
	{
		cout << endl << count + 1 << " RollNumber : " << SelCourse->enrolledStudents[i].rollNumber;
		count++;
	}

	cout << endl;
	cout << "Select the student you want to grade : ";
	int stdSelection;
	cin >> stdSelection;

	cout << "Enter Marks : " << endl;
	int stdMarks;
	cin >> stdMarks;

	cout << "What grade you want to give ? (0:A , 1:B , 2:C , 3:D , 4:F ) (Enter in number) : " << endl;
	int grade;
	cin >> grade;

	SelCourse->enrolledStudents[stdSelection - 1].grades.marks = stdMarks;
	SelCourse->enrolledStudents[stdSelection - 1].grades.stdGrade = std_Grade(grade);

	char t;
	cout << endl << " Done !To go back press any key and enter: ";
	cin >> t;
	displayTeacherLoggedInPage();

}

void findAllCourses() {
	for (int i = 0; i < backend.coursesLength; i++)
	{
		for (int j = 0; j < backend.teacherLength; j++)
		{

			if (backend.currentCourses[i].teacher.person.name == LoggedInTeacher->person.name)
			{
				LoggedInTeacher->alottedCoursesIndexes[LoggedInTeacher->alottedCoursesCount] = i;
				LoggedInTeacher->alottedCoursesCount++;

			}
		}
	}
}

void displayallTeachers() {
	int count = 0;
	cout << "** Teacher on System : **" << endl;
	for (int i = 0; i < backend.teacherLength; i++)
	{
		Teacher currTeacher = backend.currentTeachers[i];
		cout << i + 1 << ". " << currTeacher.person.name << endl;
		count++;
	}

	if (count == 0) {
		cout << "No Teachers Found go back to login and add teacher through admin !!! On next page press -1 to go back " << endl;
	}


}

void showStudentsInCourse() {

	system("CLS");

	cout << "** Select Course : **" << endl;
	showAssignedCourses(1);
	cout << endl << "Select In Which course you want to see students ";
	int sel;
	cin >> sel;

	Course SelCourse = backend.currentCourses[LoggedInTeacher->alottedCoursesIndexes[sel - 1]];

	for (int i = 0; i < SelCourse.studentsLength; i++)
	{
		cout << endl << " RollNumber : " << SelCourse.enrolledStudents[i].rollNumber;
	}
	char t;
	cout << endl << "To go back press any key and enter: ";
	cin >> t;
	displayTeacherLoggedInPage();

}

void checkTeacherDetails() {
	system("CLS");
	cout << "***** Teacher Details *****" << endl;

	cout << " Name: " << LoggedInTeacher->person.name << endl;
	cout << " Age: " << LoggedInTeacher->person.age << endl;
	cout << " City: " << LoggedInTeacher->person.address.city << endl;
	cout << " Department: " << returnDepartmentName(LoggedInTeacher->dept) << endl << endl;

	cout << " Press any key and enter to exit and go back : ";
	char x;
	cin >> x;

	displayTeacherLoggedInPage();

}

void displayTeacherLoggedInPage() {

	system("CLS");
	findAllCourses();

	cout
		<< endl << "-*******  GIKI LMS Login *******-" <<
		endl << "     ---  Welcome Teacher  ---" << endl

		<< endl << "  *Teacher Actions*" << endl << endl
		<< "  1. Check Details " << endl
		<< "  2. See Allotted Courses" << endl
		<< "  3. See Students in Alloted Courses" << endl
		<< "  4. Assign Marks And Grades To Students" << endl
		<< "  5. See Top Student In A course" << endl
		<< "  6. Grade wise division of students in a course." << endl;


	cout << endl << " Select option (-1 to go back to login) : ";
	int choice = 0;
	cin >> choice;

	switch (choice)
	{
	case 1:
		checkTeacherDetails();
		break;
	case 2:
		showAssignedCourses(0);
		break;
	case 3:
		showStudentsInCourse();
		break;
	case 4:
		gradeStudents();
		break;
	case 5:
		seeTopStudentInCourse();

		break;
	case 6:
		seeStudentsByGrades();
		break;

	case -1:
		displayLoginPage();
		break;
	default:
		break;
	}
}

void displayTeacherPage() {
	system("CLS");

	displayallTeachers();
	cout << "Which Teacher are you? (Enter Index ) : ";
	cin >> teacherIndex;

	LoggedInTeacher = &(backend.currentTeachers[teacherIndex - 1]);

	displayTeacherLoggedInPage();

}



void showAssignedCourses(int sel = 0) {
	if (!sel)
	{
		system("CLS");

	}

	cout << "*** Assigned Courses ***";
	cout << " #" << endl;
	int count = 0;

	for (int i = 0; i < LoggedInTeacher->alottedCoursesCount; i++)
	{

		cout << count + 1 << "    " << backend.currentCourses[LoggedInTeacher->alottedCoursesIndexes[i]].courseCode << endl;
		count++;
	}

	if (!sel)
	{
		if (count <= 0)
		{
			cout << "No Courses that you are Alloted To! " << endl;
		}


		cout << "Press any key and enter to go back: ";
		char x;
		cin >> x;
		displayTeacherLoggedInPage();
	}



}

