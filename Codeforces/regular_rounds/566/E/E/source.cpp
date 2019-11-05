#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

#define MOD 1000000007

using namespace std;

class matrix
{
public:
	int row, col;
	int size;
	unsigned long long arr[7][7];
	unsigned long long sum;

	void mult(matrix &a, matrix &b, matrix &res)
	{
		int i, j, k;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				sum = 0;

				for (k = 0; k < size; k++)
				{
					sum = (sum + a.arr[i][k] * b.arr[k][j]) % (MOD - 1);
				}

				res.arr[i][j] = sum;
			}
		}
	}

	void mult2(matrix &a, matrix &b, matrix &res)
	{
		int n, m, l;
		int i, j, k;

		n = a.row;
		m = b.col;
		l = a.col;
		res.row = n;
		res.col = m;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				sum = 0;

				for (k = 0; k < l; k++)
				{
					sum = (sum + a.arr[i][k] * b.arr[k][j]) % (MOD - 1);
				}

				res.arr[i][j] = sum;
			}
		}
	}

	matrix()
	{
	}

	matrix(const matrix &other)
	{
		int n, m;
		int i, j;

		n = other.row;
		m = other.col;

		row = n;
		col = m;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				arr[i][j] = other.arr[i][j];
			}
		}
	}
};

int main()
{
	unsigned long long mat[3][3] = { { 1, 1, 1 },{ 1, 0, 0 },{ 0, 1, 0 } };
	unsigned long long mat2[7][7] = {	
						 { 1,1,1,1,0,0,0 }
						,{ 1,0,0,0,0,0,0 }
						,{ 0,1,0,0,0,0,0 }
						,{ 0,0,0,1,0,0,1 }
						,{ 0,0,0,0,1,0,1 }
						,{ 0,0,0,0,0,1,1 }
						,{ 0,0,0,0,0,0,1 }
	};
	unsigned long long n, f1, f2, f3, f4, f5, c;
	unsigned long long val[3];
	unsigned long long i, j;
	matrix t1[3], t2;
	matrix m1, m2;
	matrix pw[64], pw2[64];
	unsigned long long to2[64];
	matrix last1, last2, cur1, cur2, sol1[3], sol2;
	long long temp;
	long long cpw;
	long long cres = 1;
	long long sol;

	m1.row = m1.col = m1.size = 3;
	m2.row = m2.col = m2.size = 7;

	t1[0].col = t1[1].col = t1[2].col = t2.col = 1;
	t1[0].row = t1[1].row = t1[2].row = 3;
	t2.row = 7;

	scanf("%llu %llu %llu %llu %llu", &n, &f1, &f2, &f3, &c);

	val[0] = f1;
	val[1] = f2;
	val[2] = f3;

	c = c*c % MOD;

	f4 = f1 + f2 + f3%MOD;
	f5 = f2 + f3 + f4%MOD;

	t1[0].arr[0][0] = 0;
	t1[0].arr[1][0] = 0;
	t1[0].arr[2][0] = 1;
	t1[1].arr[0][0] = 0;
	t1[1].arr[1][0] = 1;
	t1[1].arr[2][0] = 0;
	t1[2].arr[0][0] = 1;
	t1[2].arr[1][0] = 0;
	t1[2].arr[2][0] = 0;

	t2.arr[0][0] = 0;
	t2.arr[1][0] = 0;
	t2.arr[2][0] = 0;
	t2.arr[3][0] = 1;
	t2.arr[4][0] = 0;
	t2.arr[5][0] = 0;
	t2.arr[6][0] = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			m1.arr[i][j] = mat[i][j];
		}
	}

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			m2.arr[i][j] = mat2[i][j];
		}
	}

	to2[0] = 1;
	pw[0] = m1;
	pw2[0] = m2;

	for (i = 1; i < 64; i++)
	{
		to2[i] = to2[i - 1] * 2;

		pw[i].size = pw[i].row = pw[i].col = 3;
		pw2[i].size = pw2[i].row = pw2[i].col = 7;

		pw[i].mult(pw[i - 1], pw[i - 1], pw[i]);
		pw2[i].mult(pw2[i - 1], pw2[i - 1], pw2[i]);
	}

	last1.row = last1.col = last1.size = 3;
	last2.row = last2.col = last2.size = 7;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i == j)
			{
				last1.arr[i][j] = 1;
			}

			else
			{
				last1.arr[i][j] = 0;
			}
		}
	}

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (i == j)
			{
				last2.arr[i][j] = 1;
			}

			else
			{
				last2.arr[i][j] = 0;
			}
		}
	}

	cur1 = last1;
	cur2 = last2;
	temp = n - 1;

	for (i = 0; i < 64; i++)
	{
		if (temp == 0)
		{
			break;
		}

		if (temp % 2)
		{
			last1.mult(cur1, pw[i], last1);
			last2.mult(cur2, pw2[i], last2);
		}

		temp /= 2;

		cur1 = last1;
		cur2 = last2;
	}

	sol1[0].mult2(last1, t1[0], sol1[0]);
	sol1[1].mult2(last1, t1[1], sol1[1]);
	sol1[2].mult2(last1, t1[2], sol1[2]);
	sol2.mult2(last2, t2, sol2);

	temp = sol2.arr[2][0];
	cpw = c;

	for (i = 0; i < 64; i++)
	{
		if (temp == 0)
		{
			break;
		}

		if (temp % 2)
		{
			cres = cres*cpw%MOD;
		}

		temp /= 2;

		cpw = cpw*cpw%MOD;
	}

	sol = cres;

	for (j = 0; j < 3; j++)
	{
		cpw = val[j];
		cres = 1;
		temp = sol1[j].arr[2][0];

		for (i = 0; i < 64; i++)
		{
			if (temp == 0)
			{
				break;
			}

			if (temp % 2)
			{
				cres = cres*cpw%MOD;
			}

			temp /= 2;

			cpw = cpw*cpw%MOD;
		}

		sol = sol*cres%MOD;
	}

	printf("%llu\n", sol);

	return 0;
}