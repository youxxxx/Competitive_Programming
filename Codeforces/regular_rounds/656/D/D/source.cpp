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

string str;

int dnc(int l, int r, char val)
{
	if (l + 1 == r)
	{
		return val != str[l];
	}

	int cand1 = 0;

	for (int i = (l + r) / 2; i < r; i++)
	{
		cand1 += val != str[i];
	}

	cand1 += dnc(l, (l + r) / 2, val + 1);

	int cand2 = 0;

	for (int i = l; i < (l + r) / 2; i++)
	{
		cand2 += val != str[i];
	}

	cand2 += dnc((l + r) / 2, r, val + 1);

	return cand1 < cand2 ? cand1 : cand2;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char arr[200001];

		scanf("%d", &n);
		
		scanf("%s", arr);

		str = arr;

		printf("%d\n", dnc(0, n, 'a'));
	}

	return 0;
}