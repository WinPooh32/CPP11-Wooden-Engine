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
					if ( i == 0 && j < 16)

							{
							cout<<setw(2)<<setfill('-')<<j<<" ";	
							}
						
							else if(i <12&& j==0 )
							{
							cout<<setw(2)<<setfill('-')<< i <<" ";
							}	
						else
							{	
								array1[i][j]==0;
								array1[i][j]=num;
								cout <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
							}			
					}
				cout<<endl;
			}


	while(edMode ==true)
	{
		for(int i=0; i < 13 ;i++)
		{
		  for(int j=0;j < 17 ;j++)
			    {
				if ( i == 0 && j < 16)

						{
						cout<<setw(2)<<setfill('-')<<j<<" ";	
						}
					
						else if(i <12&& j==0 )
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

	cout<<"put the x of the one you want to change"<<endl;
	cin>>x;
	cout<<"put the y of the one you want to change"<<endl;
        cin>>y;
	cout<<"put the number you want to put"<<endl;
        cin>>output;
	array1[x][y]=output;
	cout<<x<<y<<output<<endl;

	}
}




// void save()
// {
// 	int num2;
// int array2[16][12];
// ofstream out;
// out.open("savedate.txt");
// for(int i=0; i < 12 ;i++)
// 	{
// 	  for(int j=0;j< 16 ;j++)
// 	    {
			
			
// 			array2[i][j]=num2;
// 			 out <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
			
// 		}
// 		out<<endl;
// 	}
// 	out.close();
// }


	

