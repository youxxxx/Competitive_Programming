#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	map<string, int> list;
	int acc = 0;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char input[101];
		string str;
		int val;

		scanf("%s %d", input, &val);

		str = input;

		acc += val;

		list[str] = acc;
	}

	char input[101];
	string str;

	scanf("%s", input);
	str = input;

	int sol;

	sol = list[str];

	printf("%d\n", acc - sol);

	return 0;
}