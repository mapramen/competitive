#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>

vector<int> GetShuffledArray(vector<int> a){
  int n = a.size();

  vector<int> c(n + 1);
  vector<tiii> v;

  for(int i = 0; i < n; ++i){
    int x = a[i];
    v.push_back({++c[x], x, i});
  }
  sort(v.begin(), v.end());

  vector<int> b(n);
  for(int k = 0; k < n; ++k){
    b[get<2>(v[k])] = get<1>(v[(k + 1) % n]);
  }

  return b;
}

int GetCycleLength(vector<map<int,int>>& c, int i){
  int ans = 1;

  if(c[i].begin()->second == 0){
    c[i].erase(c[i].begin());
    return ans;
  }

  int j = i;
  while(true){
    while(c[j].begin()->second == 0){
      c[j].erase(c[j].begin());
    }

    --(c[j].begin()->second);

    if(c[j].begin()->first == i){
      break;
    }

    ++ans;
    j = c[j].begin()->first;
  }

  return ans;
}

int GetMinShuffleCount(vector<int> a, vector<int> b){
  int n = a.size();
  vector<map<int,int>> c(n + 1);

  for(int i = 0; i < n; ++i){
    if(a[i] != b[i]){
      ++c[a[i]][b[i]];
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    for(auto it = c[i].begin(); it != c[i].end(); ++it){
      int j = it->first;
      if(c[j].count(i) == 0){
        continue;
      }
      
      int ansx = min(it->second, c[j][i]);
      ans += ansx;

      c[i][j] -= ansx, c[j][i] -= ansx;
    }
  }

  for(int i = 1; i <= n; ++i){
    while(!c[i].empty()){
      ans += (GetCycleLength(c, i) - 1);
    }
  }

  return ans;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n), b(n);

  for(int& x: a){
    scanf("%d", &x);
  }

  for(int& x: b){
    scanf("%d", &x);
  }

  vector<int> c = GetShuffledArray(a);

  return GetMinShuffleCount(a, b) == GetMinShuffleCount(a, c);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "AC" : "WA");
  }
  return 0;
}