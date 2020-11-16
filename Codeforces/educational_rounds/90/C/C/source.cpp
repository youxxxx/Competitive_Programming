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

	scanf("%lld", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[1000001];
		string str;

		scanf("%s", input);
		str = input;

		const int n = str.size();

		long long lmin = 0;
		long long cur = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '+')
			{
				cur++;
			}

			else
			{
				cur--;
			}

			if (cur < lmin)
			{
				lmin = cur;
			}
		}

		long long left = -lmin + 1;

		cur = 0;
		long long ptr = 0;
		long long sol = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '+')
			{
				cur++;
			}

			else
			{
				cur--;
			}

			sol += left;

			if (-cur > ptr)
			{
				ptr++;

				left--;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}