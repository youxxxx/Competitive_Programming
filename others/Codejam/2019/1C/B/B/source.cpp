#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int t, z, f;
	int i, j, k;
	vector<int> fig[5];
	vector<int> list;
	string missing;
	char answer;
	char input;
	char temp[10];
	bool taken[5];
	int look;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &t, &f);

	for (z = 0; z < t; z++)
	{
		look = 120;
		missing.clear();
		list.clear();

		for (i = 0; i < 119; i++)
		{
			list.push_back(i);
		}

		for (i = 0; i < 5; i++)
		{
			taken[i] = false;
		}

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				fig[j].clear();
			}

			for (j = 0; j < list.size(); j++)
			{
				printf("%d\n", list[j] * 5 + i + 1);
				fflush(stdout);

				scanf("%s", temp);

				input = temp[0];

				fig[input - 'A'].push_back(list[j]);
			}

			for (j = 0; j < 5; j++)
			{
				if (!taken[j] && fig[j].size() != look / (5 - i))
				{
					list.clear();

					for (k = 0; k < fig[j].size(); k++)
					{
						list.push_back(fig[j][k]);
					}

					missing.push_back('A' + j);
					
					taken[j]=true;

					break;
				}
			}

			look /= (5 - i);
		}

		for (i = 0; i < 5; i++)
		{
			if (!taken[i])
			{
				missing.push_back(i + 'A');

				break;
			}
		}

		printf("%s\n", missing.c_str());
		fflush(stdout);

		scanf("%s", temp);

		answer = temp[0];

		if (answer == 'N')
		{
			return 0;
		}
	}

	return 0;
}