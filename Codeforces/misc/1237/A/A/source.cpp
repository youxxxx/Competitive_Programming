#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<long long> arr;
	vector<long long> sol;
	vector<int> idx;
	long long input;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		sol.push_back(input / 2 - ((input < 0 && input % 2)));

		if (input % 2)
		{
			idx.push_back(i);
		}
	}

	for (i = 0; i < idx.size() / 2; i++)
	{
		sol[idx[i]] += 1;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d\n", sol[i]);
	}

	return 0;
}