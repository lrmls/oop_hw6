#ifndef __CUSTOMER
#define __CUSTOMER
#include "std_lib_facilities.h"
#include "view.h"
#include "stock.h"
#include "seller.h"
//forward declaration of order class to avoid #include loop
class order;

class customer{
private:
	string name;
	stock* warehouse;

	
public:
	customer(stock*);
	vector<robot> shop(vector<seller>, int*);
	void print();
	void set_name(string);
	string get_name();
	void order_nav(vector<order>);
	void show_bill(vector<order>);
};
#endif