#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	vector<int> inc;
	int i;
	int input;
	int size;
	int sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (i = n - 1; i >= 1; i--)
	{
		if (arr[i] == arr[i - 1])
		{
			if (!inc.empty() && inc.front() == arr[i])
			{
				printf("NO\n");

				return 0;
			}

			inc.insert(inc.begin(),arr[i]);

			arr.erase(arr.begin() + i);
		}
	}

	printf("YES\n%d\n", inc.size());

	for (i = 0; i < inc.size(); i++)
	{
		printf("%d ", inc[i]);
	}

	printf("\n%d\n", arr.size());

	for (i = arr.size() - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}