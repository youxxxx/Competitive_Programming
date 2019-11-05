#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int input1, input2;
	int n, m;
	int i;
	long long int max = 0;
	int sol = 0;
	vector<int> songs;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);
		
		max += input1;

		songs.push_back(input1 - input2);
	}

	max -= m;

	sort(songs.begin(), songs.end());

	if (max > 0)
	{
		for (i = 0; i < n; i++)
		{
			max -= songs[n - i - 1];

			if (max <= 0)
			{
				break;
			}
		}

		if (i == n)
		{
			sol = -1;
		}

		else
		{
			sol = i + 1;
		}
	}

	printf("%d", sol);

	return 0;
}