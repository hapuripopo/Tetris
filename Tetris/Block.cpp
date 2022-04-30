#include "Block.h"

//블럭 모양
const int Block::SHAPE[7][4][4][2] = {
	//I
	{ { {0, -1}, {0, 0}, {0, 1}, {0, 2} },
	{ {-2, 0}, {-1, 0}, {0, 0}, {1, 0} },
	{ {0, -1}, {0, 0}, {0, 1}, {0, 2} },
	{ {-2, 0}, {-1, 0}, {0, 0}, {1, 0} } },
	//L
	{ { {0, -1}, {0, 0}, {0, 1}, {1, 1} },
	{ {-1, 0}, {0, 0}, {1, 0}, {-1, 1} },
	{ {-1, -1}, {0, -1}, {0, 0}, {0, 1} },
	{ {1, -1}, {-1, 0}, {0, 0}, {1, 0} } },
	//RL
	{ { {0, -1}, {0, 0}, {-1, 1}, {0, 1} },
	{ {-1, -1}, {-1, 0}, {0, 0}, {1, 0} },
	{ {0, -1}, {1, -1}, {0, 0}, {0, 1} },
	{ {-1, 0}, {0, 0}, {1, 0}, {1, 1} } },
	//T
	{ { {0, -1}, {-1, 0}, {0, 0}, {0, 1} },
	{ {0, -1}, {-1, 0}, {0, 0}, {1, 0} },
	{ {0, -1}, {0, 0}, {1, 0}, {0, 1} },
	{ {-1, 0}, {0, 0}, {1, 0}, {0, 1} } },
	//O
	{ { {0, 0}, {1, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, },
	//S
	{ { {0, 0}, {1, 0}, {-1, 1}, {0, 1} },
	{ {-1, -1}, {-1, 0}, {0, 0}, {0, 1} },
	{ {0, 0}, {1, 0}, {-1, 1}, {0, 1} },
	{ {-1, -1}, {-1, 0}, {0, 0}, {0, 1} } },
	//RS
	{ { {-1, 0}, {0, 0}, {0, 1}, {1, 1} },
	{ {0, -1}, {-1, 0}, {0, 0}, {-1, 1} },
	{ {-1, 0}, {0, 0}, {0, 1}, {1, 1} },
	{ {0, -1}, {-1, 0}, {0, 0}, {-1, 1} } }
};

//_x getter
int Block::GetBlock_x(void)
{
	return _x;
}

//_y getter
int Block::GetBlock_y(void)
{
	return _y;
}

//Block 클래스 생성자
Block::Block(int name, int rotate)//블럭 종류, 회전 수
	:_name(name), _rotate(rotate)
{
	_x = CREATE_X;				//생성위치 결정
	_y = CREATE_Y;
	for (int i = 0; i < 4; i++)	//모양 결정
	{
		for (int j = 0; j < 2; j++)
		{
			_shape[i][j] = SHAPE[name][rotate][i][j];
		}
	}
}

void Block::operator=(const Block &ref)
{
	_name = ref._name;

	_x = CREATE_X;
	_y = CREATE_Y;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			_shape[i][j] = ref._shape[i][j];
	}

	_rotate = ref._rotate;
}

//블럭 출력
void Block::PrintBlock() const
{
	for (int i = 0; i < 4; i++)
	{
		Cursor(_x + (_shape[i][0] * 2), _y + _shape[i][1]);
		cout << "□";
	}
}

//다음 블럭 출력
void Block::PrintNextBlock() const
{
	for (int i = 0; i < 4; i++)
	{
		Cursor(GameTable::X + 32 + (_shape[i][0] * 2), GameTable::Y + 3 + _shape[i][1]);
		cout << "□";
	}
}

//블럭 삭제
void Block::DeleteBlock() const
{
	for (int i = 0; i < 4; i++)
	{
		Cursor(_x + (_shape[i][0] * 2), _y + _shape[i][1]);
		cout << "  ";
	}
}

//x, y 만큼 이동
void Block::ShiftBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (GameTable::IsBlock(_x + (_shape[i][0] * 2) + x, _y + _shape[i][1] + y)	//이동할 위치에 블럭이 있으면 취소
			|| !GameTable::IsInTable_X(_x + (_shape[i][0] * 2) + x))				//테이블 가로 범위를 넘으면 취소
			return;
	}

	DeleteBlock();	//원래위치의 블럭 삭제
	_x += x;		//좌표이동
	_y += y;
	PrintBlock();		//이동한 위치 블럭 출력
}

//블럭 하강
void Block::DownBottom()
{
	while (!FixBlock())
	{
		ShiftBlock(0, 1);
	}
}

//블럭 회전
void Block::RotateBlock()
{
	int temp_shape[4][2];		//회전 될 모양

	for (int i = 0; i < 4; i++)	//모양 임시회전
	{
		for (int j = 0; j < 2; j++)
		{
			temp_shape[i][j] = SHAPE[_name][(_rotate + 1) % 4][i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (GameTable::IsBlock(_x + (temp_shape[i][0] * 2), _y + temp_shape[i][1])	//회전할 위치에 블럭이 있으면 취소
			||!GameTable::IsInTable_X(_x + (temp_shape[i][0] * 2)))					//회전할 위치가 가로범위를 넘으면 취소
			return;
	}

	DeleteBlock();

	for (int i = 0; i < 4; i++)	//모양 회전
	{
		for (int j = 0; j < 2; j++)
		{
			_shape[i][j] = temp_shape[i][j];
		}
	}
	_rotate = (_rotate + 1) % 4;

	PrintBlock();
}

//블럭 쌓기
bool Block::FixBlock()
{
	for (int i = 0; i < 4; i++)	//바닥에 닿았는지 확인
	{
		if (GameTable::IsBlock(_x + (_shape[i][0] * 2), _y + _shape[i][1] + 1))
		{
			for (int j = 0; j < 4; j++)	//블럭 상태 변경
			{
				GameTable::Box[_y + _shape[j][1] - GameTable::Y + 2][(_x + (_shape[j][0] * 2) - GameTable::X) / 2] = FIX;
			}
			return true;
		}
	}
	return false;
}
