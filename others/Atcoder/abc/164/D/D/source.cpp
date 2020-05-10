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
	set<string> list;
	long long left[2][2019] = { 0, };
	string str;
	char input[200001];

	scanf("%s", &input);
	str = input;

	const int n = str.size();

	long long sol = 0;

	for (int i = 0; i < n; i++)
	{
		int num;

		num = str[i] - '0';

		for (int j = 0; j < 2019; j++)
		{
			left[i % 2][(j * 10 + num) % 2019] = left[!(i % 2)][j];
		}

		left[i % 2][num]++;

		sol += left[i % 2][0];
	}

	printf("%lld\n", sol);

	return 0;
}