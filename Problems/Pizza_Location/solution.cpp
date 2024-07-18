#include <iostream>

using namespace std;

int T, k, r, m, n, res;
int place[22][2];
int solit[101][3];
int matranke[22][101];
int visited[101];
int p[22];

int pow2(int a)
{
  return a * a;
}

void markDistance()
{
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(pow2(place[i][0] - solit[j][0]) + pow2(place[i][1] - solit[j][1]) <= pow2(r))
      {
        matranke[i][j] = 1;
      }
    }
  }
}

void reset()
{
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      matranke[i][j] = 0;
    }
  }
  for(int i = 0; i < m; i++)
  {
    p[i] = 0;
  }
  res = 0;
}
void resetVisited()
{
  for(int j = 0; j < n; j++)
  {
    visited[j] = 0;
  }

}

void backtrack(int step, int st)
{
  if(step == k)
  {
    int sum = 0;
    resetVisited();
    for(int i = 0; i < k; i++)
    {
      int pl = p[i];
      for(int j = 0; j < n; j++)
      {
        if(visited[j] == 0 && matranke[pl][j] != 0)
        {
          sum += solit[j][2];
          visited[j] = 1;
        }
      }
    }
    if(sum > res) res = sum;
    return;
  }
  for(int i = st; i < m; i++)
  {
    p[step] = i;
    backtrack(step + 1, i + 1);
  }
}

int main()
{
  //freopen("input.txt", "r", stdin);
  cin >> T;
  for(int tc = 1; tc <= T; tc++)
  {
    cin >> k >> r;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
      cin >> place[i][0] >> place[i][1];
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> solit[i][0] >> solit[i][1] >> solit[i][2];
    }
    reset();
    markDistance();
    backtrack(0, 0);
    cout << "#" << tc << " " << res << endl;
  }
  return 0;
}