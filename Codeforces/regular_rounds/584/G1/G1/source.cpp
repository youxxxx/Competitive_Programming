#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int n, q;
	int start[200001], end[200001], cnt[200001];
	int i;
	int cur;
	vector<int> arr;
	vector<int> list;
	int chunks;
	int input;
	int lmax, sum;
	int sol = 0;
	int curs, cure;

	memset(start, -1, sizeof(start));
	memset(end, -1, sizeof(end));
	memset(cnt, 0, sizeof(cnt));

	scanf("%d %d", &n, &q);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (start[input] == -1)
		{
			start[input] = i;
			end[input] = i;

			cnt[input]++;

			arr.push_back(input);
		}

		else
		{
			cnt[input]++;

			end[input] = i;
		}
	}

	curs = 0;
	cure = end[arr[0]];
	cur = arr[0];
	chunks = 0;
	sum = cnt[cur];
	lmax = cnt[cur];

	for (i = 1; i < arr.size(); i++)
	{
		if (start[arr[i]] > cure)
		{
			if (chunks)
			{
				sol += sum - lmax;
			}

			cur = arr[i];
			chunks = 0;
			sum = cnt[cur];
			lmax = cnt[cur];
			curs = start[cur];
			cure = end[cur];
		}

		else
		{
			sum += cnt[arr[i]];

			chunks++;

			if (cnt[arr[i]] > lmax)
			{
				lmax = cnt[arr[i]];
			}

			if (end[arr[i]] > cure)
			{
				cure = end[arr[i]];
			}
		}
	}

	if (chunks)
	{
		sol += sum - lmax;
	}

	printf("%d\n", sol);

	return 0;
}