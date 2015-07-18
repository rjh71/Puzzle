#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void rnd(char *);
void show(char *);
int check(char *);
int change(char *);

int main()
{
	char puzzle[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int finish;
	int errorcheck;

	show(puzzle);

	rnd(puzzle);

	while(1)
	{
		show(puzzle);
		finish = check(puzzle);
		errorcheck = change(puzzle);

		if(finish == 1)
			break;
		if(errorcheck == -2)
			break;
	}

	return 0;
}
void rnd(char *puzzle)
{
	char tmp;
	int num;

	srand(time(NULL));

	for(int i = 0; i < 9; i++)
	{
		num = rand() % 8;
		tmp = puzzle[i];
		puzzle[i] = puzzle[num];
		puzzle[num] = tmp;
	}
}
void show(char *puzzle)
{
	system("clear");
	printf("\n\n\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|		|		|		|\n");
	printf("\t\t|	%d	|	%d	|	%d	|\n", puzzle[0], puzzle[1], puzzle[2]);
	printf("\t\t|		|		|		|\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|		|		|		|\n");
	printf("\t\t|	%d	|	%d	|	%d	|\n", puzzle[3], puzzle[4], puzzle[5]);
	printf("\t\t|		|		|		|\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|		|		|		|\n");
	printf("\t\t|	%d	|	%d	|	%d	|\n", puzzle[6], puzzle[7], puzzle[8]);
	printf("\t\t|		|		|		|\n");
	printf("\t\t-------------------------------------------------\n\n");
	printf("\t\t\t상하좌우 범위 내에서만 움직일 수 있습니다.\n\n\n");
	printf("\t\t\t");
}
int check(char *puzzle)
{
	int success=0;

	for(int i = 0; i < 9; i++)
		if(puzzle[i] == i)
			success++;

	if(success == 9)
		return 1;

	else
		return -1;

	return 0;
}
int change(char *puzzle)
{
	int from, to;
	char tmp;

	for(int i = 0; i < 9; i++)
		if(puzzle[i] == 0)
			from = i;

	printf("옮길 위치 : ");
	scanf("%d", &to);

	if(to == -1)
		return -2;

	if(to < 1 || to > 9)
		return -1;

	to--;

	if(from % 3 == 0)
	{
		if(to == from -3 || to == from + 3 || to == from + 1)
		{
			tmp = puzzle[from];
			puzzle[from] = puzzle[to];
			puzzle[to] = tmp;
		}
		else
		{
			return -1;
		}
	}

	else if(from % 3 == 1)
	{
		if(to == from -3 || to == from + 3 || to == from + 1 || to == from - 1)
		{
			tmp = puzzle[from];
			puzzle[from] = puzzle[to];
			puzzle[to] = tmp;
		}
		else
		{
			return -1;
		}
	}
	else if(from % 3 == 2)
	{
		if(to == from -3 || to == from + 3 || to == from - 1)
		{
			tmp = puzzle[from];
			puzzle[from] = puzzle[to];
			puzzle[to] = tmp;
		}
		else
			return -1;
	}
	return 0;
}
