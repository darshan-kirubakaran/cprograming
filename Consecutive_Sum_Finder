#include <iostream>
#include <string>

void PrintArray(int answers[]);
int CheckSumOfArray(int numbers[]);
void ResetArray(int answer[]);

int const num = 15;

int main()
{
	int answers[num];

	bool answerFound = false;

	ResetArray(answers);

	int i;

	for(i = 1; i < num; i++)
	{
		if (CheckSumOfArray(answers) > num)
		{
			ResetArray(answers);
		}
		else if(CheckSumOfArray(answers) == num)
		{
			PrintArray(answers);
			ResetArray(answers);

			answerFound = true;
		}
		else
		{
			answers[i - 1] = i;
		}
	}

	if (!answerFound)
	{
		printf("%d has no answer\n", num);
	}

	return 0;
}

void ResetArray(int answers[])
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		answers[i] = 0;
	}
}

int CheckSumOfArray(int numbers[])
{
	int i;
	int sum = 0;

	for (i = 0; i < num; i++)
	{
		sum += numbers[i];
	}

	return sum;
}

void PrintArray(int answers[])
{
	int i;

	for(i = 0; i < num; i++)
	{
		if (answers[i] == 0) { continue; }

		printf("%d ", answers[i]);

		if (i == num - 1) { break; }

		printf("+ ");
	}

	printf("= %d\n", num);
}
