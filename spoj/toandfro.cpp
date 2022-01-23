#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int m;

  scanf("%d", &m);
  if(m == 0){
    exit(0);
  }

  string s;
  cin >> s;

  int n = s.size() / m;
  vector<vector<char>> a(n, vector<char>(m));

  for(int x = 0, k = 0; x < n; ++x){
    int y = x % 2 == 0 ? 0 : m - 1;
    int dy = x % 2 == 0 ? 1 : -1;

    for( ; 0 <= y && y < m; y += dy, ++k){
      a[x][y] = s[k];
    }
  }

  s.clear();
  for(int y = 0; y < m; ++y){
    for(int x = 0; x < n; ++x){
      s.push_back(a[x][y]);
    }
  }

  return s;
}

int main(){
  while(true){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}