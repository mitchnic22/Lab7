/***********************
Nicholas Mitchell
CPSC 1021, Section1, F20
nemitch@g.clemson.edu
Nushrat Humaira
***********************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;


typedef struct Employee{
	string lastName;
	string firstName;
	int birthYear;
	double hourlyWage;
}employee;
bool name_order(const employee& lhs, const employee& rhs);
int myrandom (int i) { return rand()%i;}


int main(int argc, char const *argv[]) {
  // IMPLEMENT as instructed below
  /*This is to seed the random generator */
  srand(unsigned (time(0)));


  /*Create an array of 10 employees and fill information from standard input with prompt messages*/
	employee empArr[10]; // struct array declaration
	for (int i = 0; i < 10; i++) { // for loop for user input
		cout << "Enter employee " << i + 1 << "'s last name: ";
		cin >> empArr[i].lastName; // gets last name from user
		cout << endl;
		cout << "Enter employee " << i + 1 << "'s first name: ";
		cin >> empArr[i].firstName; // gets first name from user
		cout << endl;
		cout << "Enter employee " << i + 1 << "'s birth year: ";
		cin >> empArr[i].birthYear; // gets birth year from user
		cout << endl;
		cout << "Enter employee " << i + 1 << "'s hourly wage: ";
		cin >> empArr[i].hourlyWage; // gets hourly wage from user
		cout << endl;
	}	

  /*After the array is created and initialzed we call random_shuffle() see the
   *notes to determine the parameters to pass in.*/
	employee *ptr, *endPtr; // declares pointers

	ptr = &empArr[0]; // ptr points to beginning of employee array
	endPtr = &empArr[11]; // endPtr points to end of employee array

	random_shuffle(&ptr, &endPtr, myrandom); // shuffles employees 

   /*Build a smaller array of 5 employees from the first five cards of the array created
    *above*/
	employee arr[5] = {empArr[1],empArr[2],empArr[3],empArr[4],empArr[5]}; // creates new array of 5
   

    /*Sort the new array.  Links to how to call this function is in the specs
     *provided*/
	ptr = &arr[0]; // ptr points to beginning of new array
	endPtr = &arr[6]; // endPtr points end of new array

	sort(ptr, endPtr, name_order); // calls sort function
   
    /*Now print the array below */
	for (employee &n : arr) { // for loop for output
		cout << setw(20) << right << n.lastName + "," + n.firstName << "\n"; // displays name
		cout << setw(20) << right << n.birthYear << "\n"; // displays birth year
		cout << fixed; // sets the output to fixed number
		cout << setprecision(2); // sets output to 2 decimal points
		cout << setw(20) << right << n.hourlyWage << "\n"; // displays hourly wage
	};
	cout << endl;

return 0;
}


/*This function will be passed to the sort funtion. Hints on how to implement
* this is in the specifications document.*/
bool name_order(const employee& lhs, const employee& rhs) {
  // IMPLEMENT
	return lhs.lastName < rhs.lastName; // returns with last names in ascending order
}

