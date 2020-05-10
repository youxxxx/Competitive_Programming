#include<cstdio>
#include<map>

using namespace std;

int main()
{
	int t, n;
	int i, j, k;
	map<string, int> list;
	map<string, int>::iterator it;
	char input[21];
	string str;
	bool prevleft, curleft;
	int sum, psum;

	scanf("%d", &t);

	for (k = 0; k < t; k++)
	{
		scanf("%d", &n);

		sum = 0;

		for (i = 0; i < n; i++)
		{
			psum = 0;

			scanf("%s", input);

			str = input;

			it = list.find(str);

			if (it == list.end())
			{
				psum = 2;

				if (str[0] == 'd' || str[0] == 'f')
				{
					prevleft = true;
				}

				else
				{
					prevleft = false;
				}

				for (j = 1; j < str.size(); j++)
				{
					if (str[j] == 'd' || str[j] == 'f')
					{
						curleft = true;
					}

					else
					{
						curleft = false;
					}

					psum += 2 + ((prevleft&&curleft) || (!prevleft && !curleft)) * 2;

					prevleft = curleft;
				}

				list[str] = psum / 2;
			}

			else
			{
				psum = it->second;
			}

			sum += psum;
		}

		list.clear();

		printf("%d\n", sum);
	}

	return 0;
}