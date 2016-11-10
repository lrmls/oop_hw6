/*
	Main for HW6 that will setup fltk and run fltk
*/

#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Menu_Bar.H>
#include<FL/Fl_Menu_Item.H>

#include "shop.h"


int main()
{
	shop shop;
	//scaling size variables
	int win_w = 1000;
	int win_h = 750;
	Fl_Window* window = new Fl_Window(win_w, win_h, "Lrmls' Robot Shop");
	Fl_Box *box = new Fl_Box(100, 100, 200, 175, "Use me betterb");
	box->box(FL_UP_BOX);
	Fl_Menu_Bar* toolbar = new Fl_Menu_Bar(0, 0, win_w, 30);
	Fl_Menu_Item toolbar_options[] = {
		{ "&File", 0, 0, 0, FL_SUBMENU},
			{ "Open", FL_ALT + 'o'/*open file callback*/},
			{ "Save", FL_ALT + 's'/*save file callback*/ },
		{0},
		{ "&Create", 0, 0, 0, FL_SUBMENU },
			{ "Part", FL_CTRL + 'p' ,(Fl_Callback *) shop.partCB },
			{ "Robot", FL_CTRL + 'r'/*create robot callback*/ },
		{ 0 },
		{ "&Order", 0, 0, 0, FL_SUBMENU},
			{ "Place Order", /*customer order callback*/ },
		{ 0 },
	{ 0 }
	};
	toolbar-> menu(toolbar_options);

	window->end();
	window->show();
	return Fl::run();
}