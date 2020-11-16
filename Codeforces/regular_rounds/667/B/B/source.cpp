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
		long long a, b, x, y, n;

		scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &n);

		long long a1 = a;
		long long b1 = b;
		long long n1 = n;
		long long subt = min(a1 - x, n1);
		n1 -= subt;
		a1 -= subt;
		subt = min(b1 - y, n1);
		b1 -= subt;
		const long long cand1 = a1*b1;

		a1 = a;
		b1 = b;
		n1 = n;
		subt = min(b1 - y, n1);
		n1 -= subt;
		b1 -= subt;
		subt = min(a1 - x, n1);
		a1 -= subt;
		const long long cand2 = a1*b1;

		printf("%lld\n", min(cand1, cand2));
	}

	return 0;
}