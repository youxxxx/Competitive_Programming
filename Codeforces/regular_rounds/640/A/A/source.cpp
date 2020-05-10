#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);
		int base = 1;
		vector<int> arr;

		while (n)
		{
			if (n % 10)
			{
				arr.push_back(n % 10 * base);
			}

			n /= 10;
			base *= 10;
		}

		printf("%d\n", arr.size());

		for (int i = 0; i < arr.size(); i++)
		{
			printf("%d ", arr[i]);
		}

		printf("\n");
	}

	return 0;
}