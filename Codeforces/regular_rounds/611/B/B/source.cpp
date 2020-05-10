#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

class comp
{
public:
	bool operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first < b.first;
	}
};

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		int q;

		q = n / m;

		printf("%d\n", m*q + m / 2 < n ? m*q + m / 2 : n);
	}

	return 0;
}