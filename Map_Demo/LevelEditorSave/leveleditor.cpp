#include <iostream>
#include <fstream>
#include <sstream>
//#include <string>

using namespace std; 

	
int main()
{
	ifstream myFile("chaaou.txt");
	int mygrid[16][12]; 
	int i = 0;
	int j = 0;
	
				while(myFile >> mygrid[16][12])
				{
					cout << mygrid[i][j] << "\n";
					
					if(i == 15 && j == 15)
					{
						return 0;
					}
					else if(j == 15)
					{
						j=0;
						i++;
					}
					else if(j != 15)
					{
						j++;
					}
				}
		
	return 0;
}
	
