/*
	view class
	displays all the menus and does data validation on input
*/
#ifndef __VIEW
#define __VIEW
#include "std_lib_facilities.h"



class view{
public:
	void startMen();
	void managerMen();
	void partMen();
	void customerMen();
	void customer_options();
	void sellerMen();   //unresolved feature, viewing their sales records
	void bossMen();
	

	int valid_option(string, int);
	int valid_part_num(string);
	int valid_model_num(string input);
	double valid_double(string);
};
#endif