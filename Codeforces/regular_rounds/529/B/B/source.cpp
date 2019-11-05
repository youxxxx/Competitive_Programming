#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	int input;
	int mx;
	int sol;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	mx = arr[n - 1] - arr[n - 2] > arr[1] - arr[0] ? arr[n - 1] - arr[n - 2] : arr[1] - arr[0];

	sol = arr[n - 1] - arr[0] - mx;

	printf("%d\n", sol);

	return 0;
}