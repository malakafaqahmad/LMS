#pragma once
#include <string>

using namespace std;

enum Department
{
	AI, CE, SE, ME, EE
};

enum std_Grade {
	A, B, C, D, F
};

struct Grade {
	std_Grade stdGrade;
	int marks;

};

enum EducationLevel {
	HighSchool, Bachlors, Masters, PHD
};

struct Address {
	string city;
	string state;
	int zipCode;
};

struct Person {
	string name;
	float age;
	Address address;
	EducationLevel eduLevel;
};

struct studentValueSelector {
	string ValueName;
};





Department returnDepartment(int deptIndex) {
	switch (deptIndex)
	{
	case 0:
		return AI;
		break;
	case 1:
		return CE;
		break;
	case 2:
		return SE;
		break;
	case 3:
		return ME;
		break;
	case 4:
		return ME;
		break;
	default:
		break;
	}
};// return department  give an index


string returnDepartmentName(int deptIndex) { // returns department string given an index
	switch (deptIndex)
	{
	case 0:
		return "AI";
		break;
	case 1:
		return "CE";
		break;
	case 2:
		return "SE";
		break;
	case 3:
		return "ME";
		break;
	case 4:
		return "ME";
		break;
	default:
		break;
	}
};


