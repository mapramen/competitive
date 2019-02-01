#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define B 5

int a[N][B];

int main(){
  int n;
  vector<int> v;

  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 0; j < B; ++j)
      cin >> a[i][j];

  for(int i = 1; i <= n; ++i){
    bool check = 0;
    for(int j = 1; j <= n && check == 0; ++j){
      for(int k = 1; k <= n && check == 0; ++k){
        if(i == j || j == k || i == k)
          continue;
        int d = 0;
        for(int x = 0; x < B; ++x)
          d += (a[j][x] - a[i][x]) * (a[k][x] - a[i][x]);
        check = (d > 0);
      }
    }
    if(check == 0)
      v.PB(i);
  }

  cout << v.size() << '\n';
  for(auto x : v)
    cout << x << '\n';

  return 0;
}
