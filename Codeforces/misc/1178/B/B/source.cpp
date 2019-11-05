#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	char input[1000001];
	string str;
	int i;
	long long sol = 0;
	long long phase[3] = { 0, };
	long long v, o;
	char last = ' ';

	scanf("%s", input);
	
	str = input;

	n = str.size();

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'v')
		{
			if (last == 'v')
			{
				v++;

				phase[0]++;

				phase[2] += phase[1];
			}

			else
			{
				v = 1;
				o = 0;
			}
		}

		else
		{
			if (last == 'o')
			{
				o++;

				phase[1] += phase[0];
			}

			else
			{
				o = 1;
				v = 0;

				phase[1] += phase[0];
			}
		}

		last = str[i];
	}

	printf("%lld\n", phase[2]);

	return 0;
}