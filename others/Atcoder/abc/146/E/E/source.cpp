#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

int main()
{
	int n, k;
	vector<int> arr;
	long long cnt[200001] = { 0, };


	scanf("%d %d", &n, &k);

	k = n < k ? n : k;

	int acc = 0;

	cnt[0] = 1;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);

		acc += input - 1;

		acc %= k;

		cnt[acc]++;
	}

	long long sol = 0;
	
	for (int i = 0; i < k; i++)
	{
		sol += cnt[i] * (cnt[i] - 1) / 2;
	}

	printf("%lld\n", sol);
	
	return 0;
}