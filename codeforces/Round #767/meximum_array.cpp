#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> V(N);
vector<int> a;

void Pop(int n){
  while(a.size() != n){
    int x = a.back();
    a.pop_back();
    V[x].pop_back();
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  a.resize(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  for(int x = 0; x <= n; ++x){
    V[x].clear();
  }

  for(int i = n - 1; i != -1; --i){
    V[a[i]].push_back(i);
  }
  reverse(a.begin(), a.end());

  vector<int> v;
  while(!a.empty()){
    int x = 0, y = 0;
    for( ; x <= n && !V[x].empty(); ++x){
      y = max(y, V[x].back());
    }

    Pop(x == 0 ? (a.size() - 1) : (n - 1 - y));

    v.push_back(x);
  }

  printf("%lu\n", v.size());
  for(int x: v){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}