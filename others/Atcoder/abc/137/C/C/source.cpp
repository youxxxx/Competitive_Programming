#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	vector<string> arr;
	char input[20];
	string str;
	long long i, prev, sol = 0;

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		sort(str.begin(), str.end());

		arr.push_back(str);
	}

	sort(arr.begin(), arr.end());

	prev = 0;

	for (i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			sol += (i - prev)*(i - prev - 1) / 2;

			prev = i;
		}
	}

	sol += (i - prev)*(i - prev - 1) / 2;

	printf("%lld\n", sol);

	return 0;
}