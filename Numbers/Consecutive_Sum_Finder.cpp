#include <iostream>
#include <stdio.h>
#include <string>

void PrintAnswer(int start, int end, int num);
int ReturnSum(int start, int end);

int main()
{
	int num = 0;

	printf("Entre a number: ");
	scanf("%d", &num);

	bool answerFound = false;


	int i, j;

	for(i = 1; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (ReturnSum(i, j) > num)
			{
				break;
			}
			else if (ReturnSum(i, j) == num)
			{
				PrintAnswer(i, j, num);

				answerFound = true;
			}
		}
	}

	if (!answerFound)
	{
		printf("%d has no answer\n", num);
	}

	return 0;
}

int ReturnSum(int start, int end)
{
	int i;
	int sum = 0;

	for (i = start; i <= end; i++)
	{
		sum += i;
	}

	return sum;
}

void PrintAnswer(int start, int end, int num)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("%d ", i);

		if (i == end) { break; }

		printf("+ ");
	}

	printf("= %d\n", num);
}
