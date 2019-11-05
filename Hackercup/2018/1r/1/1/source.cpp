#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	int i, j, k;
	int t, n;
	FILE *in, *out;
	int up, down;
	char input;
	bool stuck;
	bool pipe[3][1000];

	in = fopen("let_it_flow.txt", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &t);

	for (i = 0; i < t; i++)
	{
		up = 0;
		down = 0;
		stuck = false;

		fscanf(in, "%d", &n);

		for (j = 0; j < 3; j++)
		{
			fscanf(in, "%c", &input);

			for (k = 0; k < n; k++)
			{
				fscanf(in, "%c", &input);

				pipe[j][k] = (input == '.');
			}
		}

		stuck = !pipe[0][0] || !pipe[1][0];

		stuck = stuck || (n % 2);

		if (!stuck)
		{
			up = 1;

			for (j = 1; j < n - 1; j++)
			{
				if (j % 2)
				{
					down = (up*(pipe[2][j] && pipe[1][j])) % 1000000007;
					up = (up*(pipe[0][j] && pipe[1][j])) % 1000000007;

					stuck = !up && !down;
				}

				else
				{
					up = (up*(pipe[0][j] && pipe[1][j]) + down*(pipe[2][j] && pipe[1][j])) % 1000000007;

					stuck = !up;
				}

				if (stuck)
				{
					break;
				}
			}

			up *= (pipe[1][n - 1] && pipe[2][n - 1]) * !stuck;
		}

		fprintf(out, "Case #%d: %d\n", i+1, up % 1000000007);
	}

	fclose(out);
	fclose(in);

	return 0;
}