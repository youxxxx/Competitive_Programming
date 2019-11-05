#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<vector<long long>> arr;
	vector<long long> cur;
	int i, j;
	int n;
	long long input;
	long long mlt;
	vector<long long> sol;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		cur.clear();

		for (j = 0; j < n; j++)
		{
			scanf("%lld", &input);

			cur.push_back(input);
		}

		arr.push_back(cur);
	}

	mlt = arr[0][1] * arr[0][2];
	mlt /= arr[1][2];

	mlt = (long long)sqrt((double)mlt);

	printf("%lld", mlt);

	for (i = 1; i < n; i++)
	{
		printf(" %lld", arr[0][i] / mlt);
	}

	return 0;
}