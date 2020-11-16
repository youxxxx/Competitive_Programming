#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

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

		char input[200001];

		scanf("%s", input);

		string str = input;

		queue<int> q[2];
		int ptr = 0;
		int sol[200001];

		for (int i = 0; i < n; i++)
		{
			const int bit = str[i] - '0';

			if (q[bit].empty())
			{
				ptr++;

				sol[i] = ptr;

				q[!bit].push(ptr);
			}

			else
			{
				sol[i] = q[bit].front();

				q[!bit].push(q[bit].front());

				q[bit].pop();
			}
		}

		printf("%d\n", ptr);

		for (int i = 0; i < n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}