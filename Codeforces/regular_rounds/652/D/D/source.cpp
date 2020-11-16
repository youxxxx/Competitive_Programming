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

#define MOD 1000000007

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	long long mat[2][6] = { 0, };
	long long sol[2000001];

	sol[1] = 0;
	mat[1][0] = 1;
	mat[1][1] = 0;
	mat[1][2] = 0;
	mat[1][3] = 0;
	mat[1][4] = 0;
	mat[1][5] = 0;

	for (int i = 2; i <= 20; i++)
	{
		mat[i % 2][0] = (mat[!(i % 2)][4] * 2 % MOD + mat[!(i % 2)][3]) % MOD;
		mat[i % 2][1] = mat[!(i % 2)][0];
		mat[i % 2][2] = (mat[!(i % 2)][2] + mat[!(i % 2)][1]) % MOD;
		mat[i % 2][3] = (mat[!(i % 2)][1] * 2 % MOD + mat[!(i % 2)][0]) % MOD;
		mat[i % 2][4] = mat[!(i % 2)][3];
		mat[i % 2][5] = (mat[!(i % 2)][5] + mat[!(i % 2)][4]) % MOD;

		sol[i] = mat[i % 2][2 + !(i % 2) * 3] * 4 % MOD;

		if (mat[i % 2][2] < mat[i % 2][5])
		{
			printf("%d : <\n", i);
		}

		else if (mat[i % 2][2] > mat[i % 2][5])
		{
			printf("%d : >\n", i);
		}

		else
		{
			printf("%d : =\n", i);
		}
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		printf("%lld\n", sol[n]);
	}

	return 0;
}