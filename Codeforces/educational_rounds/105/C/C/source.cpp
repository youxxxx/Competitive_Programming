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

void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		vector<int> a, b;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			a.push_back(input);
		}

		vector<int>::iterator it = lower_bound(a.begin(), a.end(), 0);
		const int az = it - a.begin();

		for (int i = 0; i < m; i++)
		{
			int input;

			scanf("%d", &input);

			b.push_back(input);
		}

		it = lower_bound(b.begin(), b.end(), 0);
		const int bz = it - b.begin();

		int base[200001];

		for (int i = 0; i < m; i++)
		{
			base[i] = 0;
		}

		int neg = 0;
		int pos = 0;

		if(bz)
		{
			int ptr = bz - 1;

			for (int i = az - 1; i >= 0; i--)
			{
				while (ptr > 0 && b[ptr] > a[i])
				{
					ptr--;
				}

				if (b[ptr] == a[i])
				{
					base[i] = 1;

					neg++;
				}
			}
		}

		if (bz != m)
		{
			int ptr = bz;

			for (int i = az; i < n; i++)
			{
				while (ptr < m - 1 && b[ptr] < a[i])
				{
					ptr++;
				}

				if (b[ptr] == a[i])
				{
					base[i] = 1;

					pos++;
				}
			}
		}

		int cur = neg;

		if (bz)
		{
			int ptr = bz - 1;
			int ptr2 = bz - 1;

			for (int i = az - 1; i >= 0; i--)
			{
				cur -= base[i];

				base[i] = 0;

				while (ptr > 0 && b[ptr] > a[i])
				{
					//cur -= base[ptr];

					//base[ptr] = 0;

					ptr--;
				}

				while (ptr2 >= 0 && b[ptr2] > b[ptr] - (az - i))
				{
					//cur -= base[ptr2];

					//base[ptr2] = 0;

					ptr2--;
				}

				int val = cur;

				if (b[ptr] <= a[i])
				{
					val += abs(ptr - ptr2);
				}

				neg = max(neg, val);
			}

			while (ptr > 0 && ptr2 >= 0)
			{
				ptr--;
				
				//cur -= base[ptr];

				//base[ptr] = 0;

				while (ptr2 >= 0 && b[ptr2] > b[ptr] - az)
				{
					//cur -= base[ptr2];

					//base[ptr2] = 0;

					ptr2--;
				}

				neg = max(neg, abs(ptr - ptr2));
			}

			if (b[0] <= a[az - 1])
			{
				neg = max(neg, 1);
			}
		}

		cur = pos;

		if (bz != m)
		{
			int ptr = bz;
			int ptr2 = bz;

			for (int i = az; i < n; i++)
			{
				cur -= base[i];

				base[i] = 0;

				while (ptr < m - 1 && b[ptr] < a[i])
				{
					//cur -= base[ptr];

					//base[ptr] = 0;

					ptr++;
				}

				while (ptr2 < m && b[ptr2] < b[ptr] + (i - az + 1))
				{
					//cur -= base[ptr2];

					//base[ptr2] = 0;

					ptr2++;
				}

				int val = cur;

				if (b[ptr] >= a[i])
				{
					val += abs(ptr - ptr2);
				}

				pos = max(pos, val);
			}

			while (ptr < m - 1 && ptr2 < m)
			{
				ptr++;

				//cur -= base[ptr];

				//base[ptr] = 0;

				while (ptr2 < m && b[ptr2] < b[ptr] + (n - az))
				{
					//cur -= base[ptr2];

					//base[ptr2] = 0;

					ptr2++;
				}

				pos = max(pos, abs(ptr - ptr2));
			}

			if (b[m - 1] >= a[az])
			{
				pos = max(pos, 1);
			}
		}

		printf("%d\n", pos + neg);
	}

	return 0;
}