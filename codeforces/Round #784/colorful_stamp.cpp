#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  string s;

  cin >> n >> s;

  for(int x = 0; x < n; ++x){
    if(s[x] == 'W'){
      continue;
    }
    
    int y = x, r = 0, b = 0;
    for( ; y < n && s[y] != 'W'; ++y){
      r += (s[y] == 'R');
      b += (s[y] == 'B');
    }

    if(r == 0 || b == 0){
      return false;
    }

    x = y - 1;
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}