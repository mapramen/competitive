#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N), vertices(N);
bool marked[N];
ll ans[N];

int DFS(int i){
  marked[i] = 0;
  int ans = 1;
  for(auto k : adj[i]){
    if(marked[k]){
      ans += DFS(k);
    }
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    vertices[x].PB(i);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = N - 1; i > 0; --i){
    vector<int> v;
    for(int j = i; j < N; j += i){
      for(auto x : vertices[j]){
        v.PB(x);
        marked[x] = 1;
      }
    }

    ll val = 0;
    for(auto x : v){
      if(marked[x] == 0)
        continue;
      ll valx = DFS(x);
      val += (valx * (valx + 1) / 2);
    }

    ans[i] = val;
    for(int j = i + i; j < N; j += i)
      ans[i] -= ans[j];
  }

  for(int i = 1; i < N; ++i){
    if(ans[i]){
      printf("%d %lld\n", i, ans[i]);
    }
  }

  return 0;
}
