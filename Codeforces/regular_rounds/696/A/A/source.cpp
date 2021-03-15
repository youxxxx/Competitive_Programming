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

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		char input[100001];
		scanf("%d %s", &n, input);
		const string str = input;
		string sol;
		int prev = -1;

		for (int i = 0; i < n; i++)
		{
			int cur;

			if (str[i] == '1')
			{
				if (prev == 2)
				{
					cur = 1;
				}

				else
				{
					cur = 2;
				}
			}

			else
			{
				if (prev == 1)
				{
					cur = 0;
				}

				else
				{
					cur = 1;
				}
			}

			prev = cur;

			sol.push_back(cur + '0' - (str[i] - '0'));
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}