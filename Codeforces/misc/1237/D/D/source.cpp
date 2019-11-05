#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct coord
{
	long long x;
	long long y;
	long long z;
	int idx;
};

struct row
{
	vector<coord> points;
	vector<long long> xpos;
	int marks;

	row()
	{
		marks = 0;
	}
};

struct plane
{
	long long zpos;
	vector<row> rows;
	vector<long long> ypos;
	int marks = 0;
	int numofpoints = 0;

	plane()
	{
		marks = 0;
	}
};

bool func(coord &a, coord &b)
{
	return a.z < b.z || a.z == b.z&&a.y < b.y || a.z == b.z&&a.y == b.y&&a.x < b.x;
}

int main()
{
	int n;
	int i, j, k, l;
	long long x, y, z;
	vector<coord> points;
	vector<plane> p;
	vector<coord> box;
	vector<long long>::iterator it, it2;
	coord cur;
	plane curplane;
	row currow;
	bool marked[50001] = { 0, };
	int cury, curz;
	int start;
	int idx, idx2;
	int cnt = 0;

	// freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld", &x, &y, &z);

		cur.x = x;
		cur.y = y;
		cur.z = z;
		cur.idx = i + 1;

		points.push_back(cur);
	}

	sort(points.begin(), points.end(), func);

	currow.points.push_back(points[0]);
	currow.xpos.push_back(points[0].x);
	cury = points[0].y;
	curz = points[0].z;

	for (i = 1; i < n; i++)
	{
		if (points[i].z != curz)
		{
			curplane.zpos = curz;
			curplane.rows.push_back(currow);
			curplane.ypos.push_back(cury);

			cnt += currow.points.size();

			curplane.numofpoints = cnt;

			p.push_back(curplane);

			curplane.rows.clear();
			curplane.ypos.clear();

			curz = points[i].z;

			currow.points.clear();
			currow.xpos.clear();

			currow.points.push_back(points[i]);
			currow.xpos.push_back(points[i].x);

			cury = points[i].y;
		}

		else if (points[i].y != cury)
		{
			curplane.rows.push_back(currow);
			curplane.ypos.push_back(cury);

			cnt += currow.points.size();

			currow.points.clear();
			currow.xpos.clear();

			currow.points.push_back(points[i]);
			currow.xpos.push_back(points[i].x);

			cury = points[i].y;
		}

		else
		{
			currow.points.push_back(points[i]);
			currow.xpos.push_back(points[i].x);
		}
	}

	curplane.zpos = curz;
	curplane.rows.push_back(currow);
	curplane.ypos.push_back(cury);

	cnt += currow.points.size();

	curplane.numofpoints = cnt;

	p.push_back(curplane);

	start = 0;

	for (i = 0; i < p.size(); i++)
	{
		for (j = 0; j < p[i].rows.size(); j++)
		{
			box.clear();

			for (k = 0; k < p[i].rows[j].points.size(); k++)
			{
				if (!marked[p[i].rows[j].points[k].idx])
				{
					box.push_back(p[i].rows[j].points[k]);
				}
			}

			for (l = 0; l < box.size() - 1; l += 2)
			{
				printf("%d %d\n", box[l].idx, box[l + 1].idx);
			}

			if (box.size() % 2)
			{
				if (j != p[i].rows.size() - 1)
				{
					it = lower_bound(p[i].rows[j + 1].xpos.begin(), p[i].rows[j + 1].xpos.end(), box.back().x);

					if (it == p[i].rows[j + 1].xpos.end())
					{
						it--;
					}

					idx = it - p[i].rows[j + 1].xpos.begin();

					printf("%d %d\n", box.back().idx, p[i].rows[j + 1].points[idx].idx);

					p[i].rows[j + 1].points.erase(p[i].rows[j + 1].points.begin() + idx);
					p[i].rows[j + 1].xpos.erase(p[i].rows[j + 1].xpos.begin() + idx);

					//marked[p[i].rows[j + 1].points[idx].idx] = true;

					/*
					if (++p[i].rows[j + 1].marks == p[i].rows[j + 1].points.size())
					{
						p[i].rows.erase(p[i].rows.begin() + j + 1);
					}
					*/

					if (p[i].rows[j + 1].points.empty())
					{
						p[i].rows.erase(p[i].rows.begin() + j + 1);
					}
				}

				else
				{
					it2 = lower_bound(p[i + 1].ypos.begin(), p[i + 1].ypos.end(), box.back().y);

					if (it2 == p[i + 1].ypos.end())
					{
						it2--;
					}

					idx2 = it2 - p[i + 1].ypos.begin();

					it = lower_bound(p[i + 1].rows[idx2].xpos.begin(), p[i + 1].rows[idx2].xpos.end(), box.back().x);

					if (it == p[i + 1].rows[idx2].xpos.end())
					{
						it--;
					}

					idx = it - p[i + 1].rows[idx2].xpos.begin();

					printf("%d %d\n", box.back().idx, p[i + 1].rows[idx2].points[idx].idx);

					p[i + 1].rows[idx2].points.erase(p[i + 1].rows[idx2].points.begin() + idx);
					p[i + 1].rows[idx2].xpos.erase(p[i + 1].rows[idx2].xpos.begin() + idx);

					//marked[p[i + 1].rows[idx2].points[idx].idx] = true;

					/*
					if (++p[i + 1].rows[idx2].marks == p[i + 1].rows[idx2].points.size())
					{
						p[i + 1].rows.erase(p[i + 1].rows.begin() + idx2);
					}
					*/

					if (p[i + 1].rows[idx2].points.empty())
					{
						p[i + 1].rows.erase(p[i + 1].rows.begin() + idx2);
					}

					if (p[i + 1].numofpoints == 1)
					{
						p.erase(p.begin() + i + 1);
					}
				}
			}
		}
	}

	return 0;
}	