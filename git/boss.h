
#ifndef __BOSS
#define __BOSS

#include "std_lib_facilities.h"
#include "seller.h"
#include "order.h"

class boss{
private:
	string name;


public:
	boss(string);
	boss();
	void load(stock*, vector<order>*, vector<seller>*, vector<customer>*);
	void save(stock*, vector<order>, vector<seller>, vector<customer>);
	bool evaluate(vector<order>, vector<seller>);
};
#endif