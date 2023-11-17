/*********************************************************************
** Program Filename: Coffee Shop
** Author: Keona Abad
** Date: 11/13/2023
** Description: The user interface for a coffee shop
** Input: Choice 1-8 of options the user has
** Output: Option chosen
*********************************************************************/
#include <iostream>
#include "display.h"

using namespace std;

/*********************************************************************
** Function: main
** Description: runs the whole program by loading the shop and asking the user what option they would like to choose
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int main()
{

	//your main function lives here
	cout << "Welcome to Coffee++" << endl;
	int choice = -1;
	Shop s;
	s.load_data();
	while (choice != QUIT){
		choice = get_choice();
		perform_action(s, choice);
	}

	cout << "Bye!" << endl;

	return 0;
}
