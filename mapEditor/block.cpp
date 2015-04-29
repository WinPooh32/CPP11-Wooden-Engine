#include"block.h"
#include<QLabel>
#include<QPixmap>
#include<QWidget>
#include<QMouseEvent>

Block::Block(bool tile_flag,QWidget* parent)
	:QLabel(parent)
{
	tile_flag_=tile_flag;
	ok_flag_=false;
	mark_flag_=false;
	number_=-1;
	setPixmap(QPixmap(":/images/normal.png"));
}

void Block::setNumber(int number)
{
	number_=number;
}

bool Block::isMine()const
{
	return tile_flag_;
}

void Block::mousePressEvent(QMouseEvent* event)
{
	if(event->button()==Qt::LeftButton){
		if(ok_flag_==false&&mark_flag_==false){
			ok_flag_=true;
			if(tile_flag_==true){
				setPixmap(QPixmap(":/images/tile.png"));
				update();
				emit two();
			}else{
				setPixmap(QPixmap(":/images/tile_"+QString("%1").arg(number_)+".png"));
				update();
				emit one();
			}
		}
	}else if(event->button()==Qt::RightButton){
		if(ok_flag_==false){
			if(mark_flag_==false){
				mark_flag_=true;
				setPixmap(QPixmap(":/images/flag.png"));
			}else{
				mark_flag_=false;
				setPixmap(QPixmap(":/images/normal.png"));
			}
			update();
		}	
	}
}

