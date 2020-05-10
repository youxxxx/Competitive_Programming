#define _USE_MATH_DEFINES

#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

double xrotate(double x, double y, double angle)
{
	return x*cos(angle) - y*sin(angle);
}

double yrotate(double x, double y, double angle)
{
	return x*sin(angle) + y*cos(angle);
}

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, q;
		double xdir[6] = { 1,0.5,-0.5,-1,-0.5,0.5 };
		double ydir[6] = { 0,1,1,0,-1,-1 };
		vector <pair<pair<double, double>, int>> lacc;
		//vector < pair<pair<double, double>, int>> racc, subt;
		string move;
		char input[200001];
		double root3;
		double deg60;

		root3 = sqrt((double)3.0) / (double)2.0;
		deg60 = M_PI / (double)3.0;

		xdir[0] = 1;
		ydir[1] = ydir[2] = root3;
		ydir[4] = ydir[5] = -root3;

		scanf("%d %d", &n, &q);

		scanf("%s", input);

		move = input;

		for (int i = 0; i < n; i++)
		{
			move[i] -= '0';
		}

		int curdir = 0;
		double curx = 0, cury = 0;

		lacc.push_back(make_pair(make_pair(curx, cury), curdir));

		for (int i = 0; i < n; i++)
		{
			curdir = (curdir + move[i]) % 6;

			curx = curx + xdir[curdir];
			cury = cury + ydir[curdir];

			lacc.push_back(make_pair(make_pair(curx, cury), curdir));
		}

		curdir = 0;
		curx = 0;
		cury = 0;

		/*
		racc.push_back(make_pair(make_pair(curx, cury), curdir));

		for (int i = 0; i < n; i++)
		{
			curdir = (curdir - move[i] + 6) % 6;

			double nextx, nexty;

			nextx = xrotate(curx, cury, -deg60*(double)curdir);
			nexty = yrotate(curx, cury, -deg60*(double)curdir);

			curx = nextx;
			cury = nexty;

			curx = curx - xdir[curdir];
			cury = cury - ydir[curdir];

			racc.push_back(make_pair(make_pair(curx, cury), curdir));
		}
		*/

		for (int i = 0; i < q; i++)
		{
			int l, r;
			double xadd, xsub;
			double yadd, ysub;
			int adddir, subdir;
			double nextx, nexty;

			scanf("%d %d", &l, &r);

			curdir = 0;
			curx = 0;
			cury = 0;

			xsub = lacc[l - 1].first.first;
			ysub = lacc[l - 1].first.second; 
			subdir = lacc[l - 1].second;

			nextx = xrotate(xsub, ysub, -deg60*(double)subdir);
			nexty = yrotate(xsub, ysub, -deg60*(double)subdir);

			xsub = nextx;
			ysub = nexty;

			xadd = lacc[r].first.first;
			yadd = lacc[r].first.second;

			nextx = xrotate(xadd, yadd, -deg60*(double)subdir);
			nexty = yrotate(xadd, yadd, -deg60*(double)subdir);

			xadd = nextx;
			yadd = nexty;

			double xsol, ysol;

			xsol = xadd - xsub;
			ysol = yadd - ysub;

			printf("%.8lf %.8lf\n", xsol, ysol);
		}
	}

	return 0;
}