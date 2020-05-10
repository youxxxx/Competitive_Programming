#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	/*
	for (int a = 2; a <= 50; a++)
	{
		for (int b = a; b <= a*a; b++)
		{
			int n, m;
			int q, r;

			n = a;
			m = b;

			if (m == n + 1 || m == n*n - 1)
			{
				continue;
			}

			q = m / n;
			r = m%n;

			int sol[51][51];
			bool row[51][51] = { 0, };
			bool col[51][51] = { 0, };

			memset(sol, -1, sizeof(sol));

			if (r == 0)
			{
				int off;

				off = q - 1;

				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						sol[i][j] = (off + i - j + n) % n;
					}
				}
			}

			else if (!(r % 2) || m == n*n - 2)
			{
				if (n == 3)
				{
					continue;
				}

				int off, other;

				if (m == n*n - 2)
				{
					off = n - 1;
					other = n - 2;
				}

				else
				{
					off = q - 1;
					other = off + r / 2;
				}

				for (int i = 0; i < n - 2; i++)
				{
					sol[i][i] = off;

					row[off][i] = true;
					col[off][i] = true;
				}

				sol[n - 2][n - 2] = other;
				row[other][n - 2] = col[other][n - 2] = true;
				sol[n - 1][n - 1] = other;
				row[other][n - 1] = col[other][n - 1] = true;

				sol[n - 2][n - 1] = sol[n - 1][n - 2] = off;
				row[off][n - 2] = row[off][n - 1] = true;
				col[off][n - 2] = col[off][n - 1] = true;

				for (int i = 0; i < n - 2; i++)
				{
					for (int j = 1; j < n; j++)
					{
						if (sol[i][(i + j) % n] == -1 && !row[other][i] && !col[other][(i + j) % n])
						{
							sol[i][(i + j) % n] = other;
							row[other][i] = true;
							col[other][(i + j) % n] = true;

							break;
						}
					}
				}

				for (int k = 0; k < n; k++)
				{
					if (k == off || k == other)
					{
						continue;
					}

					for (int i = 0; i < n; i++)
					{
						for (int j = 1; j < n; j++)
						{
							if (sol[i][(i + j) % n] == -1 && !row[k][i] && !col[k][(i + j) % n])
							{
								sol[i][(i + j) % n] = k;
								row[k][i] = true;
								col[k][(i + j) % n] = true;

								break;
							}
						}
					}
				}
			}

			else
			{
				if (n == 3)
				{
					continue;
				}

				int off, other, other2;

				off = q - 1;

				if (m == n*(n - 1) + 1 || m == n*(n - 1) - 1)
				{
					if (m == n*(n - 1) + 1)
					{
						other = off - 1;
						other2 = off + 1;
					}

					else
					{
						other = off + 1;
						other2 = off + 2;
					}

					for (int i = 0; i < n - 3; i++)
					{
						sol[i][i] = off;

						row[off][i] = true;
						col[off][i] = true;
					}


					sol[n - 2][n - 2] = other2;
					sol[n - 1][n - 1] = other2;

					for (int i = 0; i < n - 3; i++)
					{
						sol[i][i + 1] = other2;

						row[other2][i] = true;
						col[other2][i + 1] = true;
					}

					sol[n - 3][0] = other2;
					row[other2][n - 3] = true;
					row[other2][0] = true;

					sol[n - 3][n - 2] = sol[n - 2][n - 1] = sol[n - 1][n - 3] = off;

					for (int i = 0; i < 4; i++)
					{
						row[off][n - 4 + i] = row[other2][n - 4 + i] = true;
						col[off][n - 4 + i] = col[other2][n - 4 + i] = true;
					}

					sol[n - 3][n - 3] = other;
					row[other][n - 3] = true;
					col[other][n - 3] = true;

					for (int i = n - 2; i < n; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if (sol[i][j] == -1 && !row[other][i] && !col[other][j])
							{
								sol[i][j] = other;
								row[other][i] = true;
								col[other][j] = true;

								break;
							}
						}
					}

					for (int i = 0; i < n - 3; i++)
					{
						for (int j = 2; j < n; j++)
						{
							if (sol[i][(i + j) % n] == -1 && !row[other][i] && !col[other][(i + j) % n])
							{
								sol[i][(i + j) % n] = other;
								row[other][i] = true;
								col[other][(i + j) % n] = true;

								break;
							}
						}
					}

					for (int k = 0; k < n; k++)
					{
						if (k == off || k == other || k == other2)
						{
							continue;
						}

						for (int i = 0; i < n; i++)
						{
							for (int j = 1; j < n; j++)
							{
								if (sol[i][(i + j) % n] == -1 && !row[k][i] && !col[k][(i + j) % n])
								{
									sol[i][(i + j) % n] = k;
									row[k][i] = true;
									col[k][(i + j) % n] = true;

									break;
								}
							}
						}
					}
				}

				else
				{
					if (r == 1)
					{
						other = off - 1;
						other2 = off + 2;
					}

					else if (m == n*n - 3)
					{
						off = n - 1;
						other = n - 2;
						other2 = n - 3;
					}

					else
					{
						other = off + r / 2;
						other2 = off + r / 2 + 1;
					}

					for (int i = 0; i < n - 2; i++)
					{
						sol[i][i] = off;

						row[off][i] = true;
						col[off][i] = true;
					}

					sol[n - 2][n - 2] = other;
					row[other][n - 2] = col[other][n - 2] = true;
					sol[n - 1][n - 1] = other2;
					row[other2][n - 1] = col[other2][n - 1] = true;

					sol[n - 2][n - 1] = sol[n - 1][n - 2] = off;
					row[off][n - 2] = row[off][n - 1] = true;
					col[off][n - 2] = col[off][n - 1] = true;

					for (int i = 0; i < n; i++)
					{
						if (i == n - 2)
						{
							continue;
						}
						for (int j = 1; j < n; j++)
						{
							if (sol[i][(i + j) % n] == -1 && !row[other][i] && !col[other][(i + j) % n])
							{
								sol[i][(i + j) % n] = other;
								row[other][i] = true;
								col[other][(i + j) % n] = true;

								break;
							}
						}
					}

					for (int i = 0; i < n - 1; i++)
					{
						for (int j = 1; j < n; j++)
						{
							if (sol[i][(i + j) % n] == -1 && !row[other2][i] && !col[other2][(i + j) % n])
							{
								sol[i][(i + j) % n] = other2;
								row[other2][i] = true;
								col[other2][(i + j) % n] = true;

								break;
							}
						}
					}

					for (int k = 0; k < n; k++)
					{
						if (k == off || k == other || k == other2)
						{
							continue;
						}

						for (int i = 0; i < n; i++)
						{
							for (int j = 1; j < n; j++)
							{
								if (sol[i][(i + j) % n] == -1 && !row[k][i] && !col[k][(i + j) % n])
								{
									sol[i][(i + j) % n] = k;
									row[k][i] = true;
									col[k][(i + j) % n] = true;

									break;
								}
							}
						}
					}
				}
			}

			int rowcnt[51][51] = { 0, }, colcnt[51][51] = { 0, };


			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					rowcnt[sol[i][j]][i]++;
					colcnt[sol[i][j]][j]++;
				}
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (rowcnt[i][j] != 1 || colcnt[i][j] != 1)
					{
						printf("ERROR %d %d\n", a, b);

						return 0;
					}
				}
			}
		}
	}
	*/

	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int n, m;
		int q, r;

		scanf("%d %d", &n, &m);

		if (m == n + 1 || m == n*n - 1)
		{
			printf("Case #%d: IMPOSSIBLE\n", tc);

			continue;
		}

		q = m / n;
		r = m%n;

		int sol[51][51];
		bool row[51][51] = { 0, };
		bool col[51][51] = { 0, };

		memset(sol, -1, sizeof(sol));

		if (r == 0)
		{
			int off;

			off = q - 1;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					sol[i][j] = (off + i - j + n) % n;
				}
			}
		}

		else if (!(r % 2) || m == n*n - 2)
		{
			if (n == 3)
			{
				printf("Case #%d: IMPOSSIBLE\n", tc);

				continue;
			}

			int off, other;

			if (m == n*n - 2)
			{
				off = n - 1;
				other = n - 2;
			}

			else
			{
				off = q - 1;
				other = off + r / 2;
			}

			for (int i = 0; i < n - 2; i++)
			{
				sol[i][i] = off;

				row[off][i] = true;
				col[off][i] = true;
			}

			sol[n - 2][n - 2] = other;
			row[other][n - 2] = col[other][n - 2] = true;
			sol[n - 1][n - 1] = other;
			row[other][n - 1] = col[other][n - 1] = true;

			sol[n - 2][n - 1] = sol[n - 1][n - 2] = off;
			row[off][n - 2] = row[off][n - 1] = true;
			col[off][n - 2] = col[off][n - 1] = true;

			for (int i = 0; i < n - 2; i++)
			{
				for (int j = 1; j < n; j++)
				{
					if (sol[i][(i + j) % n] == -1 && !row[other][i] && !col[other][(i + j) % n])
					{
						sol[i][(i + j) % n] = other;
						row[other][i] = true;
						col[other][(i + j) % n] = true;

						break;
					}
				}
			}

			for (int k = 0; k < n; k++)
			{
				if (k == off || k == other)
				{
					continue;
				}

				for (int i = 0; i < n; i++)
				{
					for (int j = 1; j < n; j++)
					{
						if (sol[i][(i + j) % n] == -1 && !row[k][i] && !col[k][(i + j) % n])
						{
							sol[i][(i + j) % n] = k;
							row[k][i] = true;
							col[k][(i + j) % n] = true;

							break;
						}
					}
				}
			}
		}

		else
		{
			if (n == 3)
			{
				printf("Case #%d: IMPOSSIBLE\n", tc);

				continue;
			}

			int off, other, other2;

			off = q - 1;

			if (m == n*(n - 1) + 1 || m == n*(n - 1) - 1)
			{
				if (m == n*(n - 1) + 1)
				{
					other = off - 1;
					other2 = off + 1;
				}

				else
				{
					other = off + 1;
					other2 = off + 2;
				}

				for (int i = 0; i < n - 3; i++)
				{
					sol[i][i] = off;

					row[off][i] = true;
					col[off][i] = true;
				}


				sol[n - 2][n - 2] = other2;
				sol[n - 1][n - 1] = other2;

				for (int i = 0; i < n - 3; i++)
				{
					sol[i][i + 1] = other2;

					row[other2][i] = true;
					col[other2][i + 1] = true;
				}

				sol[n - 3][0] = other2;
				row[other2][n - 3] = true;
				row[other2][0] = true;

				sol[n - 3][n - 2] = sol[n - 2][n - 1] = sol[n - 1][n - 3] = off;

				for (int i = 0; i < 4; i++)
				{
					row[off][n - 4 + i] = row[other2][n - 4 + i] = true;
					col[off][n - 4 + i] = col[other2][n - 4 + i] = true;
				}

				sol[n - 3][n - 3] = other;
				row[other][n - 3] = true;
				col[other][n - 3] = true;

				for (int i = n - 2; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (sol[i][j] == -1 && !row[other][i] && !col[other][j])
						{
							sol[i][j] = other;
							row[other][i] = true;
							col[other][j] = true;

							break;
						}
					}
				}

				for (int i = 0; i < n - 3; i++)
				{
					for (int j = 2; j < n; j++)
					{
						if (sol[i][(i + j) % n] == -1 && !row[other][i] && !col[other][(i + j) % n])
						{
							sol[i][(i + j) % n] = other;
							row[other][i] = true;
							col[other][(i + j) % n] = true;

							break;
						}
					}
				}

				for (int k = 0; k < n; k++)
				{
					if (k == off || k == other || k == other2)
					{
						continue;
					}

					for (int i = 0; i < n; i++)
					{
						for (int j = 1; j < n; j++)
						{
							if (sol[i][(i + j) % n] == -1 && !row[k][i] && !col[k][(i + j) % n])
							{
								sol[i][(i + j) % n] = k;
								row[k][i] = true;
								col[k][(i + j) % n] = true;

								break;
							}
						}
					}
				}
			}

			else
			{
				off = q - 1;

				if (r == 1)
				{
					other = off - 1;
					other2 = off + 2;
				}

				else if (m == n*n - 3)
				{
					off = n - 1;
					other = n - 2;
					other2 = n - 3;
				}

				else
				{
					other = off + r / 2;
					other2 = off + r / 2 + 1;
				}

				for (int i = 0; i < n - 2; i++)
				{
					sol[i][i] = off;

					row[off][i] = true;
					col[off][i] = true;
				}

				sol[n - 2][n - 2] = other;
				row[other][n - 2] = col[other][n - 2] = true;
				sol[n - 1][n - 1] = other2;
				row[other2][n - 1] = col[other2][n - 1] = true;

				sol[n - 2][n - 1] = sol[n - 1][n - 2] = off;
				row[off][n - 2] = row[off][n - 1] = true;
				col[off][n - 2] = col[off][n - 1] = true;

				for (int i = 0; i < n; i++)
				{
					if (i == n - 2)
					{
						continue;
					}
					for (int j = 1; j < n; j++)
					{
						if (sol[i][(i + j) % n] == -1 && !row[other][i] && !col[other][(i + j) % n])
						{
							sol[i][(i + j) % n] = other;
							row[other][i] = true;
							col[other][(i + j) % n] = true;

							break;
						}
					}
				}

				for (int i = 0; i < n - 1; i++)
				{
					for (int j = 1; j < n; j++)
					{
						if (sol[i][(i + j) % n] == -1 && !row[other2][i] && !col[other2][(i + j) % n])
						{
							sol[i][(i + j) % n] = other2;
							row[other2][i] = true;
							col[other2][(i + j) % n] = true;

							break;
						}
					}
				}

				for (int k = 0; k < n; k++)
				{
					if (k == off || k == other || k == other2)
					{
						continue;
					}

					for (int i = 0; i < n; i++)
					{
						for (int j = 1; j < n; j++)
						{
							if (sol[i][(i + j) % n] == -1 && !row[k][i] && !col[k][(i + j) % n])
							{
								sol[i][(i + j) % n] = k;
								row[k][i] = true;
								col[k][(i + j) % n] = true;

								break;
							}
						}
					}
				}
			}
		}

		printf("Case #%d: POSSIBLE\n", tc);

		for (int i = 0; i < n; i++)
		{
			printf("%d", sol[i][0] + 1);

			for (int j = 1; j < n; j++)
			{
				printf(" %d", sol[i][j] + 1);
			}

			printf("\n");
		}
	}

	return 0;
}