#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	string a, b, c;
	char input[101];
	int i;
	int cnt = 0;
	int val;

	scanf("%d", &n);

	scanf("%s", input);
	a = input;
	scanf("%s", input);
	b = input;
	scanf("%s", input);
	c = input;

	for (i = 0; i < n; i++)
	{
		val = ((a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]));

		val -= !!val;

		cnt += val;
	}

	printf("%d\n", cnt);

	return 0;
}