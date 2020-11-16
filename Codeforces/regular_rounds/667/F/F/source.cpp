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

	int n, k;

	scanf("%d %d", &n, &k);

	char input[201];

	scanf("%s", input);
	string s = input;

	scanf("%s", input);
	string t = input;

	if (t[0] == t[1])
	{
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			cnt += (s[i] == t[0]);
		}

		int num = min(n, cnt + k);

		printf("%d\n", num*(num - 1) / 2);

		return 0;
	}

	int sol = 0;

	for (int i = 0; i <= k; i++)
	{
		string temp = s;
		
		int left = i;

		for (int j = 0; j < n && left; j++)
		{
			if (temp[j] != t[0])
			{
				temp[j] = t[0];

				left--;
			}
		}

		left = k - i;

		for (int j = n - 1; j >= 0 && left; j--)
		{
			if (temp[j] != t[1])
			{
				temp[j] = t[1];

				left--;
			}
		}

		int a = 0;
		int cand = 0;

		for (int j = 0; j < n; j++)
		{
			a += (temp[j] == t[0]);

			if (temp[j] == t[1])
			{
				cand += a;
			}
		}

		if (cand > sol)
		{
			sol = cand;
		}
	}

	printf("%d\n", sol);

	return 0;
}