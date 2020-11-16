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
		int n;
		vector<int> sol;
		int check[51] = { 0, };

		scanf("%d", &n);

		for (int i = 0; i < n * 2; i++)
		{
			int input;

			scanf("%d", &input);

			if (!check[input])
			{
				sol.push_back(input);
			}

			check[input]++;
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}