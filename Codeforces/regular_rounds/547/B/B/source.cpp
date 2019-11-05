#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	int cnt = 0;
	vector<int> arr;
	int input;
	int i;
	int lmax = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		cnt = cnt*input + input;

		if (cnt > lmax)
		{
			lmax = cnt;
		}

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		cnt = cnt*arr[i] + arr[i];

		if (cnt > lmax)
		{
			lmax = cnt;
		}
	}

	printf("%d\n", lmax);

	return 0;
}