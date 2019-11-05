#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int H, W, h, w;

	scanf("%d %d %d %d", &H,&W,&h,&w);

	printf("%d\n", H*W - (h*W + H*w - h*w));

	return 0;
}