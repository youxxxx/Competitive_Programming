#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<int> arr;
		int n;

		scanf("%d", &n);

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);

			cnt += input % 2;
		}

		if (!(cnt % 2))
		{
			printf("YES\n");
		}


		else
		{
			sort(arr.begin(), arr.end());

			bool found = false;

			for (int i = 0; i < n - 1; i++)
			{
				if (arr[i + 1] - arr[i] == 1)
				{
					found = true;

					break;
				}
			}

			if (found)
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}
		}
	}

	return 0;
}