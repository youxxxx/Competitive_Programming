#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long r, s, p;
	long long n, k;
	char input[100001];
	string str;

	scanf("%lld %lld", &n, &k);
	scanf("%lld %lld %lld", &r, &s, &p);

	scanf("%s", input);
	str = input;

	long long sol = 0;

	for (long long i = 0; i < k; i++)
	{
		switch (str[i])
		{
		case 'r':
			sol += p;
			break;
		case 's':
			sol += r;
			break;
		case 'p':
			sol += s;
			break;
		}
	}

	for (long long i = k; i < n; i++)
	{
		if (str[i] == str[i - k])
		{
			str[i] = 'x';
		}

		else
		{
			switch (str[i])
			{
			case 'r':
				sol += p;
				break;
			case 's':
				sol += r;
				break;
			case 'p':
				sol += s;
				break;
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}