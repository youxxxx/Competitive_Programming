#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t, n;
	vector<string> stk;
	char input[100];
	string temp;
	int i, j, z;
	int player, winner;
	bool end;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %s", &n, input);
		temp = input;

		if (temp == "Dee")
		{
			player = 0;
		}

		else
		{
			player = 1;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%s", input);

			stk.push_back(input);
		}

		winner = -1;
		end = false;

		while (winner == -1)
		{
			for (i = 0; i < n; i++)
			{
				if (stk[i].empty() || stk[i][0] - '0' != player)
				{
					continue;
				}

				while (!stk[i].empty() && stk[i][0] - '0' == player)
				{
					stk[i].erase(0, 1);
				}

				break;
			}

			if (i == n)
			{
				winner = player;
			}

			player = !player;
		}

		if (winner == 0)
		{
			printf("Dee\n");
		}

		else if (winner == 1)
		{
			printf("Dum\n");
		}

		else
		{
			printf("Error\n");
		}

		stk.clear();
	}

	return 0;
}