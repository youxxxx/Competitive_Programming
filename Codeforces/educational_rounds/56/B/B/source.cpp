#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int t;
	int i;
	char input[1001];
	string str;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%s", input);

		str = input;

		sort(str.begin(), str.end());

		if (str.front() == str.back())
		{
			printf("-1\n");
		}

		else
		{
			printf("%s\n", str.c_str());
		}
	}

	return 0;
}