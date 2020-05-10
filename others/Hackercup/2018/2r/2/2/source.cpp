#include<cstdio>

using namespace std;

int main()
{
	FILE *in, *out;
	int t, n, k, min;
	int i, j;
	int sol;

	in = fopen("ethan_finds_the_shortest_path.txt", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &t);

	for (i = 0; i < t; i++)
	{
		fscanf(in, "%d %d", &n, &k);

		if (n <= 2 || k <= 2)
		{
			fprintf(out, "Case #%d: 0\n", i + 1);

			fprintf(out, "1\n1 %d 1\n", n);
		}

		else
		{
			min = n;

			if (k < min)
			{
				min = k;
			}

			sol = ((k - 1) + (k - min + 1))*(min - 1) / 2 - k;

			fprintf(out, "Case #%d: %d\n%d\n", i + 1, sol, min);

			fprintf(out, "1 %d %d\n", n, k);

			for (j = 1; j <= min - 2; j++)
			{
				fprintf(out, "%d %d %d\n", j, j + 1, k - j);
			}

			fprintf(out, "%d %d %d\n", min - 1, n, k - min + 1);
		}
	}

	fclose(out);
	fclose(in);

	return 0;
}