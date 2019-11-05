#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	char input[200001];
	vector<pair<long long, char>> arr;
	string str;
	long long i;
	long long start = 0;
	long long sol;

	scanf("%I64d", &n);

	scanf("%s", input);

	str = input;

	/*
	if (n == 1)
	{
		prlong longf("0\n");

		return 0;
	}
	*/

	for (i = 1; i < n; i++)
	{
		if (str[i] != str[i - 1])
		{
			arr.push_back(pair<long long, char>(i - start, str[i - 1]));

			start = i;
		}
	}

	arr.push_back(pair<long long, char>(n - start, str[n - 1]));
/*
	if (arr.size() == 1)
	{
		sol = (n*(n + 1) / 2) % 998244353;
	}
	
	else
	{
	}
*/

	if (arr.size() == 2)
	{
		sol = (n + 1) % 998244353;
	}

	else if (arr[0].second != arr[arr.size() - 1].second)
	{
		sol = (arr[0].first + arr[arr.size() - 1].first + 1) % 998244353;
	}

	else
	{
		sol = ((arr[0].first + 1) * (arr[arr.size() - 1].first + 1)) % 998244353;
	}

	printf("%I64d\n", sol);

	return 0;
}