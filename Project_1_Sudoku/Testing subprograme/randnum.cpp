#include <ncurses/curses.h>
#include <ctime>
#include <unistd.h> 
#include <iostream>
#define TRUE 1
#define FALES 0
#define Ws 6 
#define Hs 2
using namespace std;

int	RandCheck(int *randLine, int temp, int count);
int main()
{
   int height, width;
   int i, j, count2=0;
   int countBlock=0, selI, selJ;
   int randLine[9], randSquare[3][3], sukodu[9][9]={0}, count=0, temp;
   initscr();
   cbreak(); // disable key buffering
   noecho(); // disable echoing
   keypad(stdscr, TRUE); // enable keypad reading
   getmaxyx(stdscr, height, width); // get screen size
   mvaddstr(0, 0, "Pressed Key: ");   
   srand(time(0));
   mvaddstr(Hs, Ws," -----------------------------------"); 
   for( i=Hs+1 ; i <= Hs+17 ; i=i+2 )
   {
	 	mvaddstr(i, Ws,"|   |   |   |   |   |   |   |   |   |");
	 	mvaddstr(i+1, Ws," -----------------------------------"); 
   }
   
   for( i=0 ; i<9 ; i++ )
   	  randLine[i] = 0;
   	  
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

	//ncurses demostrate  
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

   getch();
   endwin();
   return 0;  	  
}  
int	RandCheck(int *randLine, int temp, int count)
{
    int i;
    for( i=0 ; i<count ; i++ )
    {
        if( randLine[i] == temp )
        	return FALES; 
    } 
    return TRUE;       
}  

                  
//demostrate in DEV  
/*  for( i=0 ; i<9 ; i++ )
   {
       for( j=0 ; j<9 ; j++ )
       {
           cout<< sukodu[i][j] << " ";
           if( j==2 || j==5 )
           cout << " ";
       }
       cout <<endl;
       if( i==2 || i==5 )
       		cout << endl;
   } */    


