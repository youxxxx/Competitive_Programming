#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[5001];
		string str;

		scanf("%d", &n);

		scanf("%s", input);
		str = input;
		
		string lmin;
		int k = 0;

		lmin = str;

		for (int i = 1; i < n; i++)
		{
			string cand;

			cand = str.substr(i);

			if ((n - i) % 2)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					cand.push_back(str[j]);
				}
			}

			else
			{
				cand.append(str.substr(0, i));
			}

			if (cand < lmin)
			{
				lmin = cand;
				k = i;
			}
		}

		printf("%s\n%d\n", lmin.c_str(), k + 1);
	}

	return 0;
}