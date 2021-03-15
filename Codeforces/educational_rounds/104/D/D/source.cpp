#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<long long> arr;

	for (long long i = 3; i * i / 2 + 1 <= 1000000000; i+=2)
	{
		const int b = i*i / 2;
		const int c = b + 1;

		if (c*c - b*b == b + c)
		{
			arr.push_back(c);
		}
	}

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;

		scanf("%lld", &n);

		vector<long long>::iterator ret = upper_bound(arr.begin(), arr.end(), n);

		printf("%d\n", (int)(ret - arr.begin()));
	}

	return 0;
}