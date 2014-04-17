#include <ncurses/curses.h>
#include <ctime>
#include <unistd.h> 
int main()
{
    int width, height;
    int go_on;
    initscr();
 
    printw("Hello Ncurses!!");
    //refresh();
    getch();
    endwin();
    return 0;
}
    
