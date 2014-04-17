#include <ncurses/curses.h>
#include <ctime> // for time_t and time( )
#include <unistd.h> // for sleep( )
#include <iostream>
using namespace std;

void Game();

int main()
{
    int width, height, select;
    int c,go_on,i=0;
    char **ch;
    initscr();
    cbreak(); // disable key buffering
    noecho(); // disable echoing
    nodelay( stdscr, 1 );
    keypad(stdscr, TRUE); // enable keypad reading
    getmaxyx(stdscr, height, width); // get screen size
    go_on = TRUE;
    /*while(go_on)
    {
        move(1,i);
        c = getch();
        switch(c)
        {
            case '1' : printw("%c", (char)c );ch[i]='1';i++;move(1,i); break;
            case '2' : printw("%c", (char)c );ch[i]='2';i++;move(1,i); break;
            case '3' : printw("%c", (char)c );ch[i]='3';i++;move(1,i); break;
            case '4' : printw("%c", (char)c );ch[i]='4';i++;move(1,i); break;
            case '5' : printw("%c", (char)c );ch[i]='5';i++;move(1,i); break;
            case 'a' : printw("%c", (char)c );ch[i]='a';i++;move(1,i); break;
            case 'q' : go_on = FALSE; break;
            default : mvprintw(3,3,"X");
        }    
    }  */  
    getline(ch,20,'\n'); 
    
    endwin();
    return 0;
}    

