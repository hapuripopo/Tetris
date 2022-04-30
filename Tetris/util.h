#pragma once
#include "main.h"

//방향키
#define LEFT 75
#define RIGHT 77 
#define UP 72 
#define DOWN 80
#define ENTER 13
#define SPACE 32
#define ESC 27
#define P 112

void Cursor(int x, int y);	//커서이동
int KeyControl(void);		//방향키 입력을 받고 입력받은 키 반환
