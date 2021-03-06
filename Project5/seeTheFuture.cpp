#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
game* copyContent(game* board)
{
	/*This function is used to copy the content of given board and returns that copy*/
	game* temp=(game*)malloc(sizeof(game));
	int n=board->n;
	temp->n = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->a[i][j] = board->a[i][j];
		}
	}
	return temp;
}
void printer(game* board)
{
	/*prints the current state of the board*/
	int n = board->n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%6d ", board->a[i][j]);
		}
		printf("\n");
	}
}
void preview(game* board)
{
	/*used to direct the user to see the preview of the board*/
	system("cls");
	printf("LEFT:\n");
	game* temp = copyContent(board);
	playLeft(temp);
	printer(temp);

	printf("DOWN:\n");
	temp = copyContent(board);
	playDown(temp);
	printer(temp);

	printf("UP:\n");
	temp = copyContent(board);
	playUp(temp);
	printer(temp);

	printf("RIGHT:\n");
	temp = copyContent(board);
	playRight(temp);
	printer(temp);
	system("pause");
}