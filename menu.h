#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    Menu();
    Menu(int);
    Menu& operator=(const Menu &);
    Menu(const Menu&);
    ~Menu();
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate
    void set_num_coffee(int);
    void set_coffee_arr(Coffee*);
    int get_num_coffee();
    Coffee* get_coffee_arr();
    // Suggested functions:
    Coffee search_coffee_by_name(string name); 
    Menu search_coffee_by_price(float budget); 
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu

    // feel free to add more member functions
};

#endif