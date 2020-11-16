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

	int n;
	int arr[300001];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int lprev[300001];
	int gprev[300001];
	int lrprev[300001];
	int grprev[300001];
	int lnext[300001] = { 0, };
	int gnext[300001] = { 0, };
	memset(lprev, -1, sizeof(lprev));
	memset(lrprev, -1, sizeof(lrprev));
	memset(gprev, -1, sizeof(gprev));
	memset(grprev, -1, sizeof(grprev));

	lprev[0] = gprev[0] = -1;
	lnext[0] = gnext[0] = 1;

	for (int i = 1; i < n; i++)
	{
		lnext[i] = gnext[i] = i + 1;

		if (arr[i - 1] >= arr[i])
		{
			lprev[i] = i - 1;

			if (!lnext[i - 1])
			{
				lnext[i - 1] = i;
			}
		}

		else
		{
			int ptr = lprev[i - 1];
			int ptr2 = lprev[i - 1];

			if (ptr == -1)
			{
			}

			else
			{
				int curmax = arr[ptr2];
				while (lprev[ptr] != -1 && arr[ptr] < arr[i])
				{
					if (!lnext[ptr2] || arr[lnext[ptr2]] < arr[ptr2])
					{
						lnext[ptr2] = i;
					}

					ptr = lprev[ptr];

					if (arr[ptr] > curmax)
					{
						ptr2 = ptr;
					}
				}

				if (!lnext[ptr2] || arr[lnext[ptr2]] < arr[ptr2])
				{
					lnext[ptr2] = i;
				}

				lprev[i] = ptr;
				lrprev[i] = ptr2;
			}
		}

		if (arr[i - 1] <= arr[i])
		{
			gprev[i] = i - 1;

			if (!gnext[i - 1])
			{
				gnext[i - 1] = i;
			}
		}

		else
		{
			int ptr = gprev[i - 1];
			int ptr2 = gprev[i - 1];

			if (ptr == -1)
			{
			}

			else
			{
				int curmax = arr[ptr2];

				while (gprev[ptr] != -1 && arr[ptr] > arr[i])
				{
					if (!gnext[ptr2] || arr[gnext[ptr2]] > arr[ptr2])
					{
						gnext[ptr2] = i;
					}

					ptr = gprev[ptr];

					if (arr[ptr] < curmax)
					{
						ptr2 = ptr;
					}
				}

				if (!gnext[ptr2] || arr[gnext[ptr2]] > arr[ptr2])
				{
					gnext[ptr2] = i;
				}

				gprev[i] = ptr;
				grprev[i] = ptr2;
			}
		}
	}

	/*
	for (int i = 0; i < n; i++)
	{
		if (!lnext[i])
		{
			lnext[i] = i + 1;
		}

		if (!gnext[i])
		{
			gnext[i] = i + 1;
		}
	}
	*/

	int lmin[300001];

	memset(lmin, -1, sizeof(lmin));

	lmin[0] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (lmin[lnext[i]] == -1 || lmin[i] + 1 < lmin[lnext[i]])
		{
			lmin[lnext[i]] = lmin[i] + 1;
		}

		if (lmin[gnext[i]] == -1 || lmin[i] + 1 < lmin[gnext[i]])
		{
			lmin[gnext[i]] = lmin[i] + 1;
		}
	}

	printf("%d\n", lmin[n - 1]);

	return 0;
}