#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[150001];
		string str;
		int n;

		scanf("%s", input);
		str = input;
		n = str.size();

		vector<pair<char, int>> list;
		int cnt = 1;

		for (int i = 1; i < n; i++)
		{
			if (str[i - 1] != str[i])
			{
				list.push_back({ str[i - 1],cnt });

				cnt = 1;
			}

			else
			{
				cnt++;
			}
		}

		list.push_back({ str[n - 1],cnt });

		int m;

		m = list.size();
		vector<int> sol;
		vector<int> acclist; 

		acclist.push_back(0);

		for (int i = 1; i < m; i++)
		{
			acclist.push_back(acclist.back() + list[i - 1].second);
		}

		for (int i = 0; i < m - 2; i++)
		{
			if (i < m - 4 && list[i].first == 't' && list[i + 1].first == 'w'  && list[i + 2].first == 'o'&&list[i + 3].first == 'n'&&list[i + 4].first == 'e' && list[i+1].second==1&&list[i+3].second==1)
			{
				if (list[i + 2].second == 1)
				{
					sol.push_back(acclist[i + 2]);
				}

				else
				{
					sol.push_back(acclist[i + 1]);
					sol.push_back(acclist[i + 3]);
				}

				i += 4;
			}

			else if ((i < 2 || !(list[i - 2].first == 't' && list[i - 1].first == 'w' && list[i - 1].second == 1)) && list[i].first == 'o'&&list[i + 1].first == 'n'&&list[i + 2].first == 'e' && list[i + 1].second == 1)
			{
				sol.push_back(acclist[i + 1]);

				i += 2;
			}

			else if ((i >= m - 4 || !(list[i + 3].first == 'n' && list[i + 4].first == 'e' && list[i + 3].second == 1)) && list[i].first == 't'&&list[i + 1].first == 'w'&&list[i + 2].first == 'o' && list[i + 1].second == 1)
			{
				sol.push_back(acclist[i + 1]);

				i += 2;
			}
		}

		printf("%d\n", sol.size());

		for (int i = 0; i < sol.size(); i++)
		{
			printf("%d ", sol[i] + 1);
		}

		printf("\n");
	}

	return 0;
}