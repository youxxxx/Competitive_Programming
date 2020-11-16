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
		long long n, s;

		scanf("%lld %lld", &n, &s);

		vector<long long> digit;

		long long temp = n;
		long long cur = 0;

		while (temp)
		{
			digit.push_back(temp % 10);

			cur += temp % 10;

			temp /= 10;
		}

		if (cur <= s)
		{
			printf("0\n");

			continue;
		}

		long long sol = 10 - digit[0];

		cur -= digit[0] - 1;
		long long base = 1;

		for (int i = 1; i < digit.size() && cur>s; i++)
		{
			base *= 10;

			sol += (9 - digit[i])*base;
			cur -= digit[i];
		}

		printf("%lld\n", sol);
	}

	return 0;
}