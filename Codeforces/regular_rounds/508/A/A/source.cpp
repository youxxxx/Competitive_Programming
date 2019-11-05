#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	int i, j;
	string s;
	char input[100001];
	int cnt[26] = { 0, };
	int lmin;
	int max = 0;

	scanf("%d %d", &n, &k);
	scanf("%s", input);
	s = input;

	for (i = 0; i < n; i++)
	{
		cnt[s[i] -= 'A']++;

		lmin = 100001;

		for (j = 0; j < k; j++)
		{
			if (cnt[j] < lmin)
			{
				lmin = cnt[j];
			}
		}

		max = lmin*k;
	}

	printf("%d", max);

	return 0;
}