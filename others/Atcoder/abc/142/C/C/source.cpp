#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	int i;
	int cnt = 0;
	int input;
	vector<pair<int, int>> arr;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(make_pair(input, i));
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i].second + 1);
	}

	return 0;
}