#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[200001];
	string str;
	long long tc,cases;
	long long n;
	char type[127];
	long long xdir[4] = { -1,1,0,0 };
	long long ydir[4] = { 0,0,-1,1 };
	long long xmin, xmax;
	long long ymin, ymax;
	//vector<pair<long long, long long>> lmin, lmax, rmin, rmax;
	pair<long long, long long> lmin[200001], lmax[200001], rmin[200001], rmax[200001];
	pair<long long, long long> curmin, curmax, ncoord[2];
	long long xsize, ysize;
	long long xcoord, ycoord;
	long long i, j;
	long long sol, cand;

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%s", input);

		str = input;

		n = str.size();

		type['W'] = 0;
		type['S'] = 1;
		type['A'] = 2;
		type['D'] = 3;

		xmin = xmax = ymin = ymax = xcoord = ycoord = 0;

		/*
		lmin.clear();
		lmax.clear();
		rmin.clear();
		rmax.clear();

		lmin.push_back(make_pair(0, 0));
		lmax.push_back(make_pair(0, 0));
		*/

		lmin[0] = make_pair(0, 0);
		lmax[0] = make_pair(0, 0);

		for (i = 0; i < n; i++)
		{
			xcoord += xdir[type[str[i]]];
			ycoord += ydir[type[str[i]]];

			if (xcoord < xmin)
			{
				xmin = xcoord;
			}

			if (xcoord > xmax)
			{
				xmax = xcoord;
			}

			if (ycoord < ymin)
			{
				ymin = ycoord;
			}

			if (ycoord > ymax)
			{
				ymax = ycoord;
			}

			/*
			lmin.push_back(make_pair(xmin, ymin));
			lmax.push_back(make_pair(xmax, ymax));
			*/

			lmin[i + 1] = make_pair(xmin, ymin);
			lmax[i + 1] = make_pair(xmax, ymax);
		}

		sol = (xmax - xmin + 1)*(ymax - ymin + 1);

		xmin = xmax = xcoord;
		ymin = ymax = ycoord;

		/*
		rmin.push_back(make_pair(xmin, ymin));
		rmax.push_back(make_pair(xmax, ymax));
		*/
		rmin[n] = make_pair(xmin, ymin);
		rmax[n] = make_pair(xmax, ymax);

		for (i = n - 1; i >= 0; i--)
		{
			xcoord -= xdir[type[str[i]]];
			ycoord -= ydir[type[str[i]]];

			if (xcoord < xmin)
			{
				xmin = xcoord;
			}

			if (xcoord > xmax)
			{
				xmax = xcoord;
			}

			if (ycoord < ymin)
			{
				ymin = ycoord;
			}

			if (ycoord > ymax)
			{
				ymax = ycoord;
			}

			/*
			rmin.insert(rmin.begin(), make_pair(xmin, ymin));
			rmax.insert(rmax.begin(), make_pair(xmax, ymax));
			*/

			rmin[i] = make_pair(xmin, ymin);
			rmax[i] = make_pair(xmax, ymax);
		}

		for (i = 0; i <= n; i++)
		{
			for (j = 0; j < 4; j++)
			{
				ncoord[0].first = rmin[i].first + xdir[j];
				ncoord[0].second = rmin[i].second + ydir[j];
				ncoord[1].first = rmax[i].first + xdir[j];
				ncoord[1].second = rmax[i].second + ydir[j];

				if (lmin[i].first < ncoord[0].first)
				{
					ncoord[0].first = lmin[i].first;
				}

				if (lmin[i].second < ncoord[0].second)
				{
					ncoord[0].second = lmin[i].second;
				}

				if (lmax[i].first > ncoord[1].first)
				{
					ncoord[1].first = lmax[i].first;
				}

				if (lmax[i].second > ncoord[1].second)
				{
					ncoord[1].second = lmax[i].second;
				}

				if ((ncoord[1].first - ncoord[0].first + 1)*(ncoord[1].second - ncoord[0].second + 1) < sol)
				{
					sol = (ncoord[1].first - ncoord[0].first + 1)*(ncoord[1].second - ncoord[0].second + 1);
				}
			}
		}

		printf("%lld\n", sol);
	}
	
	return 0;
}