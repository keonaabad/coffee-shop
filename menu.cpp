#include "menu.h"
#include <iostream>
#include <fstream>

using namespace std;

//Menu needs big 3 implementation because in shop you use the assignment overload operator in load_menu and menu uses dynamic memory so a destructor is needed

Menu::Menu(){
	this->num_coffee = 0;
	this->coffee_arr = new Coffee[num_coffee];
}

Menu::Menu (int size) {
	this->num_coffee = size;
	this->coffee_arr = new Coffee[num_coffee];
}

Menu::Menu(const Menu& other_menu){
	num_coffee = other_menu.num_coffee;
	coffee_arr = new Coffee[num_coffee];
	for(int i = 0; i < num_coffee; i++){
		coffee_arr[i] = other_menu.coffee_arr[i];
	}
}

Menu& Menu::operator=(const Menu& other_menu){
	if(this == &other_menu){
		return *this;
	}
	if(coffee_arr != nullptr){
		delete [] coffee_arr;
	}
	num_coffee = other_menu.num_coffee;
	coffee_arr = new Coffee[num_coffee];
	for(int i = 0; i < num_coffee; i++){
		coffee_arr[i] = other_menu.coffee_arr[i];
	}
	return *this;
}

Menu::~Menu(){
	delete[] coffee_arr;
	coffee_arr = nullptr;
}

//function defintions from menu.h goes here

/*********************************************************************
** Function: set_num_coffee
** Description: sets the number of coffees on the menu
** Parameters: number of coffees
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Menu::set_num_coffee(int n){
	this->num_coffee = n;
}

/*********************************************************************
** Function:set_coffee_arr
** Description: sets the array of coffees to a given array
** Parameters: new coffee array
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Menu::set_coffee_arr(Coffee* c){
	this->coffee_arr = c;
}

/*********************************************************************
** Function: get_num_coffee
** Description: returns the number of coffees on the menu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int Menu::get_num_coffee(){
	return num_coffee;
}

/*********************************************************************
** Function: get_coffee_arr
** Description: returns the array of coffees on the menu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: use [] after function call to access a specific index of coffee arr
*********************************************************************/

Coffee* Menu::get_coffee_arr(){
	return coffee_arr;
}

/*********************************************************************
** Function: search_coffee_by_name
** Description: searches the coffee array for the given name
** Parameters: name
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

Coffee Menu::search_coffee_by_name(string name) {
	for(int i = 0; i < num_coffee; i++){
		if(coffee_arr[i].get_name() == name){
			cout << (i + 1) << ".  ";
			return coffee_arr[i];
		}
	}
	Coffee c;
	return c;
}

/*********************************************************************
** Function: search_coffee_by_price
** Description: returns all of the coffees below a given price
** Parameters: budget
** Pre-Conditions: need at least 1 coffee on the menu
** Post-Conditions: none
*********************************************************************/

Menu Menu::search_coffee_by_price(float budget){
	int num = 0;
	Menu temp;
	for(int i = 0; i < num_coffee; i++){
		if(coffee_arr[i].get_small_cost() <= budget || coffee_arr[i].get_medium_cost() <= budget || coffee_arr[i].get_large_cost() <= budget){
			temp.add_to_menu(coffee_arr[i]);
			num++;
		}
	}
	temp.set_num_coffee(num);
	return temp;
}

/*********************************************************************
** Function: add_to_menu
** Description: adds a given coffee to coffee_arr and updates num_coffee
** Parameters: coffee to add
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Menu::add_to_menu(Coffee& coffee_to_add){
	num_coffee++;
	Coffee* temp = new Coffee[num_coffee];
	for(int i = 0; i < num_coffee-1; i++){
		temp[i] = coffee_arr[i];
	}
	temp[num_coffee - 1] = coffee_to_add;
	coffee_arr = new Coffee[num_coffee];
	for(int i = 0; i < num_coffee; i++){
		coffee_arr[i] = temp[i];
	}
	delete [] temp;
	temp = nullptr;
} 

/*********************************************************************
** Function: remove_from_menu
** Description: removes a coffee at a given index
** Parameters: index of coffee on menu to remove
** Pre-Conditions: need at least 1 coffee on the menu
** Post-Conditions: none
*********************************************************************/

void Menu::remove_from_menu(int index_of_coffee_on_menu){
	num_coffee--;
	Coffee* temp = new Coffee[num_coffee];
	if(index_of_coffee_on_menu != num_coffee){
		for(int i = 0; i < index_of_coffee_on_menu; i++){
			temp[i] = coffee_arr[i];
		}
		for(int i = index_of_coffee_on_menu; i < num_coffee + 1; i++){
			temp[i-1] = coffee_arr[i];
		}
	}
	else{
		for(int i = 0; i < num_coffee; i++){
			temp[i] = coffee_arr[i];
		}
	}
	coffee_arr = new Coffee[num_coffee];
	for(int i = 0; i < num_coffee; i++){
		coffee_arr[i] = temp[i];
	}
	delete [] temp;
	temp = nullptr;
}