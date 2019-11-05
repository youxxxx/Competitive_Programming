#include<cstdio>
#include<vector>

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long la, ra, ta;
	long long lb, rb, tb;
	long long qa, rema, qb, remb;
	long long off;
	long long diff, max;
	long long temp;
	long long start;
	bool inseg = false, valid = false;
	long long i, j;
	long long cons = 0;
	long long lseg, rseg;

	scanf("%I64d %I64d %I64d", &la, &ra, &ta);
	scanf("%I64d %I64d %I64d", &lb, &rb, &tb);

	qa = ta;
	qb = tb;

	if (qa > qb)
	{
		temp = qa;
		qa = qb;
		qb = temp;

		temp = la;
		la = lb;
		lb = temp;

		temp = ra;
		ra = rb;
		rb = temp;

		temp = ta;
		ta = tb;
		tb = temp;
	}

	/*
	lseg = la;
	rseg = ra;

	if (lb > lseg)
	{
		lseg = lb;
	}

	if (rb < rseg)
	{
		rseg = rb;
	}

	cons = rseg - lseg + 1;
	*/

	diff = gcd(qa, qb);

	max = qa*qb / diff;

	lb += qb;
	rb += qb;

	off = (lb - la) / diff;

	la += off*diff;
	ra += off*diff;

	lseg = la;
	rseg = ra;

	if (lb > lseg)
	{
		lseg = lb;
	}

	if (rb < rseg)
	{
		rseg = rb;
	}

	if (rseg - lseg + 1 > cons)
	{
		cons = rseg - lseg + 1;
	}

	off = (rb - ra) / diff;

	la += off*diff;
	ra += off*diff;

	lseg = la;
	rseg = ra;

	if (lb > lseg)
	{
		lseg = lb;
	}

	if (rb < rseg)
	{
		rseg = rb;
	}

	if (rseg - lseg + 1 > cons)
	{
		cons = rseg - lseg + 1;
	}

	la += diff;
	ra += diff;

	lseg = la;
	rseg = ra;

	if (lb > lseg)
	{
		lseg = lb;
	}

	if (rb < rseg)
	{
		rseg = rb;
	}

	if (rseg - lseg + 1 > cons)
	{
		cons = rseg - lseg + 1;
	}

	la += diff;
	ra += diff;

	lseg = la;
	rseg = ra;

	if (lb > lseg)
	{
		lseg = lb;
	}

	if (rb < rseg)
	{
		rseg = rb;
	}

	if (rseg - lseg + 1 > cons)
	{
		cons = rseg - lseg + 1;
	}
	/*
	for (i = 0; i < qa / diff; i++)
	{
		lseg = (la + i*diff) % (qa * 2);
		rseg = (ra + i*diff) % (qa * 2);

		off = lb / qa;

		lseg += off*qa;
		rseg += off*qa;

		if (lb > lseg)
		{
			lseg = lb;
		}

		if (rb < rseg)
		{
			rseg = rb;
		}

		if (rseg - lseg + 1 > cons)
		{
			cons = rseg - lseg + 1;
		}

		lseg = (la + i*diff) % (qa * 2) + qa;
		rseg = (ra + i*diff) % (qa * 2) + qa;

		if (lb > lseg)
		{
			lseg = lb;
		}

		if (rb < rseg)
		{
			rseg = rb;
		}

		if (rseg - lseg + 1 > cons)
		{
			cons = rseg - lseg + 1;
		}
		/*
		lseg = (la + i*diff) % (qa * 2);
		rseg = (ra + i*diff) % (qa * 2);

		off = (lb + tb) / qa;

		lseg += off*qa;
		rseg += off*qa;

		if (lb + tb > lseg)
		{
			lseg = lb + tb;
		}

		if (rb + tb < rseg)
		{
			rseg = rb + tb;
		}

		if (rseg - lseg + 1 > cons)
		{
			cons = rseg - lseg + 1;
		}

		lseg = (la + i*diff) % (qa * 2) + qa;
		rseg = (ra + i*diff) % (qa * 2) + qa;

		off = (lb + tb) / qa;

		lseg += off*qa;
		rseg += off*qa;

		if (lb + tb > lseg)
		{
			lseg = lb + tb;
		}

		if (rb + tb < rseg)
		{
			rseg = rb + tb;
		}

		if (rseg - lseg + 1 > cons)
		{
			cons = rseg - lseg + 1;
		}
		*/

		/*
		for (j = 0; j < qb*2 / qa; j++)
		{
			lseg = (la + i*diff + j * qa) % (qa * 2);
			rseg = (ra + i*diff + j * qa) % (qa * 2);

			if (lb > lseg)
			{
				lseg = lb;
			}

			if (rb < rseg)
			{
				rseg = rb;
			}

			if (rseg - lseg + 1 > cons)
			{
				cons = rseg - lseg + 1;
			}

			lseg = (la + i*diff + j * qa) % (qa * 2);
			rseg = (ra + i*diff + j * qa) % (qa * 2);

			if (lb + tb > lseg)
			{
				lseg = lb + tb;
			}

			if (rb + tb < rseg)
			{
				rseg = rb + tb;
			}

			if (rseg - lseg + 1 > cons)
			{
				cons = rseg - lseg + 1;
			}
		}
		*/


	/*
	off = (lb + qb - la) % qb;
	rb = (rb + qb + off - lb) % qb;
	lb = off;
	ra -= la;
	la = 0;

	if (rb < lb || lb == 0 && rb == 0)
	{
		inseg = true;

		start = 0;
	}

	for (i = 1; i < max; i++)
	{
		valid = false;

		if (i%qa >= la&&i%qa <= ra)
		{
			if (	i%qb >= lb&&i%qb <= rb
				||	i%qb >= lb&&rb < lb
				||	i%qb <=rb && rb<lb
				)
			{
				valid = true;
			}
		}

		if (!inseg&&valid)
		{
			inseg = true;

			start = i;
		}

		else if (inseg && !valid)
		{
			inseg = false;

			if ((i - start) > cons)
			{
				cons = i - start;
			}
		}
	}

	if (inseg)
	{
		if ((i - start) > cons)
		{
			cons = i - start;
		}
	}

	*/

	printf("%I64d\n", cons);

	return 0;
}