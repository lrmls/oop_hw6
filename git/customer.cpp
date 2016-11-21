


#include "std_lib_facilities.h"
#include "customer.h"
#include "robot.h"
#include "order.h"


customer::customer(stock* stock) : warehouse{ stock } {}
//initialize with a stock* for easy access of any customer to robots for searching
void customer::print(){
	cout << name;
}

void customer::set_name(string title){
	name = title;
}
string customer::get_name(){ return name; }

vector<robot> customer::shop(vector<seller> associates, int* seller_index){
	//add as many robots as desired, adding to vector to be returned
	string input;
	int choice, qty;
	view view;
	vector<robot> purchases;
	
	//loop to select however many robots to buy
	do{
		cout << "select an associate:\n";
		for (int i = 0; i < associates.size(); i++){
				cout << "(" << i + 1 << ") " << associates[i].get_name() << endl;
			}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input, associates.size());
		} while (choice == -1);
	*seller_index = choice - 1;
	 do{
		do{
			
			cout << "Select a Robot:\n";
			for (int i = 0; i < warehouse->get_qty_robot(); i++)
			{
				robot x = warehouse->get_robot(i);
				cout << "(" << i + 1 << ") ";
				x.print();
			}
			fflush(stdin); cin >> input;
			choice = view.valid_option(input, warehouse->get_qty_robot());
		} while (choice == -1);
		robot rob = warehouse->get_robot(choice - 1);
		rob.print_parts();
		
		do {
			cout << "Purchase this robot?\n  (1) Yes          (2) No\n";
			fflush(stdin); cin >> input;
			choice = view.valid_option(input, 2);
		} while (choice == -1);
		if (choice == 1){
			do{
				cout << "How many to purchase?(max 5): ";
				fflush(stdin); cin >> input;
				qty = view.valid_option(input, 5);
			} while (qty == -1);
			for (int i = 0; i < qty; i++){ purchases.push_back(rob); }
		}
		do{
			cout << "Continue shopping?  (1) Yes          (2) No\n";
			fflush(stdin); cin >> input;
			choice = view.valid_option(input, 2);
		} while (choice == -1);
	} while (choice == 1);

	if (purchases.size() == 0){ cout << "No purchase made, exiting:"; return purchases; }
		
	cout << "Thank you for your purchase. You can review your orders through the menu.\n";
		
	return purchases;
	
}

void customer::order_nav(vector<order> all){
	//take all orders. trim into vector of only current customers orders, 
	vector<order> mine;
	int i = 0, choice;
	view view;
	string input;
	for (order x : all){
		if (name == x.get_cust_name())
		{
			mine.push_back(x);
		}
	}
	if (mine.size() == 0){ cout << "No order history.\n";  return; }
	while(true){
		//loop until exit, displaying orders listed by date of order.
		cout << "Select an order:\n";
		i = 0;
		for (order x : mine){
			cout << "(" << ++i << ") ";
			x.print_date();
			cout << "\tTotal: $" << x.get_price() << endl;
		}
		cout << "(0) Quit\n";
		do{
			fflush(stdin); cin >> input;
			if (input == "0"){ break; }
			choice = view.valid_option(input, mine.size());
		} while (choice == -1);
		if (input == "0"){ break; }
		mine[choice-1].print_info();
	} 
}

void customer::show_bill(vector<order> all){
	//show monetary data from each order, also grand total
	int i = 0;
	double total = 0;
	for (order h : all){
		if (name == h.get_cust_name())
		{
			cout << "(" << ++i << ") ";
			h.print_price_breakdown();
			if (!h.is_payed())
				total += h.get_price();
		}
	}
	cout << "Outstanding balance: $" << total << endl;
}
