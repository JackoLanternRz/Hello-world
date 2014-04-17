#include <ncurses.h>
#include <ctime> // for time_t and time( )
#include <unistd.h> // for sleep( )
#include "Time.h"
using namespace std;

Time::Time(){}

void Time::setT1()
{
    lT=0;
    t1 = time(NULL);
}

void Time::setT2()
{
    time(&t2);
}

void Time::displayTime()
{
    t = t2-t1+lT;
    mvprintw( 4, 62, "%4d" , t );
}

void Time::Save()
{
    FILE *fp;
    fp = fopen("t.txt","w");
    fprintf(fp,"%d",t);
    fclose(fp);
    mvaddstr(22, 17, "   Game Saved   ");
}
void Time::Load()
{
    lT=0;
    FILE *fp;
    fp = fopen("t.txt","r");
    fscanf(fp,"%d", &lT);
    t=lT;
    fclose(fp);
    mvaddstr(22, 17, "   Game Loaded   ");
}
