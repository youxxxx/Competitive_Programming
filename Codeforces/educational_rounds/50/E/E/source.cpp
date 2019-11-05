#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int gcd(int a, int b)
{
	int t;

	a = abs(a);
	b = abs(b);

	while (b != 0)
	{
		t = a%b;
		a = b;
		b = t;
	}

	return a;
}

int main()
{
	int **coord;
	int i, j;
	vector<int> x, y;
	long long int xst, yst, xed, yed;
	long long int sum = 0;
	int n;

	scanf("%d", &n);

	coord = new int*[n];

	for (i = 0; i < n; i++)
	{
		coord[i] = new int[4];

		for (j = 0; j < 4; j++)
		{
			scanf("%d", &coord[i][0]);
		}

		x.push_back(coord[i][0] - coord[i][2]);
		y.push_back(coord[i][1] - coord[i][3]);

		if (x[i] == 0)
		{
			sum += y[i];
		}

		else if (y[i] == 0)
		{
			sum += x[i];
		}
		
		else
		{
			sum += gcd(abs(x[i]), abs(y[i]));
		}
	}
	
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if ((long long int)x[i] * (long long int)y[j] == (long long int)x[j] * (long long int)y[i])
			{
				if (abs(coord[i][0]-coord[j][0])/gcd(abs(coord[i][0]-coord[j][0]),abs(coord[i][1]-coord[j][1]))==abs(x[i])/gcd(abs(x[i]),abs(y[i])))
				{
					if (coord[i][0] >= coord[j][0] && coord[i][0] <= coord[j][2]
						|| coord[i][0] >= coord[j][2] && coord[i][0] <= coord[j][0])
					{
						xst = coord[i][0];
						yst = coord[i][1];
					}

					else if (coord[i][2] >= coord[j][0] && coord[i][2] <= coord[j][2]
						|| coord[i][2] >= coord[j][2] && coord[i][2] <= coord[j][0])
					{
						xst = coord[i][2];
						yst = coord[i][3];
					}

					else if (coord[j][0] >= coord[i][0] && coord[j][0] <= coord[i][2]
						|| coord[j][0] >= coord[i][2] && coord[j][0] <= coord[i][0])
					{
						xst = coord[j][0];
						yst = coord[j][1];
					}

					else if (coord[j][2] >= coord[i][0] && coord[j][2] <= coord[i][2]
						|| coord[j][2] >= coord[i][2] && coord[j][2] <= coord[i][0])
					{
						xst = coord[j][2];
						yst = coord[j][3];
					}
				}
			}
		}
	}
}