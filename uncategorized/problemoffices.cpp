#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001

vector< vector<int> > adj(N);
int parent[N], s[N];
bitset<N> dp;

void DFS(int i){
  for(auto k : adj[i]){
    DFS(k);
    s[i] += s[k];
  }
  s[i] += (adj[i].size() == 0);
}

int RootChild(int c){
  while(parent[c] != 1)
    c = parent[c];
  return c;
}

void Fill(int k, vector<int>& v){
  while(parent[k] != 1){
    int i = parent[k];
    for(auto j : adj[i]){
      if(j != k){
        v.PB(s[j]);
      }
    }
    k = i;
  }
}

bool Check(int a, int b, int c, int d){
  if(s[1] % 2 == 1)
    return 0;

  c = RootChild(c);
  d = RootChild(d);

  int m = s[1] / 2 - 1 - s[c];

  if(m < 0)
    return 0;

  vector<int> v;
  Fill(a, v);
  Fill(b, v);

  a = RootChild(a), b = RootChild(b);

  for(auto k : adj[1]){
    if(k != a && k != b && k != c && k != d)
      v.PB(s[k]);
  }

  dp.reset();
  dp.set(0);

  for(auto x : v)
    dp |= (dp << x);

  return dp.test(m);
}

int main(){
  int n, a, b, c, d;

  scanf("%d", &n);

  scanf("%d%d%d%d", &a, &b, &c, &d);

  for(int i = 2; i <= n; ++i){
    int p;
    scanf("%d", &p);
    parent[i] = p;
    adj[p].PB(i);
  }

  DFS(1);

  if((Check(a, b, c, d) && Check(c, d, b, a)) || (Check(a, b, d, c) && Check(d, c, b, a)))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
