#include <ncurses/curses.h>
#include <ctime> // for time_t and time( )
#include <unistd.h> // for sleep( )
#include <iostream>
#define Ws 6 
#define Hs 2
#define LRS 4
#define UDS 2
using namespace std;
void CheckPositionX( int &x );
void CheckPositionY( int &y );

int main()
{
    int width, height;
    int c, x = Ws+2, y =Hs+1 ,i=Hs;
    int go_on;
    initscr();
    cbreak(); // disable key buffering
    noecho(); // disable echoing
    keypad(stdscr, TRUE); // enable keypad reading
    nodelay( stdscr, 1 );
    getmaxyx(stdscr, height, width); // get screen size
	time_t t1, t2;
	t1= time(NULL);
	go_on = TRUE;
	while(go_on)
	{	
  		time(&t2);
    	mvprintw( 3, 3, "%3d" , t2-t1 );
        move(y, x);
        c = getch();
            switch(c)
             	{
                case KEY_LEFT:	 x=x-LRS; mvaddstr(0, 14, "Left "); CheckPositionX(x); break;
                case KEY_RIGHT:	 x=x+LRS; mvaddstr(0, 14, "Right"); CheckPositionX(x); break;
                case KEY_UP:	 y=y-UDS; mvaddstr(0, 14, "Up   "); CheckPositionY(y); break;
                case KEY_DOWN: 	 y=y+UDS; mvaddstr(0, 14, "Down "); CheckPositionY(y); break;
                case '0': printw(" ");  break;
                case '1': printw("1");	break;
                case '2': printw("2");	break;
                case '3': printw("3");	break;
                case '4': printw("4");	break;
                case '5': printw("5");	break;
                case '6': printw("6");	break;
                case '7': printw("7");	break;
                case '8': printw("8");	break;
                case '9': printw("9");	break;
                case 'z': go_on = FALSE; break;
                default: ;
            } // switch (c)
            while (x < 0) x += width;
            while (x >= width) x -= width;
            while (y < 0) y += height;
            while (y >= height) y -= height;
        //refresh();
	}   	
 //Make map    
 /**************************************************************************************************  
   	t1 = time(NULL);
    go_on = TRUE;
	while (go_on) {

        move(y, x);
        c = getch();
            switch(c)
         	{
            case KEY_LEFT:	 x=x-LRS; mvaddstr(0, 14, "Left "); CheckPositionX(x); break;
            case KEY_RIGHT:	 x=x+LRS; mvaddstr(0, 14, "Right"); CheckPositionX(x); break;
            case KEY_UP:	 y=y-UDS; mvaddstr(0, 14, "Up   "); CheckPositionY(y); break;
            case KEY_DOWN: 	 y=y+UDS; mvaddstr(0, 14, "Down "); CheckPositionY(y); break;
            case '0': printw(" ");  break;
            case '1': printw("1");	break;
            case '2': printw("2");	break;
            case '3': printw("3");	break;
            case '4': printw("4");	break;
            case '5': printw("5");	break;
            case '6': printw("6");	break;
            case '7': printw("7");	break;
            case '8': printw("8");	break;
            case '9': printw("9");	break;
            case 'z': go_on = FALSE; break;
            default: ;
            } // switch (c)
        while (x < 0) x += width;
        while (x >= width) x -= width;
        while (y < 0) y += height;
        while (y >= height) y -= height;
    } // while (go_on)
/***********************************************************************************************/    
    endwin();
    return 0;
} // main( )
void CheckPositionX( int &x )
{
    if( x >= Ws+2+(4*9) ) //RIGHT
    	x = x-(4*9);
	else if( x < Ws+2 ) //LEFT
		x = x+(4*9); // X side check 	
}
void CheckPositionY(int &y )
{		
	if( y >= Hs+1+(2*10) ) //DOWN
		y = y-(2*10);
	else if( y < Hs+1 )	//UP
		y = y+(2*10); // Y side check 
}   

