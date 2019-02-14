#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< pii > c(1), d(1);
int a[N], b[N];

int main(){
  int n, m, C, D, ansc = 0, anscc = 0, ansd = 0, ansdd = 0, ans;
  char s[2];

  scanf("%d%d%d", &n, &C, &D);
  while(n--){
    int x, y;
    scanf("%d%d", &x, &y);
    scanf("%s", s);
    if(s[0] == 'C')
      c.PB(MP(y, x));
    else
      d.PB(MP(y, x));
  }

  n = c.size() - 1;
  m = d.size() - 1;

  sort(c.begin() + 1, c.begin() + n + 1);
  sort(d.begin() + 1, d.begin() + m + 1);

  for(int i = 1; i <= n; i++){
    if(c[i].first <= C)
      ansc = max(ansc, c[i].second);
    a[i] = max(c[i].second, a[i - 1]);
  }

  for(int i = 1; i <= m; i++){
    if(d[i].first <= D)
      ansd = max(ansd, d[i].second);
    b[i] = max(d[i].second, b[i - 1]);
  }

  for(int i = n, j = 1; i > 1; i--)
    for(j = max(1, min(j - 1, i - 1)); j < i && c[j].first + c[i].first <= C; j++)
      anscc = max(anscc, c[i].second + a[j]);

  for(int i = m, j = 1; i > 1; i--)
    for(j = max(1, min(j - 1, i - 1)); j < i && d[j].first + d[i].first <= D; j++)
      ansdd = max(ansdd, d[i].second + b[j]);

  if(ansc == 0 || ansd == 0)
    ansc = ansd = 0;

  ans = max(ansc + ansd, max(anscc, ansdd));

  printf("%d\n", ans);

  return 0;
}
