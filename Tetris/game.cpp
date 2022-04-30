#include "game.h"

//게임 초기설정
void Init(void)
{
	//콘솔 앱 크기
	system("mode con cols=60 lines=35 | title TETRIS");
	//커서 숨기기
	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = false;
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursor);
}

//메뉴출력 밑 이동
int Menu(void)
{
	int x = 26;		//커서 기준점
	int y = 18;

	Cursor(x - 20, 9); cout << "▨▨▨  ▨▨▨  ▨▨▨  ▨▨▨    ▨▨▨   ▨▨   ";
	Cursor(x - 20, 10); cout << "  ▨    ▨        ▨    ▨   ▨     ▨    ▨     ";
	Cursor(x - 20, 11); cout << "  ▨    ▨▨▨    ▨    ▨▨▨      ▨    ▨▨▨ ";
	Cursor(x - 20, 12); cout << "  ▨    ▨        ▨    ▨  ▨      ▨        ▨ ";
	Cursor(x - 20, 13); cout << "  ▨    ▨▨▨    ▨    ▨   ▨   ▨▨▨   ▨▨ ";

	Cursor(x - 2, y);
	cout << "> 게임시작 ";
	Cursor(x, y + 2);
	cout << "최고점수";
	Cursor(x, y + 4);
	cout << "게임조작";
	Cursor(x, y + 6);
	cout << "게임종료";

	while (true)
	{
		int sel = KeyControl(); //방향키 입력정보

		switch (sel)
		{
		case UP:
			if (y > 18) {
				Cursor(x - 2, y);
				cout << " ";
				y -= 2;		//기준점 이동
				Cursor(x - 2, y);//커서이동
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 24) {
				Cursor(x - 2, y);
				cout << " ";
				y += 2;		//기준점 이동
				Cursor(x - 2, y);//커서이동
				cout << ">";
			}
			break;
		case SPACE: case ENTER:
			return y - 18;
		default:
			break;
		}
	}
}

//게임시작
void GameStart()
{
	system("cls");
	srand((unsigned int)time(NULL));
	Block block(rand() % 7, rand() % 4);		//초기 블럭 생성
	GameTable::PrintScore();
	while (true) 
	{
		if (GameTable::IsOver())	//라인 오버시
		{
			Sleep(100);
			GameTable::GameOver();	//게임 종료
			break;
		}

		int combo = 0;
		while (GameTable::DeleteLine())			//모든 완성라인 삭제
		{
			GameTable::Score += 150 * combo;			//라인 연속삭제시 추가점수 최대 900점
			combo++;
			GameTable::PrintScore();
		}
		GameTable::SetSpeed();	//점수에 따라 블럭하강 속도 재설정

		GameTable::PrintBox();					//게임 테두리 출력
		block.PrintBlock();						//블럭 출력

		Block nextBlock(rand() % 7, rand() % 4);//다음 블럭 랜덤 생성
		GameTable::PrintNextBox();				//다음 블럭 출력
		nextBlock.PrintNextBlock();

		clock_t oldTime = clock();				//시간 측정
		while (true)
		{
			clock_t curTime = clock();
			if (_kbhit())			//키 입력이 있으면
			{
				int input = KeyControl();

				if (input == ESC)	//ESC입력시 점수입력, 테이블 초기화, 종료
				{
					Sleep(100);
					GameTable::GameOver();
					return;
				}

				if (input == SPACE)	//스페이스 바 입력시 블럭 하강
				{
					block.DownBottom();
					break;
				}

				switch (input)		//방향키 입력시 블럭이동
				{
				case LEFT:
					block.ShiftBlock(-2, 0);
					break;
				case RIGHT:
					block.ShiftBlock(2, 0);
					break;
				case DOWN:
					block.ShiftBlock(0, 1);
					break;
				case UP:
					block.RotateBlock();
					break;
				case P:
					Cursor(12, 30);
					system("pause");
					Cursor(12, 30);
					cout << "                                    ";
					break;
				default:
					break;
				}
			}

			if (curTime - oldTime > GameTable::Speed)//블럭 내려오기
			{
				if (block.FixBlock())	//블럭이 고정되면 반복문을 탈출하고 새 블럭 생성
					break;
				oldTime = curTime;
				block.ShiftBlock(0, 1);
			}
		}
		block = nextBlock;				//다음 블럭이 현재 블럭이 됨
	}
}

//점수 출력
void BestScore()
{
	system("cls"); //화면 초기화
	int x = 15;
	int y = 11;
	Cursor(x, y); cout << "▨▨▨  ☆BEST SCORE☆  ▨▨▨";
	Cursor(x + 10, y + 2); cout <<GameTable::GetBest() << " 점";
	Cursor(x, y + 4); cout << "▨▨▨▨▨▨▨▨▨▨▨▨▨▨▨";

	Cursor(x + 2, 20);  cout << "나가려면 ESC를 누르세요.";
	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}

//게임정보
void GameInfo()
{
	system("cls"); //화면 초기화
	int x = 12;
	int y = 14;
	Cursor(x + 14, y - 6); cout << "게임 조작";

	Cursor(x, y); cout << "←, → 방향키 : 좌우 블럭이동";
	Cursor(x, y + 2); cout << "↓ 방향키 : 아래로 블럭이동";
	Cursor(x, y + 4); cout << "↑ 방향키 : 블럭 회전 (반시계 방향)";
	Cursor(x, y + 6); cout << "SPACE : 블럭 하강";
	Cursor(x, y + 8); cout << "ESC : 종료, 나가기 / P : 일시정지";

	Cursor(x, y + 12); cout << "제작자 : sunmoon4228@gmail.com";

	while (true)
	{
		if (KeyControl() == ESC)
			return;
	}
}
