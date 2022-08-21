#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int L[N], R[N], C[N], parent[N];
priority_queue<pii,vector<pii>,greater<pii>> reds, blues;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

void Relax(priority_queue<pii,vector<pii>,greater<pii>>& Q, int x){
  while(!Q.empty() && Q.top().first < x){
    Q.pop();
  }
}

void AddEdge(pii a, pii b){
  Union(a.second, b.second);
}

void AddEdges(priority_queue<pii,vector<pii>,greater<pii>>& Q){
  while(Q.size() > 1){
    pii a = Q.top();
    Q.pop();

    AddEdge(a, Q.top());
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d%d", &C[i], &L[i], &R[i]);
  }

  Reset(n);

  vector<pii> v{{INT_MAX, 0}};
  for(int i = 1; i <= n; ++i){
    v.push_back({L[i], i});
    v.push_back({R[i] + 1, 0});
  }
  sort(v.begin(), v.end());

  for(auto [x, i]: v){
    Relax(reds, x);
    Relax(blues, x);

    if(i == 0){
      continue;
    }

    if(C[i] == 0){
      reds.push({R[i], i});
    }
    else{
      blues.push({R[i], i});
    }

    if(blues.empty() || reds.empty()){
      continue;
    }

    AddEdges(reds);
    AddEdges(blues);

    AddEdge(reds.top(), blues.top());
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += Find(i) == i;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}