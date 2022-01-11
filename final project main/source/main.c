#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>


#define   WIDTH        100
#define   HIGH         20
#define   MAX_LENGHT   100
#define   SPEED        200
#define   MAX_SCORE    5

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

void check(void)
{
	int i;

	if (snake.x_buf[0] == 0 || snake.x_buf[0] == WIDTH + 4 || snake.y_buf[0] == 0 || snake.y_buf[0] == HIGH + 2)
	{
		printf("Game Over!\n");
		printf("Your score: %d", snake.score);
		exit(0);
	}
	for (i = 1; i < snake.len; i++)
	{
		if (snake.x_buf[0] == snake.x_buf[i] && snake.y_buf[0] == snake.y_buf[i])
		{
			printf("Game Over!\n");
			printf("Your score: %d", snake.score);
			exit(0);
		}
	}

	if (snake.score == MAX_SCORE)
	{
		printf("Your are win!\n");
		printf("Your score: %d", snake.score);
		exit(0);
	}

	gotoxy(0, HIGH + 6);
	printf("Your score: %d", snake.score);
}

int main(void)
{
	DrawMap();
	CreateSnake();
	while (1)
	{
		CreateFood();
		move();
		Sleep(SPEED - 2 * snake.len);
		check();
	}
}