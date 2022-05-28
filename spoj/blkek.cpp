#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

char s[N];

int Solve(){
  scanf("%s", s);

  int cnt_k = 0, cnt_ke = 0, cnt_kek = 0;
  for(int i = 0; s[i] != '\0'; ++i){
    if(s[i] == 'K'){
      ++cnt_k, cnt_kek += cnt_ke;
    }
    else if(s[i] == 'E'){
      cnt_ke += cnt_k;
    }
  }

  return cnt_kek;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}