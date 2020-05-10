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

		printf("%d\n", (arr[2] - arr[0] - 2 >= 0 ? arr[2] - arr[0] - 2 : 0) * 2);
	}

	return 0;
}