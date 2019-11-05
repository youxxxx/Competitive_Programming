#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	bool num[101] = { 0, };
	int i, j;
	int n;
	vector<int> arr;
	int input;
	int cnt = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n; i++)
	{
		if (!num[arr[i]])
		{
			for (j = 1; j <= 100 / arr[i]; j++)
			{
				num[arr[i] * j] = true;
			}

			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}