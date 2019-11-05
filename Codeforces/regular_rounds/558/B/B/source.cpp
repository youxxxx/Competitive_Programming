#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int ribbon[100001] = { 0, };
	int cnt[100001] = { 0, };
	int rnum = 0;
	int min = -1, max = -1;
	int sol = 0;
	int n;
	int i;
	int input;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	scanf("%d", &input);

	min = max = 1;

	cnt[0] = -1;
	cnt[1] = 1;
	ribbon[input] = 1;
	sol = 1;
	rnum = 1;
	
	for (i = 1; i < n; i++)
	{
		scanf("%d", &input);

		if (ribbon[input] == 0)
		{
			rnum++;

			min = 1;
		}

		cnt[ribbon[input]]--;

		cnt[++ribbon[input]]++;

		if ((cnt[ribbon[input] - 1] == 0 && min == ribbon[input] - 1))
		{
			min++;
		}

		if (cnt[ribbon[input]] == 1 && max == ribbon[input] - 1)
		{
			max++;
		}

		if (rnum == 1)
		{
			sol = i + 1;
		}

		else if (min == max && min == 1)
		{
			sol = i + 1;
		}

		/*
		else if (cnt[min] == 1 && max - min == 1)
		{
			sol = i + 1;
		}
		*/

		else if (cnt[max] == 1 && max - min == 1)
		{
			sol = i + 1;
		}

		else if (min == 1 && cnt[min] == 1 && rnum - 1 == cnt[max])
		{
			sol = i + 1;
		}
	}

	printf("%d\n", sol);

	return 0;
}