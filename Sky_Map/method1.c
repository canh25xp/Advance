/*
 * DFS above
 * BFS below
 */

#include <stdio.h>

int tc, T, n, a[26][26], visited[26][26], num, cnt, max;
int tx, ty, i, j;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y)
{
	visited[x][y] = 1;
	cnt++;
	int k; // Khai bao bien k o local la bat buoc voi DFS
	for (k = 0; k < 4; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (tx >= 0 && tx < n && ty >= 0 && ty < n && !visited[tx][ty] && a[tx][ty])
			DFS(tx, ty);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 0; tc < T; tc++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
				visited[i][j] = 0;
			}
		
		num = max = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					num++;
					cnt = 0;
					DFS(i, j);
					if (max < cnt)
						max = cnt;
				}
			}
			
		printf("%d %d\n", num, max);
	}
	
	return 0;
}


/*
#include <stdio.h>

int tc, T, n, a[26][26], visited[26][26], num, cnt, max;
int qX[1000], qY[1000], u, v, k, tx, ty, i, j;
int frontX, rearX, frontY, rearY;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void initQueue()
{
	frontX = rearX = frontY = rearY = -1;
}

int isEmptyX()
{
	if (frontX == rearX)
		return 1;
	return 0;
}

int isEmptyY()
{
	if (frontY == rearY)
		return 1;
	return 0;
}

void enQueueX(int elementX)
{
	rearX++;
	qX[rearX] = elementX;
}

void enQueueY(int elementY)
{
	rearY++;
	qY[rearY] = elementY;
}

int deQueueX()
{
	frontX++;
	return qX[frontX];
}

int deQueueY()
{
	frontY++;
	return qY[frontY];
}

void BFS(int x, int y)
{
	visited[x][y] = 1;
	cnt = 1;
	enQueueX(x);
	enQueueY(y);
	while (!isEmptyX())
	{
		u = deQueueX();
		v = deQueueY();
		for (k = 0; k < 4; k++)
		{
			tx = u + dx[k];
			ty = v + dy[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < n
				&& !visited[tx][ty] && a[tx][ty] == 1)
				{
					enQueueX(tx);
					enQueueY(ty);
					visited[tx][ty] = 1;
					cnt++;
				}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 0; tc < T; tc++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
				visited[i][j] = 0;
			}
		
		num = max = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					num++;
					initQueue();
					BFS(i, j);
					if (max < cnt)
						max = cnt;
				}
			}
			
		printf("%d %d\n", num, max);
	}
	
	return 0;
}
*/