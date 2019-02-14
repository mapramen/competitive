#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int v[N], l[N], r[N], p[N], inf = INT_MAX;
set<int> s;

void SetParent(int i, int j){
  if(j > 0)
    p[j] = i;
}

void DFS(int i, int lower, int upper){
  if(lower < v[i] && v[i] < upper)
    s.insert(v[i]);

  if(l[i] > 0)
    DFS(l[i], lower, min(upper, v[i]));

  if(r[i] > 0)
    DFS(r[i], max(lower, v[i]), upper);
}

int main(){
  int n, root, ans = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d%d%d", &v[i], &l[i], &r[i]);
    SetParent(i, l[i]);
    SetParent(i, r[i]);
  }

  for(root = 1; p[root] != 0; root++);

  DFS(root, -inf, inf);

  for(int i = 1; i <= n; i++)
    ans += (s.find(v[i]) == s.end());

  printf("%d\n", ans);

  return 0;
}
