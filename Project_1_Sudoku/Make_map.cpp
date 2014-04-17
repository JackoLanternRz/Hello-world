#include "Make_map.h"
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#define TRUE 1
#define FALES 0
#define Ws 6
#define Hs 2
#define V 11
#include <stdio.h>
using namespace std;

Make_map::Make_map()
{
}

void Make_map::setMap()
{
		// creat rand number
    while( count < 9 )
    {
        temp = ((rand()%9)+1);
        if( RandCheck(randLine,temp,count) == TRUE )
        {
           randLine[count] = temp;
           count++;
        }
    }
    //make line into square
    for( i=0 ; i<3 ; i++ )
    {
        for( j=0 ; j<3 ; j++ )
        {
            randSquare[i][j] = randLine[count2];
            count2++;
        }
	}

		/*make sukodu square*/
    for( i=0 ; i<3 ; i++ )
    {
        for( j=0 ; j<3 ; j++ )
        {
           sukodu[i+3][j+3] = randSquare[i][j];
        }
	}

    //make sukodu
    for( i=0 ; i<3 ; i++ )
    {
       /*L M*/
       sukodu[4][i] = sukodu[3][i+3];
       sukodu[5][i] = sukodu[4][i+3];
       sukodu[3][i] = sukodu[5][i+3];

       /*R M*/
       sukodu[5][i+6] = sukodu[3][i+3];
       sukodu[3][i+6] = sukodu[4][i+3];
       sukodu[4][i+6] = sukodu[5][i+3];

       /*U M*/
       sukodu[i][4] = sukodu[i+3][3];
       sukodu[i][5] = sukodu[i+3][4];
       sukodu[i][3] = sukodu[i+3][5];

       /*D M*/
       sukodu[i+6][5] = sukodu[i+3][3];
       sukodu[i+6][3] = sukodu[i+3][4];
       sukodu[i+6][4] = sukodu[i+3][5];

    }
    for( i=0 ; i<3 ; i++ )
    {
       /*L U*/
       sukodu[1][i] = sukodu[0][i+3];
       sukodu[2][i] = sukodu[1][i+3];
       sukodu[0][i] = sukodu[2][i+3];

       /*R U*/
       sukodu[2][i+6] = sukodu[0][i+3];
       sukodu[0][i+6] = sukodu[1][i+3];
       sukodu[1][i+6] = sukodu[2][i+3];

       /*L D*/
       sukodu[7][i] = sukodu[6][i+3];
       sukodu[8][i] = sukodu[7][i+3];
       sukodu[6][i] = sukodu[8][i+3];

       /*R D*/
       sukodu[8][i+6] = sukodu[6][i+3];
       sukodu[6][i+6] = sukodu[7][i+3];
       sukodu[7][i+6] = sukodu[8][i+3];
    }  //end of sukodu

    FILE *fp;
    fp = fopen("Sukodu.txt","w");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",sukodu[i][j]);
    	}
    	fprintf(fp,"\n");
    }

    //dig blocks
	while( countBlock <= 41 )
	{
  		selI = rand()%9;
  		selJ = rand()%9;
  		if( sukodu[selI][selJ] != 0 )
  		{
  		    sukodu[selI][selJ] = 0 ;
  		    countBlock++;
  		}
	}

}//end of setMap

int Make_map::RandCheck(int *randLine, int temp, int count)
{
    int i;
    for( i=0 ; i<count ; i++ )
    {
        if( randLine[i] == temp )
        	return FALES;
    }
    return TRUE;
}

void Make_map::displayMap()
{
    mvaddstr(2,49, "-----------------------");
    mvaddstr(3,48,"|                       |");
    mvaddstr(4,48,"|    Time :             |");
    mvaddstr(5,48,"|    Steps:             |");
    mvaddstr(6,48,"|                       |");
    mvaddstr(7,49, "-----------------------");

    mvaddstr(8,49,  "-----------------------" );
    mvaddstr(9,48, "|  Control: Arrow keys  |");
    mvaddstr(10,48,"|  ChangeQuestion: N/n  |");
    mvaddstr(11,48,"|  CheckAns:   F/f      |");
    mvaddstr(12,48,"|  SaveGame:   S/s      |");
    mvaddstr(13,48,"|  LoadGame:   L/l      |");
    mvaddstr(14,48,"|  Quit:       Z/z      |");
    mvaddstr(15,49, "-----------------------" );

    mvaddstr(16,49, "-----------------------" );
    mvaddstr(17,48,"|                       |");
    mvaddstr(18,48,"|    Situation:         |");
    mvaddstr(19,48,"|                       |");
    mvaddstr(20,49, "-----------------------" );


    i=Hs+1;
    {
        mvaddstr(Hs, Ws," -----------------------------------");
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
        mvaddstr(i, Ws, "|   |   |   |   |   |   |   |   |   |");i++;
        mvaddstr(i, Ws, " -----------------------------------");i++;
    }
    i=Hs+1;
    {
        attron(colorattr(1));
        mvaddstr(Hs, Ws,"*-----------*-----------*-----------*");
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i+=2;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i+=2;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i++;
        mvaddstr(i, Ws, "*-----------*-----------*-----------*");i++;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i+=2;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i+=2;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i++;
        mvaddstr(i, Ws, "*-----------*-----------*-----------*");i++;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i+=2;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i+=2;
        mvaddstr(i, Ws, "|");mvaddstr(i, Ws+12, "|");mvaddstr(i, Ws+24, "|");mvaddstr(i, Ws+36, "|");i++;
        mvaddstr(i, Ws, "*-----------*-----------*-----------*");
        attroff(colorattr(1));
    }



	i=Hs+1;
    for( i=0; i < 9 ; i++ )
    {
       for( j=0 ; j < 9 ; j++ )
       {
			if( sukodu[i][j] > 0 && ban[i][j]== 1 )
			{
			    attron(colorattr(2));
            	mvprintw( (i*2)+Hs+1 , (j*4)+Ws+2 , "%d" , sukodu[i][j]);
            	attroff(colorattr(2));
         	}
         	else if( sukodu[i][j] > 0 && ban[i][j] == 0 )
         	{
         	    mvprintw( (i*2)+Hs+1 , (j*4)+Ws+2 , "%d" , sukodu[i][j]);
         	}

       }
    } //end of ncurses demostration

}//end of displayMap

int Make_map::BanSpace()
{
    for( i=0 ; i<9 ; i++ )
    {
        for( j=0 ; j<9 ; j++ )
        {
            if( sukodu[i][j] > 0 )
            {
                ban[i][j] = 1;
            }
        }
    }
}

void Make_map::getAns( int ans , int y , int x )
{

    if( ban[x][y] == 0 )
    {
        switch(ans)
        {
            case 1 : printw("1"); sukodu[x][y] = ans; break;
            case 2 : printw("2"); sukodu[x][y] = ans; break;
            case 3 : printw("3"); sukodu[x][y] = ans; break;
            case 4 : printw("4"); sukodu[x][y] = ans; break;
            case 5 : printw("5"); sukodu[x][y] = ans; break;
            case 6 : printw("6"); sukodu[x][y] = ans; break;
            case 7 : printw("7"); sukodu[x][y] = ans; break;
            case 8 : printw("8"); sukodu[x][y] = ans; break;
            case 9 : printw("9"); sukodu[x][y] = ans; break;
            case 0 : printw(" "); break;
            default: ;
        }
    }
}

void Make_map::initialize()
{
   for( i=0 ; i<9 ; i++ )
   	  randLine[i] = 0;

  count = 0;
  count2 = 0;
  countBlock = 0;
  k=0;
  WRONGANS=0;


    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
			sukodu[i][j] = 0 ;
			ban[i][j] = 0;
		}
	}

}

void Make_map::CheckAns()
{
    /*FILE *fp;
    fp = fopen("PlayerAns.txt","w");
    for( i=0 ; i<9 ; i++ )
    {
    	for( j=0 ; j<9 ; j++ )
    	{
    	    fprintf(fp,"%d ",sukodu[i][j]);
    	}
    	fprintf(fp,"\n");
    }*/

    //big square
    WRONGANS = FALSE;
    for( k=1 ; k<10 ; k++ )
        ans[k] = 0;

    for( I=0 ; I<9 ; I+=3 )
    {
        for( J=0 ; J<9 ; J+=3 )
        {
            //small square
            for( i=0 ; i<3 ; i++ )
            {
                for( j=0 ; j<3 ; j++ )
                {
                    for( k=1 ; k<10 ; k++ )
                    {
                        if( sukodu[I+i][J+j]== k )
                            ans[k]++;
                    }
                }
            }
            for( k=1 ; k<10 ; k++ )
            {
                if( ans[k] != 1 )
                {
                    WRONGANS = TRUE;
                }
            }

            for( k=1 ; k<10 ; k++ )
                ans[k] = 0;

        }//end of bigsquare J
    }//end of bigsquare I

    //row
    for( i=0 ; i<9 ; i++ )
    {
        for( j=0 ; j<9 ; j++ )
        {
            for( k=1 ; k<10 ; k++ )
            {
                if( sukodu[i][j] == k )
                {
                    ans[k]++;
                }
            }
        }//every row scan

        for( k=1 ; k<10 ; k++ )
        {
            if( ans[k] != 1 )
            {
                WRONGANS = TRUE;
            }
        }
        for( k=1 ; k<10 ; k++ )
                ans[k] = 0;
    }//run row

    //col
    for( j=0 ; j<9 ; j++ )
    {
        for( i=0 ; i<9 ; i++ )
        {
            for( k=1 ; k<10 ; k++ )
            {
                if( sukodu[i][j] == k )
                {
                    ans[k]++;
                }
            }
        }//every col scan

        for( k=1 ; k<10 ; k++ )
        {
            if( ans[k] != 1 )
            {
                WRONGANS = TRUE;
            }
        }
        for( k=1 ; k<10 ; k++ )
                ans[k] = 0;
    }//run col

    if( WRONGANS == TRUE )
    {
        mvaddstr(18, 66, "WA");
        WRONGANS = 0;
    }
    else
    {
        mvaddstr(18, 66, "AC");
        for( i=0 ; i<3 ; i++ )
        {
            mvaddstr(8 , V, "                            " );
            mvaddstr(9 , V, "                            " );
            mvaddstr(10, V, "     Congratulations !!     " );
            mvaddstr(11, V, "                            " );
            mvaddstr(12, V, "                            " );
            mvaddstr(13, V, "                            " );
            refresh();
            sleep(1);
            mvaddstr(8 , V, "                            " );
            mvaddstr(9 , V, "                            " );
            mvaddstr(10, V, "                            " );
            mvaddstr(11, V, "                            " );
            mvaddstr(12, V, "                            " );
            mvaddstr(13, V, "                            " );
            refresh();
            sleep(1);
        }

        mvaddstr(8 , V, "                            " );
        mvaddstr(9 , V, "                            " );
        mvaddstr(10, V, "     Congratulations !!     " );
        mvaddstr(11, V, "                            " );
        mvaddstr(12, V, "                            " );
        mvaddstr(13, V, "                            " );
        refresh();
        sleep(2);
        mvaddstr(8 , V, "                            " );
        mvaddstr(9 , V, "     Congratulations !!     " );
        mvaddstr(10, V, "       New  Game(N/n)       " );
        mvaddstr(11, V, "       Load Game(L/l)       " );
        mvaddstr(12, V, "         Quit (Z/z)         " );
        mvaddstr(13, V, "                            " );
    }

}

void Make_map::Save()
{
    FILE *fp;
    fp = fopen("m.txt","w");
    for( i=0 ; i<9 ; i++ )
    {
        for( j=0 ; j<9 ; j++ )
        {

				fprintf(fp,"%d ",sukodu[i][j] );
			
        }
        fprintf(fp,"\n");
        
    }
    for( i=0 ; i<9 ; i++ )
    {
        for( j=0 ; j<9 ; j++ )
        {
            fprintf(fp,"%d ",ban[i][j] );
        }
        fprintf(fp,"\n");
    }
    fclose(fp);

}

void Make_map::Load()
{
    FILE *fp;
    fp = fopen("m.txt","r");
    for( i=0 ; i<9 ; i++ )
    {
        for( j=0 ; j<9 ; j++ )
        {
            fscanf(fp,"%d ",&sukodu[i][j] );
        }
        fscanf(fp,"\n");
    }
    for( i=0 ; i<9 ; i++ )
    {
        for( j=0 ; j<9 ; j++ )
        {
            fscanf(fp,"%d ",&ban[i][j] );
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
}

int Make_map::colorattr(int color_id)
{
    int attr;
    if( !has_colors() )
    {
        attr = A_UNDERLINE;
    }
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    switch(color_id)
    {
        case 1:
                attr = COLOR_PAIR(1);
                break;
        case 2:
                attr = COLOR_PAIR(2);
                break;
        case 3:
                attr = COLOR_PAIR(3);
                break;
        case 4:
                attr = COLOR_PAIR(4);
                break;
        case 5:
                attr = COLOR_PAIR(5);
                break;
        case 6:
                attr = COLOR_PAIR(6);
                break;
        case 7:
                attr = COLOR_PAIR(7);
                break;
        default:
                attr = A_NORMAL;
	}
    return(attr);
}


