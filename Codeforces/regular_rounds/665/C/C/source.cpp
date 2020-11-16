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

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;

		int temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		int lmin = 1000000000;

		int arr[100001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (arr[i] < lmin)
			{
				lmin = arr[i];
			}
		}

		int temp = lmin;
		vector<int> pos;
		vector<int> swap;

		for (int i = 0; i < n; i++)
		{
			if (gcd(lmin, arr[i]) == lmin)
			{
				swap.push_back(arr[i]);
				pos.push_back(i);
			}
		}

		sort(swap.begin(), swap.end());

		for (int i = 0; i < pos.size(); i++)
		{
			arr[pos[i]] = swap[i];
		}

		bool valid = true;

		for (int i = 1; i < n; i++)
		{
			if (arr[i] < arr[i - 1])
			{
				valid = false;

				break;
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}