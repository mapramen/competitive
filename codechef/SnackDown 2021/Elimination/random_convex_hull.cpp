#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 31
#define MOD 998244353 

vector<int> px, py, a;

void ReadArray(int n, vector<int>& a){
  a.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }
}

ll CrossProduct(int x1, int y1, int x2, int y2, int x3, int y3){
  return 1ll * (x2 - x1) * (y3 - y1) - 1ll * (x3 - x1) * (y2 - y1);
}

int GetCount(int x1, int y1, int x2, int y2){
  a.clear();
  
  for(int x: px){
    if(x == x1 || x == x2){
      continue;
    }

    int c = 0;
    for(int y: py){
      if(y == y1 || y == y2){
        continue;
      }

      ll sign = CrossProduct(x1, y1, x2, y2, x, y);
      c += (sign > 0 || (sign == 0 && (x < min(x1, x2) || max(x1, x2) < x)));
    }
    a.push_back(c);
  }

  sort(a.begin(), a.end());

  int ans = 1;
  for(int i = 0, n = a.size(); i < n; ++i){
    if(a[i] <= i){
      return 0;
    }
    ans = (1ll * ans * (a[i] - i)) % MOD;
  }

  return ans;
}

int Calculate(int x1, int y1, int x2, int y2){
  if(x1 == x2 || y1 == y2){
    return 0;
  }

  ll area = CrossProduct(0, 0, x1, y1, x2, y2);

  return area == 0 ? 0 : (1ll * GetCount(x1, y1, x2, y2) * (MOD + area % MOD)) % MOD;
}

int Solve(){
  int n;
  scanf("%d", &n);

  ReadArray(n, px);
  ReadArray(n, py);

  int ans = 0;
  for(int x1: px){
    for(int x2: px){
      for(int y1: py){
        for(int y2: py){
          ans = (ans + Calculate(x1, y1, x2, y2)) % MOD;
        }
      }
    }
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