/*
	Definition of class hierarchy for robot types
	base class			component
	derived classes		head, arm, torso, motor, battery
*/
#ifndef __PARTS_CLASS
#define __PARTS_CLASS
#include "std_lib_facilities.h"



class component{
protected:
	int part_num;
	string name;
	double weight=0;
	double price=0;
	string comment;
	//friend robot::robot(head, torso, arm, motor, vector<battery>);   //just wanna be ur friend

public:
	component(int, string, double, double);
	component(int, string, double, double, string); //for if initialized comment
	void print();		//for testing var init
	int get_part_num();		//getters for part data
	string get_name();
	double get_weight();
	double get_price();
};

class head : public component{
public:
	head();
	head(int, string, double, double);
	void print();		//for testing var init
};

class torso : public component{
private:
	int power_slots;
public:
	torso();
	torso(int, string, double, double, int);
	void print();		//for testing var init
	int get_slots();
};

class arm : public component{
private:
	double energy_use;
public:
	arm();
	arm(int, string, double, double, double);
	void print();		//for testing var init
	double get_usage();
};

class motor : public component{
private:
	double energy_use;
	double max_spd;
public:
	motor();
	motor(int, string, double, double, double, double);
	void print();		//for testing var init
	double get_usage();
	double get_spd();
};

class battery : public component{
private:
	double supply;
public:
	battery();
	battery(int, string, double, double, double);
	void print();		//for testing var init
	double get_power_supply();
};

#endif