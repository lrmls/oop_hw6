/*
	product manager class
	responsibilities:	create parts,			  store parts in stock
						create robots from parts, store robots in stock
*/

#ifndef __MANAGER_CLASS
#define __MANAGER_CLASS
#include "std_lib_facilities.h"
#include "parts.h"
#include "stock.h"

class manager{
private:
	stock *warehouse;
	string name;
public:
	manager(stock*, string);
	manager();
	void make_part();
	void make_robot();
};
#endif