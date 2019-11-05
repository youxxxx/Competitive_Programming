#include<cstdio>
#include<string>

using namespace std;

int main()
{
	string s, t, cand;
	char input[1000001];
	int target;
	int num = 0;
	int i, j, k;
	int cur;
	int cnt = 0;
	int not= -1;

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	target = s[0];

	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == target)
		{
			num++;
		}

		else if (not== -1)
		{
			not = i;
		}
	}

	if (not==-1)
	{
		if (t.size() % s.size())
		{
			printf("0\n");
		}

		else
		{
			printf("1\n");
		}

		return 0;
	}
		
	for (i = 1; i < (t.size() + num - 1) / num; i++)
	{
		cand.push_back(t[i - 1]);

		if ((t.size() - num*i) % (s.size() - num))
		{
			continue;
		}

		cur = i;

		not = -1;

		for (j = 1; j < s.size(); j++)
		{
			if (s[j] == target)
			{
				for (k = 0; k < i; k++)
				{
					if (t[cur + k] != t[k])
					{
						break;
					}
				}

				if (k != i)
				{
					break;
				}

				cur += i;
			}

			else
			{
				if (not == -1)
				{
					not = cur;

					if (i == (t.size() - i * num) / (s.size() - num))
					{
						for (k = 0; k < (t.size() - i * num) / (s.size() - num); k++)
						{
							if (t[cur + k] != t[k])
							{
								break;
							}
						}

						if (k == (t.size() - i * num) / (s.size() - num))
						{
							break;
						}
					}
				}

				else
				{
					for (k = 0; k < (t.size() - i * num) / (s.size() - num); k++)
					{
						if (t[cur + k] != t[k + not])
						{
							break;
						}
					}

					if (k != (t.size() - i * num) / (s.size() - num))
					{
						break;
					}
				}

				cur += (t.size() - i * num) / (s.size() - num);
			}
		}

		if (j == s.size())
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);
	
	return 0;
}