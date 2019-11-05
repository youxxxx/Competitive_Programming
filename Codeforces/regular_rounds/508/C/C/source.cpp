#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long int n;
	long long int i, j;
	vector<long long int> a, b;
	long long int sa = 0, sb = 0;
	long long int input;

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		a.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		b.push_back(input);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (i = 0; i < n; i++)
	{
		if (b.empty())
		{
			sa += a.back();

			a.pop_back();
		}

		else if (a.empty())
		{
			b.pop_back();
		}

		else if (a.back() >= b.back())
		{
			sa += a.back();

			a.pop_back();
		}

		else
		{
			b.pop_back();
		}

		if (a.empty())
		{
			sb += b.back();

			b.pop_back();
		}

		else if (b.empty())
		{
			a.pop_back();
		}

		else if (b.back() >= a.back())
		{
			sb += b.back();

			b.pop_back();
		}

		else
		{
			a.pop_back();
		}
	}

	printf("%I64d", sa - sb);

	return 0;
}