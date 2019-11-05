#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	string str;
	vector<int> arr;
	int input;
	int i;
	int t, z;
	long long a, b, k;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d %I64d", &a, &b, &k);

		printf("%I64d\n", (a - b)*(k / 2) + a*(k % 2));
	}

	return 0;
}