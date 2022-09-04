#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 10

int c[B];

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int k = 0; k < B; ++k){
    c[k] = 0;
  }

  while(n--){
    int x;
    scanf("%d", &x);
    ++c[(x % B)];
  }

  vector<int> v;
  for(int k = 0; k < B; ++k){
    int x = min(3, c[k]);
    while(x--){
      v.push_back(k);
    }
  }

  for(int m = v.size(), x = 0; x < m; ++x){
    for(int y = x + 1; y < m; ++y){
      for(int z = y + 1; z < m; ++z){
        if((v[x] + v[y] + v[z]) % B == 3){
          return true;
        }
      }
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}