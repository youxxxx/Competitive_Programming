#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	long long x1, x2, y1, y2, r1, r2;
	long long cdist, rsum;
	double xsol, ysol, ratio, at;
	double xsign, ysign;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);

		cdist = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

		rsum = (r1 + r2)*(r1 + r2);

		if (cdist >= rsum)
		{
			printf("YES\n%lld %lld\n", x1, y1);
		}

		else if (r1 >= r2)
		{
			if (x1 == x2&&y1 == y2 && r1 == r2)
			{
				printf("NO\n");
			}

			else if (x1 == x2&&y1 == y2)
			{
				printf("YES\n%lld %lld\n", x1 + r1, y1);
			}

			else
			{
				if (y1 == y2)
				{
					if (x1 > x2)
					{
						printf("YES\n%lld %lld\n", x1 + r1, y1);
					}

					else
					{
						printf("YES\n%lld %lld\n", x1 - r1, y1);
					}
				}

				else if (x1 == x2)
				{
					if (y1 > y2)
					{
						printf("YES\n%lld %lld\n", x1, y1 + r1);
					}

					else
					{
						printf("YES\n%lld %lld\n", x1, y1 - r1);
					}
				}

				else
				{
					xsign = (double)((x1 - x2) / abs(x1 - x2));
					ysign = (double)((y1 - y2) / abs(y1 - y2));
					ratio = (double)abs((y1 - y2)) / (double)abs((x1 - x2));

					at = atan((double)(y1 - y2) / (double)(x1 - x2));

					ratio += 1.0;

					printf("YES\n%.7lf %.7lf\n", (double)x1 + (double)r1 * cos(at) * xsign, (double)y1 + (double)r1 * sin(at) * xsign);
				}
			}
		}

		else if(sqrt((double)cdist)+(double)r1<=(double)r2)
		{
			printf("NO\n");
		}

		else
		{
			if (x1 == x2&&y1 == y2)
			{
				printf("NO\n");
			}

			else
			{
				if (y1 == y2)
				{
					if (x1 > x2)
					{
						printf("YES\n%lld %lld\n", x1 + r1, y1);
					}

					else
					{
						printf("YES\n%lld %lld\n", x1 - r1, y1);
					}
				}

				else if (x1 == x2)
				{
					if (y1 > y2)
					{
						printf("YES\n%lld %lld\n", x1, y1 + r1);
					}

					else
					{
						printf("YES\n%lld %lld\n", x1, y1 - r1);
					}
				}

				else
				{
					xsign = (double)((x1 - x2) / abs(x1 - x2));
					ysign = (double)((y1 - y2) / abs(y1 - y2));
					//ratio = (double)abs((y1 - y2)) / (double)abs((x1 - x2));

					at = atan((double)(y1 - y2) / (double)(x1 - x2));

					//ratio += 1.0;

					printf("YES\n%.7lf %.7lf\n", (double)x1 + (double)r1 * cos(at) * xsign, (double)y1 + (double)r1 * sin(at) * xsign);
				}
			}
		}
	}

	return 0;
}
