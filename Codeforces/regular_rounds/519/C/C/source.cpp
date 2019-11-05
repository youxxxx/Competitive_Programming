#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	char input[1001];
	string str;
	int state = 0;
	int i;
	vector<int> sol;

	scanf("%s", input);
	str = input;

	for (i = str.size() - 1; i >= 0; i--)
	{
		switch (state)
		{
		case 0:
			if (str[i] == 'a')
			{
				sol.insert(sol.begin(), 1);

				state = 1;
			}

			else
			{
				sol.insert(sol.begin(), 0);

				state = 0;
			}
			break;
		case 1:
			if (str[i] == 'a')
			{
				sol.insert(sol.begin(), 0);

				state = 1;
			}

			else
			{
				sol.insert(sol.begin(), 1);

				state = 2;
			}
			break;
		case 2:
			if (str[i] == 'a')
			{
				sol.insert(sol.begin(), 1);

				state = 3;
			}

			else
			{
				sol.insert(sol.begin(), 0);

				state = 2;
			}
			break;
		case 3:
			if (str[i] == 'a')
			{
				sol.insert(sol.begin(), 0);

				state = 3;
			}

			else
			{
				sol.insert(sol.begin(), 1);

				state = 0;
			}
			break;
		}
	}

	for (i = 0; i < sol.size(); i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}