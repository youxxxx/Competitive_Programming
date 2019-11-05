#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, k;
	int i;
	vector<int> arr[101];
	int pw[101];
	int max[101] = { 0, };
	int midx[101] = { 0, };
	int school[101];
	int cnt = 0;
	vector<int> list;

	int input;

	scanf("%d %d %d", &n, &m, &k);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		pw[i] = input;
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		if (pw[i] > max[input])
		{
			max[input] = pw[i];

			midx[input] = i;
		}

		school[i] = input;
	}
	
	for (i = 0; i < k; i++)
	{
		scanf("%d", &input);

		if (max[school[input]] != pw[input])
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}