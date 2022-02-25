#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300

char s[N];

string Solve(){
  int a;
  scanf("%d%s", &a, s);

  if(a == 0){
    return string(s);
  }

  int b = 0;
  for(int i = 0; s[i] != '\0'; ++i){
    b = (10 * b + s[i] - '0') % a;
  }

  return to_string(__gcd(a, b));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}