#include <iostream>
#include "display.h"

using namespace std;

/* name: print_options()
 * description: print possible options to the user
 * parameters: none
 * pre-condition: none
 * post-conditon: none
 */
void print_options() {
	cout << endl; 
	cout << "What would you like to do: " << endl;
	cout << "  1. View shop info " << endl;
	cout << "  2. Add an item to menu " << endl;
	cout << "  3. Remove an item from menu " << endl;
	cout << "  4. Search by coffee name " << endl;
	cout << "  5. Search by price " << endl;
	cout << "  6. Place an order " << endl;
	cout << "  7. Clone a shop " << endl;
	cout << "  8. Log out " << endl;
	cout << endl;
}

/*********************************************************************
** Function: get_choice
** Description: asks the user what option they would like to choose
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int get_choice() {
	int choice = -1; 
	do {
		print_options();
		cout << "Selection: ";
		cin >> choice;
	}while (!(choice >= 1 && choice <= QUIT));

	return choice; 
}

/*********************************************************************
** Function: perform_action
** Description: performs what action each option is associated with
** Parameters: shop and choice
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void perform_action(Shop& s, int choice) {
	switch (choice){
		case 1:
			s.view_shop_detail();
			break;
		case 2:
			s.add_to_menu();
			break;
		case 3:
			s.remove_from_menu();
			break;
		case 4:
			s.search_by_name();
			break;
		case 5:
			s.search_by_price();
			break;
		case 6:
			s.place_order();
			break;
		case 7:
			Shop g = s.clone_shop();

			break;
	}

	return;
}
