/* colortest.c
   CJH BOC 2003.03.06
*/
#include <iostream>
#include <stdio.h>
#include <ncurses/curses.h>

void initial()
{
    	int height,width;
        initscr();
        cbreak();
        noecho();
        nonl();
        keypad(stdscr, TRUE);
        getmaxyx(stdscr, height, width);
        refresh();
}
int colorattr( int color_id)
{
        int attr;
        if(! has_colors() ){
            attr = A_UNDERLINE;
        }
        else {
        	start_color();
            init_pair(1, COLOR_BLUE, COLOR_BLACK);
            init_pair(2, COLOR_YELLOW, COLOR_BLACK);
            init_pair(3, COLOR_RED, COLOR_BLACK);
            init_pair(4, COLOR_GREEN, COLOR_BLACK);
            init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
            init_pair(6, COLOR_CYAN, COLOR_BLACK);
            init_pair(7, COLOR_WHITE, COLOR_BLACK);
            switch(color_id){
                        case        1:
                                attr = COLOR_PAIR(1);
                                break;
                        case        2:
                                attr = COLOR_PAIR(2);
                                break;
                        case        3:
                                attr = COLOR_PAIR(3);
                                break;
                        case        4:
                                attr = COLOR_PAIR(4);
                                break;
                        case        5:
                                attr = COLOR_PAIR(5);
                                break;
                        case        6:
                                attr = COLOR_PAIR(6);
                                break;
                        case        7:
                                attr = COLOR_PAIR(7);
                                break;
                        
                        default        :
                                attr = A_NORMAL;
                }
        }
        return(attr);
}

int workend(int rc)
{
        endwin();
        return(rc);
}

int main()
/*int        argc;
char        *argv[];*/
{
        int color_id,i;

        /*if(argc < 2)        {
                fprintf(stderr, "Usage : %s color_id\n", argv[0]);
                exit(-1);
        }*/
        //scanf("%d",&color_id);
        initial();
        for( i=1 ; i<=7 ; i++ )
        {
            color_id = i;
            attrset(colorattr(color_id));
            attron(colorattr(color_id));
            mvprintw(i, 20, "ABCDEFGHIJKLMN");
            //mvgetch(24, 0);
        }    
        //mvprintw(i, 20, "ABCDEFGHIJKLMN");
        getch();
        workend(0);
}


