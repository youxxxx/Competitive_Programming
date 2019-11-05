#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int i, j;
	char input;
	char ans[3] = { 'R','P','S' };
	char ai[3];
	char sol[3] = { 'R','R','R' };
	int add;
	bool mimic = false;
	string input2;

	for (i = 0; i < 10; i++)
	{
		printf("%c\n",ans[i%3]);
		fflush(stdout);

		//scanf("%c", &input);
		getline(cin, input2);
		input = input2[0];

		ai[i % 3] = input;

		if (i == 3)
		{
			for (j = 0; j < 3; j++)
			{
				if (ai[1] == ans[(0 + j) % 3] && ai[2] == ans[(1 + j) % 3] && ai[0] == ans[(2 + j) % 3])
				{
					mimic = true;

					add = j;
				}
			}
		}
		//scanf("%c", &input);
	}

	if (ai[0] == ai[1] && ai[1] == ai[2])
	{
		switch (ai[0])
		{
		case 'R':
			sol[0] = sol[1] = sol[2] = 'P';
			break;
		case 'P':
			sol[0] = sol[1] = sol[2] = 'S';
			break;
		case 'S':
			sol[0] = sol[1] = sol[2] = 'R';
			break;
		}
	}

	else if (mimic)
	{
		/*
		sol[0] = 'P';
		sol[1] = 'S';
		sol[2] = 'R';
		*/

		for (i = 0; i < 3; i++)
		{
			sol[i] = ans[(1 + i + add) % 3];
		}
	}

	for (i = 0; i < 10; i++)
	{
		printf("%c\n", sol[i % 3]);
		fflush(stdout);

		//scanf("%c", &input);
		getline(cin, input2);
		input = input2[0];

		//scanf("%c", &input);
	}

	return 0;
}