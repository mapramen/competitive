#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> a, s;

bool Check(int n, int m, int l){
  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      s[x][y] = (a[x][y] >= l) + s[x - 1][y] + s[x][y - 1] - s[x - 1][y - 1];
    }
  }

  int t = l * l;
  for(int x = l; x <= n; ++x){
    for(int y = l; y <= m; ++y){
      if(s[x][y] + s[x - l][y - l] - s[x][y - l] - s[x - l][y] == t){
        return true;
      }
    }
  }

  return false;
}

int BinarySearch(int n, int m){
  int x = 1, y = n, ans = 1;
  while(x <= y){
    int mid = (x + y) / 2;
    if(Check(n, m, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  a = vector<vector<int>>(n + 1, vector<int>(m + 1));
  s = vector<vector<int>>(n + 1, vector<int>(m + 1));

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  return BinarySearch(n, m);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}