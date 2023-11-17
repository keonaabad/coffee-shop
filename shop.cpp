#include "shop.h"
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

//uses big 3 implementation to clone shops and shop has dynamic memory that needs to be freed by a destructor

//function defintions from shop.h goes here

Shop::Shop(){
	Menu m;
	phone = "";
	address = "";
	revenue = 0;
	num_orders = 0;
	order_arr = nullptr;
}

Shop::Shop(const Shop& other_shop){
	m = other_shop.m;
	phone = other_shop.phone;
	address = other_shop.address;
	revenue = other_shop.revenue;
	num_orders = other_shop.num_orders;
	order_arr = new Order[num_orders];
	for(int i = 0; i < num_orders; i++){
		order_arr[i] = other_shop.order_arr[i];
	}
}

Shop& Shop::operator=(const Shop& other_shop){
	if(this == &other_shop){
		return *this;
	}
	if(order_arr != nullptr){
		delete [] order_arr;
	}
	m = other_shop.m;
	phone = other_shop.phone;
	address = other_shop.address;
	revenue = other_shop.revenue;
	num_orders = other_shop.num_orders;
	order_arr = new Order[num_orders];
	for(int i = 0; i < num_orders; i++){
		order_arr[i] = other_shop.order_arr[i];
	}
	return *this;
}

Shop::~Shop(){
	delete [] order_arr;
	order_arr = nullptr;
}

/*********************************************************************
** Function: set_menu
** Description: sets the shop's menu to a given menu
** Parameters: menu
** Pre-Conditions: shop object has to have been created
** Post-Conditions: none
*********************************************************************/

void Shop::set_menu(Menu menu){
	this->m = menu;
}

/*********************************************************************
** Function: set_phone
** Description: sets the phone number of the shop to a given phone number
** Parameters: phone number
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

void Shop::set_phone(const string p){
	this->phone = p;
}

/*********************************************************************
** Function: set_address
** Description: sets the address of the shop to a given value
** Parameters: address
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

void Shop::set_address(const string a){
	this->address = a;
}

/*********************************************************************
** Function: set_order_arr
** Description: sets the order_arr to a given array
** Parameters: order array
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

void Shop::set_order_arr(Order* o){
	this->order_arr = o;
}

/*********************************************************************
** Function: set_num_orders
** Description: sets the number of orders to a given number
** Parameters: number of orders
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

void Shop::set_num_orders(int n){
	this->num_orders = n;
}

/*********************************************************************
** Function: get_menu
** Description: gets the menu from the shop
** Parameters: none
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

Menu Shop::get_menu(){
	return m;
}

/*********************************************************************
** Function: get_phone
** Description: gets the phone number from the shop
** Parameters: none
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

string Shop::get_phone() const{
	return phone;
}

/*********************************************************************
** Function: get_address
** Description: gets the address of the shop
** Parameters: none
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

string Shop::get_address() const{
	return address;
}

/*********************************************************************
** Function: get_order_arr
** Description: gets the array of orders
** Parameters: none
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

Order* Shop::get_order_arr(){
	return order_arr;
}

/*********************************************************************
** Function: get_num_orders
** Description: gets the number of orders
** Parameters: none
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

int Shop::get_num_orders(){
	return num_orders;
}

/*********************************************************************
** Function: is_number
** Description: tests if an inputted value is a number
** Parameters: value as a string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

bool is_number(string s){
	for(char c : s){
		if(isdigit(c)){
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: is_float
** Description: checks if an inputted value is a float
** Parameters: value as a string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

bool is_float(string s){
	for(char c : s){
		if(c == '.'){
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: cin_str
** Description: asks the user an inputted question until their response is a string
** Parameters: question to ask
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

string cin_str(string ask){
	cout << ask;
	string s;
	cin >> s;
	while(is_number(s)){
		cout << "Invalid input!" << endl;
		cout << ask;
		cin >> s;
	}
	return s;
}

/*********************************************************************
** Function: cin_float
** Description: asks the user an inputted question until their response is a float
** Parameters: question to ask
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

float cin_float(string ask){
	cout << ask;
	string s;
	cin >> s;
	while(!is_number(s)){
		cout << "Invalid input!" << endl;
		cout << ask;
		cin >> s;
	}
	return stof(s);
}

/*********************************************************************
** Function: cin_int
** Description: asks the user an inputted question until their response is an integer
** Parameters: question to ask
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int cin_int(string ask){
	cout << ask;
	string s;
	cin >> s;
	while(!is_number(s) || is_float(s)){
		cout << "Invalid input!" << endl;
		cout << ask;
		cin >> s;
	}
	return stoi(s);
}

/*********************************************************************
** Function: cin_char
** Description: asks the user an inputted question until their response is a character
** Parameters: question to ask
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

char cin_char(string ask){
	cout << ask;
	string s;
	cin >> s;
	bool not_char = true;
	int loops = 0;
	do{
		for(char c : s){
			loops++;
			if(loops > 1){
				not_char = false;
			}
		}
	} while(not_char);
	return s[0];
}

/*********************************************************************
** Function: load_shop_info
** Description: loads the info from shop_info.txt to the shop
** Parameters: file object (shop_info.txt)
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

void Shop::load_shop_info(ifstream& file){
	string a[3];
	if(file.is_open()){
		file >> phone >> a[0] >> a[1] >> a[2];
		revenue = 0;
		file.close();
		address = a[0] + ' ' + a[1] + ' ' + a[2];
	}
	else{
		cout << "Invalid file!" << endl;
		exit(0);
	}
}

/*********************************************************************
** Function: load_menu
** Description: loads the menu from menu.txt to the shop
** Parameters: file object (menu.txt)
** Pre-Conditions: need to have created a shop object
** Post-Conditions: none
*********************************************************************/

void Shop::load_menu(ifstream& file){
	if(file.is_open()){
		int size;
		file >> size;
		m = Menu(size);
		Coffee* temp = new Coffee[size];
		for(int i = 0; i < size; i++){
			string n;
			float s, md, l;
			file >> n >> s >> md >> l;
			Coffee c(n,s,md,l);
			temp[i] = c;
		}
		m.set_coffee_arr(temp);
	}
	else{
		cout << "Invalid file!" << endl;
		exit(0);
	}
}

/*********************************************************************
** Function: load_orders
** Description: resets orders.txt
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::load_orders(){
	num_orders = 0;
	ofstream file("orders.txt");
	if(file.is_open()){
		file << 0;
	}
	else{
		cout << "Invalid file!" << endl;
		exit(0);
	}
	file.close();
}

/*********************************************************************
** Function: load_data
** Description: loads shop info, menu, and orders
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::load_data(){
	ifstream file;
	file.open("shop_info.txt");
	load_shop_info(file);
	file.close();
	file.open("menu.txt");
	load_menu(file);
	file.close();
	load_orders();
	order_arr = new Order[num_orders];
}

/*********************************************************************
** Function: view shop detail
** Description:shows the user the details of the shop
** Parameters: none
** Pre-Conditions: need to have ran load data to get accurate information
** Post-Conditions: none
*********************************************************************/

void Shop::view_shop_detail(){
	cout << "Address: " << address << endl;
	cout << "Phone: " << phone << endl;
	cout << "The shop revenue is: $" << round(revenue*100)/100 << endl;
	cout << "Here is our menu:\n" << endl;
	for(int i = 0; i < m.get_num_coffee(); i++){
		cout << (i + 1) << ". " << m.get_coffee_arr()[i].get_name() << endl;
		cout << "	Small - " << m.get_coffee_arr()[i].get_small_cost() << endl;
		cout << "	Medium - " << m.get_coffee_arr()[i].get_medium_cost() << endl;
		cout << "	Large - " << m.get_coffee_arr()[i].get_large_cost() << endl;
	}
	cout << "\nOrders info: " << endl;
	if(num_orders > 0){
		for(int i = 0; i < num_orders; i++){
			cout << "ID: " << order_arr[i].get_id() << endl;
			cout << "Name: " << order_arr[i].get_coffee_name() << endl;
			cout << "Size: " << order_arr[i].get_coffee_size() << endl;
			cout << "Quantity: " << order_arr[i].get_quantity() << endl;
		}
	}
	else{
		cout << "(No orders to display)" << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: add_to_menu
** Description: adds a user inputted coffee to the menu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::add_to_menu(){
	string n;
	float s,md,l;
	n = cin_str("Enter the name of the new coffee drink (in 1 word): ");
	s = cin_float("Enter price of small size (8oz): ");
	md = cin_float("Enter price of medium size (12oz): ");
	l = cin_float("Enter price of large size (16oz): ");
	Coffee c(n,s,md,l);
	m.add_to_menu(c);
	ofstream file;
	file.open("menu.txt");
	file << m.get_num_coffee() << endl;
	for(int i = 0; i < m.get_num_coffee(); i++){
		file << m.get_coffee_arr()[i].get_name() << ' ' << m.get_coffee_arr()[i].get_small_cost() << ' ' << m.get_coffee_arr()[i].get_medium_cost() << ' ' << m.get_coffee_arr()[i].get_large_cost() << endl;
	}
}

/*********************************************************************
** Function: remove_from_menu
** Description: removes an item from the menu
** Parameters: none
** Pre-Conditions: need to have at least one item on the menu
** Post-Conditions: none
*********************************************************************/

void Shop::remove_from_menu(){
	int n;
	for(int i = 0; i < m.get_num_coffee(); i++){
		cout << "	" << (i + 1) << "  " << m.get_coffee_arr()[i].get_name() << endl;
	};
	n = cin_int("Which of the drinks above from our menu would you like to remove? Enter 1-" + to_string(m.get_num_coffee()) + ": ");
	while(n < 1 || n > m.get_num_coffee()){
		cout << "Invalid input" << endl;
		n = cin_int("Which of the drinks above from our menu would you like to remove? Enter 1-" + to_string(m.get_num_coffee()) + ": ");
	}
	m.remove_from_menu(n-1);
	ofstream file;
	file.open("menu.txt");
	file << m.get_num_coffee() << endl;
	for(int i = 0; i < m.get_num_coffee(); i++){
		file << m.get_coffee_arr()[i].get_name() << " " << m.get_coffee_arr()[i].get_small_cost() << " " << m.get_coffee_arr()[i].get_medium_cost() << " " << m.get_coffee_arr()[i].get_large_cost() << endl;
	}
	cout << "Item removed" << endl;
}

/*********************************************************************
** Function: search_by_name
** Description: searches by name for a specific coffee on the menu
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::search_by_name(){
	string name;
	name = cin_str("Enter the coffee name: ");
	Coffee c = m.search_coffee_by_name(name);
	if(c.get_name() == ""){
		cout << "Sorry, we don’t have that product at the moment.\n" << endl;
	}
	else{
		c.print_coffee();
	}
}

/*********************************************************************
** Function: search_by_price
** Description: finds all coffees under a user inputted price
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::search_by_price(){
	float price;
	price = cin_float("Enter your budget for one drink, and I will list out our products that are below or equal to your budget: ");
	Menu temp = m.search_coffee_by_price(price);
	for(int i = 0; i < temp.get_num_coffee(); i++){
		cout << (i + 1) << ".  " << temp.get_coffee_arr()[i].get_name() << endl;
		if(temp.get_coffee_arr()[i].get_small_cost() <= price){
			cout << "	Small - " << temp.get_coffee_arr()[i].get_small_cost() << endl;
		}
		if(temp.get_coffee_arr()[i].get_medium_cost() <= price){
			cout << "	Medium - " << temp.get_coffee_arr()[i].get_medium_cost() << endl;
		}
		if(temp.get_coffee_arr()[i].get_large_cost() <= price){
			cout << "	Large - " << temp.get_coffee_arr()[i].get_large_cost() << endl;
		}
	}
	cout << endl;
}

/*********************************************************************
** Function: get_drink_index
** Description: gets the index of the coffee that the user wants to order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

int Shop::get_drink_index(){
	int order_i;
	order_i = cin_int("Which one of these drinks above from our menu would you like to order? Enter 1-" + to_string(m.get_num_coffee()) + ": ");
	while(order_i < 1 || order_i > 8){
		cout << "Invalid input!" << endl;
		order_i = cin_int("Which one of these drinks above from our menu would you like to order? Enter 1-" + to_string(m.get_num_coffee()) + ": ");
	}
	return order_i - 1;
}

/*********************************************************************
** Function: ask_size
** Description: asks the user what size they want their coffee to be
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

char Shop::ask_size(int order_i){
	cout << "	" << m.get_coffee_arr()[order_i].get_name() << endl;
	cout << "		" << "Small: " << m.get_coffee_arr()[order_i].get_small_cost() << endl;
	cout << "		" << "Medium: " << m.get_coffee_arr()[order_i].get_medium_cost() << endl;
	cout << "		" << "Large: " << m.get_coffee_arr()[order_i].get_large_cost() << '\n' << endl;
	char s = cin_char("Enter the size: s-small, m-medium, l-large: ");
	while(s != 's' || s != 'm' || s != 'l'){
		if(s == 's' || s== 'm' || s == 'l'){
			break;
		}
		cout << "Invalid input, try again!" << endl;
		s = cin_char("Enter the size: s-small, m-medium, l-large: ");
	}
	return s;
}

/*********************************************************************
** Function: save_order
** Description: saves a new order to orders.txt
** Parameters: order to save
** Pre-Conditions: need to have initialized the order
** Post-Conditions: none
*********************************************************************/

void Shop::save_order(){
	ofstream file("orders.txt");
	file << num_orders << endl;
	for(int i = 0; i < num_orders; i++){
		file << order_arr[i].get_id() << ' ' << order_arr[i].get_coffee_name() << ' ' << order_arr[i].get_coffee_size() << ' ' << order_arr[i].get_quantity() << endl;
	}
	file.close();
}

/*********************************************************************
** Function: decide_cost
** Description: decides the cost based on coffee, size, and quantity
** Parameters: order index, size, and quantity
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::decide_cost(int order_i, char s, int q){
	if(s == 's'){
		revenue += m.get_coffee_arr()[order_i].get_small_cost() * q;
	}
	else if(s == 'm'){
		revenue += m.get_coffee_arr()[order_i].get_medium_cost() * q;
	}
	else{
		revenue += m.get_coffee_arr()[order_i].get_large_cost() * q;
	}
}

/*********************************************************************
** Function: handle_order
** Description: updates the order_arr with the new order
** Parameters: order index, size, quantity
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::handle_order(int order_i, char s, int q){
	Order* temp = new Order[num_orders];
	for(int i = 0; i < num_orders - 1; i++){
		temp[i] = order_arr[i];
	}
	order_arr = new Order[num_orders];
	for(int i = 0; i < num_orders; i++){
		order_arr[i] = temp[i];
	}
	Order o(num_orders, m.get_coffee_arr()[order_i].get_name(), s, q);
	order_arr[num_orders - 1] = o;
	decide_cost(order_i, s, q);
	cout << "Your order has been placed. Your order number is " << num_orders << ".\n" << endl;
	save_order();
	delete [] temp;
	temp = nullptr;
}

/*********************************************************************
** Function: confirm_order
** Description: confirms the order or cancels it depending on what the user decides
** Parameters: order index, size, quantity
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::confirm_order(int order_i, char s, int q){
	int confirm;
	cin_int("Confirmed? 1-yes, 0-no: ");
	while(confirm > 1 || confirm < 0){
		cout << "Invalid input!" << endl;
		confirm = cin_int("Confirmed? 1-yes, 0-no: ");
	}
	if(!confirm){
		handle_order(order_i, s, q);
	}
	else{
		cout << "Order cancelled!\n" << endl;
	}
}

/*********************************************************************
** Function: place_order
** Description: asks user what they would like to order and saves it to the array and file
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

void Shop::place_order(){
	num_orders++;
	for(int i = 0; i < m.get_num_coffee(); i++){
		cout << i + 1 << ". " << m.get_coffee_arr()[i].get_name() << endl;
	}
	int order_i = get_drink_index();
	char s = ask_size(order_i);
	int q;
	q = cin_int("Enter quantity: ");
	confirm_order(order_i, s, q);
	cout << endl;
	cout << "Your total cost is: $" << round(revenue*100)/100 << endl;
	
}

/*********************************************************************
** Function: clone_shop
** Description: clones the shop
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/

Shop Shop::clone_shop() {
	
	Shop cloned_shop(*this);

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}