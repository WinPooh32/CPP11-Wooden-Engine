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
							//cout<<setw(2)<<setfill('-')<<j<<" ";	
							}
						
							else if(i <12&& j==0 )
							{
							//cout<<setw(2)<<setfill('-')<< i <<" ";
							}	
						else
							{	
								array1[i][j]==0;
								array1[i][j]=num;
								//cout <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
							}			
					}
				//cout<<endl;
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

	cout<<"Close|100| Save|101| Load|102|"<< endl <<"Put the y of the box you want to change:";
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
			
			num==00;
			array1[i][j]=num;
			//out <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
			
		}
		out<< "File Saved.";
	}
	out.close();
	}
	if(x == 102)
	{
	ifstream myFile("chaaou.txt");
	int i = 1;
	int j = 1;
	
				while(myFile >> array1[i][j])
				{
					//cout << std::setw(2) << std::setfill('0') << array1[i][j] << " " ;
					
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
	cout<<"put the x of the one you want to change"<<endl;
        cin>>y;
	cout<<"put the number you want to put"<<endl;
        cin>>output;
	array1[x][y]=output;
	cout<<x<<y<<output<<endl;
	}

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


	

