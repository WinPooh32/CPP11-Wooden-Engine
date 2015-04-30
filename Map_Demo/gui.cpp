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
int array1[13][17];
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
				
				if(i ==0 && j<17)
				{
					cout<<setw(2)<<setfill('-')<<j<<" ";
				}
				else if(j ==0 && i <17)        
                                {
                                        cout<<setw(2)<<setfill('-')<<i<<" ";
                                }

				else
				{					
					cout <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
				}							
			}

			cout<<endl;
		}

		cout<<"Close|100| Save|101| Load|102|"<< endl;
		 cout<<"Type the number of row you want to edit:"<<endl;
                 cin>>x;
		if(x == 100)
		{
			edMode == true; 
			return 0;
		}
		if(x == 101)
		{
			ofstream out;
			out.open("test.txt");
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
			ifstream in;
			in.open("test.txt");
		
	
			for(int i=1; 1 < 13; i++)
			{
				for(int j=1; j < 17;j++)
				{
					in >> array1[i][j];
				}
			}		
	


			in.close();	


		//	while(myFile >> array1[i][j])
		//		{	
		//		
		//			if (j < 16 && i <13)
		//			{
		//				j++;
		//			}
		///			if(j == 16 && i < 12 )
		///			{
		///				j=1;
		///				i++;
		///			}			
				

		//			 if( j==16 && i==12)
		//			{
		//				return 0;
		//			}

				
		//		}
		
		}
	
		if(x < 100)
		{
			cout<<"Type the number of col you want to edit:"<<endl;
                        cin>>y;
			cout<<"Type the number of the tile you want to select:"<<endl;
			cout<<"Colors -> Red: 00 Green: 01 Blue: 02"<<endl;
			cout<<"Wall -> Center: 03 Top: 04 TopRight: 05 Right: 06 BottomRight: 07 Bottom: 08 BottomLeft: 09 Left: 10 TopLeft: 11"<<endl;
        		cin>>output;
			array1[x][y]=output;
		}

	}
}
