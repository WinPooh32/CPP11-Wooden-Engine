#ifndef BLOCK_AREA_H_
#define BLOCK_AREA_H_

#include"block.h"
#include<QWidget>
class QGridLayout;

class BlockArea:public QWidget
{
	Q_OBJECT
public:
	BlockArea(QWidget* parent=0);
private slots:
	void tileOne();
	void tileTwe();
private:
	int type(int x,int y)const;		//计算以x,y为中心的九宫格内的雷数
private:
	QGridLayout* mainLayout;
	int row_;
	int column_;
	int total_block_number_;
	int total_tile_number_;
	int ok_block_number_;
};

#endif
