#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;

		int temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int lcm(int a, int b)
{
	return a*b / gcd(a, b);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[21];

		scanf("%s", input);
		const string s = input;
		const int n = s.size();
		scanf("%s", input);
		const string t = input;
		const int m = t.size();

		int l = lcm(n, m);

		string sol;

		for (int i = 0; i < l / n; i++)
		{
			sol.append(s);
		}

		bool valid = true;

		for (int i = 0; i < l; i++)
		{
			if (sol[i] != t[i%m])
			{
				valid = false;

				break;
			}
		}

		if (valid)
		{
			printf("%s\n", sol.c_str());
		}

		else
		{
			printf("-1\n");
		}
	}

	return 0;
}