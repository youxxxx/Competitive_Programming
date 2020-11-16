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

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int arr[51];

		int start=-1, end;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (arr[i])
			{
				if (start == -1)
				{
					start = i;
				}

				end = i;
			}
		}
		
		int sol = 0;

		for (int i = start; i <= end; i++)
		{
			sol += !arr[i];
		}

		printf("%d\n", sol);
	}

	return 0;
}