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
		int n;
		long long x;

		scanf("%d %lld", &n, &x);

		vector<int> arr;

		for (int i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end(), greater<long long>());

		long long acc = 0;
		int idx = -1;

		for (int i = 0; i < n; i++)
		{
			acc += arr[i];

			if (acc / (long long)(i + 1) < x)
			{
				break;
			}

			idx = i;
		}

		printf("%d\n", idx + 1);
	}

	return 0;
}