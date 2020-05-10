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
		int n;
		int ub;
		vector<int> arr, arr2;

		scanf("%d", &n);

		ub = (int)sqrt((double)n);

		for (int i = 1; i <= ub; i++)
		{
			arr.push_back(n / i);
		}

		int ub2;

		ub2 = arr.size() - 1;

		if (n / arr.back() != arr.back())
		{
			arr.push_back(n / arr.back());
		}

		for (int i = 0; i < ub2; i++)
		{
			arr2.push_back(n / arr[i]);
		}

		printf("%d\n", arr.size() + arr2.size() + 1);

		printf("0");

		for (int i = 0; i < arr2.size(); i++)
		{
			printf(" %d", arr2[i]);
		}

		for (int i = arr.size() - 1; i >= 0; i--)
		{
			printf(" %d", arr[i]);
		}

		printf("\n");
	}

	return 0;
}