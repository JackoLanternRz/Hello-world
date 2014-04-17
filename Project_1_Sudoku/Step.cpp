#include <ncurses.h>
#include <unistd.h> // for sleep( )
#include "Step.h"
using namespace std;

Step::Step(){}

void Step::set()
{
    step = 0;
    mvprintw( 5, 62, "%4d" , step );
}

void Step::getStep()
{
    step++;
    mvprintw( 5, 62, "%4d" , step );
}


void Step::Save()
{
    mvprintw( 5, 62, "%4d" , step );
    FILE *fp;
    fp = fopen("s.txt","w");
    fprintf(fp,"%d",step);
    fclose(fp);
}
void Step::Load()
{
    FILE *fp;
    fp = fopen("s.txt","r");
    fscanf(fp,"%d", &step);
    mvprintw( 5, 62, "%4d" , step );
    fclose(fp);
}

