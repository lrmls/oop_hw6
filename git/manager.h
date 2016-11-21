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

#include<FL/Fl_Widget.h>

class manager{
private:
	stock *warehouse;
	string name;

	//hold string to validate for callback access
	static string valprice;
	static string valweight;
	static string valpartnum;
	static string valname;
	static string valsupply;
	static string valoutput;
	static string valslots;
public:
	manager(stock*, string);
	manager();
	static void make_part(int);
	void make_robotCB();

	static void part_validateCB(Fl_Widget* w, void* x);
	static void valpartnumCB(Fl_Widget*, void*);
};
#endif