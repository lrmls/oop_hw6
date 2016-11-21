/*
	mthods for managing stock
	getters,setters. for all parts and robots
	also can print entire stock becuase its useful to be able to see as a product manager
*/

#include "std_lib_facilities.h"
#include "stock.h"

//methods for adding to robot and parts vectors
void stock::add_robot(robot rob){ robots.push_back(rob); }
void stock::add_part_h(head h){ heads.push_back(h); }
void stock::add_part_t(torso t){ torsos.push_back(t); }
void stock::add_part_a(arm a){ arms.push_back(a); }
void stock::add_part_m(motor m){ motors.push_back(m); }
void stock::add_part_b(battery b){ batteries.push_back(b); }
//getters of vector sizes
int stock::get_qty_robot(){ return robots.size(); }
int stock::get_qty_h(){ return heads.size(); }
int stock::get_qty_t(){ return torsos.size(); }
int stock::get_qty_a(){ return arms.size(); }
int stock::get_qty_m(){ return motors.size(); }
int stock::get_qty_b(){ return batteries.size(); }
//get a part from storage based on index  
robot stock::get_robot(int index){ return robots[index]; }
arm stock::get_arm(int index){ return arms[index]; }
head stock::get_head(int index){ return heads[index]; }
torso stock::get_torso(int index){ return torsos[index]; }
motor stock::get_motor(int index){return motors[index]; }
battery stock::get_battery(int index){ return batteries[index]; }


void stock::print_inventory(){ 
	cout << "robots:\n";
	for (robot rob : robots){
		rob.print();
	}
	cout << "\nheads:\n";
	for (head part : heads){
		part.print();
	}
	cout << "\narms:\n";
	for (arm part : arms){
		part.print();
	}
	cout << "\ntorsos:\n";
	for (torso part : torsos){
		part.print();
	}
	cout << "\nmotors:\n";
	for (motor part : motors){
		part.print();
	}
	cout << "\nbatteries:\n";
	for (battery part : batteries){
		part.print();
	}
	cout << endl;
}

