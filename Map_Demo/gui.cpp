    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
	#include <iomanip> 
	 using namespace std;
	//save
	 #undef main

int num;
int x;
int y;
int choose;
int output;
int array1[16][12];
bool edMode =true;
int main()
{
	

	for(int i=0; i < 13 ;i++)
	{
		for(int j=0;j < 17 ;j++)
		{
			num==0;
			array1[i][j]=num;			
		}	
	}


	while(edMode ==true)
	{
		for(int i=0; i < 13 ;i++)
		{
			for(int j=0;j < 17 ;j++)
			{
				if ( i == 0 && j < 17)
				{
					cout<<setw(2)<<setfill('-')<<j<<" ";	
				}
					
				else if(i <13&& j==0 )
				{
					cout<<setw(2)<<setfill('-')<< i <<" ";
				}	
				else
				{	
							
					cout <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
				}			
			}

			cout<<endl;
		}

		cout<<"Close|100| Save|101| Load|102|"<< endl <<"Type number of the row of the tile you want to change:";
		cin>>x;

		if(x == 100)
		{
			edMode == true; 
			return 0;
		}
		if(x == 101)
		{
			ofstream out;
			out.open("savedate.txt");
			for(int i=1; i < 13 ;i++)
			{
				for(int j=1;j< 17 ;j++)
	   			 {
					
					out<<setw(2)<<setfill('0')<<array1[i][j]<<" ";
			
				 }
				out<<endl;
			       	
			}
			out.close();
			cout<<"File saved."<<endl;
			cout<<endl;
		}
		if(x == 102)
		{
			ifstream myFile("chaaou.txt");
			int i = 1;
			int j = 1;
	
				while(myFile >> array1[i][j])
				{	
					if(i == 16 && j == 12)
					{
						return 0;
					}
					else if(j == 12)
					{
						j=0;
						i++;
						//cout<<endl;
					}
					else if(j != 12)
					{
						j++;
					}
				}
		
		}
	
		if(x < 100)
		{
			cout<<"Type the number of the column of the tile you want to change:"<<endl;
        		cin>>y;
			cout<<"Type the number of the tile you want to select:"<<endl;
        		cin>>output;
			array1[x][y]=output;
		}

	}
}
