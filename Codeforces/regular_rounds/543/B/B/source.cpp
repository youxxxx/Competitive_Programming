#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n;
	int i, j;
	vector<int> arr;
	map<int, int> sum;
	map<int, int>::iterator it;
	std::pair<std::map<int, int>::iterator, bool> ret;
	int input;
	int lmax = 0;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			ret = sum.insert(pair<int,int>(arr[i] + arr[j],1));

			if (!ret.second)
			{
				ret.first->second++;
			}
		}
	}

	for (it = sum.begin(); it != sum.end(); it++)
	{
		if (it->second > lmax)
		{
			lmax = it->second;
		}
	}

	printf("%d\n", lmax);

	return 0;
}