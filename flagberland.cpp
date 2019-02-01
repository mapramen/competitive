#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int n, m;
vector< string > v;

bool CheckRow(){
  if(n % 3 != 0)
    return 0;

  set<char> s;

  for(int x1 = 0, x2 = n / 3; x1 < n; x1 += (n / 3), x2 += (n / 3)){
    set<char> sx;
    for(int x = x1; x < x2 && sx.size() <= 1; ++x)
      for(int y = 0; y < m && sx.size() <= 1; ++y)
        sx.insert(v[x][y]);
    if(sx.size() > 1)
      return 0;
    s.insert(v[x1][0]);
  }

  return (s.size() == 3);
}

bool CheckColumn(){
  if(m % 3 != 0)
    return 0;

  set<char> s;

  for(int y1 = 0, y2 = m / 3; y1 < m; y1 += m / 3, y2 += m / 3){
    set<char> sx;
    for(int y = y1; y < y2 && sx.size() <= 1; ++y)
      for(int x = 0; x < n && sx.size() <= 1; ++x)
        sx.insert(v[x][y]);
    if(sx.size() > 1)
      return 0;
    s.insert(v[0][y1]);
  }

  return (s.size() == 3);
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    v.PB(s);
  }

  if(CheckRow() || CheckColumn())
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
