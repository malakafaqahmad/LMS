#include "headersLib.h"
#include "login.h"


using namespace std;

int main()
{
	// there is some demo data in backEnd.h that initialize demo students , teacher and courses ,to make testing easier
	setupDemoStudents();

	//displays the login page from login.h 
	displayLoginPage();

	return 0;
}

