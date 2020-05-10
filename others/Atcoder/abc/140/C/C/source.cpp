#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<long long> a, b;
	int i;
	long long input;
	long long sol = 0;

	scanf("%d", &n);

	for (i = 0; i < n - 1; i++)
	{
		scanf("%lld", &input);

		b.push_back(input);
	}

	sol += b[0];

	for (i = 1; i < n - 1; i++)
	{
		sol += b[i - 1] < b[i] ? b[i - 1] : b[i];
	}

	sol += b[n - 2];

	printf("%lld\n", sol);

	return 0;
}