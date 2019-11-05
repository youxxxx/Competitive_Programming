#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int input;
	int cnt[101] = { 0, };
	int i;
	int req = 0;
	vector<int> solo;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		cnt[input]++;
	}

	for (i = 1; i <= 100; i++)
	{
		if (cnt[i] % 2)
		{
			solo.push_back(i);
		}
	}

	for (i = 0; i < solo.size() / 2; i++)
	{
		req += solo[i * 2 + 1] - solo[i * 2];
	}

	printf("%d\n", req);

	return 0;
}