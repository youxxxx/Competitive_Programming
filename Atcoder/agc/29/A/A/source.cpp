#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[200001];
	string str;
	long long sum = 0, cnt = 0;
	int i;

	scanf("%s", input);

	str = input;

	for (i = 0; i < str.size(); i++)
	{
		if (input[i] == 'W')
		{
			cnt++;

			sum += i;
		}
	}

	sum -= cnt*(cnt - 1) / 2;

	printf("%lld\n", sum);

	return 0;
}