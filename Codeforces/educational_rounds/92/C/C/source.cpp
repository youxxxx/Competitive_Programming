#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int tot[10] = { 0, };
		char input[200001];

		scanf("%s", input);
		string str = input;

		const int n = str.size();

		for (int i = 0; i < n; i++)
		{
			tot[str[i] - '0']++;
		}

		int sol = 0;

		for (int i = 0; i < 10; i++)
		{
			if (tot[i] > sol)
			{
				sol = tot[i];
			}
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == j)
				{
					continue;
				}

				int cnt = 0;

				for (int k = 0; k < n; k++)
				{
					if (!(cnt % 2))
					{
						if (str[k] - '0' == i)
						{
							cnt++;
						}
					}

					else
					{
						if (str[k] - '0' == j)
						{
							cnt++;
						}
					}
				}

				cnt -= cnt % 2;

				if (cnt > sol)
				{
					sol = cnt;
				}
			}
		}

		printf("%d\n", n - sol);
	}

	return 0;
}