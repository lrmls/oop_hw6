
//shop, houses all data storage and contains callbacks. Acts as interface between data storage and FLTK

#include "std_lib_facilities.h"
#include "parts.h"
#include "manager.h"
#include "stock.h"
#include "view.h"
#include "robot.h"
#include "shop.h"
#include "boss.h"

#include <FL/Fl_Widget.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Menu_Button.h>

#include <iostream>
#include <fstream>
#include <stdexcept>

shop::shop() {
	manager ben(&warehouse, "Laramie");
	pm = ben;
}

 void shop::partCB(Fl_Widget* w, void* x){
	 int type=0;
	 string label = ((Fl_Menu_*)w)->text();
	 if (strcmp(label.c_str(), "Head") == 0) { type = 1; }
	 if (strcmp(label.c_str(), "Arm") == 0) { type = 2; }
	 if (strcmp(label.c_str(), "Torso") == 0) { type = 3; }
	 if (strcmp(label.c_str(), "Motor") == 0) { type = 4; }
	 if (strcmp(label.c_str(), "Battery") == 0) { type = 5; }
	 ((shop*)x)->pm.make_part(type);
	 
 }
 void shop::robotCB(Fl_Widget* w, void* x) {
	 shop* main = ((shop*)x);
	  
	 
	 if (warehouse.get_qty_h() == 0 || warehouse.get_qty_a() == 0 || warehouse.get_qty_t() == 0 || warehouse.get_qty_m() == 0 || warehouse.get_qty_b() == 0)
	 {
		 Fl_Window* win = new Fl_Window(550, 350, "Error");
		 Fl_Box* err = new Fl_Box(0, 0, 100, 25, "Required Parts Unavailable");
		 return;
	 }
	 
	 main->pm.make_robotCB();
 }


/*
void shop::run(){
	
	
	
	//********************************menu navigation***********************************
	
	string input;
	int choice;
	while (true){									//**********************
		do{											//    Data validation loop
			view.startMen();						//    Used exhaustively throughout
			fflush(stdin);  cin >> input;			//    to ensure clean valid input
			choice = view.valid_option(input, 5);
		} while (choice == -1);						//************************
		if (choice == 5){ return; };

		if (choice == 1)
		{			//manager menus************************************************
			do{
				view.managerMen();
				fflush(stdin);  cin >> input;
				choice = view.valid_option(input, 3);
			} while (choice == -1);
			if (choice == 1)
			{
				pm.make_part();
			}
			else if (choice == 2)
			{
				pm.make_robot();
			}
			else if (choice == 3)
			{
				warehouse.print_inventory();
			}
		}


		else if (choice == 2)
		{			//associates menus************************************************
			cout << "Hire new associate?\n  (1) yes          (2)no\n";
			do{
				fflush(stdin); cin >> input;
				choice =view.valid_option(input, 2);
			} while (choice == -1);
			if (choice == 1){
				cout << "Enter Name:";
				cin >> input;
				seller newby(input);
				sellers.push_back(newby);
			}
		}
		else if (choice == 3)


		{		//customer menus*****************************************************
			int cust_num;
			int seller_index;
			customer customer(&warehouse);

			//determine customer
			do{				
				do{		
					view.customerMen();
					fflush(stdin);  cin >> input;
					choice = view.valid_option(input, 2);
				} while (choice == -1);
				if (choice == 1)
				{
					cout << "name: ";
					fflush(stdin);  cin >> input;
					customer.set_name(input);
					customers.push_back(customer);
					cust_num = 0;
				}
				else if (choice == 2)
				{
					cust_num = get_customer();
					if (cust_num != -1){ customer = customers[cust_num]; }
				}
			} while (cust_num == -1);
			//customer option selection
			do{		
				view.customer_options();
				fflush(stdin);  cin >> input;
				choice = view.valid_option(input, 3);
			} while (choice == -1);
			if (choice == 1)
			{	//purchase
				if (warehouse.get_qty_robot() == 0 ){ cout << "No available robots models\n"; }
				else if(sellers.size() == 0) { cout << "No avalaible associates to help\n"; }
				else{ 
					vector<robot> purchases = customer.shop(sellers, &seller_index);	//
					if (purchases.size() == 0){ continue; }
					seller associate = get_seller(seller_index);
					order order(customer, associate, purchases);
					orders.push_back(order);
				}
			}	//order history
			else if (choice == 2)
			{
				customer.order_nav(orders);
				
			}	//bill
			else if (choice == 3)
			{
				customer.show_bill(orders);
			}
		}	//end scope of individual customer object	


		else if (choice == 4){
			do{		//Boss Menus *************************************************
				view.bossMen();
				fflush(stdin);  cin >> input;
				choice = view.valid_option(input, 5);
			} while (choice == -1);
			if (choice == 3)
			{
				boss.load(&warehouse, &orders, &sellers, &customers);
			}
			if (choice == 4)
			{
				boss.save(&warehouse, orders, sellers, customers);
			}
			if (choice == 5)
			{
				if (boss.evaluate(orders, sellers))  { cout << "Raise given. Good Job!\n"; }
				else{ cout << "Work Harder!\n"; }
			}
		}
		else { cout << "Coming Soon! :)\n"; };
	}
}

int shop::get_customer(){
	if (customers.size() == 0){ cout << "there are no existing customers\n"; return -1; }
	else{
		int i = 0;
		int choice;
		string input;
		do{
			cout << "name?\n";
			for (customer c : customers)
			{
				cout << "(" << i+1 << ") "; c.print(); cout << endl; i++;
			}
			cin >> input;
			choice = view.valid_option(input, customers.size());
		} while (choice == -1);
		return choice-1;
	}
}

seller shop::get_seller(int index){
	return sellers[index];
}
*/