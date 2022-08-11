#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 100001

bool visited[N];

bool Check(vector<int>& a, int k, int m){
  for(int i = 0; i <= m; ++i){
    visited[i] = false;
  }

  for(int& x: a){
    if(x <= m){
      visited[x] = true;
    }
  }

  int x = m + 1, y = a.size();
  for(int i = 0; i <= m; ++i){
    x -= visited[i];
    y -= visited[i];
  }

  return x <= min(k, y);
}

int BinarySearch(int k, vector<int>& a){
  int x = 0, y = a.size(), ans = -1;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(a, k, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int m = BinarySearch(k, a);

  map<int,int> C;
  for(int x: a){
    ++C[x];
  }

  vector<tiii> v;
  for(pii p: C){
    int i, ci;
    tie(i, ci) = p;
    ci -= (i <= m);
    if(ci != 0){
      v.push_back({i <= m, ci, i});
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  set<int> S;
  for(int i = 0; i <= m; ++i){
    if(!visited[i]){
      auto [t, cx, x] = v.back();
      v.pop_back();
      if(cx != 1){
        v.push_back({t, cx - 1, x});
      }
    }
    S.insert(i);
  }

  while(!v.empty()){
    auto [t, cx, x] = v.back();
    v.pop_back();
    if(cx != 1){
      v.push_back({t, cx - 1, x});
    }
    S.insert(x);
  }

  return S.size() - m - 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}