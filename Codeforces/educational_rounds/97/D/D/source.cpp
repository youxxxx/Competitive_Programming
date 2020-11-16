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

		int lmax = 0;
		int sol = 1;

		int ptr = 1;
		int arr[200001];
		arr[1] = 0;
		int prev = 0;

		int input;
		scanf("%d", &input);
		
		for (int i = 2; i <= n; i++)
		{
			int input;

			scanf("%d", &input);

			if (input < prev)
			{
				ptr++;
			}

			prev = input;

			arr[i] = arr[ptr] + 1;
		}

		printf("%d\n", arr[n]);
	}

	return 0;
}