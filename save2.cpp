    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
	 using namespace std;
	//save
	 #undef main

int num;
int array1[16][12];

int main()
{
ofstream out;
out.open("savedate.txt");
for(int i=0; i < 12 ;i++)
	{
	  for(int j=0;j< 16 ;j++)
	    {
			
			
			array1[i][j]=num;
			 out <<setw(2)<<setfill('0')<<array1[i][j] << " " ;
			
		}
		out<<endl;
	}
	out.close();
}

