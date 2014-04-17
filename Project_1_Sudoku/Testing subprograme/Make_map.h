using namespace std;

class Make_map
{
public:
    //constructor initializes variables
    Make_map();
    
    void setMap();
    int	RandCheck( int*, int, int );
    void displayMap();
    int transmit();
    
private:
	int i, j, count2, k;
    int countBlock, selI, selJ;
    int randLine[9], randSquare[3][3], sukodu[9][9], Tsukodu[81], count, temp;
    
    void initialize();
};    
    
    

