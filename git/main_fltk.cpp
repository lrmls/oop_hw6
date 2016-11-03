/*
	Main for HW6 that will setup fltk and run fltk
*/

#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>

int main()
{
	//scaling size variables
	int win_w = 1000;
	int win_h = 750;
	Fl_Window window(win_w, win_h, "Lrmls' Robot Shop");
	Fl_Box *box = new Fl_Box(100, 100, 200, 175, "Use me betterb");
	box->box(FL_UP_BOX);
	window.end();
	window.show();
	return Fl::run();
}