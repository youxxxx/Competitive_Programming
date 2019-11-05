#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n, i;
	int pw;
	vector<pair<int, int>> arr;

	arr.push_back(pair<int, int>(1, 2));
	arr.push_back(pair<int, int>(1, 4));
	pw = 4;

	for (i = 2; i < 25; i++)
	{
		pw *= 2;

		arr.push_back(pair<int, int>(arr[i - 2].first * 2 + arr[i - 1].first, pw));
	}

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		printf("%d %d ", arr[n - 1].first, arr[n - 1].second);
	}

	return 0;
}