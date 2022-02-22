#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool CanSkip(char c){
  return !(('0' <= c && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

ll Solve(){
  ll ans = 0, x = 0;
  char op = '+';

  while(op != '='){
    char c = getchar();
    if(CanSkip(c)){
      continue;
    }

    if('0' <= c && c <= '9'){
      x = 10 * x + (c - '0');
      continue;
    }

    if(op == '+'){
      ans += x;
    }
    else if(op == '-'){
      ans -= x;
    }
    else if(op == '*'){
      ans *= x;
    }
    else{
      ans /= x;
    }

    x = 0;
    op = c;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}