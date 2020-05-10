#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n, m;
	vector<long long> arr, sol;
	long long input, prev;
	int i;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &m);

		arr.clear();
		sol.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		for (i = 0; i < m; i++)
		{

		}
	}
	return 0;
}
