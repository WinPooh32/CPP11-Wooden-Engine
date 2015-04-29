#ifndef BLOKC_H_
#define BLOCK_H_

#include<QLabel>
class QWidget;
class QMouseEvent;

class Block:public QLabel
{
	Q_OBJECT

public:
	explicit Block(bool tile_flag,QWidget* parent=0);

	void setNumber(int number);

	bool isMine()const;

signals:
	void Two();
	void One();

protected:
	void mousePressEvent(QMouseEvent* event);

private:
	bool tile_flag_;
	bool ok_flag_;
	bool mark_flag_;
	int number_;
};

#endif
