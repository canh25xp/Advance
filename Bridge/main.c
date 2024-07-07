#include <stdio.h>

int tc, T, i, j, n, a[50][6], check, max;
int tx, ty;

int dy[3] = {-1, 0, 1};

void DFS(int x, int y, int curCoin)
{
	if (x == 0 && max < curCoin)
		max = curCoin;

	int k;
	for (k = 0; k < 3; k++)
	{
		tx = x - 1;
		ty = y + dy[k];
		if (tx >= 0 && ty >= 0 && ty < 5)
		{
			if (a[tx][ty] != 2)
				DFS(tx, ty, curCoin + a[tx][ty]);
			else
			{
				if (check)
				{
					check = 0;
					DFS(tx, ty, curCoin);
					check = 1;
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < 5; j++)
				scanf("%d", &a[i][j]);
		
		max = -1;
        check = 1;
		DFS(n, 2, 0);
		
		printf("#%d %d\n", tc, max);
	}
	
	return 0;
}