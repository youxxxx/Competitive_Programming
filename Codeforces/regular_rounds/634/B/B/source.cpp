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

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, a, b;

		scanf("%d %d %d", &n, &a, &b);

		string base;

		for (int i = 0; i < b; i++)
		{
			base.push_back('a' + i);
		}

		for (int i = b; i < a; i++)
		{
			base.push_back('a' + b - 1);
		}

		string sol;

		for (int i = 0; i < n; i++)
		{
			sol.push_back(base[i%a]);
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}