#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

int Solve(){
  scanf("%s", s);

  int n = strlen(s);

  int j = n - 1;
  for(int x = n - 1; x != -1; --x){
    if(s[x] == '0'){
      j = x;
    }
  }

  int i = j;
  for( ; i != -1 && s[i] != '1'; --i);
  i = max(-1, i - 1);

  return j - i;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}