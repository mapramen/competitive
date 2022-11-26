#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

const int INF = 1E9;
vector<int> fib;

void Initialize(){
  for(int a = 0, b = 1; b <= INF; b += a, a = b - a){
    fib.push_back(b);
  }
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<int> c(n);
  for(int& x: c){
    scanf("%d", &x);
  }

  ll s = 0;
  for(int x: c){
    s += x;
  }

  int k = 0;
  for( ; k < fib.size() && s > 0; s -= fib[k], ++k);
  --k;

  for(int x = -1; k > -1; --k){
    int y = -1;
    for(int z = 0; z < n; ++z){
      if(z != x && (y == -1 || c[z] > c[y])){
        y = z;
      }
    }

    if(y == -1 || c[y] < fib[k]){
      return false;
    }

    c[y] -= fib[k];
    x = y;
  }

  return k == -1 && *max_element(c.begin(), c.end()) == 0;
}

int main(){
  Initialize();
  
  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  
  return 0;
}