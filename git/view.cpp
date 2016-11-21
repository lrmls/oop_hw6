/*
	methods for view menus and data validation
*/

#include "std_lib_facilities.h"
#include "view.h"
#include "stock.h"


void view::startMen(){
	//initial menu display 
	cout << "\nUser Level:\n";
	cout << "  (1) Product Manager" << endl << "  (2) Sales Associate\n"
		<< "  (3) Beloved Customer" << endl << "  (4) Wonderfully Haired Boss\n"
		<< "  (5) Exit"				<< endl;
}

//		******************* manager menus **********************
void view::managerMen(){
	//product manager's options 
	cout << "Select option:\n";
	cout << "  (1) Create Part" << setw(30) << right << " (2) Create Robot\n"
		<< "  (3) View Inventory\n";
}

void view::partMen(){
	//menu display for part type
	cout << "Part Type:\n";
	cout << "  (1) Head" << setw(20) << right << "(2) Torso\n"
		<< "  (3) Arm" << setw(21) << right << "(4) Motor\n"
		<< "  (5) Battery\n";
}

//		******************* customer menus **********************
void view::customerMen(){
	//determine customer idenetitity
	cout << "History:\n";
	cout << "  (1) new" << setw(20) << right << "(2) returning\n";
}

void view::customer_options(){
	//customer options
	cout << "Select Option:\n";
	cout << "  (1) Shop" << setw(35) << right << "(2) Purchase History\n"
		<< "  (3) Current bill\n";
}
//      ******************* Boss Menus  *******************************

void view::bossMen(){
	//Boss options
	cout << "Select Option:\n";
	cout << "  (1) Shop Stats" << setw(33) << right << "(2) Order History\n"
		<< "  (3) Load Shop" << setw(30) << right << "(4) Save Shop\n"
		<< "  (5) Evaluate Associate\n";
}

//		******************* menu input validation **********************
int view::valid_part_num(string input){
	//vaidates string input returns valid 4 digit integer number
	if (input.length() != 4) { return -1; }
	for (int i = 0; i < input.length(); i++) { if (input[i]<'0' || input[i]>'9') return -1; }
	return stoi(input);
}

int view::valid_model_num(string input){
	//vaidates string input returns valid 5 digit integer number
	if (input.length() != 5) { return -1; }
	for (int i = 0; i < input.length(); i++) { if (input[i]<'0' || input[i]>'9') return -1; }
	return stoi(input);
}

double view::valid_double(string input){
	//validates a double variable from string input, limit 1 decimal.
	int decimal = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '.') { decimal++; continue; }
		if (input[i]<'0' || input[i]>'9') return -1;
	}
	if (decimal > 1) { return -1; }
	return stod(input);
}
int view::valid_option(string option, int max){
	//validates a single digit number from string input between 1 and MAX(determined by caller)
	if (option.length() > 1) { return -1; }
	if (option[0] < '1' || option[0] > '9') { return -1; }
	int num = stoi(option);
	if (num > max) { return -1; }
	return num;
}