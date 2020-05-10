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
		int h, m;

		scanf("%d %d", &h, &m);

		printf("%d\n", (23 - h) * 60 + (60 - m));
	}

	return 0;
}