/*
	boss class
	stores and loads shop data from .txt with certain defined format
	also evaluates associates orders and can 'give raise'
*/
#include "std_lib_facilities.h"
#include "boss.h"
#include "parts.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

boss::boss(string title) :name{ title }{}
boss::boss() {}

void boss::load(stock* warehouse, vector<order>* orders, vector<seller>* sellers, vector<customer>* customers){
	//read from formatted file
	//file format: 1) space delimited. 2) 1st char = flag indicating data type 3) string containing data in order per type
	//data types/flags= parts::  h: head, a: arm, t:torso, b:battery, m:motor, r:robot
	//				    people::  c: customer, s:seller, o:order
	char flag;
	int item_num, pow_slots, h_num, t_num, a_num, m_num, b_num, r_num, i, j;						//variables for part initialization
	int day, month, year;
	double weight, price, pow_use, pow_sup, spd;
	vector<battery> power;
	string name;

	string file = "shopImage.txt";
	ifstream read{ file };

	if (!read){ cout << "failed to read data from " << file << endl; }
	while (read >> flag){
		
		switch (flag){				//**************parts*****************
		case 'h':{							
			read >> item_num; read >> name; read >> weight; read >> price;
			head head(item_num, name, weight, price);
			warehouse->add_part_h(head);
			break; }
		case 't':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_slots;
			torso torso(item_num, name, weight, price, pow_slots);
			warehouse->add_part_t(torso);
			break; }
		case 'a':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_use;
			arm arm(item_num, name, weight, price, pow_use);
			warehouse->add_part_a(arm);
			break; }
		case 'b':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_sup;
			battery battery(item_num, name, weight, price, pow_sup);
			warehouse->add_part_b(battery);
			break; }
		case 'm':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_use; read >> spd;
			motor motor(item_num, name, weight, price, pow_use, spd);
			warehouse->add_part_m(motor);
			break; }
		case 'r':{					//**************robots*****************
			read >> item_num; read >> name; read >> price; read >> h_num; read >> t_num; read >> a_num; read >> m_num;
			//gets messy because i set up my get_part methods to operate by index chosen through menu, now im reading in by part num, must search for each part from vector
			head head;
			for (i = 0; i < warehouse->get_qty_h(); i++) { head = warehouse->get_head(i); if (head.get_part_num() == h_num){ break; }; }
			torso torso;
			for (i = 0; i < warehouse->get_qty_t(); i++) { torso = warehouse->get_torso(i); if (torso.get_part_num() == t_num){ break; }; }
			arm arm;
			for (i = 0; i < warehouse->get_qty_a(); i++) { arm = warehouse->get_arm(i); if (arm.get_part_num() == a_num){ break; }; }
			motor motor;
			for (i = 0; i < warehouse->get_qty_m(); i++) { motor = warehouse->get_motor(i); if (motor.get_part_num() == m_num){ break; }; }
			battery battery;
			for (i = 0; i < torso.get_slots(); i++){
				read >> b_num;
				for (j = 0; j < warehouse->get_qty_b(); j++) { battery = warehouse->get_battery(j); if (battery.get_part_num() == b_num){ break; }; }{
				power.push_back(battery);
				}
			}
				robot rob(head, torso, arm, motor, power, name, item_num);
				warehouse->add_robot(rob);
			break; }
		case 'c':{					//**************people*****************
			read >> name;
			customer cust(warehouse); cust.set_name(name); customers->push_back(cust);
			break; }
		case 's':{
			read >> name;
			seller assoc(name); sellers->push_back(assoc);
			break; }
		case 'o':{					//**************orders*****************
			customer cust(warehouse);
			read >> name; cust.set_name(name);
			read >> name;
			seller sell(name);
			bool payed;
			read >> i; payed = (bool)i;
			read >> day >> month >> year;
			vector<robot> bots;
			read >> r_num;
			for (j = 0, read >> item_num; j < r_num; j++){
				robot rob;
				for (i = 0, rob = warehouse->get_robot(i); i < warehouse->get_qty_robot(); i++){ if (rob.get_model_num() == r_num){ break; } }
				bots.push_back(rob);
			}

			order order(cust, sell, bots, day, month, year, payed);
			orders->push_back(order);
			break; }
		}
	}
	read.close();
}

void boss::save(stock* warehouse, vector<order> orders, vector<seller> sellers, vector<customer> customers){
	// **********ORDER IMPORTANT*********************
	// Must store parts before robots                Store all before orders
	
	string file = "shopImage.txt";
	ofstream store{ file };
	if (!store){ cout << "Failed to open " << file << "for writing\n"; return; }
	
	int i = 0, j = 0;
	//*************************parts***************
	for (i = 0; i < warehouse->get_qty_h(); i++){
		head h =warehouse->get_head(i);
		store << "h " << h.get_part_num() << " " << h.get_name() << " " << h.get_weight() << " " << h.get_price() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_t(); i++){
		torso t = warehouse->get_torso(i);
		store << "t " << t.get_part_num() << " " << t.get_name() << " " << t.get_weight() << " " << t.get_price() << " " << t.get_slots() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_a(); i++){
		arm a = warehouse->get_arm(i);
		store << "a " << a.get_part_num() << " " << a.get_name() << " " << a.get_weight() << " " << a.get_price() << " " << a.get_usage() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_m(); i++){
		motor m = warehouse->get_motor(i);
		store << "m " << m.get_part_num() << " " << m.get_name() << " " << m.get_weight() << " " << m.get_price() << " " << m.get_usage() << " " << m.get_spd() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_b(); i++){
		battery b = warehouse->get_battery(i);
		store << "b " << b.get_part_num() << " " << b.get_name() << " " << b.get_weight() << " " << b.get_price() << " " << b.get_power_supply() << "\n";
	}
	//*************************robots***************
	for (i = 0; i < warehouse->get_qty_robot(); i++){
		robot r = warehouse->get_robot(i);
		store << "r " << r.get_model_num() << " " << r.get_name() << " " << r.get_price() << " " << r.get_head().get_part_num() << " " << r.get_torso().get_part_num() << " "
			<< r.get_arm().get_part_num() << " " << r.get_motor().get_part_num() << " ";
		for (battery b:r.get_battery()){  store << b.get_part_num() << " ";  }
		store << "\n";
	}
	//*************************people***************
	for (i = 0; i < customers.size(); i++){
		store << "c " << customers[i].get_name() << "\n";
	}
	for (i = 0; i < sellers.size(); i++){
		store << "s " << sellers[i].get_name() << "\n";
	}
	//*************************orders***************
	for (i = 0; i < orders.size(); i++){
		store << "o " << orders[i].get_cust_name() << " " << orders[i].get_seller_name() << " ";
		if (orders[i].is_payed()){ store << "1 "; }
		else{ store << "0 "; }
		store << orders[i].get_day() << " " << orders[i].get_month() << " " << orders[i].get_year() << " ";
		store << orders[i].get_qty_bot() << " ";
		for (j = 0; j < orders[i].get_qty_bot(); j++){
			store << orders[i].get_bot(j).get_model_num() << " ";
		}
		store << "\n";
	}

	store.close();
}

bool boss::evaluate(vector<order> orders, vector<seller> associates){
	//view selected associates orders. give raise or not
	if (associates.size() == 0){ cout << "No Available Associates. Hire someone.\n"; }
	string input;
	int choice;
	view view;
	do{
		cout << "Select an associate to appraise:\n";
		int i = 0;
		for (seller s : associates){  cout << "(" << ++i << ") " << s.get_name() << endl;  }
		fflush(stdin);  cin >> input;
		choice = view.valid_option(input, associates.size());
	} while (choice == -1);
	cout << associates[choice - 1].get_name() << "'s sales:\n";
	for (order o : orders)
	{
		if (associates[choice - 1].get_name() == o.get_seller_name())
		{
			o.print_info();
		}
	}
	do{
		cout << "Give " << associates[choice - 1].get_name() << " a raise?\n  (1) No          (2) Yes\n";
		fflush(stdin);  cin >> input;
		choice = view.valid_option(input, 2);
	} while (choice == -1);
	return (bool)(choice-1);

}