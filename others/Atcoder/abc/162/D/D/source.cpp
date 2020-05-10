#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	long long n;

	scanf("%lld", &n);

	char input[4001];
	string str;

	scanf("%s", input);

	str = input;

	long long cnt[255] = { 0, };

	for (int i = 0; i < n; i++)
	{
		cnt[str[i]]++;
	}

	long long sol;

	sol = cnt['R'] * cnt['G'] * cnt['B'];

	for (int i = 1; i < n - 1; i++)
	{
		int bound;

		bound = i < n - 1 - i ? i : n - 1 - i;

		for (int j = 1; j <= bound; j++)
		{
			if (str[i - j] != str[i + j] && str[i + j] != str[i] && str[i - j] != str[i])
			{
				sol--;
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}