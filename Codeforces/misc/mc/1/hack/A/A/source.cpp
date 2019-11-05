#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
	FILE *fp;
	int i;

	fp = fopen("output.txt", "w");

	fprintf(fp,"100000\n");

	for (i = 0; i < 100000; i++)
	{
		fprintf(fp,"%d ", i);
	}

	fclose(fp);

	return 0;
}