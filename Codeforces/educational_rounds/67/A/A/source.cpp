#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, z;
	int i;
	int s, t, n, ex;

	scanf("%d", &tc);

	for (z = 0; z < tc; z++)
	{
		scanf("%d %d %d", &n, &s, &t);

		ex = s + t - n;

		s -= ex;
		t -= ex;

		printf("%d\n", (s > t ? s : t) + 1);
	}

	return 0;
}