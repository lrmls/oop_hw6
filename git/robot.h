/*
	defines robot class
*/
#ifndef __ROBOT
#define __ROBOT
#include "std_lib_facilities.h"
#include "parts.h"



class robot{
private:
	int model_num;
	string name;
	double weight=0;
	double price=0;
	double power=0;
	double energy_use=0;

	head skull;
	torso body;
	arm grabber;
	motor mover;
	vector<battery> energy;

public:
	robot();
	robot(head, torso, arm, motor, vector<battery>, string, int);
	void print();
	void print_parts();

	int get_model_num();
	double get_price();
	string get_name();
	arm get_arm();
	head get_head();
	torso get_torso();
	motor get_motor();
	vector<battery> get_battery();
};
#endif