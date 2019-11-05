#include<cstdio>
#include<vector>
#include<string>
#include<queue>

using namespace std;

void rec(vector<int> &box, long long &cnt, int target, int dest)
{
	int max;

}

int main()
{
	int t, z;
	int n, m;
	int i;
	char *input;
	string str;
	long long cnt;
	int index;
	int start, start2;
	bool valid;
	vector<int> box;
	queue<pair<int,int>> q;
	pair<int,int> cur;

	scanf("%d", &t);

	input = new char[100001];

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		start = -1;

		for (i = 0; i < n; i++)
		{
			if (str[i] == '#')
			{
				box.push_back(i);
			}
		}

		m = box.size();

		cnt = 0;

		valid = true;

		for (i = 0; i < m; i++)
		{
			if (box[i] > i)
			{
				if (box[i] == n - 1)
				{
					valid = false;

					break;
				}

				if (i + 1 < m&&box[i + 1] == box[i] + 1)
				{
					q.push(pair<int, int>(i + 1, box[i] + 2));

					while (!q.empty())
					{
						cur = q.front();

						q.pop();

						if (box[cur.first] + 2 >= n || cur.second >= n)
						{
							valid = false;

							break;
						}

						cnt += cur.second - box[cur.first];

						box[cur.first] = cur.second;

						if (cur.first + 1 < m && box[cur.first + 1] < cur.second + 2)
						{
							q.push(pair<int, int>(cur.first + 1, cur.second + 2));
						}
					}

					if (!valid)
					{
						break;
					}
				}

				if (!valid)
				{
					break;
				}

				cnt += box[i] - i;

				box[i] = i;
			}

			if (!valid)
			{
				break;
			}
		}

		if (!valid)
		{
			printf("-1\n");
		}
		
		else
		{
			printf("%lld\n", cnt);
		}

		while (!q.empty())
		{
			q.pop();
		}

		box.clear();
		/*
		while (++start < n&&str[start] == '.');

		if (start == n)
		{
			printf("0\n");

			continue;
		}

		if (start == 0)
		{
			while (++start < n&&str[start] == '#');

			if (start == n)
			{
				printf("0\n");

				continue;
			}

			start2 = start;

			while (++start2 < n&&str[start2] == '.');

			if (start2 == n)
			{
				printf("0\n");

				continue;
			}

			else
			{
				rec(str, cnt, start2, start);
			}
		}

		else
		{
			rec(str,cnt)
		}
		*/
	}

	return 0;
}