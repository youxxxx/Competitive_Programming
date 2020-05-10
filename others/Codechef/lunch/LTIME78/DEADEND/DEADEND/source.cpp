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
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		if (n == 1)
		{
			printf("1\n");

			continue;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			if (i > 0 && arr[i] == arr[i - 1] + 1)
			{
				continue;
			}
			
			if (i < n - 1)
			{
				if (arr[i] == arr[i + 1] - 1)
				{
					i++;

					continue;
				}

				if (arr[i] == arr[i + 1] - 2)
				{
					i++;

					cnt++;

					continue;
				}
			}

			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}