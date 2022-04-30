#pragma once
#include "main.h"

//BOX 가로, 세로 크기
#define TABLE_WIDTH 12		//BOX 가로
#define TABLE_HEIGHT 20		//BOX 세로

//BLOCK의 상태
#define EMPTY 0		//빈 공간
#define LINE 1		//박스 테두리
#define OVER 2		//게임오버 경계
#define FIX 10		//쌓인블럭

class GameTable
{
public:
	const static int CBOX[TABLE_HEIGHT + 2][TABLE_WIDTH];	//게임 박스 (고정)
	static int Box[TABLE_HEIGHT + 2][TABLE_WIDTH];			//게임 박스
	static int NextBox[7][7];
	static int X;		//x좌표
	static int Y;		//y좌표
	static int Score;	//점수
	static int Speed;	//블럭 하강속도
	//이름(점수 기록용)

public:
	static void ResetBox();
	static void PrintBox();		//테트리스 박스 출력
	static void PrintNextBox();	//다음 블럭을 보여주는 박스 출력
	static bool IsBlock(int, int);
	static bool IsInTable_X(int);
	static bool CheckLine(int);	//한 줄 완성됐는지 확인
	static bool DeleteLine();	//한 줄 삭제
	static void PrintScore();
	static void SetSpeed();		//블럭 하강속도 설정
	static bool IsOver();		//라인을 넘었는지 확인
	static void GameOver();		//게임 오버
	static int GetBest();		//최고점수 받아오기
	static void SetBest(int);	//최고점수 기록
};
