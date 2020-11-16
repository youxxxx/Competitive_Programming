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
		vector<long long> pos;
		vector<long long> neg;
		int zero = 0;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			if (input > 0)
			{
				pos.push_back(input);
			}

			else if (input < 0)
			{
				neg.push_back(input);
			}

			else
			{
				zero = 1;
			}
		}

		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end(), greater<long long>());

		long long sol = -999999999999999999;

		if (zero)
		{
			sol = 0;
		}

		for (int i = 0; i <= 5; i++)
		{
			if (pos.size() < i || neg.size() < 5 - i)
			{
				continue;
			}

			long long cand = 1;

			for (int j = 0; j < i; j++)
			{
				cand *= pos[j];
			}

			for (int j = 0; j < 5 - i; j++)
			{
				cand *= neg[j];
			}

			if (cand > sol)
			{
				sol = cand;
			}
			
			cand = 1;

			for (int j = (int)pos.size() - 1; j >= (int)pos.size() - i; j--)
			{
				cand *= pos[j];
			}

			for (int j = (int)neg.size() - 1; j >= (int)neg.size() - (5 - i); j--)
			{
				cand *= neg[j];
			}

			if (cand > sol)
			{
				sol = cand;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}