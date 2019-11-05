#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	long long l, r;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d", &l, &r);

		printf("%I64d %I64d\n", l, l * 2);
	}

	return 0;
}