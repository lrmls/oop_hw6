/*
	implementaion of manager class
	big menu navigation steps for creating parts and robots.
	constructed with a stock* for easy stock access because stock access is all that manager does
*/

#include "std_lib_facilities.h"
#include "manager.h"
#include "parts.h"
#include "view.h"

manager::manager(stock *repo, string title){
	warehouse = repo;
	name = title;
}
manager::manager() {}

void manager::make_part(){
	//make any part and store it into warehouse 
	view view;
	int part_num;
	string name;
	double weight, price;
	string input;
	int option;
	//gather part information shared by all parts
	do{
		cout << "4 digit Part number: ";
		fflush(stdin);  cin >> input;
		part_num = view.valid_part_num(input);
	}while(part_num == -1);
	cout << "Part name: ";
	fflush(stdin); getline(cin,name);
	do{
		cout << "weight(lbs): ";
		fflush(stdin); cin >> input;
		weight = view.valid_double(input);
	} while (weight == -1);
	do{
		cout << "price($): ";
		fflush(stdin); 	cin >> input;
		price = view.valid_double(input);
	} while (price == -1);
	//determine part type to gather part-unique data
	do{
		view.partMen();
		fflush(stdin); cin >> input;							 
		option = view.valid_option(input, 5);
	}while (option == -1);

	//options 1 head, 2 torso, 3 arm, 4 motor, 5 battery
	switch (option){
	case 1:
	{	head head(part_num, name, weight, price);
		warehouse->add_part_h(head);
		 break;}
	case 2:
	{	int bat_num;
		do{
			cout << "Number of battery slots(max 4): ";
			fflush(stdin); cin >> input;
			bat_num = view.valid_option(input, 4);
		} while (bat_num == -1);
		torso torso(part_num, name, weight, price, bat_num);
		warehouse->add_part_t(torso);
		break;} 
	case 3:
	{	double usage;
		do{
			cout << "Energy Usage(watts): ";
			fflush(stdin);  cin >> input;
			usage = view.valid_double(input);
		} while (usage == -1);
		arm arm(part_num, name, weight, price, usage);
		warehouse->add_part_a(arm);
		 break;}
	case 4:
	{	double usage;
		double spd;
		do{
			cout << "Energy Usage(watts): ";
			fflush(stdin);  cin >> input;
			usage = view.valid_double(input);
		} while (usage == -1);
		do{
			cout << "Max speed(mph): ";
			fflush(stdin);  cin >> input;
			spd = view.valid_double(input);
		} while (spd == -1);
		motor motor(part_num, name, weight, price, usage, spd);
		warehouse->add_part_m(motor);
		break; }
	case 5:
	{	double supply;
		do{
			cout << "Energy supply(kwh): ";
			fflush(stdin);  cin >> input;
			supply = view.valid_double(input);
		} while (supply == -1);
		battery battery(part_num, name, weight, price, supply);
		warehouse->add_part_b(battery);
		break; }
	}
}

void manager::make_robot(){
	// make a robot from selected parts.
	view view;
	int h, a, t, m;				//short sweet variable names for index of parts
	int slots, model;
	vector<battery> b;
	string input;
	int choice;
	if (warehouse->get_qty_h() == 0 || warehouse->get_qty_a() == 0 || warehouse->get_qty_t() == 0 || warehouse->get_qty_m() == 0 || warehouse->get_qty_b() == 0)
	{
		cout << "Not enough parts to construct robot.\n"; return;
	}
	//************************************************************
	do{
		cout << "Select a Head:\n";
		for (int i = 0; i < warehouse->get_qty_h(); i++)
		{
			head x = warehouse->get_head(i);
			cout << "(" << i + 1 << ") ";
			x.print();
		}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input,warehouse->get_qty_h());
	} while (choice == -1);
	h = choice -1;				//account for indexing. menu started @ 1 cuz i want it to
	//************************************************************
	do{
		cout << "Select a Torso:\n";
		for (int i = 0; i < warehouse->get_qty_t(); i++)
		{
			torso x = warehouse->get_torso(i);
			cout << "(" << i + 1 << ") ";
			x.print();
		}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input, warehouse->get_qty_t());
		
	} while (choice == -1);
	t = choice - 1;
	slots = warehouse->get_torso(t).get_slots();
	//************************************************************
	do{
		cout << "Select an Arm:\n";
		for (int i = 0; i < warehouse->get_qty_a(); i++)
		{
			arm x = warehouse->get_arm(i);
			cout << "(" << i + 1 << ") ";
			x.print();
		}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input, warehouse->get_qty_a());
	} while (choice == -1);
	a = choice - 1;
	//************************************************************
	do{
		cout << "Select a Motor:\n";
		for (int i = 0; i < warehouse->get_qty_m(); i++)
		{
			motor x = warehouse->get_motor(i);
			cout << "(" << i + 1 << ") ";
			x.print();
		}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input, warehouse->get_qty_m());
	} while (choice == -1);
	m = choice - 1;
	//************************************************************
	do{
		cout << "Select " << slots - b.size() << " Batteries(one at a time):\n";
		for (int i = 0; i < warehouse->get_qty_b(); i++)
		{
			battery x = warehouse->get_battery(i);
			cout << "(" << i + 1 << ") ";
			x.print();
		}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input, warehouse->get_qty_b());
		if (choice != -1){ b.push_back( warehouse->get_battery(choice - 1) ) ; }
		
	}while (choice == -1 || b.size()<slots);
	do{
		cout << "5 digit Part number: ";
		fflush(stdin); cin >> input;
		model = view.valid_model_num(input);
	} while (model == -1);
	cout << "Part name: ";
	fflush(stdin); getline(cin, input);
	robot robbie(warehouse->get_head(h), warehouse->get_torso(t), warehouse->get_arm(a), warehouse->get_motor(m), b, input, model);
	warehouse->add_robot(robbie);

}
