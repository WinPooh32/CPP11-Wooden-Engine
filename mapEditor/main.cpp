#include"block_area.h"
#include<QApplication>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	BlockArea area;
	area.show();
	return app.exec();
}
