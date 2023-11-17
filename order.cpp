#include "order.h"

using namespace std;

//needs only assignment overload opperator from big 3 because it is used in handle_order but order has no dynamic memory so a destructor isn't needed

//function defintions from order.h goes here
Order::Order(){
    this->id = 0;
    this->coffee_name = "";
    this->coffee_size = 'c';
    this->quantity = 0;
}

Order::Order(int i, string n, char s, int q){
    this->id = i;
    this->coffee_name = n;
    this->coffee_size = s;
    this->quantity = q;
}

Order& Order::operator=(const Order& other_order){
	if(this == &other_order){
		return *this;
	}
	id = other_order.id;
	coffee_name = other_order.coffee_name;
    coffee_size = other_order.coffee_size;
    quantity = other_order.quantity;
	return *this;
}

/*********************************************************************
** Function: set_id
** Description: sets the id of the order
** Parameters: id
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Order::set_id(const int i){
    this->id = i;
}

/*********************************************************************
** Function: set_coffee_name
** Description: sets the coffee name for the order
** Parameters: name
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Order::set_coffee_name(const string n){
    this->coffee_name = n;
}

/*********************************************************************
** Function: set_coffee_size
** Description: sets the size of the coffee in the order
** Parameters: size
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Order::set_coffee_size(const char s){
    this->coffee_size = s;
}

/*********************************************************************
** Function: set_quantity
** Description: sets the quantity of coffees in the order
** Parameters: quantity
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Order::set_quantity(const int q){
    this->quantity = q;
}

/*********************************************************************
** Function: get_id
** Description: returns the id of the order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int Order::get_id() const{
    return id;
}

/*********************************************************************
** Function: get_coffee_name
** Description: returns the coffee name in the order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

string Order::get_coffee_name() const{
    return coffee_name;
}

/*********************************************************************
** Function: get_coffee_size
** Description: returns the size of the coffee in the order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

char Order::get_coffee_size() const{
    return coffee_size;
}

/*********************************************************************
** Function: get_quantity
** Description: returns the number of coffees in the order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int Order::get_quantity() const{
    return quantity;
}