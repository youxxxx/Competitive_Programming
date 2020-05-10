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
	int cases;

	scanf("%d", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		char input[50001];
		string str;

		scanf("%s", input);
		str = input;
		string a, b;
		int bit = 1;

		for (int i = 0; i < n; i++)
		{
			switch (str[i])
			{
			case '2':
				if (bit)
				{
					a.push_back('1');
					b.push_back('1');
				}

				else
				{
					a.push_back('0');
					b.push_back('2');
				}
				break;
			case '0':
				a.push_back('0');
				b.push_back('0');
				break;
			default:
				a.push_back('0' + bit);
				b.push_back('0' + !bit);
				bit = 0;
				break;
			}
		}

		printf("%s\n%s\n", a.c_str(), b.c_str());
	}

	return 0;
}