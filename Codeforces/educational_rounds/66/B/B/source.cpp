#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	char input[10];
	string str;
	int n;
	int i;
	long long val = 0;
	stack<long long> s;
	long long mult, prod;
	bool of = false;

	scanf("%d", &n);

	s.push(1);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		if (str == "for")
		{
			scanf("%lld", &mult);

			if (s.top()*mult < 4294967296)
			{
				s.push(s.top()*mult);
			}

			else
			{
				s.push(4294967296);
			}
		}

		else if (str == "add")
		{
			if (!of)
			{
				val += s.top();

				if (val >= 4294967296)
				{
					of = true;
				}
			}
		}

		else
		{
			s.pop();
		}
	}

	if (of)
	{
		printf("OVERFLOW!!!\n");
	}

	else
	{
		printf("%lld\n", val);
	}

	return 0;
}