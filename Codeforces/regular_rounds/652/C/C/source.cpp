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
		int n, m;

		scanf("%d %d", &n, &m);

		vector<long long> arr;

		for (int i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		vector<long long> num;

		for (int i = 0; i < m; i++)
		{
			long long input;

			scanf("%lld", &input);

			num.push_back(input);
		}

		sort(num.begin(), num.end(), greater<long long>());

		long long sol = 0;
		long long ptr = 0;

		for (int i = 0; i < m; i++)
		{
			sol += arr[ptr];

			ptr += num[i] - 1;

			sol += arr[n - i - 1];
		}

		printf("%lld\n", sol);
	}

	return 0;
}