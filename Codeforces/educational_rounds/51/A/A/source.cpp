#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int t,n;
	char input[200];
	int cnt[3], cand[3];
	int stat[200];
	string str;
	int i, j, index[2], min, temp, temp2;
	int res, ab;
	bool one;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%s", input);

		str.clear();

		str = input;

		n = str.size();

		res = ab = -1;

		one = false;

		for (j = 0; j < 3; j++)
		{
			cnt[j] = 0;
		}

		for (j = 0; j < n; j++)
		{
			if (str[j] >= '0'&&str[j] <= '9')
			{
				cnt[0]++;

				stat[j] = 0;
			}

			else if (str[j] >= 'A'&&str[j] <= 'Z')
			{
				cnt[1]++;

				stat[j] = 1;
			}

			else
			{
				cnt[2]++;

				stat[j] = 2;
			}
		}



		if (!(cnt[0] && cnt[1] && cnt[2]))
		{
			if (!cnt[0] && !cnt[1])
			{
				str[0] = '0';
				str[1] = 'A';
			}

			else if (!cnt[0] && !cnt[2])
			{
				str[0] = '0';
				str[1] = 'a';
			}

			else if (!cnt[1] && !cnt[2])
			{
				str[0] = 'A';
				str[1] = 'a';
			}

			else if (!cnt[0])
			{
				if (cnt[1] == 1)
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 2);

					str[temp] = '0';
				}

				else if (cnt[2] == 1)
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 1);

					str[temp] = '0';
				}

				else
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 1 && stat[temp]!=2);

					str[temp] = '0';
				}
			}

			else if (!cnt[1])
			{
				if (cnt[0] == 1)
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 2);

					str[temp] = 'A';
				}

				else if (cnt[2] == 1)
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 0);

					str[temp] = 'A';
				}

				else
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 0 && stat[temp] != 2);

					str[temp] = 'A';
				}
			}

			else if (!cnt[2])
			{
				if (cnt[0] == 1)
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 1);

					str[temp] = 'a';
				}

				else if (cnt[1] == 1)
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 0);

					str[temp] = 'a';
				}

				else
				{
					temp = -1;

					while (++temp < n&&stat[temp] != 0 && stat[temp] != 1);

					str[temp] = 'a';
				}
			}

			/*
			else if (!cnt[0])
			{
				if (cnt[1] == 1)
				{
					res = 1;
					ab = 2;
					one = true;
				}

				else if (cnt[1] == 2)
				{
					res = 1;
					ab = 2;
				}

				else if (cnt[2] == 1)
				{
					res = 2;
					ab = 1;
					one = true;
				}

				else if (cnt[2] == 2)
				{
					res = 2;
					ab = 1;
				}

				else
				{
					str[0] = 'A';
					str[1] = 'a';
				}
			}

			else if (!cnt[1])
			{
				if (cnt[0] == 1)
				{
					res = 0;
					ab = 2;
					one = true;
				}

				else if (cnt[0] == 2)
				{
					res = 0;
					ab = 2;
				}

				else if (cnt[2] == 1)
				{
					res = 2;
					ab = 0;
					one = true;
				}

				else if (cnt[2] == 2)
				{
					res = 2;
					ab = 0;
				}

				else
				{
					str[0] = '0';
					str[1] = 'a';
				}
			}

			else if (!cnt[2])
			{
				if (cnt[0] == 1)
				{
					res = 0;
					ab = 1;
					one = true;
				}

				else if (cnt[0] == 2)
				{
					res = 0;
					ab = 1;
				}

				else if (cnt[1] == 1)
				{
					res = 1;
					ab = 0;
					one = true;
				}

				else if (cnt[1] == 2)
				{
					res = 1;
					ab = 0;
				}

				else
				{
					str[0] = '0';
					str[1] = 'A';
				}
			}

			if (res != -1)
			{
				if (one)
				{
					for(j=0;)
				}

				else
				{
					temp = -1;

					for (j = 0; j < 2; j++)
					{
						while (++temp < n&&stat[temp] != res);

						temp2 = temp;

						while (--temp2 >= 0 && stat[temp2] != ab);

						if (temp2 >= 0 && temp - temp2 < min)
						{
							min = temp - temp2;

							index[0] = temp;
							index[1] = temp2;
						}

						temp2 = temp;

						while (++temp2 < n&&stat[temp2] != ab);

						if (temp2 < n && temp2 - temp < min)
						{
							min = temp2 - temp;

							index[0] = temp;
							index[1] = temp2;
						}
					}

					if (!cnt[0])
					{
						str[index[0]] = str[index[1]] = '0';
					}

					else if (!cnt[1])
					{
						str[index[0]] = str[index[1]] = 'A';
					}

					else
					{
						str[index[0]] = str[index[1]] = 'a';
					}
				}
			}
			*/
		}

		printf("%s\n", str.c_str());
	}

	return 0;
}