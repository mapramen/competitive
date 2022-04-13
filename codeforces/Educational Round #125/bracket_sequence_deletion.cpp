#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001

char s[N];

void Solve(){
  int n;
  scanf("%d%s", &n, s);

  int deletion_count = 0, characters_left = n;

  for(int i = 0; i < n; ++i){
    char c = s[i];
    int x = c == '(' ? 1 : -1;

    for(++i; i < n; ++i){
      if(s[i] == c){
        break;
      }

      if(x >= 0){
        x += (s[i] == '(' ? 1 : -1);
      }

      if(x == 0){
        break;
      }
    }

    if(i == n){
      break;
    }

    ++deletion_count, characters_left = n - i - 1;
  }

  printf("%d %d\n", deletion_count, characters_left);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}