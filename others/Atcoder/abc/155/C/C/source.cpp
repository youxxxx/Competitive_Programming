#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	map<string, int> list;

	int lmax = 0;

	for (int i = 0; i < n; i++)
	{
		char input[20];

		scanf("%s", input);

		string str;

		str = input;

		map<string, int>::iterator ret;
		
		ret = list.find(str);

		int val;

		if (ret == list.end())
		{
			val = 1;

			list[str] = 1;
		}

		else
		{
			val = ++ret->second;
		}

		if (val > lmax)
		{
			lmax = val;
		}
	}

	for (map<string, int>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (it->second == lmax)
		{
			printf("%s\n", it->first.c_str());
		}
	}

	return 0;
}