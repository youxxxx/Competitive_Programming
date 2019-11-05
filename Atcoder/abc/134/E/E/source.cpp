#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	vector<int> arr, sol;
	vector<int>::iterator it;
	int i;
	int input;
	int lmin = 1000000001;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sol.push_back(arr[0]);

	for (i = 1; i < n; i++)
	{
		it = lower_bound(sol.begin(), sol.end(), arr[i]);

		if (it == sol.begin())
		{
			sol.insert(sol.begin(), arr[i]);
		}

		else
		{
			*--it = arr[i];
		}
	}

	printf("%d\n", sol.size());

	return 0;
}