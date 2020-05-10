#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int t, z;
	char input[102];
	string str, a, b;
	int i;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		for (i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] == '4')
			{
				a.insert(a.begin(),'1');
				b.insert(b.begin(),'3');
			}

			else
			{
				a.insert(a.begin(), '0');
				b.insert(b.begin(), str[i]);
			}
		}

		while (a.front() == '0')
		{
			a.erase(a.begin());
		}

		printf("Case #%d: %s %s\n", z + 1, a.c_str(), b.c_str());

		a.clear();
		b.clear();
	}

	return 0;
}