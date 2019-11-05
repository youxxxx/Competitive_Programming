#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	int val[200001], ch[200001];
	int i;
	int input;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		val[input] = i;
	}

	scanf("%d", &input);

	for (i = 1; i <= input; i++)
	{
		ch[i] = 1;
	}

	for (i = 1; i < n; i++)
	{
		scanf("%d", &input);
	}
}