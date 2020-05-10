#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<int> arr;

		for (int i = 0; i < 3; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		if (arr[2] >= arr[1] + arr[0])
		{
			printf("%d\n", arr[0] + arr[1]);

			continue;
		}

		int sol = 0;

		sol += arr[1] - arr[0];

		arr[1] = arr[0];
		arr[2] -= sol;

		sol += arr[2] + (arr[0] * 2 - arr[2]) / 2;

		printf("%d\n", sol);
	}

	return 0;
}