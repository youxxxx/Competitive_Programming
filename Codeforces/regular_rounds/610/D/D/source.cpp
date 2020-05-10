#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	string stra,strb;

	for (int i = 0; i < 300; i++)
	{
		stra.push_back('a');
		strb.push_back('b');
	}

	int numofa, numofb;
	int input;
	int n;

	printf("%s\n", stra.c_str());
	fflush(stdout);
	scanf("%d", &input);
	numofa = 300 - input;
	printf("%s\n", strb.c_str());
	fflush(stdout);
	scanf("%d", &input);
	numofb = 300 - input;

	string base;

	for (int i = 0; i < numofa; i++)
	{
		base.push_back('a');
	}

	for (int i = 0; i < numofb; i++)
	{
		base.push_back('b');
	}

	n = numofa + numofb;

	printf("%s\n", base.c_str());
	fflush(stdout);
	scanf("%d", &input);

	if (input == 0 || input == -1)
	{
		return 0;
	}

	int baseval;
	int target = 0;

	baseval = input;

	bool check[301] = { 0, };
	char temp;

	check[0] = true;

	bool correct[301] = { 0, }, wrong[301] = { 0, };

	for (int i = target + 1; i < n; i++)
	{
		if (base[target] == base[i])
		{
			continue;
		}

		check[i] = true;

		temp = base[target];
		base[target] = base[i];
		base[i] = temp;

		printf("%s\n", base.c_str());
		fflush(stdout);
		scanf("%d", &input);

		if (input == 0 || input == -1)
		{
			return 0;
		}

		if (input == baseval + 2)
		{
			correct[target] = true;

			correct[i] = true;
		}

		else if (input == baseval - 2)
		{
			wrong[target] = true;

			wrong[i] = true;
		}

		temp = base[target];
		base[target] = base[i];
		base[i] = temp;
	}

	for (int i = 1; i < n; i++)
	{
		if (check[i] && !correct[i] && !wrong[i])
		{
			if (correct[0])
			{
				wrong[i] = true;
			}

			else
			{
				correct[i] = true;
			}
		}
	}

	int target2;

	for (int i = 1; i < n; i++)
	{
		if (base[i] != base[target])
		{
			target2 = i;

			break;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (check[i] || i == target2)
		{
			continue;
		}

		temp = base[target2];
		base[target2] = base[i];
		base[i] = temp;

		printf("%s\n", base.c_str());
		fflush(stdout);
		scanf("%d", &input);

		if (input == 0 || input == -1)
		{
			return 0;
		}

		if (input == baseval + 2)
		{
			correct[i] = true;
		}

		else if (input == baseval - 2)
		{
			wrong[i] = true;
		}

		else
		{
			if (wrong[target2])
			{
				correct[i] = true;
			}

			else
			{
				wrong[i] = true;
			}
		}

		temp = base[target2];
		base[target2] = base[i];
		base[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		if (wrong[i])
		{
			base[i] = ('b' - base[i]) + 'a';
		}
	}

	printf("%s\n", base.c_str());
	fflush(stdout);
	scanf("%d", &input);

	return 0;
}