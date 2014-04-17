#ifndef MakeMap_H
#define MakeMap_H
class Make_map
{
public:
    //constructor initializes variables
    Make_map();

    void setMap();
    int	RandCheck( int*, int, int );
    void displayMap();
    int BanSpace();
    void getAns(int, int, int);
    void initialize();
    void CheckAns();
    void Save();
    void Load();

private:
	int i, j, count2, k, I, J;
    int countBlock, selI, selJ;
    int randLine[9], randSquare[3][3], sukodu[9][9], count, temp, ban[9][9];
    int ans[10],WRONGANS;

    int colorattr(int);

};
#endif


