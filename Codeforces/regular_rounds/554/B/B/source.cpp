#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int x;
	int bit[21];
	int temp;
	int i = 0;
	int n;
	int pw = 1;
	vector<int> op;
	bool full = true;

	scanf("%d", &x);

	temp = x;

	while (temp)
	{
		bit[i++] = temp % 2;

		if (!(temp % 2))
		{
			full = false;
		}

		temp /= 2;

		pw *= 2;
	}

	if (full)
	{
		printf("0\n");

		return 0;
	}

	n = i;

	for (i = n - 1; i >= 1; i--)
	{
		pw /= 2;

		if (!(x%pw))
		{
			op.push_back(i - 1);

			x ^= pw / 2 - 1;

			x++;
		}

		else if (!(pw&x))
		{
			x ^= (pw - 1);

			x++;

			op.push_back(i + 1);
		}

		if (x == 1)
		{
			break;
		}
	}

	if (!(x % 2))
	{
		op.push_back(0);
	}

	printf("%d\n", op.size() * 2);

	for (i = 0; i < op.size(); i++)
	{
		printf("%d ", op[i]);
	}

	return 0;
}