#include<cstdio>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	int i;
	vector<int> arr;
	int cur = 0, rem;
	set<int> res;
	set<int>::iterator it;

	scanf("%d %d", &n, &k);

	if (k * 2 + 1 >= n)
	{
		printf("1\n%d", n / 2 + 1);

		return 0;
	}

	rem = n % (k * 2 + 1);

	if (rem == 0)
	{
		for (i = 0; i < n / (k * 2 + 1); i++)
		{
			arr.push_back((k * 2 + 1)*i + (k + 1));
		}
	}

	else if (rem >= k + 1)
	{
		for (i = 0; i < n / (k * 2 + 1) + 1; i++)
		{
			arr.push_back((k * 2 + 1)*i + (rem - k));
		}
	}

	else
	{
		for (i = 0; i < n / (k * 2 + 1) + 1; i++)
		{
			arr.push_back((k * 2 + 1)*i + rem);
		}
	}

	printf("%d\n", arr.size());

	for (i = 0; i < arr.size(); i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}