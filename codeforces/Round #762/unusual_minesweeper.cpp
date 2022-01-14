#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int parent[N], value[N];

void Reset(int n){
  for(int i = 0; i < n; ++i){
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

  if(j < i){
    swap(i, j);
  }

  parent[j] = i;
  value[i] = min(value[i], value[j]);
}

void Process(vector<pii>& a, int k, function<int (pii&)> xFunc, function<int (pii&)> yFunc){
  map<int,vector<pii>> M;

  for(int i = a.size() - 1; i != -1; --i){
    int x = xFunc(a[i]), y = yFunc(a[i]);
    auto xt = M.find(x);
    if(xt != M.end()){
      xt->second.push_back({y, i});
    }
    else{
      M[x] = {{y, i}};
    }
  }

  for(auto [x, v]: M){
    sort(v.begin(), v.end());

    int py = INT_MIN, i = -1;
    for(auto [cy, j]: v){
      if(py != INT_MIN && cy - py <= k){
        Union(i, j);
      }
      py = cy, i = j;
    }
  }
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<pii> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d%d%d", &a[i].first, &a[i].second, &value[i]);
  }

  Reset(n);
  Process(a, k, [](pii& p) { return p.first; }, [](pii& p) { return p.second; });
  Process(a, k, [](pii& p) { return p.second; }, [](pii& p) { return p.first; });

  vector<int> v;
  for(int i = 0; i < n; ++i){
    if(parent[i] == i){
      v.push_back(value[i]);
    }
  }

  sort(v.begin(), v.end());

  int ans = v.back();
  for(int i = v.size() - 1, t = 0; i != -1; --i, ++t){
    int ansx = max(t, i == 0 ? 0 : v[i - 1]);
    ans = min(ans, ansx);
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