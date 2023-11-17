#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	Order();
	Order(int, string, char, int);
	Order& operator=(const Order&);
	void set_id(const int);
	void set_coffee_name(const string);
	void set_coffee_size(const char);
	void set_quantity(const int);
	int get_id() const;
	string get_coffee_name() const;
	char get_coffee_size() const;
	int get_quantity() const;
};
#endif