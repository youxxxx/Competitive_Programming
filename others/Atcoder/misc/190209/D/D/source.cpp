#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long l;
	long long i;
	long long smin, nmin, emin, edmin;
	long long sol;
	long long input;
	vector<long long> arr;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &l);

	sol = 2 * l;

	for (i = 0; i < l; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	smin = nmin = emin = edmin = 0;

	for (i = 0; i < l; i++)
	{
		if (emin + (arr[i] % 2)< edmin + arr[i])
		{
			edmin = emin + (arr[i] % 2);
		}

		else
		{
			edmin += arr[i];

			if (edmin > 2 * l)
			{
				edmin = 2 * l;
			}
		}

		if (smin < emin + arr[i] % 2 + !arr[i])
		{
			emin = smin;
		}

		else
		{
			emin += arr[i] % 2 + !arr[i];
		}

		if (nmin < smin + !(arr[i] % 2))
		{
			smin = nmin;
		}

		else
		{
			smin += !(arr[i] % 2);
		}

		nmin += arr[i];

		if (nmin > l * 2)
		{z
			nmin = l * 2;
		}
	}

	if (nmin < sol)
	{
		sol = nmin;
	}

	if (smin < sol)
	{
		sol = smin;
	}

	if (emin < sol)
	{
		sol = emin;
	}

	if (edmin < sol)
	{
		sol = edmin;
	}

	/*
	smin = nmin = emin = edmin = 0;

	for (i = l - 1; i >= 0; i--)
	{
		if (emin + (arr[i] % 2)< edmin + arr[i])
		{
			edmin = emin + (arr[i] % 2);
		}

		else
		{
			edmin += arr[i];
		}

		if (smin < emin + arr[i] % 2 + !arr[i])
		{
			emin = smin;
		}

		else
		{
			emin += arr[i] % 2 + !arr[i];
		}

		if (nmin < smin + !(arr[i] % 2))
		{
			smin = nmin;
		}

		else
		{
			smin += !(arr[i] % 2);
		}

		nmin += arr[i];
	}

	if (nmin < sol)
	{
		sol = nmin;
	}

	if (smin < sol)
	{
		sol = smin;
	}

	if (emin < sol)
	{
		sol = emin;
	}

	if (edmin < sol)
	{
		sol = edmin;
	}
	*/

	printf("%lld\n", sol);

	return 0;
}