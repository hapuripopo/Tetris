#include "GameTable.h"

int GameTable::X = 8;
int GameTable::Y = 6;

const int GameTable::CBOX[TABLE_HEIGHT + 2][TABLE_WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int GameTable::Box[TABLE_HEIGHT + 2][TABLE_WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int GameTable::NextBox[7][7] = {
	{1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1},
};

int GameTable::Score = 0;

int GameTable::Speed = 800;	//초기 블럭 하강 속도

void GameTable::ResetBox()
{
	for (int i = 0; i < TABLE_HEIGHT + 2; i++)		//테이블 초기화
	{
		for (int j = 0; j < TABLE_WIDTH; j++)
		{
			Box[i][j] = CBOX[i][j];
		}
	}
	Score = 0;	//점수 초기화
	Speed = 800;	//속도 초기화
}

//테트리스 박스 출력
void GameTable::PrintBox()
{
	for (int i = 0; i < TABLE_HEIGHT + 2; i++)
	{
		Cursor(X, Y + i - 2);
		for (int j = 0; j < TABLE_WIDTH; j++)
		{
			if (Box[i][j] == LINE)
				cout << "▩";
			else if (Box[i][j] == OVER)
				cout << "__";
			else if (Box[i][j] == EMPTY)
				cout << "  ";
			else if (Box[i][j] == FIX)
				cout << "■";
		}
	}
}

//다음 블럭을 보여주는 박스 출력
void GameTable::PrintNextBox()
{
	Cursor(X + 26, Y - 1);
	cout << "NEXT..";
	for (int i = 0; i < 7; i++)
	{
		Cursor(X + 26, Y + i);
		for (int j = 0; j < 7; j++)
		{
			if (NextBox[i][j] == 1)
				cout << "▩";
			else
				cout << "  ";
		}
	}
}

//x, y좌표에 블럭이 있는지 확인
bool GameTable::IsBlock(int x, int y)
{
	if (Box[y - Y + 2][(x - X)/2] == LINE || Box[y - Y + 2][(x - X)/2] == FIX)
		return true;
	return false;
}

//해당 x좌표가 테이블 범위인지 확인
bool GameTable::IsInTable_X(int x)
{
	if (X < x && x < X + (TABLE_WIDTH - 2) * 2 + 2)
		return true;
	return false;
}

//해당 라인이 완성됐는지 확인
bool GameTable::CheckLine(int line)
{
	for (int i = 1; i < TABLE_WIDTH - 1; i++)
	{
		if (Box[line][i] != FIX)			//라인이 완성되지 않음, false반환
			return false;
	}
	return true;
}

//한 줄 완성시 라인 삭제
bool GameTable::DeleteLine()
{
	for (int i = TABLE_HEIGHT + 1; i > 2; i--)
	{
		if (CheckLine(i))	//한 줄 완성했는지 확인 (밑에서부터)
		{
			for (int j = 1; j < TABLE_WIDTH - 1; j++)//블럭 삭제하기
			{
				Box[i][j] = EMPTY;
			}

			PrintBox();		//블럭 삭제 보여주기
			Sleep(100);

			for (int j = i; j > 2; j--)	//블럭 당기기, 바닥 초기화하기
			{
				for (int k = 1; k < TABLE_WIDTH - 1; k++)
				{
					if (j == 3)
						Box[j][k] = OVER;
					else if (j == 4)
						Box[j][k] = EMPTY;
					else
						Box[j][k] = Box[j - 1][k];
				}
			}
			Score += 1000;	//삭제 시 기본점수
			return true;
		}
	}
	return false; 
}

//스코어 출력
void GameTable::PrintScore()
{
	Cursor(X + 26, 20);
	cout << "Best Score : " << GetBest();
	Cursor(X + 26, 22);
	cout << "Your Score : " << Score;
}

//라인을 넘었는지 확인
bool GameTable::IsOver()
{
	for (int i = 1; i < TABLE_WIDTH - 1; i++)
	{
		if (Box[3][i] == FIX)
			return true;
	}
	return false;
}

//라인 오버시 게임종료, 최고점수저장, 초기화
void GameTable::GameOver()
{
	system("cls");
	int x = 15;
	int y = 11;
	if (GetBest() >= Score)
	{
		Cursor(x, y); cout << "▨▨▨   ..GAME OVER..  ▨▨▨";
		Cursor(x + 10, y + 2); cout << Score << " 점";
		Cursor(x, y + 4); cout << "▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨";
	}
	else	//최고점수보다 높으면 저장
	{
		Cursor(x, y); cout << "▨▨▨  ☆BEST SCORE☆  ▨▨▨";
		Cursor(x + 10, y + 2); cout << Score << " 점";
		Cursor(x, y + 4); cout << "▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨";
		SetBest(Score);
	}

	Cursor(x + 2, 20);  cout << "나가려면 ESC를 누르세요...";
	ResetBox();	//게임 초기화
	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}

//블럭 하강속도 설정
void GameTable::SetSpeed()
{
	if (Score > 100000)
		Speed = 200;
	else if (Score > 50000)
		Speed = 400;
	else if (Score > 10000)
		Speed = 600;
	else
		Speed = 800;
}

int GameTable::GetBest()
{
	ifstream is("BestScore.txt");	//파일 읽어오기
	static int best;

	if (is.is_open())
	{
		is >> best;
	}
	else
	{
		ofstream os("BestScore.txt");//파일이 없으면 만들기
		os << 0;
		best = 0;
		os.close();
	}

	is.close();
	return best;
}

void GameTable::SetBest(int score)
{
	ofstream os("BestScore.txt");
	os << score;
	os.close();
}
