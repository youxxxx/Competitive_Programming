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
	int n;

	scanf("%d", &n);

	int cnt[200001] = { 0, };

	for (int i = 0; i < n - 1; i++)
	{
		int input;

		scanf("%d", &input);

		cnt[input]++;
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}