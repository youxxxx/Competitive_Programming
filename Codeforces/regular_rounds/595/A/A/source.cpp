#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int tc, cases;
	int last;
	int two;
	int i;
	int n;
	int input;
	vector<int> arr;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		arr.clear();

		two = 0;

		last = -1;

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		two = 0;

		for (i = 0; i < n - 1; i++)
		{
			if (arr[i] == arr[i + 1] - 1)
			{
				two = 1;

				break;
			}
		}

		printf("%d\n", two + 1);
	}

	return 0;
}