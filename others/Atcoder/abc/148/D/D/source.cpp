#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == cnt + 1)
		{
			cnt = arr[i];
		}
	}

	if (cnt == 0)
	{
		printf("%d\n", -1);
	}

	else
	{
		printf("%d\n", n - cnt);
	}

	return 0;
}
