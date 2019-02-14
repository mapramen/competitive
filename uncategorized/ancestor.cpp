#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

vector< vector<int> > adj1(N), adj2(N);
int s[N], f[N], T[2 * N], ans[N], timer;

void DFS1(int i, int p){
  s[i] = ++timer;
  for(auto k : adj1[i]){
    if(k == p)
      continue;
    DFS1(k, i);
  }
  f[i] = ++timer;
}

void Update(int i, int x){
  for( ; i < 2 * N; i += (i & -i))
    T[i] += x;
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void DFS2(int i, int p){
  Update(s[i], 1);
  Update(f[i], -1);

  for(auto k : adj2[i]){
    if(k == p)
      continue;
    DFS2(k, i);
  }

  Update(s[i], -1);
  Update(f[i], 1);

  ans[i] = Query(s[i]);
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
      adj1[i].clear();
      adj2[i].clear();
    }

    for(int x = 1; x < n; x++){
      int i, j;
      scanf("%d%d", &i, &j);
      adj1[i].PB(j);
      adj1[j].PB(i);
    }

    for(int x = 1; x < n; x++){
      int i, j;
      scanf("%d%d", &i, &j);
      adj2[i].PB(j);
      adj2[j].PB(i);
    }

    timer = 0;
    DFS1(1, 0);
    DFS2(1, 0);

    for(int i = 1; i <= n; i++)
      printf("%d ", ans[i]);
    printf("\n");
  }
  
  return 0;
}
