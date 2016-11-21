/*
	class for storing vectors of parts and robots
*/
#ifndef __STOCK_CLASS
#define __STOCK_CLASS

#include "std_lib_facilities.h"
#include "parts.h"
#include "robot.h"


class stock{
private:				
	//robots
	vector<robot> robots;
	//parts
	vector<head> heads;
	vector<torso> torsos;
	vector<arm> arms;
	vector<battery> batteries;
	vector<motor> motors;

	
public: 
	//setters
	void add_robot(robot);
	void add_part_h(head);
	void add_part_t(torso);
	void add_part_a(arm);
	void add_part_m(motor);
	void add_part_b(battery);
	//getters
	int get_qty_robot();
	int get_qty_h();
	int get_qty_t();
	int get_qty_a();
	int	get_qty_m();
	int get_qty_b();
	head get_head(int);
	torso get_torso(int);
	arm get_arm(int);
	motor get_motor(int);
	battery get_battery(int);
	robot get_robot(int);
	
	void print_inventory();
	
	};
#endif