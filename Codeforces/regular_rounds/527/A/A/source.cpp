#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n, k;
	int i, j;
	string res;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &k);

		for (i = 0; i < k; i++)
		{
			for (j = 0; j < n / k; j++)
			{
				res.push_back('a' + i);
			}
		}

		for (j = 0; j < n - (n / k * k); j++)
		{
			res.push_back('a');
		}

		printf("%s\n", res.c_str());

		res.clear();
	}

	return 0;
}