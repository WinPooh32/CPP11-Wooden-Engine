#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

//#include <string>

using namespace std; 

	
int main()
{
	ifstream myFile("chaaou.txt");
	int mygrid[16][12]; 
	int i = 0;
	int j = 0;
	
				while(myFile >> mygrid[i][j])
				{
					cout << std::setw(2) << std::setfill('0') << mygrid[i][j] << " " ;
					
					if(i == 15 && j == 15)
					{
						return 0;
					}
					else if(j == 15)
					{
						j=0;
						i++;
						cout<<endl;
					}
					else if(j != 15)
					{
						j++;
					}
				}
		
	return 0;
}
	
