    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
 
//save

void save(tile&map,int &map, int &flag,)
{
  int location[17];
  int num;
  char output;
 ofstream outfile("savedate");//created txt

for(int i=0;i<=16;i++)
  {
   
    outfile <<location[i].getType//two number for type
            <<“ ”；

  }

outfile<<location[17]<<map.lv<<" "<< endl;

 flag=1;//1 means has something,0 mean nothing
 return;
}
//load
void load(tile&map,int &map)
{
 ifstream infile;
 infile.open("savedate");
 int num;
 int d[17];
 int location[17];
 char p;
   for(int i=0;i<=16;i++)
  {
   do
   {
    infile.get(p);
   }
   while(isspace((int)p)&&!infile.eof());//eof(make surethere is a file),isspace for check white space
   infile.putback(p);
   infile>>num;
   location[i]=num;
   location[i].type =d[i];
  }
 map.lv=d[17];
 
 infile.close();//close file
 
}