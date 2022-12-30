#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];
bool found[N];

int main(){
  scanf("%s", s);

  for(int mod = 10; mod < N; mod *= 10){
    for(int i = 0, x = 0; s[i] != '\0'; ++i){
      x = (10 * x + (s[i] - '0')) % mod;
      found[x] = true;
    }
  }

  int ans = 0;
  for( ; found[ans]; ++ans);

  printf("%d\n", ans);
  
  return 0;
}