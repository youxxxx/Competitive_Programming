#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int i;
	vector<int> arr;
	int t;
	long long a, res;
	
	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		res = 1;
		
		scanf("%I64d", &a);

		while (a)
		{
			res = res << (a % 2);

			a = a >> 1;
		}

		printf("%I64d\n", res);
	}

	return 0;
}