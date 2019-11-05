#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	bool zero = false;
	int i;
	long long sol = 0, input;
	bool neg = false;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		if (input == 0)
		{
			zero = true;

			sol++;
		}

		else if (input < 0)
		{
			sol += abs(input) - 1;

			neg = !neg;
		}

		else
		{
			sol += input - 1;
		}
	}

	if (neg && !zero)
	{
		sol += 2;
	}

	printf("%lld\n", sol);

	return 0;
}
