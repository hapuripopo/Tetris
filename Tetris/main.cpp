#include "main.h"

int main(void)
{
	Init();		//초기설정

	while (true) 
	{
		system("cls");		//화면 초기화
		int sel = Menu();	//메뉴 호출, 선택

		if (sel == 6)	//게임종료
		{
			Cursor(10, 30);
			return 0;
		}

		switch (sel)
		{
		case 0:			//게임시작
			GameStart();
			break;
		case 2:			//최고점수
			BestScore();
			break;
		case 4:			//게임정보
			GameInfo();
			break;
		default:
			break;
		}
	}
}
