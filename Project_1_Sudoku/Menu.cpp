#include <ncurses.h>
#include <unistd.h> 
#include "Menu.h"
using namespace std;

Menu::Menu(){}

void Menu::Check( int &y , int &Y )
{
    if( y > 12 )
	{
	    y=y-4;
     	Y=Y-2;
 	} 
	else if( y<10 )
	{
	    y=y+4;
	    Y=Y+2;
	}       
}

void Menu::PrintMenu()
{
    mvaddstr(6,34,"S u k o d u");
    mvaddstr(10,34, "->");
    mvaddstr(10,37,"Start");
    mvaddstr(12,37,"Exit");
    mvaddstr(22,0,"Ctrl:[UP][Down][Right]");
    mvaddstr(22,65,"Select: [Right]" ); 
}  
