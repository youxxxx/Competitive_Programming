#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int u;

		scanf("%d", &u);

		char sol[11];
		int cnt[26] = { 0 };
		int fcnt[26] = { 0, };
		//vector<string> arr;

		for (int i = 0; i < 10000; i++)
		{
			int q;
			char input[20];
			string str;

			scanf("%d %s", &q, input);

			str = input;
			
			//arr.push_back(str);

			const int n = str.size();

			for (int j = 0; j < n; j++)
			{
				cnt[str[j] - 'A']++;
			}

			fcnt[str[0] - 'A']++;
		}

		vector<pair<int,int>> cand;

		for (int i = 0; i < 26; i++)
		{
			if (cnt[i])
			{
				if (!fcnt[i])
				{
					sol[0] = i + 'A';
				}

				else
				{
					cand.push_back({ fcnt[i],i });
				}
			}
		}
		
		sort(cand.begin(), cand.end());

		for (int i = 8; i >= 0; i--)
		{
			sol[9 - i] = cand[i].second + 'A';
		}

		sol[10] = NULL;

		printf("Case #%d: %s\n", tc, sol);
	}

	return 0;
}