#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	long long a, b;
	long long sol;

	scanf("%lld %lld", &a, &b);

	a--;

	switch (b % 4)
	{
	case 0:
		sol = b;
		break;
	case 1:
		sol = 1;
		break;
	case 2:
		sol = b + 1;
		break;
	case 3:
		sol = 0;
		break;
	}

	if (a >= 0)
	{
		switch (a % 4)
		{
		case 0:
			sol ^= a;
			break;
		case 1:
			sol ^= 1;
			break;
		case 2:
			sol ^= a + 1;
			break;
		case 3:
			sol ^= 0;
			break;
		}
	}

	printf("%lld\n", sol);

	return 0;
}