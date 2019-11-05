#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n;
	int i;
	vector<int> arr;
	int input;
	int cnt;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		cnt = 0;

		for (i = 0; i < n; i++)
		{
			if (arr[i] <= cnt)
			{
				cnt++;
			}
		}

		arr.clear();

		printf("%d\n", cnt);
	}

	return 0;
}