#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

long long dnc(long long bit, vector<long long> &arr)
{
	int n;

	n = arr.size();

	vector<long long> box[2];

	if (!bit)
	{
		return 0;
	}

	while (bit)
	{
		for (int i = 0; i < n; i++)
		{
			box[!!(bit&arr[i])].push_back(arr[i]);
		}

		if (!box[0].empty() && !box[1].empty())
		{
			break;
		}

		bit /= 2;

		box[0].clear();
		box[1].clear();
	}

	if (!bit)
	{
		return 0;
	}

	long long l, r;

	l = dnc(bit / 2, box[0]);
	r = dnc(bit / 2, box[1]);

	return bit + (l < r ? l : r);
}

int main()
{
	int n;

	scanf("%d", &n);

	vector<long long> arr;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);
	}

	long long bit;

	bit = 1 << 30;

	printf("%lld\n", dnc(bit, arr));

	return 0;
}