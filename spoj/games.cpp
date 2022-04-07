#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20

char s[N];

int Solve(){
  scanf("%s", s);

  int x = 0, y = 1;
  
  int i = 0;
  for( ; s[i] != '\0' && s[i] != '.'; ++i);

  if(s[i] == '.'){
    for(++i; s[i] != '\0'; ++i){
      x = 10 * x + (s[i] - '0');
      y = 10 * y;
    }
  }

  return y / __gcd(x, y);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}