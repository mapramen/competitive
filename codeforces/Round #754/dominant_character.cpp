#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];

int Solve(){
  int n;

  scanf("%d%s", &n, s);

  for(int k = 1; k <= 6; ++k){
    for(int i = k; i < n; ++i){
      int a = 0, b = 0, c = 0;
      for(int j = i - k; j <= i; ++j){
        a += (s[j] == 'a');
        b += (s[j] == 'b');
        c += (s[j] == 'c');
      }

      if(a > b && a > c){
        return k + 1;
      }
    }
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}