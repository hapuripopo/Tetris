#pragma once
#include "main.h"

//블럭 생성 위치
#define CREATE_X 20
#define CREATE_Y 5

//테트리스 블럭
class Block
{
private:
	int _name;			//블럭 이름
	int _x;				//x좌표
	int _y;				//y좌표
	int _shape[4][2];	//블럭 모양 좌표
	int _rotate;		//블럭 회전 수

public:
	const static int SHAPE[7][4][4][2];

public:
	Block(int, int);
	void operator=(const Block&);
	int GetBlock_x(void);
	int GetBlock_y(void);
	void PrintBlock() const;
	void PrintNextBlock() const;
	void DeleteBlock() const;
	void ShiftBlock(int, int);
	void DownBottom();
	void RotateBlock();
	bool FixBlock();		//fix -> true , down -> false
};
