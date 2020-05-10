#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n, k;
	string str;
	char input[100001];
	int i;
	int sol = 0;
	int cand = 0;
	int ptr = 1, ptr2;
	queue<int> state;
	bool phase = false;

	scanf("%d %d", &n, &k);

	scanf("%s", input);

	str = input;

	if (n == 1)
	{
		printf("0\n");

		return 0;
	}

	for (i = 0; i < n - 1; i++)
	{
		sol += (str[i] == str[i + 1]);
	}
	
	for (i = 1; i < n; i++)
	{
		cand += str[i] != str[i + 1];
	}

	if (cand % 2)
	{
		if (k >= cand / 2 + 1)
		{
			sol = n - 1;
		}

		else
		{
			sol += k * 2;
		}
	}

	else
	{
		if (k >= cand / 2)
		{
			sol = n - 1;
		}

		else
		{
			sol += k * 2;
		}
	}

	printf("%d\n", sol);

	return 0;
}