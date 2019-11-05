#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

#define MOD 1000000007

using namespace std;

int main()
{
	int t, tc;
	int n, k;
	int acc;
	int temp, ptr;
	char input[1000001];
	long long pw[1000001];
	string str;
	int i;
	long long cur, sol;
	//stack<long long> s;

	freopen("class_treasurer.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cur = 2;

	for (i = 0; i < 1000000; i++)
	{
		pw[i] = cur;

		cur = cur * 2 % MOD;
	}

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d", &n, &k);

		scanf("%s", input);

		str = input;
		sol = 0;
		acc = 0;

		for (i = n - 1; i >= 0; i--)
		{
			if (str[i] == 'B')
			{
				//s.push(pw[i]);

				if (++acc > k)
				{
					acc -= 2;

					sol = (sol + pw[i]) % MOD;

					if (acc < 0)
					{
						acc = 0;
					}

					//s.pop();
				}
			}

			else
			{
				if (--acc < 0)
				{
					acc = 0;

					/*
					while (!s.empty())
					{
						s.pop();
					}
					*/
				}
			}

			//pw = pw * 2 % MOD;
		}

		printf("Case #%d: %lld\n", t + 1, sol);
	}

	return 0;
}