#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	int n;
	int ptr;
	vector<long long> arr;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		if (input == -1)
		{
			ptr = i;
		}

		arr.push_back(input);
	}

	int free, base, temp;
	vector<int> ub;

	free = (int)log2((double)(ptr + 1.1));
	base = (int)pow(2.0, (double)free);

	temp = base * 2;

	while (temp <= n)
	{
		ub.push_back(temp - 1);

		temp *= 2;
	}
	int prev = n;

	vector<long long> box;

	long long sol = 0;

	for (int i = ub.size() - 1; i >= 0; i--)
	{
		for (int j = prev - 1; j >= ub[i]; j--)
		{
			box.push_back(arr[j]);
		}

		sort(box.begin(), box.end());

		sol += box[0];

		box.erase(box.begin());

		prev = ub[i];
	}

	printf("%lld\n", sol);

	return 0;
}