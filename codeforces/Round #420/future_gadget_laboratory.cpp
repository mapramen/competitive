#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

int a[N][N];

int main(){
  int n;
  bool valid = 1;

  cin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> a[i][j];

  for(int i = 1; i <= n && valid == 1; i++){
    for(int j = 1; j <= n && valid == 1; j++){
      if(a[i][j] == 1)
        continue;
        
      bool validx = 0;
      for(int x = 1; x <= n && validx == 0; x++){
        for(int y = 1; y <= n && validx == 0; y++){
          if(x == i || y == j)
            continue;
          validx = (a[i][y] + a[x][j] == a[i][j]);
        }
      }
      valid &= validx;
    }
  }

  if(valid == 1)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
