#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 52
#define N 10

vector<int> V[M][N];
map<vector<int>,string> dp;

void Reset(){
  for(int k = 0; k < M; ++k){
    for(int i = 0; i < N; ++i){
      V[k][i].clear();
    }
  }
  dp.clear();
}

void ReadString(int i){
  string s;
  cin >> s;

  int x = 1;
  for(char c: s){
    int k = 'a' <= c && c <= 'z' ? c - 'a' : 26 + c - 'A';
    V[k][i].push_back(x);
    ++x;
  }
}

string Calculate(int n, vector<int>& v){
  auto it = dp.find(v);
  if(it != dp.end()){
    return it->second;
  }

  string ans;
  vector<int> u(n);

  for(int k = 0; k < M; ++k){
    bool found = true;

    for(int i = 0; i < n && found; ++i){
      u[i] = 0;
      int x = v[i];
      for(int y: V[k][i]){
        if(y > x){
          u[i] = y;
          break;
        }
      }
      found = u[i] > v[i];
    }

    if(!found){
      continue;
    }

    string ansx = string(1, k < 26 ? 'a' + k : 'A' + k - 26) + Calculate(n, u);
    if(ansx.size() > ans.size()){
      ans = ansx;
    }
  }

  dp[v] = ans;
  return ans;
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset();
  for(int i = 0; i < n; ++i){
    ReadString(i);
  }

  vector<int> v(n);
  string ans = Calculate(n, v);

  cout << ans.size() << '\n';
  cout << ans << '\n';
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}