#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int a[N], set_no[N], set_size[N];
bool visited[N];

int FindSet(int i){
  if(i != set_no[i])
    set_no[i] = FindSet(set_no[i]);
  return set_no[i];
}

void UnionSet(int i, int j){
  i = FindSet(i), j = FindSet(j);
  if(j < i)
    swap(i, j);

  if(i != j){
    set_no[j] = i;
    set_size[i] += set_size[j];
  }
}

int main(){
  int n, m;
  vector< pii > v;
  double ans = 0;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    v.PB(MP(a[i], i));
    set_no[i] = i;
    set_size[i] = 1;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  sort(v.begin(), v.end(), greater< pii >());

  for(auto p : v){
    int i, ai, cnt;
    ll ansx = 0;
    tie(ai, i) = p;
    set<int> s;

    for(auto k : adj[i]){
      if(visited[k] && FindSet(i) != FindSet(k))
        s.insert(FindSet(k));
    }

    cnt = 1;
    for(auto x : s){
      ansx += 1ll * cnt * set_size[x];
      cnt += set_size[x];
      UnionSet(i, x);
    }

    ans += ansx * ai;
    visited[i] = 1;
  }

  ans /= 1ll * n * (n - 1) / 2;

  printf("%.9lf\n", ans);

  return 0;
}
