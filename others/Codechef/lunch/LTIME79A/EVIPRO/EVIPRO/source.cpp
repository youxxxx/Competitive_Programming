#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;
		char input[3000001];
		string str;
		long long tot;

		scanf("%s", input);
		str = input;
		n = str.size();

		tot = n*(n - 1) / 2 + n;

		long long sol = 0;

		for (long long i = 0; i < n - 1; i++)
		{
			long long base;

			base = (str[i] == str[i + 1]);

			sol += base*(tot - n) + (!base)*n;
		}

		printf("%lld\n", sol);
	}

	return 0;
}