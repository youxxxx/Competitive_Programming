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

#define MOD 100030001

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		vector<string> arr;

		for (int i = 0; i < n; i++)
		{
			char input[101];

			scanf("%s", input);

			string str = input;

			arr.push_back(str);
		}

		int sol = 0;

		for (int i = 0; i < n - 1; i++)
		{
			sol += (arr[i][m - 1] == 'R');
		}

		for (int i = 0; i < m - 1; i++)
		{
			sol += (arr[n - 1][i] == 'D');
		}

		printf("%d\n", sol);
	}

	return 0;
}