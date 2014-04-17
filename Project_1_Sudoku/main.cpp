#include <ncurses.h>
#include <ctime> // for time_t and time( )
#include <unistd.h> // for sleep( )
#include <iostream>
#include <cstdio>
#include "Make_map.h"
#include "Time.h"
#include "CheckPosition.h"
#include "Step.h"
#include "Menu.h"

#define V 11
#define Ws 6
#define Hs 2
#define LRS 4
#define UDS 2
using namespace std;

void Game();

int main()
{
    int width, height, select;
    int c1,x1=34,y1=10, Y1=1;
    int c, x = Ws+2, y =Hs+1 ,i=Hs,X=0,Y=0;
    int go_on;
    initscr();
    cbreak(); // disable key buffering
    noecho(); // disable echoing
    nodelay( stdscr, 1 );
    start_color();
    keypad(stdscr, TRUE); // enable keypad reading
    getmaxyx(stdscr, height, width); // get screen size
    
    Make_map Map01;
    Menu M;
    M.PrintMenu();
    Time T;
	Step S;
	CheckPosition Check;
	
    select = TRUE;
    while(select)
    {
        move(y1,x1);
        c1 = getch();
        switch(c1)
        {
            case KEY_UP:	 mvprintw(y1,x1,"  "); y1=y1-2;  Y1--; M.Check(y1,Y1); mvprintw( y1, x1, "->" ); break;
            case KEY_DOWN: 	 mvprintw(y1,x1,"  "); y1=y1+2;  Y1++; M.Check(y1,Y1); mvprintw( y1, x1, "->" ); break;
            case KEY_RIGHT:  switch(Y1)
                             {
                                case 1 : erase();
                                
												T.setT1();
												S.set();
												Map01.initialize();
												Map01.setMap();
												Map01.BanSpace();
												Map01.displayMap(); 
				 
													mvaddstr(1,16,  "Pressed Key: [1~9]");
													mvaddstr(21, 17, "Clear space: [0]");
													
													go_on = TRUE;
													while (go_on) {
														move(y, x);
														c = getch();
															switch(c)
															{
															case KEY_LEFT:	 x=x-LRS;  X--; Check.CheckPositionX(x,X); mvaddstr(18, 64, "  "); break;
															case KEY_RIGHT:	 x=x+LRS;  X++; Check.CheckPositionX(x,X); mvaddstr(18, 64, "  "); break;
															case KEY_UP:	 y=y-UDS;  Y--; Check.CheckPositionY(y,Y); mvaddstr(18, 64, "  "); break;
															case KEY_DOWN: 	 y=y+UDS;  Y++; Check.CheckPositionY(y,Y); mvaddstr(18, 64, "  "); break;
															case '0': Map01.getAns(0,X,Y); S.getStep();    break;
															case '1': Map01.getAns(1,X,Y); S.getStep();	break;
															case '2': Map01.getAns(2,X,Y); S.getStep();	break;
															case '3': Map01.getAns(3,X,Y); S.getStep();	break;
															case '4': Map01.getAns(4,X,Y); S.getStep();	break;
															case '5': Map01.getAns(5,X,Y); S.getStep();	break;
															case '6': Map01.getAns(6,X,Y); S.getStep();	break;
															case '7': Map01.getAns(7,X,Y); S.getStep();	break;
															case '8': Map01.getAns(8,X,Y); S.getStep();	break;
															case '9': Map01.getAns(9,X,Y); S.getStep();	break;
															case 'z': go_on = FALSE; break;
															case 'n': Map01.initialize();Map01.setMap();Map01.BanSpace();Map01.displayMap();T.setT1();S.set(); break;
															case 'f': Map01.CheckAns(); break;
															case 'Z': go_on = FALSE; break;
															case 'N': Map01.initialize();Map01.setMap();Map01.BanSpace();Map01.displayMap();T.setT1();S.set(); break;
															case 'F': Map01.CheckAns(); break;
															case 's': Map01.Save();T.Save();S.Save();break;
															case 'S': Map01.Save();T.Save();S.Save();break;
															case 'l': Map01.initialize();Map01.Load();Map01.displayMap();T.setT1();T.Load();S.Load();break;
															case 'L': Map01.initialize();Map01.Load();Map01.displayMap();T.setT1();T.Load();S.Load();break;
															default: T.setT2(); T.displayTime();
															} // switch (c)
													//refresh();
														while (x < 0) x += width;
														while (x >= width) x -= width;
														while (y < 0) y += height;
														while (y >= height) y -= height;
													} // while (go_on)	
													
																			
											erase(); M.PrintMenu(); break;
                                case 2 : select = FALSE; break;
                                default: ;
                             }
                             break;
        }
    }
    endwin();
    return 0;
} // main( )

/***********************************************************************************************************/
/*void Game()
{
    int width, height;
    int c, x = Ws+2, y =Hs+1 ,i=Hs,X=0,Y=0;
    int go_on;
    mvaddstr(1,16,  "Pressed Key: [1~9]");
    mvaddstr(21, 17, "Clear space: [0]");
	Time T;
	Step S;

 	Make_map Map01;
 	CheckPosition Check;
 	Map01.initialize();
    Map01.setMap();
    Map01.BanSpace();
  	Map01.displayMap();
	//T.setT1();
	//S.set();
    go_on = TRUE;
	while (go_on) {
        move(y, x);
	refresh();
        c = getch();
            switch(c)
         	{
            case KEY_LEFT:	 x=x-LRS;  X--; Check.CheckPositionX(x,X); mvaddstr(18, 64, "  ");refresh(); break;
            case KEY_RIGHT:	 x=x+LRS;  X++; Check.CheckPositionX(x,X); mvaddstr(18, 64, "  ");refresh(); break;
            case KEY_UP:	 y=y-UDS;  Y--; Check.CheckPositionY(y,Y); mvaddstr(18, 64, "  ");refresh(); break;
            case KEY_DOWN: 	 y=y+UDS;  Y++; Check.CheckPositionY(y,Y); mvaddstr(18, 64, "  ");refresh(); break;
            /*case '0': Map01.getAns(0,X,Y); S.getStep(); break;
            case '1': Map01.getAns(1,X,Y); S.getStep();	break;
            case '2': Map01.getAns(2,X,Y); S.getStep();	break;
            case '3': Map01.getAns(3,X,Y); S.getStep();	break;
            case '4': Map01.getAns(4,X,Y); S.getStep();	break;
            case '5': Map01.getAns(5,X,Y); S.getStep();	break;
            case '6': Map01.getAns(6,X,Y); S.getStep();	break;
            case '7': Map01.getAns(7,X,Y); S.getStep();	break;
            case '8': Map01.getAns(8,X,Y); S.getStep();	break;
            case '9': Map01.getAns(9,X,Y); S.getStep();	break;
            case 'z': go_on = FALSE; break;
            case 'n': Map01.initialize();Map01.setMap();Map01.BanSpace();Map01.displayMap();T.setT1();S.set(); break;
            case 'f': Map01.CheckAns(); break;
            case 'Z': go_on = FALSE; break;
            case 'N': Map01.initialize();Map01.setMap();Map01.BanSpace();Map01.displayMap();T.setT1();S.set(); break;
            case 'F': Map01.CheckAns(); break;
            case 's': Map01.Save();T.Save();S.Save();break;
            case 'S': Map01.Save();T.Save();S.Save();break;
            case 'l': Map01.Load();Map01.displayMap();Map01.BanSpace();T.Load();S.Load();break;
            case 'L': Map01.Load();Map01.displayMap();Map01.BanSpace();T.Load();S.Load();break;
            default: ;//T.setT2(); T.displayTime();
            } // switch (c)
	refresh();
        while (x < 0) x += width;
        while (x >= width) x -= width;
        while (y < 0) y += height;
        while (y >= height) y -= height;
    } // while (go_on)
}*/

