/*
To transmit an array from class to main, then print it in function.
*/
#include<iostream>
using namespace std;
class ArrayTest
{
public:
        
    int *transmit()
    {
        for( i=0 ; i<5 ; i++ )
        {
            array[i] = i;
        }     
        return array;
    }    
private:
    int array[5],i;
};
    
//int printArray( int *Array );

int main()
{
    int array[5]={},*array02,i;
	ArrayTest test01,test02;
    //array[5] = test01.transmit();
    
    array02= test02.transmit();
    //printArray( array02 );
    cout <<"array02 : ";
    for( i=0 ; i<5 ; i++ )
    {
    	cout << array02[i] << " ";
		array[i] = array02[i];
		cout << array[i] << " ";
 	}   	
 	cout << endl;
 	
 	//printArray( *array );
 	/*cout <<"array : ";
 	for( i=0 ; i<5 ; i++ )
    	cout << array[i] << " ";
	cout << endl;*/
    
    system("pause");
    return 0;
}

/*int printArray( int *Array )
{
    int i, j;
    for( i=0 ; i<5 ; i++ )
    {
        printf("%d ", Array[1][i] );
    }  
    cout << endl;  
} */   
    
     

