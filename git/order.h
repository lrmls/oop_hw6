#ifndef __ORDER
#define __ORDER
#include "std_lib_facilities.h"
#include "seller.h"
#include "customer.h"


class order{
private:
	customer cust;
	seller sellr;
	vector<robot> merchandise;
	int day, month, year;
	double sub_total;
	double tax;
	double total;
	double tax_rate;
	bool payed;

public:
	order(customer, seller, vector<robot>);
	order(customer, seller, vector<robot>, int, int, int, bool);
	void set_date();
	
	string get_cust_name();
	string get_seller_name();
	robot get_bot(int);
	int get_qty_bot();
	int get_day();
	int get_month();
	int get_year();
	double get_price();
	bool is_payed();

	void print_info();
	void print_merchandise();
	void print_price_breakdown();
	void print_date();
	void pay();
};
#endif