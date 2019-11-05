#include<cstdio>
#include<cmath>
#include<string>
#define H 10007

using namespace std;

string htable[H];
int cnt[H] = { 0, };
int trycnt[H] = { 0, };

int hvalue(string &str)
{
	int i;
	int rvalue = 0;

	for (i = 0; i < str.size(); i++)
	{
		rvalue = (rvalue * 26 + str[i] - 'a') % H;
	}

	return rvalue;
}

int put(string &str, int wave)
{
	int index;
	int rvalue;

	index = hvalue(str);

	while (!htable[index].empty() && htable[index] != str)
	{
		htable[index] = str;

		index = (index + 1) % H;
	}

	if (!cnt[index])
	{
		cnt[index] = 1;

		rvalue = 1;
	}

	else
	{
		rvalue = 0;
	}

	/*
	if (trycnt[index] != wave)
	{
		trycnt[index] = wave;

		cnt[index] = 1;

		rvalue = 1;
	}

	else
	{
		rvalue = ++cnt[index];
	}
	*/

	return rvalue;
}

int main()
{
	int n, m;
	int i;
	int type;
	char input[41];
	string str;
	int nth = 0;
	int max = 0;
	int sol = 0;
	bool nonew = false;
	int ret;
	int tot = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &type);

		if (type == 1)
		{
			if (!nonew)
			{
				nth++;

				sol += max;

				max = 0;
			}
			nonew = true;
		}

		else
		{
			scanf("%s", input);

			str = input;

			ret = put(str, nth);

			tot += ret;

			/*
			if (ret > max)
			{
				max = ret;
			}
			*/

			nonew = false;
		}
	}
	/*
	if (!nonew)
	{
		nth++;

		sol += max;
	}
	*/

	printf("%d\n", tot < nth ? tot : nth);

	return 0;
}