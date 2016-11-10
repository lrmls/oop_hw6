/*
controller object
*/
#ifndef __SHOP
#define __SHOP
#include "std_lib_facilities.h"
#include "parts.h"
#include "manager.h"
#include "stock.h"
#include "customer.h"
#include "seller.h"
#include "boss.h"
#include "order.h"

#include <FL/Fl_Widget.H>


class shop{
private:
	vector <customer> customers;
	vector <seller> sellers;
	vector <order> orders;
	stock warehouse;
	boss boss;
	view view;
	manager pm;
	
	
public:
	shop();
	void run();
	void partCB(Fl_Widget*, void*);
	int get_customer();
	seller get_seller(int);

};
#endif