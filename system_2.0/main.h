// generated by Fast Light User Interface Designer (fluid) version 1.0107
#ifndef main_h
#define main_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Double_Window.H>
#include <string>
using namespace std;

void blockshow1();
void blockshow2();
void blockshow3();
void blockshow4();
void blockshow5();
void blockshow6();
void blockshow7();
void blockshow8();
extern Fl_Double_Window *window_main;
extern Fl_Input *input;
extern Fl_Button *btnTest;
extern Fl_Return_Button *btnClose;

class SimpleWindow : public Fl_Window{

   public:
      SimpleWindow(int w, int h, const char* title);
      ~SimpleWindow(){};
      Fl_Button* copy;
      Fl_Input* inp;

   private:
      static void cb_copy(Fl_Widget*, void*);
      inline void cb_copy_i();

};

#endif
