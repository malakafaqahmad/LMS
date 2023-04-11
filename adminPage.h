#pragma once
#include "headersLib.h"
#include "backEnd.h"
#include "login.h"



void checkChoice(int);

void displayLoginPage();

/*Student Related Admin Functions*/
void addNewStudent();

void showAllStudents(int);

void removeStudentFromSystem();

void updateStudentDetails(int, int);

Student* showStudentDetails(int);
void updateStudentValue(int, Student&);

string returnStudentValueName(int selectionIndex) {
	string possibleData[] = { " Roll Number "," Department "," Name "," Age "," Education Level ", " Zip Code "
	,  " State "," City " };

	return possibleData[selectionIndex - 1];
}
/*--------*/

/*Course Related Admin Functions*/

void addCourseToSystem();
void removeCourseFromSystem();
void updateCourseDetails();
void editCourseValues(int);
void deAlocCourse();
void alocCourse();

/*-------*/


/* Teacher Related Admin Functions */
void addNewTeacher();
void removeTeacherFromSystem();
void showAllTeachers(int);
void updateTeacherDetails(int, int);
//
Teacher* showTeacherDetails(int);
void updateTeacherValue(int, Teacher&);
string returnTeacherValueName(int selectionIndex) {
	string possibleData[] = { " Salary "," Department "," Name "," Age "," Education Level ", " Zip Code "
	,  " State "," City " };

	return possibleData[selectionIndex - 1];
}
/*-------*/

void displayAdminPage() { // displays options to admin
	system("CLS");
	cout
		<< endl << "-*******  GIKI LMS Login *******-" <<
		endl << "     ---  Welcome Admin  ---" << endl

		<< endl << "  *Student Actions*" << endl << endl
		<< "  1. Add New Student To System" << endl
		<< "  2. Remove Student From System" << endl
		<< "  3. Update Student Details" << endl
		<< "  4. Check Record Of All Students" << endl
		<< "  5. Unroll Student From Course" << endl

		<< endl << "  *Teachers Actions*" << endl << endl
		<< "  6. Add New Teacher To System" << endl
		<< "  7. Remove Teacher From System" << endl
		<< "  8. Update Teacher Details" << endl
		<< "  9. Check Record Of All Teachers" << endl

		<< endl << "  *Courses Actions*" << endl << endl
		<< "  10. Add New Course To System" << endl
		<< "  11. Remove Course From System" << endl
		<< "  12. Update Course Details" << endl
		<< "  13. Check Record Of All Courses" << endl
		<< "  14. Allocate course to teacher" << endl
		<< "  15. DeAllocate a course from teacher" << endl;

	cout << endl << " Select option (-1 to go back to login) : ";
	int choice = 0;
	cin >> choice;
	checkChoice(choice);


}

void checkChoice(int choice) // checks for the admin choice and acts accordingly
{
	if (choice == -1)
	{
		displayLoginPage();
		return;
	}
	if (choice >= 1 && choice <= 15)
	{
		switch (choice)
		{
		case 1:
			addNewStudent();
			break;
		case 2:
			removeStudentFromSystem();
			break;
		case 3:
			updateStudentDetails(0, 0);
			break;
		case 4:
			showAllStudents(0);
			char sel;
			cout << "Enter any alphabet to go back: ";

			cin >> sel;

			displayAdminPage();

			break;

		case 5:
			break;
		case 6:
			addNewTeacher();
			break;
		case 7:
			removeTeacherFromSystem();
			break;
		case 8:
			updateTeacherDetails(0, 0);
			break;
		case 9:
			showAllTeachers(0);
			break;
		case 10:
			addCourseToSystem();
			break;
		case 11:
			removeCourseFromSystem();
			break;
		case 12:
			updateCourseDetails();
			break;
		case 13:
			displayCourses(1, displayAdminPage);
			break;
		case 14:
			alocCourse();
			break;
		case 15:
			deAlocCourse();
			break;
		default:
			displayAdminPage();
			break;
		}
	}
	else {
		displayAdminPage();
	}
}

void addNewStudent() { // adds new student to system
	Student* newStudent = new Student;
	system("CLS");
	cout
		<< endl << "-*******  GIKI LMS Login *******-" <<
		endl << "         ---  Add Student  ---" << endl << endl;

	cout << "Enter the Student Name : ";
	cin >> (newStudent->person.name);


	cout << endl << "Enter the Student Age:";
	cin >> (newStudent->person.age);

	cout << endl << "Enter the Student City : ";
	cin >> (newStudent->person.address.city);

	cout << endl << "Enter the Student State : ";
	cin >> (newStudent->person.address.state);

	cout << endl << "Enter the Student Zip Code : ";
	cin >> (newStudent->person.address.zipCode);

	int dept = 100;

	do {
		cout << endl << "Enter the Student Department (0:AI,1:CE,2:SE,3:ME,4:EE): ";
		cin >> dept;
		newStudent->dept = Department(dept);

	} while (dept > 4 || dept < 0);

	int eduLevel = 2;


	do {
		cout << endl << "Enter the Student Education Level (0-2) : ";
		cin >> eduLevel;


		if (eduLevel == 0)
		{
			newStudent->person.eduLevel = HighSchool;
		}
		else if (eduLevel == 1)
		{
			newStudent->person.eduLevel = Bachlors;
		}
		else if (eduLevel == 2)
		{
			newStudent->person.eduLevel = Masters;
		}
		else {
			newStudent->person.eduLevel = PHD;
		}

	} while (eduLevel < 0 || eduLevel > 2);

	newStudent->rollNumber = 2022000 + backend.studentsLength + 1;

	int currentStudentLength = backend.studentsLength;

	backend.currentStudents[currentStudentLength] = *(newStudent);
	backend.studentsLength++;

	delete newStudent;

	char x = 'a';

	while ((x != 'b') && (x != 'B'))
	{
		cout << endl << "Operation Successful . Press 'b' to go back to admin page ";
		cin >> x;


	}
	displayAdminPage();
}


void showAllStudents(int n = 0) { // displays all the students present in the system
	if (!n)
	{
		system("CLS");
	}
	cout << "         ---  All Student  ---" << endl << endl;
	cout << " #" << setw(10) << "Name" << setw(10) << "RegNo" << setw(15) << " Department" << endl;
	for (int i = 0; i < backend.studentsLength; i++)
	{
		Student currStudent = backend.currentStudents[i];
		cout << "  " << i + 1 << "." << setw(10) << currStudent.person.name << setw(10)
			<< currStudent.rollNumber << setw(15)
			<< returnDepartmentName(currStudent.dept) << endl;

	}
	return;
}
void removeStudentFromSystem() { // removes students from system
	system("CLS");
	showAllStudents(1);

	if (backend.studentsLength > 0)
	{
		int selection;
		cout << "Enter student index to delete that user (example : 1) , -1 to go back : ";
		cin >> selection;

		if (selection != (-1)) // checks if selection is valid
		{
			backend.currentStudents[selection - 1] = backend.currentStudents[selection];
			backend.studentsLength--;

			removeStudentFromSystem();
		}
		else {
			displayAdminPage();
		}



	}
	else {
		cout << "No students found type 'b' to go back :  ";
		char ch;
		cin >> ch;
		if (ch == 'b' || ch == 'B')
		{
			displayAdminPage();
		}

	}
	return;
}

Student* showStudentDetails(int index) { // displays all of the students details also returns the student pointer when caled
	Student std = backend.currentStudents[index];
	cout << "  #" << endl;
	cout << "  1. Roll Number: " << std.rollNumber << endl;
	cout << "  2. Department: " << returnDepartmentName(std.dept) << endl;
	cout << "  3. Name: " << std.person.name << endl;
	cout << "  4. Age: " << std.person.age << endl;
	cout << "  5. Education Level: " << std.person.eduLevel << endl;
	cout << "  6. Zip Code: " << std.person.address.zipCode << endl;
	cout << "  7. State: " << std.person.address.state << endl;
	cout << "  8. City: " << std.person.address.city << endl;
	return &backend.currentStudents[index];

}
void updateStudentValue(int index, Student& stdt) {
	string strHolder = " ";
	int intHolder = 0;

	switch (index)
	{
	case 1:
		int roll;
		cin >> roll;
		stdt.rollNumber = roll;
		break;
	case 2:
		cin >> intHolder;
		stdt.dept = returnDepartment(intHolder);
		break;
	case 3:
		cin >> strHolder;
		stdt.person.name = strHolder;
		break;
	case 4:
		cin >> intHolder;
		stdt.person.age = intHolder;
		break;
	case 5:
		cin >> intHolder;
		stdt.person.eduLevel = EducationLevel(intHolder);
		break;
	case 6:
		cin >> intHolder;
		stdt.person.address.zipCode = intHolder;
		break;
	case 7:
		cin >> strHolder;
		stdt.person.address.state = strHolder;
		break;
	case 8:
		cin >> strHolder;
		stdt.person.address.city = strHolder;
		break;
	default:
		break;
	}
	return;
}

void updateStudentDetails(int invalid = 0, int clearScreen = 0) {
	if (!clearScreen)
	{
		showAllStudents(0);

	}

	if (backend.studentsLength > 0)
	{
		if (invalid)
		{
			cout << "Invalid Selection !" << endl;
		}
		cout << "Enter student index to update his/her details: ";

		int selection;
		cin >> selection;


		if (selection > 0 && selection <= backend.studentsLength)
		{
			Student* std = showStudentDetails(selection - 1);
			char sel;

			do {
				cout << endl << "What value you want to change for this student select from 1-8 : ";
				cin >> selection;
				cout << endl << returnStudentValueName(selection) << ": ";

				updateStudentValue(selection, *std);
				cout << "Do you want to change another value for (this) student? ";
				cin >> sel;
			} while (sel == 'y' || sel == 'Y');

			cout << endl << "Updated Data : " << endl;
			showAllStudents(1);

			cout << "Do you want to update another student Data? ";
			cin >> sel;

			if (sel == 'y' || sel == 'Y')
			{
				updateStudentDetails(0, 1);
			}
			else {
				displayAdminPage();
			}
		}
		else {
			cout << "Invalid Selection";
			updateStudentDetails(1);
		}

	}
	else {
		cout << "No students available!. Enter any alphabet to go back : ";
		int x;
		cin >> x;
		displayAdminPage();

	}


	return;


}


void addCourseToSystem() {
	system("CLS");

	cout << "**** Add New Course ****" << endl;
	Course* newCourse = new Course;

	cout << "Enter Course Name: ";
	cin >> newCourse->courseName;

	cout << endl << "Enter Course Code: ";
	cin >> newCourse->courseCode;


	backend.currentCourses[backend.coursesLength] = *newCourse;
	backend.coursesLength++;

	delete newCourse;
	displayAdminPage();
	return;
}

void removeCourseFromSystem() {
	system("CLS");

	cout << " *** Remove Course From System ***" << endl;


	if (backend.coursesLength > 0)
	{
		displayCourses(0, displayAdminPage);

		cout << "Enter index of course you want to delete: ";
		int selection = 0;
		cin >> selection;

		for (int i = selection - 1; i < backend.coursesLength; i++) // 
		{
			backend.currentCourses[i] = backend.currentCourses[i + 1];

		}
		backend.coursesLength--;
	}
	else {
		cout << "No courses added in system!. Press any key and enter to go back : ";
		string x;
		cin >> x;

	}

	displayAdminPage();
	return;
}

void updateCourseDetails() {
	system("CLS");
	cout << " *** Update Course- ***" << endl;
	displayCourses(0, displayAdminPage);
	cout << "Enter The Course index you want to edit: ";
	int sel;
	cin >> sel;

	editCourseValues(sel);



}
void editCourseValues(int index) {

	Course currCourse = backend.currentCourses[index - 1];
	cout << endl << " #" << endl
		<< " 1. Course Name : " << currCourse.courseName << endl
		<< " 2. Course Code : " << currCourse.courseCode << endl
		<< " 3. Code Teacher: " << endl;

	cout << "What value you want to change? (1-3) : ";
	int sel;
	cin >> sel;

	string textHolder;
	int intHolder;
	switch (sel)
	{

	case 1:

		cout << endl << "New Course Name : ";
		cin >> textHolder;
		backend.currentCourses[index - 1].courseName = textHolder;
		break;
	case 2:
		cout << endl << "New Course Code : ";
		cin >> textHolder;
		backend.currentCourses[index - 1].courseCode = textHolder;
		break;
	case 3:
		break;
	default:
		break;
	}

	cout << endl << "Do u want to edit another Value? Y/N : ";
	char x;
	cin >> x;

	if (x == 'y' || x == 'Y')
	{
		editCourseValues(index);
	}
	else {
		displayAdminPage();
	}

}



void deAlocCourse() {
	system("CLS");
	displayCourses(0, displayAdminPage);

	cout << endl << "From which course you want to dealloc a teacher? Enter index : ";
	int sel;
	cin >> sel;

	backend.currentCourses[sel - 1].teacher = *(new Teacher);

	cout << "Teacher de Allocated from course, press any key and enter to go back : ";
	cin >> sel;
	displayAdminPage();

}

void alocCourse() {
	system("CLS");
	displayCourses(0, displayAdminPage);

	cout << endl << "Select Course you want to aloc to a Teacher : ";
	int selCourse;
	cin >> selCourse;

	cout << endl << "Teachers :  " << endl;
	for (int i = 0; i < backend.teacherLength; i++)
	{
		cout << " " << i + 1 << ". " << "   " << backend.currentTeachers[i].person.name << endl;
	}

	cout << "Select Teacher You want to allocate to this course (index) : ";

	int x;
	cin >> x;

	backend.currentCourses[selCourse - 1].teacher = backend.currentTeachers[x - 1];

	cout << endl << "Teacher allocated , press any key and enter to go back : ";
	char te;
	cin >> te;
	displayAdminPage();


}

void addNewTeacher() { // adds a new teacher
	Teacher* newTeacher = new Teacher; // creating new teacher object
	system("CLS");
	cout
		<< endl << "-*******  GIKI LMS Login *******-" <<
		endl << "         ---  Add Teacher  ---" << endl << endl;

	cout << "Enter the Teacher Name : ";
	cin >> (newTeacher->person.name);

	cout << "Enter the Teacher Salary : ";
	cin >> (newTeacher->salary);


	cout << endl << "Enter the Teacher Age:";
	cin >> (newTeacher->person.age);

	cout << endl << "Enter the Teacher City : ";
	cin >> (newTeacher->person.address.city);

	cout << endl << "Enter the Teacher State : ";
	cin >> (newTeacher->person.address.state);

	cout << endl << "Enter the Teacher Zip Code : ";
	cin >> (newTeacher->person.address.zipCode);

	int dept = 100;

	do { // get the department from the user
		cout << endl << "Enter the Teacher Department (0:AI,1:CE,2:SE,3:ME,4:EE): ";
		cin >> dept;
		newTeacher->dept = Department(dept);

	} while (dept > 4 || dept < 0);

	int eduLevel = 2;


	do { // gets the teacher education level
		cout << endl << "Enter the Teacher Education Level (0-2) : ";
		cin >> eduLevel;


		if (eduLevel == 0)
		{
			newTeacher->person.eduLevel = HighSchool;
		}
		else if (eduLevel == 1)
		{
			newTeacher->person.eduLevel = Bachlors;
		}
		else if (eduLevel == 2)
		{
			newTeacher->person.eduLevel = Masters;
		}
		else {
			newTeacher->person.eduLevel = PHD;
		}

	} while (eduLevel < 0 || eduLevel > 2);


	int currentTeacherLength = backend.teacherLength;

	backend.currentTeachers[currentTeacherLength] = *(newTeacher);
	backend.teacherLength++;

	delete newTeacher;

	char x = 'a';

	while ((x != 'b') && (x != 'B')) // checks for b to go back to admin page
	{
		cout << endl << "Operation Successful . Press 'b' to go back to admin page ";
		cin >> x;


	}
	displayAdminPage();
}

void removeTeacherFromSystem() { // removes a teacher from the system
	system("CLS");
	showAllTeachers(1); // function call that shows all the teachers in the system

	if (backend.teacherLength > 0) // checks if there are teachers in the system
	{
		int selection;
		cout << "Enter Teacher index to delete that user (example : 1) , -1 to go back : ";
		cin >> selection;

		if (selection != (-1))
		{
			backend.currentTeachers[selection - 1] = backend.currentTeachers[selection]; // removes the teacher at the index by overwriting it with the next in the array
			backend.teacherLength--; // index decreased of total teacher in the system

			removeTeacherFromSystem(); // calls again if admin wants to delete another one
		}
		else {
			displayAdminPage();
		}



	}
	else {
		cout << "No teachers found type 'b' to go back :  ";
		char ch;
		cin >> ch;
		if (ch == 'b' || ch == 'B')
		{
			displayAdminPage();
		}

	}
	return;
}

void showAllTeachers(int n = 0) {
	if (!n)
	{
		system("CLS");
	}
	cout << "         ---  All Teachers  ---" << endl << endl;
	cout << " #" << setw(10) << "Name" << setw(15) << " Department" << endl;
	for (int i = 0; i < backend.teacherLength; i++)
	{
		Teacher currTeacher = backend.currentTeachers[i];
		cout << "  " << i + 1 << "." << setw(10) << currTeacher.person.name << setw(15)
			<< returnDepartmentName(currTeacher.dept) << endl;

	}
	return;
}

void updateTeacherDetails(int invalid = 0, int clearScreen = 0) {
	if (!clearScreen)
	{
		showAllTeachers(0);

	}

	if (backend.teacherLength > 0)
	{
		if (invalid)
		{
			cout << "Invalid Selection !" << endl;
		}
		cout << "Enter student index to update his/her details: ";

		int selection;
		cin >> selection;


		if (selection > 0 && selection <= backend.teacherLength)
		{
			Teacher* teacher = showTeacherDetails(selection - 1);
			char sel;

			do {
				cout << endl << "What value you want to change for this Teacher select from 1-8 : ";
				cin >> selection;
				cout << endl << returnTeacherValueName(selection) << ": ";

				updateTeacherValue(selection, *teacher);
				cout << "Do you want to change another value for (this) Teacher? ";
				cin >> sel;
			} while (sel == 'y' || sel == 'Y');

			cout << endl << "Updated Data : " << endl;
			showAllTeachers(1);

			cout << "Do you want to update another Teacher Data? ";
			cin >> sel;

			if (sel == 'y' || sel == 'Y')
			{
				updateTeacherDetails(0, 1);
			}
			else {
				displayAdminPage();
			}
		}
		else {
			cout << "Invalid Selection";
			updateTeacherDetails(1);
		}

	}
	else {
		cout << "No Teacher available!. Enter any alphabet and enter to go back : ";
		int x;
		cin >> x;
		displayAdminPage();

	}
	return;


}

Teacher* showTeacherDetails(int index) {
	Teacher teacher = backend.currentTeachers[index];
	cout << "  #" << endl;
	cout << "  1. Salary: " << teacher.salary << endl;
	cout << "  2. Department: " << returnDepartmentName(teacher.dept) << endl;
	cout << "  3. Name: " << teacher.person.name << endl;
	cout << "  4. Age: " << teacher.person.age << endl;
	cout << "  5. Education Level: " << teacher.person.eduLevel << endl;
	cout << "  6. Zip Code: " << teacher.person.address.zipCode << endl;
	cout << "  7. State: " << teacher.person.address.state << endl;
	cout << "  8. City: " << teacher.person.address.city << endl;
	return &backend.currentTeachers[index];

}


void updateTeacherValue(int index, Teacher& teacher) {
	string strHolder = " ";
	int intHolder = 0;

	switch (index)
	{
	case 1:
		int salary;
		cin >> salary;
		teacher.salary = salary;
		break;
	case 2:
		cin >> intHolder;
		teacher.dept = returnDepartment(intHolder);
		break;
	case 3:
		cin >> strHolder;
		teacher.person.name = strHolder;
		break;
	case 4:
		cin >> intHolder;
		teacher.person.age = intHolder;
		break;
	case 5:
		cin >> intHolder;
		teacher.person.eduLevel = EducationLevel(intHolder);
		break;
	case 6:
		cin >> intHolder;
		teacher.person.address.zipCode = intHolder;
		break;
	case 7:
		cin >> strHolder;
		teacher.person.address.state = strHolder;
		break;
	case 8:
		cin >> strHolder;
		teacher.person.address.city = strHolder;
		break;
	default:
		break;
	}
	return;
}


