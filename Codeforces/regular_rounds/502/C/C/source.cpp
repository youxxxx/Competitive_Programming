#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n;
	vector<int> seq;
	int i, j;
	int rt;

	scanf("%d", &n);
	rt = (int)sqrt((double)n);

	for (i = 1; i <= n / rt + !!(n%rt); i++)
	{
		for (j = rt - 1; j >= 0; j--)
		{
			if (i + (n/rt + !!(n%rt))*j <= n)
			{
				seq.push_back(i + (n/rt + !!(n%rt))*j);
			}			
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", seq[i]);
	}

		return 0;
}