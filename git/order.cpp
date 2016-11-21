
#include "std_lib_facilities.h"
#include "order.h"
#include "seller.h"
#include "customer.h"
//for getting the date  
#include <ctime>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

order::order(customer buyer, seller associate, vector<robot> purchases) : cust{ buyer }, sellr{ associate }, merchandise{purchases}{
	set_date(); 
	payed = false;
	sub_total = 0;
	tax_rate = .0825;
	for (robot r : merchandise) { sub_total += r.get_price(); }
	tax = sub_total * tax_rate;
	total = sub_total + tax;
}

order::order(customer buyer, seller associate, vector<robot> purchases, int d, int m, int y, bool pay) : cust{ buyer }, sellr{ associate }, merchandise{ purchases }{
	day = d;
	month = m;
	year = y;
	payed = pay;
	sub_total = 0;
	tax_rate = .0825;
	for (robot r : merchandise) { sub_total += r.get_price(); }
	tax = sub_total * tax_rate;
	total = sub_total + tax;
}

void order::set_date(){

	time_t currentTime;
	struct tm *localTime;

	time(&currentTime);                   // Get the current time
	localTime = localtime(&currentTime);  // Convert the current time to the local time
	day = localTime->tm_mday;
	month = localTime->tm_mon + 1;
	year = localTime->tm_year + 1900;

}

string order::get_cust_name(){ return cust.get_name(); }
string order::get_seller_name(){ return sellr.get_name(); }

void order::print_info(){
	cout << "Customer: " << get_cust_name() << "\n";
	cout << "Associate: " << get_seller_name() << endl;
	cout << "Purchases:\n";
	print_merchandise();
	cout << endl;
	print_price_breakdown();
}

void order::print_merchandise(){
	for (robot r : merchandise){
		
		r.print();
		r.print_parts();
		cout << "_______________________________________________________________________\n";
	}
}

void order::print_date(){
	cout << day << "/" << month << "/" << year;
}

void order::print_price_breakdown(){ cout << fixed << setprecision(2) << "Subtotal: $" << sub_total << ", Tax: $" << tax << "\t\tTotal: $" << total << endl; }
double order::get_price(){ return total; }
bool order::is_payed(){ return payed; }
void order::pay(){ payed = true; }
int order::get_day(){ return day; }
int order::get_month(){ return month; }
int order::get_year(){ return year; }
int order::get_qty_bot(){ return merchandise.size();  }
robot order::get_bot(int index){
	return merchandise[index];
}




