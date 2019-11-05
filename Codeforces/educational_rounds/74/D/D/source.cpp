#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main()
{
	long long n;
	string str;
	char input[300001];
	vector<long long> arr;
	long long cnt = 1;
	long long i;
	char cur;
	long long base, sum = 0;

	scanf("%lld", &n);
	scanf("%s", input);
	str = input;

	cur = str[0];

	for (i = 1; i < n; i++)
	{
		if (str[i] != cur)
		{
			arr.push_back(cnt);

			cur = str[i];

			cnt = 1;
		}

		else
		{
			cnt++;
		}
	}

	arr.push_back(cnt);

	base = n*(n - 1) / 2;

	for (i = 0; i < arr.size() - 1; i++)
	{
		sum += arr[i] + arr[i + 1] - 1;
	}

	printf("%lld\n", base - sum);

	return 0;
}