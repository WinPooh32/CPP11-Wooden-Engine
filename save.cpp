    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
 
//save

void save(tile&map,int &map, int &flag,)
{
  int location[11][15];
  int num;
  char output;
 ofstream outfile("test");//created txt

for(int j=0;j <=11;j++)
{
  
  for(int i=0;i<=14;i++)
    {
     
      outfile <<location[j][i].getType//two number for type
              <<“ ”；

    }
    outfile << endl;

}

//outfile<<location[17]<<map.lv<<" "<< endl;

 flag=1;//1 means has something,0 mean nothing
 return;
}
//load
void load(tile&map,int &map)
{
 ifstream infile;
 infile.open("test");
 int num;
 int d[11][15];
 char p;
 for (int j=0;j<11;j++)
 {
   for(int i=0;i<=15;i++)
 
  {
   do
   {
    infile.get(p);
   }
   while(isspace((int)p)&&!infile.eof());//eof(make surethere is a file),isspace for check white space
   infile.putback(p);
   infile>>num;
   location[i][j]=num;
   //location[i][j].type =d[i];
  }

 //map.lv=d[17];
}
 
 infile.close();//close file
 
}