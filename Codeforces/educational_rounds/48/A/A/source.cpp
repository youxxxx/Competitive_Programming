#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	int i;
	int rem = 0;
	int input;
	vector<int> a;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		rem += input;

		a.push_back(rem / m);

		rem %= m;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}