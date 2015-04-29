#include"block_area.h"
#include<algorithm>
#include<QMessageBox>
#include<QWidget>
#include<QGridLayout>

BlockArea::BlockArea(QWidget* parent)
	:QWidget(parent)
{
	row_=10;
	column_=10;
	total_block_number_=row_*column_;
	total_tile_number_=10;
	ok_block_number_=0;

	bool *tile_flag = new bool[total_block_number_];
	for(int i=0;i<total_tile_number_;i++)
		
		tile_flag[i]=true;

	for(int i=total_tile_number_;i<total_block_number_;i++)
		
		tile_flag[i]=false;

	std::random_shuffle(tile_flag,tile_flag+total_block_number_);

	mainLayout=new QGridLayout(this);
	
	for(int i=0;i<row_;i++)
		
		for(int j=0;j<column_;j++)
			mainLayout->addWidget(new Block(tile_flag[i*column_+j]),i,j);

	for(int i=0;i<row_;i++){
		for(int j=0;j<column_;j++){
			Block* current_block=static_cast<Block*>(mainLayout->itemAtPosition(i,j)->widget());
			
			current_block->setNumber(location(i,j));
			
			connect(current_block,SIGNAL(one()),this,SLOT(tileOne()));
			connect(current_block,SIGNAL(two()),this,SLOT(tileTwo()));
		}		
	}

	setFixedSize(sizeHint());
}

void BlockArea::tileOne()
{
	++ok_block_number_;
	if(ok_block_number_==total_block_number_-total_tile_number_)
		QMessageBox::information(this,tr("stop"),tr("You fill all the block"));
}

void BlockArea::tileTwo()
{
	QMessageBox::information(this,tr("Result"),tr("You lose"));
}
