#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#define   WIDTH        100
#define   HIGH         20
#define   MAX_LENGHT   100
#define   SPEED        200

struct
{
	int x;
	int y;
}food;

struct
{
	int len;
	int x_buf[MAX_LENGHT];
	int y_buf[MAX_LENGHT];
	int score;
}snake;

void DrawMap(void)
{
	int x, y;
	for (x = 0; x < WIDTH + 4; x += 2)
	{
		y = 0;
		gotoxy(x, y);
		printf("―");
		y = HIGH + 2;
		gotoxy(x, y);
		printf("―");
	}

	for (y = 1; y < HIGH + 2; y++)
	{
		x = 0;
		gotoxy(x, y);
		printf("―");
		x = WIDTH + 2;
		gotoxy(x, y);
		printf("―");
	}

	gotoxy(0, HIGH + 5);
}

void CreateSnake(void)
{
	int orgin_x, orgin_y;
	orgin_x = WIDTH / 2 + 2;
	orgin_y = HIGH / 2 + 1;

	snake.len = 3;
	snake.x_buf[0] = orgin_x;
	snake.y_buf[0] = orgin_y;
	snake.x_buf[1] = orgin_x;
	snake.y_buf[1] = ++orgin_y;
	snake.x_buf[2] = orgin_x;
	snake.y_buf[2] = ++orgin_y;

	snake.score = -1;

	int i;
	for (i = 0; i < snake.len; i++)
	{
		gotoxy(snake.x_buf[i], snake.y_buf[i]);
		printf("―");
	}
	gotoxy(0, HIGH + 5);
}
