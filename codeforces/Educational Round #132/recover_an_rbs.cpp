#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

bool Solve(){
  scanf("%s", s);

  int n = strlen(s);
  
  int c = n / 2;
  for(int i = 0; i < n; ++i){
    c -= (s[i] == '(');
  }

  int x = -1;
  for(int i = 0; i < n && c != 0; ++i){
    if(s[i] == '?'){
      s[i] = '(';
      --c;
      x = i;
    }
  }

  int y = -1;
  for(int i = n - 1; i > -1; --i){
    if(s[i] == '?'){
      s[i] = ')';
      y = i;
    }
  }

  if(x == -1 || y == -1 || x == 0 || y == n - 1){
    return true;
  }

  for(int i = 0, p = 0; i < y; ++i){
    p += (s[i] == '(' ? 1 : -1);
    if(x <= i && p < 2){
      return true;
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