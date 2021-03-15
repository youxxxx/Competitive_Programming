#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>
#include<unordered_set>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	unordered_set<string> list;

	for (int tc = 0; tc < cases; tc++)
	{
		list.clear();

		int n, m;

		scanf("%d %d", &n, &m);

		char input[1000001];
		scanf("%s", input);
		const string str = input;

		string cur = str.substr(0, m);

		for (int i = 0; i < m; i++)
		{
			cur[i] = !(cur[i] - '0') + '0';
		}

		list.insert(cur);

		for (int i = m; i < n; i++)
		{
			cur.erase(cur.begin());
			
			cur.push_back(!(str[i] - '0') + '0');

			list.insert(cur);
		}

		if (m < 20 && (int)pow(2.0, m) == (int)list.size())
		{
			printf("NO\n");

			continue;
		}

		string zero;

		for (int i = 0; i < m; i++)
		{
			zero.push_back('0');
		}

		unordered_set<string>::iterator ret = list.find(zero);

		if (ret == list.end())
		{
			printf("YES\n%s\n", zero.c_str());

			continue;
		}

		string sol;

		for(unordered_set<string>::iterator it=list.begin();it!=list.end();it++)
		{
			string next = *it;

			for (int i = m - 1; i >= 0; i--)
			{
				if (next[i] == '0')
				{
					next[i] = '1';

					break;
				}

				else
				{
					next[i] = '0';
				}
			}

			unordered_set<string>::iterator ret = list.find(next);

			if (ret == list.end())
			{
				if (sol.empty())
				{
					sol = next;
				}

				else
				{
					sol = min(sol, next);
				}
			}
		}

		printf("YES\n%s\n", sol.c_str());
	}

	return 0;
}