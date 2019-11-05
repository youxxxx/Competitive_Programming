#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, tc;
	int n;
	vector<int> a,b;
	int i, j;
	int acnt[300001], bcnt[300001];
	int input;
	bool valid;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		valid = true;

		scanf("%d", &n);

		a.clear();
		b.clear();

		for (i = 1; i <= n; i++)
		{
			acnt[i] = bcnt[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			acnt[input]++;

			a.push_back(input);
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			bcnt[input]++;

			b.push_back(input);
		}

		for (i = 1; i <= n; i++)
		{
			if (acnt[i] != bcnt[i])
			{
				valid = false;

				break;
			}
		}

		if (!valid) 
		{
			printf("NO\n");

			continue;
		}

		j = 0;

		for (i = 0; i < n; i++)
		{
			if (a[i] < b[j])
			{
				if (acnt[b[j]] < bcnt[b[j]])
				{
					bcnt[b[j]]--;

					j++;
				}

				else
				{
					valid = false;

					break;
				}
			}

			else if (a[i] == b[j])
			{
				acnt[a[i]]--;
				bcnt[b[j]]--;

				j++;
			}

			else
			{
				acnt[a[i]]--;
			}
		}

		if (!valid)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");
	}

	return 0;
} 