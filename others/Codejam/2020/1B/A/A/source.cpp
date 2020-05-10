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
	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		long long x, y;

		scanf("%lld %lld", &x, &y);

		long long base = 2;

		if (!((x + y) % 2))
		{
			printf("Case #%d: IMPOSSIBLE\n", tc);

			continue;
		}

		long long ax, ay;

		ax = abs(x);
		ay = abs(y);

		long long subt;

		for (int i = 0; i < 33; i++)
		{
			if (base - 1 >= ax + ay)
			{
				subt = (base - 1 - (ax + ay)) / 2;

				break;
			}

			base *= 2;
		}

		vector<long long> sign;

		long long temp;
		long long tot;

		temp = subt;
		tot = base - 1;

		while (tot)
		{
			if (temp % 2)
			{
				sign.push_back(1);
			}

			else
			{
				sign.push_back(0);
			}

			temp /= 2;
			tot /= 2;
		}

		vector<long long> num;

		long long temp1, temp2;

		temp1 = ax;
		temp2 = ay;

		long long bit = 1;

		for (int i = 0; i < sign.size(); i++)
		{
			long long val;

			val = bit;

			if (sign[i])
			{
				val *= -1;
			}

			if (bit&temp1)
			{
				temp1 -= val;

				num.push_back(0);
			}

			else
			{
				temp2 -= val;

				num.push_back(1);
			}
			
			bit *= 2;
		}

		string sol;

		for (int i = 0; i < num.size(); i++)
		{
			if (!num[i])
			{
				if (x < 0 && sign[i] || x > 0 && !sign[i])
				{
					sol.push_back('E');
				}

				else
				{
					sol.push_back('W');
				}
			}

			else
			{
				if (y < 0 && sign[i] || y > 0 && !sign[i])
				{
					sol.push_back('N');
				}

				else
				{
					sol.push_back('S');
				}
			}
		}

		printf("Case #%d: %s\n", tc, sol.c_str());
	}

	return 0;
}