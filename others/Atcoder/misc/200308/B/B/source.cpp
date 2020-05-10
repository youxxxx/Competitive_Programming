#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	int a, b, m;

	scanf("%d %d %d", &a, &b, &m);

	vector<int> ref, mic;

	ref.push_back(0);
	mic.push_back(0);

	int temp = 100001;
	int lmin = 0;

	for (int i = 0; i < a; i++)
	{
		int input;

		scanf("%d", &input);

		ref.push_back(input);

		if (input < temp)
		{
			temp = input;
		}
	}

	lmin += temp;

	temp = 100001;

	for (int i = 0; i < b; i++)
	{
		int input;

		scanf("%d", &input);

		mic.push_back(input);

		if (input < temp)
		{
			temp = input;
		}
	}

	lmin += temp;

	for (int i = 0; i < m; i++)
	{
		int ai, bi, ci;

		scanf("%d %d %d", &ai, &bi, &ci);

		if (ref[ai] + mic[bi] - ci < lmin)
		{
			lmin = ref[ai] + mic[bi] - ci;
		}
	}

	printf("%d\n", lmin);

	return 0;
}