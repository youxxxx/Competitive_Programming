#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	int n, i;
	FILE *fp;

	fp = fopen("output.txt", "w");

	fprintf(fp, "1000\n");

	for (i = 0; i < 1000; i++)
	{
		fprintf(fp, "%d %d\n", i*100, (999-i) * 100);
	}

	for (i = 0; i < 1000; i++)
	{
		fprintf(fp, "-%d -%d\n", i*100, (999 - i) * 100);
	}

	fclose(fp);

	return 0;
}