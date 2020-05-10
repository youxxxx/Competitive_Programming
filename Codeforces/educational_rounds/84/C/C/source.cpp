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

#define MOD 998244353

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k * 2; i++)
	{
		int input;

		scanf("%d %d", &input, &input);
	}

	string sol;

	for (int i = 0; i < n - 1; i++)
	{
		sol.push_back('U');
	}

	for (int i = 0; i < m - 1; i++)
	{
		sol.push_back('L');
	}

	char h[2] = { 'R','L' };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			sol.push_back(h[i % 2]);
		}

		sol.push_back('D');
	}

	sol.pop_back();

	printf("%d\n%s\n", sol.size(), sol.c_str());

	return 0;
}