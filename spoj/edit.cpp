#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

char s[N];

int Solve(){
  if(scanf("%s", s) == EOF){
    exit(0);
  }

  int n = strlen(s);

  int odd_pos_cnt = 0, even_pos_cnt = 0;
  for(int i = 1; i <= n; ++i){
    if(isupper(s[i - 1])){
      continue;
    }

    if(i % 2 == 0){
      even_pos_cnt++;
    }
    else{
      odd_pos_cnt++;
    }
  }

  return min(odd_pos_cnt + n / 2 - even_pos_cnt, (n - (n / 2)) - odd_pos_cnt + even_pos_cnt);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}