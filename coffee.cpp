#include "coffee.h"
#include <iostream>

using namespace std;

//uses assignment overload opperator because it is needed in add to menu and remove from menu but we don't use a copy constructor anywhere nor do we need a destructor because coffee has no dynamic memory

Coffee::Coffee(){
    this->name = "";
    this->small_cost = 0;
    this->medium_cost = 0;
    this->large_cost = 0;
}

Coffee::Coffee(const string n, const float s, const float m, const float l){
    this->name = n;
    this->small_cost = s;
    this->medium_cost = m;
    this->large_cost = l;
}

Coffee& Coffee::operator=(const Coffee& other_coffee){
	if(this == &other_coffee){
		return *this;
	}
	name = other_coffee.name;
	small_cost = other_coffee.small_cost;
	medium_cost = other_coffee.medium_cost;
    large_cost = other_coffee.large_cost;
	return *this;
}

//function defintions from coffee.h goes here
/*********************************************************************
** Function: set_name
** Description: sets the coffee's name
** Parameters: name
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Coffee::set_name (const string n){ //constant because name doesn't change
    this->name = n;
}

/*********************************************************************
** Function: set_small_cost
** Description: sets the cost of a small
** Parameters: cost of small
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Coffee::set_small_cost(const float c){ // constant because cost doesn't change
    this->small_cost = c;
}

/*********************************************************************
** Function: set_medium_cost
** Description: sets the cost of a medium
** Parameters: cost of medium
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Coffee::set_medium_cost(const float c){
    this->medium_cost = c;
}

/*********************************************************************
** Function: set_medium_cost
** Description: sets the cost of a medium
** Parameters: cost of medium
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Coffee::set_large_cost(const float c){
    this->large_cost = c;
}

/*********************************************************************
** Function: get_name
** Description: returns the name of the coffee
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

string Coffee::get_name() const{
    return name;
}

/*********************************************************************
** Function: get_small_cost
** Description: returns the cost of a small
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

float Coffee::get_small_cost() const{
    return small_cost;
}

/*********************************************************************
** Function: get_medium_cost
** Description: returns the cost of a medium
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

float Coffee::get_medium_cost() const{
    return medium_cost;
}

/*********************************************************************
** Function: get_large_cost
** Description: returns the cost of a large
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

float Coffee::get_large_cost() const{
    return large_cost;
}

/*********************************************************************
** Function: print_coffee
** Description: prints out the info of the coffee in a visually appealing way
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Coffee::print_coffee() const{
    cout << name << "\nSmall: " << small_cost << "\nMedium: " << medium_cost << "\nLarge: " << large_cost << endl;
}