#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<int> two, one;

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		two.clear();
		one.clear();

		long long arr[200001];

		long long tot = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);

			tot += arr[i];
		}

		for (int i = 0; i < n; i++)
		{
			int b;

			scanf("%d", &b);

			if (b == 1)
			{
				one.push_back(arr[i]);
			}

			else
			{
				two.push_back(arr[i]);
			}
		}

		const int a = one.size();
		const int b = two.size();

		if (tot < m)
		{
			printf("-1\n");

			continue;
		}

		sort(one.begin(), one.end(),greater<long long>());
		sort(two.begin(), two.end(),greater<long long>());

		int ptr1 = 0;
		int ptr2 = 0;

		long long curmem = 0;
		long long curconv = 0;

		while ((ptr1 < a || ptr2 < b) && curmem < m)
		{
			if (ptr1 == a)
			{
				curconv += 2;
				curmem += two[ptr2++];
			}

			else if (ptr2 == b)
			{
				curconv++;
				curmem += one[ptr1++];
			}

			else if (one[ptr1] < two[ptr2])
			{
				curconv += 2;
				curmem += two[ptr2++];
			}

			else
			{
				curconv++;
				curmem += one[ptr1++];
			}
		}

		long long sol = curconv;

		while (ptr2 > 0 && ptr1 < a)
		{
			curconv -= 2;
			curmem -= two[--ptr2];

			while (ptr1 < a&&curmem < m)
			{
				curconv++;
				curmem += one[ptr1++];
			}

			if (curmem >= m)
			{
				sol = min(curconv, sol);
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}