#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	int i;
	int input;
	int off = -1;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = 1; i < n - 1; i++)
	{
		if (!arr[i] && arr[i - 1] && arr[i + 1])
		{
			if (off != i - 1)
			{
				off = i + 1;

				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}