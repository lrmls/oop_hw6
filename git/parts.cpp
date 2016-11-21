/*
	Definitions of different parts classes
	component is base, all others derived
	each part has 2 constructors
		default constructor that constructs with garbage beacuase i was getting errors without the default
			constructor being 'defined', only used when declaring an empty part before assigning it to
			one from storage
		main constructor that takes all needed data and sets its variables through delegation through
			componenet and its specific variables
	also each part gets and prints its data
*/

#include "std_lib_facilities.h"
#include "parts.h"


	//COMPONENT base for all parts
component::component(int num, string title, double pounds, double cost){
	part_num = num; 
	name = title; 
	weight = pounds;
	price = cost;
}
void component:: print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << endl;
} 
int component::get_part_num(){ return part_num; }
string component::get_name(){ return name; }
double component::get_weight(){ return weight; }
double component::get_price(){ return price; }
	//***************** HEAD **********************************************
head::head(int num, string title, double pounds, double price) 
	:component(num, title, pounds, price){
}
head::head() : component(0, "I", 0, 0){}

void head::print(){
	cout << fixed << setprecision(2) << "number: " << part_num << ", name: " << name << ", weight: " << weight << " lbs, price: $" << price << endl;
}
	//***************** ARM **********************************************
arm::arm(int num, string title, double pounds, double price, double usage) 
	:component(num, title, pounds, price){
	energy_use = usage;
}
arm::arm() :component(0, "I", 0, 0), energy_use{0}{}

double arm::get_usage(){ return energy_use; }	
void arm::print(){
	cout << fixed << setprecision(2) << "number: " << part_num << ", name: " << name << ", weight: " << weight << " lbs, drain: " << energy_use << " watts, price: $" << price << endl;
}

	//***************** TORSO ***************** *********************************
torso::torso(int num, string title, double pounds, double price, int amount) 
	: component(num, title, pounds, price){
	power_slots = amount;
}
torso::torso() : component(0, "I", 0, 0), power_slots{ 0 }{}
void torso::print(){
	cout << fixed << setprecision(2) << "number: " << part_num << ", name: " << name << ", weight: " << weight << " lbs, battery slots: " << power_slots << ", price: $" << price << endl;
}
int torso::get_slots(){ return power_slots; }
	//***************** BATTERY ***************** ******************************
battery::battery(int num, string title, double pounds, double price,  double power) 
	: component(num, title, pounds, price){
	supply = power;
}
battery::battery() : component(0, "I", 0, 0), supply{ 0 }{}
void battery::print(){
	cout << fixed << setprecision(2) << "number: " << part_num << ", name: " << name << ", weight: " << weight << "lbs, power supply: " << supply << " kwh, price: $" << price << endl;
}
double battery::get_power_supply(){ return supply; }
	//***************** MOTOR *****************************************************
motor::motor(int num, string title, double pounds, double price, double usage, double spd)
	: component(num, title, pounds, price){
	energy_use = usage;
	max_spd = spd;
}
motor::motor() : component(0, "I", 0, 0), energy_use{ 0 }, max_spd{0}{}

void motor::print(){
	cout << fixed << setprecision(2) << "number: " << part_num << ", name: " << name << ", weight: " << weight << " lbs, drain: " << energy_use << " watts\n\tmax speed: " << max_spd << " mph, price: $" << price << endl;
}
double motor::get_usage(){ return energy_use; }
double motor::get_spd(){ return max_spd; }