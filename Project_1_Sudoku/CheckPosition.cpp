#include "CheckPosition.h"
#define Ws 6
#define Hs 2
using namespace std;
CheckPosition::CheckPosition()
{
}
void CheckPosition::CheckPositionX( int &x, int &X )
{
    if( x >= Ws+2+(4*9) )//RIGHT
    {
        x = x-(4*9);
        X=X-9;
    }
    else if( x < Ws+2 ) //LEFT
    {
        x = x+(4*9);// X side check
        X=X+9;
    }
}
void CheckPosition::CheckPositionY( int &y, int &Y )
{
	if( y >= Hs+1+(2*9) ) //DOWN
	{
	    y = y-(2*9);
	    Y=Y-9;
	}
	else if( y < Hs+1 )	//UP
	{
	    y = y+(2*9); // Y side check
	    Y=Y+9;
	}
}
