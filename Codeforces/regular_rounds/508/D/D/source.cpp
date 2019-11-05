#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<long long int> slime;
	long long int input, sum = 0;
	bool allneg = true, allpos = true;
	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		slime.push_back(input);
	}

	sort(slime.begin(), slime.end());

	for (i = 0; i < n; i++)
	{
		if (slime[i] > 0)
		{
			allneg = false;
		}
		
		else if (slime[i] < 0)
		{
			allpos = false;
		}

		sum += abs(slime[i]);
	}

	if (allneg)
	{
		sum += slime.back() * 2;
	}

	else if (allpos)
	{
		sum -= slime.front() * 2;
	}

	printf("%I64d", sum);

	return 0;
}