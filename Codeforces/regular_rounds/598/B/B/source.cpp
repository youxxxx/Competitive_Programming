#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int pos[101];
	int input;
	int i, j;
	int proc;
	vector<int> sol, base;
	int backelem;
	int del;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		base.clear();

		base.push_back(0);

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &input);

			pos[input] = i;

			base.push_back(input);
		}

		proc = 1;
		sol.clear();
		del = 1;

		for (i = 1; i <= n; i++)
		{
			/*
			sol.push_back(i);

			if (pos[i] - del > proc)
			{
				for (j = proc; j < pos[i] - del - 1; j++)
				{
					sol.push_back(base[j]);
				}
			}

			proc = pos[i];

			base.erase(base.begin() + proc - del);

			backelem = base[proc - del - 1];

			del++;
			*/

			if (base[i] == del)
			{
				if (i == proc)
				{
					proc++;

					del++;
				}

				else
				{
					base.erase(base.begin() + i);

					base.insert(base.begin() + proc, del);

					proc = i;

					del++;
				}
			}
		}

		/*
		sol.push_back(base.back());

		for (i = 0; i < n; i++)
		{
			printf("%d ", sol[i]);
		}
		*/
		
		for (i = 1; i <= n; i++)
		{
			printf("%d ", base[i]);
		}

		printf("\n");
	}

	return 0;
}