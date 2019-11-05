#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int n, t, a;
	vector<int> h;
	int input;
	double res;
	int i;
	int index = 0;
	double min;

	scanf("%d %d %d",&n,&t,&a);

	scanf("%d", &input);

	min = abs((double)t - (double)input*0.006 - (double)a);
	
	for (i = 1; i < n; i++)
	{
		scanf("%d", &input);

		if (abs((double)t - (double)input*0.006 - (double)a) < min)
		{
			min = abs((double)t - (double)input*0.006 - (double)a);

			index = i;
		}
	}

	printf("%d\n", index + 1);

	return 0;
}