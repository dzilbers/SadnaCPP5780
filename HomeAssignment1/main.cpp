/*
File: main.cpp
Description: This is the test program (main) for managing a bus fleet
Course: 150018 C++ Workshop, Exercise 1, Question 1
Author: Dan Zilberstein
*/

#include <iostream>
#include <iomanip>
#include "mytypes.h"
#include "bus.h"
#include "line.h"

using namespace std;

// These are all of the main menu options.  Note that the numbers:
// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
// user will see them on the screen, and will input them for
// choosing a menu option.
// Add your menu options according the the exercise requirements
enum MenuOption {
	EXIT_MENU,
	CREATE_BUS_50_SITS,
	CREATE_BUS_N_SITS,
	ASSIGN_LINE_TO_BUS,
	// ...
	REMOVE_BUS,
	// ...
	SHOW_BUS,
	SHOW_LINE,
	SHOW_ALL_BUSES,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = SHOW_ALL_BUSES
};

// These strings will be seen by the user, on the main menu.  They
// must be kept consistent with the operations of menu_option
// above.
const char * const menuOptionStrings[] = {
	"exit the program",
	"create a bus without line",
	"create a bus with line",
	"assign line to a bus",
	//...
	"add a bus to the fleet",
	"remove a bus from the fleet",
	//...
	"show a bus information",
	"show line bus list",
	"show all the the buses in the fleet"
};

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {
	MenuOption chosen;

	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		// The user will see:
		//
		//           0 -- exit
		//           1 -- set dollars to shekkels conversion rate
		//           2 -- input an account
		// etc.
		//
		// The casts are for doing the "++" as an int type since
		// they are not allowed as a MenuOption type.
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
		chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;

		int chosenInt;
		cout << "Please choose a menu option: ";
		cin >> chosenInt;
		// After the user has input an int, it is cast to a
		//   MenuOption variable.
		chosen = (MenuOption)chosenInt;

		// additional preparations if needed
		// ...

		// Note how the individual cases, match nicely to the
		//     operations they will perform.
		switch (chosen) {
		case EXIT_MENU:
			// adios
			cout << "Thanx for using Bus Fleet Management Program!" << endl;
			break;
		case CREATE_BUS_50_SITS:
			// add your code here
			break;
			//... add your cases with your code here
		default:
			break;
		}
	} while (chosen != EXIT_MENU);

	// Do not forget here to request destroying all the data and freeing all the memory

	return 0;
}
