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
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int arr[101];
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		int mex[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			if (mex[0] == arr[i])
			{
				mex[0]++;
			}

			else if (mex[1] == arr[i])
			{
				mex[1]++;
			}
		}

		printf("%d\n", mex[0] + mex[1]);
	}

	return 0;
}