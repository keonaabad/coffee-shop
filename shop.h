#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop{
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate
    Shop();
    Shop(const Shop&);
    Shop& operator=(const Shop&);
    ~Shop();
    void set_menu(Menu);
    void set_phone(const string);
    void set_address(const string);
    void set_order_arr(Order*);
    void set_num_orders(int);
    Menu get_menu();
    string get_phone() const;
    string get_address() const;
    Order* get_order_arr();
    int get_num_orders();

    //Suggested functions
    void load_shop_info(ifstream&);
    void load_menu(ifstream&);
    void load_orders();
    void load_data(); //reads from files to correctly populate coffee, menu, etc.
    void view_shop_detail();
    void add_to_menu();
    void remove_from_menu();
    void search_by_name();
    void search_by_price();
    int get_drink_index();
    char ask_size(int);
    void save_order();
    void confirm_order(int, char, int);
    void decide_cost(int, char, int);
    void handle_order(int, char, int);
    void place_order();
    Shop clone_shop();
    
};

#endif
