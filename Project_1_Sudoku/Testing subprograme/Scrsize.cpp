#include <ncurses.h>
#include <ctime> // for time_t and time( )
#include <unistd.h> // for sleep( )
#include <iostream>
#include <cstdio>
using namespace std;
class LoadandSave
{
public:
	void get(int num, int i)
	{
		a[i] = num;
	}
	void Load()
	{
		FILE *fp;
		fp = fopen("sav.txt","r");
		for( int i = 0 ; i < 9 ; i++ )
		{
			fscanf(fp,"%d ", &b[i] );
			mvprintw(i,2,"%d ",b[i]);
		}
		fclose(fp);
	}
	void Save()
	{
		FILE *fp;
		fp = fopen("sav.txt","w");
		for( int i = 0 ; i < 9 ; i++ )
			fprintf(fp,"%d ", a[i] );
		fclose(fp);
	}
private:
	int a[10],b[10];
};
int main()
{
	int width, height,i=0,select;
    int go_on;
    int c,x=2,y=1;
    char ch[20];
    initscr();
    cbreak(); // disable key buffering
    noecho(); // disable echoing
    nodelay( stdscr, 1 );
    keypad(stdscr, TRUE); // enable keypad reading
    getmaxyx(stdscr, height, width); // get screen size
    select = TRUE;
    LoadandSave LS;
    while(select)
    {
        move(y,x);
        c = getch();
        switch(c)
        {
            case KEY_UP:	  y--; break;
            case KEY_DOWN:y++; break;
            case '1' : printw("1");LS.get(1,y); break;
            case '2' : printw("2");LS.get(2,y) ;break;
            case 's':LS.Save();break;
            case 'l':LS.Load();break;
            case 'q': select = 0; break;
            default: ;
           	
        }
    }

    endwin();
    return 0; 
}    
