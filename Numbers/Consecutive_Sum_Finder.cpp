#define _CRT_SECURE_NO_DEPRECATE

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


	int i, j, sum;

	for(i = 1; i <= num / 2 + 1; i++)
	{
		for (j = i + 1; j <= num / 2 + 1; j++)
		{
			sum = ReturnSum(i - 1, j);

			if (sum == num)
			{
				PrintAnswer(i, j, num);

				answerFound = true;

				break;
			}
			else if (sum  > num)
			{
				break;
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
	int sum = 0;

	sum = (end * (end + 1) / 2) - (start * (start + 1) / 2);

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
