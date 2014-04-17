#include "Make_Map.h"
#include <ncurses/curses.h>
#include <ctime>
#include <unistd.h> 
#include <iostream>
#define TRUE 1
#define FALES 0
#define Ws 6 
#define Hs 2
using namespace std;
    
Make_map::Make_map()
{
    initialize();
    setMap();
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
    //ncurses demostrate
    mvaddstr(Hs, Ws," -----------------------------------"); 
    for( i=Hs+1 ; i <= Hs+17 ; i=i+2 )
    {
	 	mvaddstr(i, Ws,"|   |   |   |   |   |   |   |   |   |");
	 	mvaddstr(i+1, Ws," -----------------------------------"); 
	}
 		  
	i=Hs+1;
    for( i=0; i < 9 ; i++ )
    {
       for( j=0 ; j < 9 ; j++ )
       {
			if( sukodu[i][j] > 0 )
			{
            	mvprintw( (i*2)+Hs+1 , (j*4)+Ws+2 , "%d" , sukodu[i][j] );
         	}   	
       }      
    } //end of ncurses demostration  
    	        
}//end of displayMap 

int Make_map::transmit()
{
    for( i=0; i < 9 ; i++ )
    {
       for( j=0 ; j < 9 ; j++ )
       {
			Tsukodu[k] = sukodu[i][j];
   			k++; 	
       }      
    }
    return &Tsukodu;
}     
             
void Make_map::initialize()
{
   for( i=0 ; i<9 ; i++ )
   	  randLine[i] = 0;
   	  
  count = 0; 	  
  count2 = 0;
  countBlock = 0;
  k=0;
  
  for( i=0 ; i<9 ; i++ )
  {
        for( j=0 ; j<9 ; j++ )
        {
			sukodu[i][j] = 0 ;
		}
	  }    				  	
}    	  
  	  

/*int main()   
{   
    initscr();   
    Make_map Map01;
    Map01.displayMap();
    getch();
    endwin();
    return 0;  	  
}*/ 


