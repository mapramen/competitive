#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 22

char s[N];

int Solve(){
  scanf("%s", s + 1);

  if(s[1] == '*'){
    exit(0);
  }

  int ans = 1;
  for(int i = 1; s[i] != '\0'; ++i){
    if(s[i] == 'Y'){
      ans = i * (ans / __gcd(ans, i));
    }
  }

  for(int i = 1; s[i] != '\0'; ++i){
    if(s[i] == 'N' && ans % i == 0){
      return -1;
    }
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}