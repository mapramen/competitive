#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char GetChar(int d){
  if(d == 0){
    return 'u';
  }

  if(d == 1){
    return 'm';
  }

  if(d == 2){
    return 'a';
  }

  if(d == 3){
    return 'n';
  }

  return 'k';
}

string Solve(){
  ll n;
  scanf("%lld", &n);

  string ans;
  for( ; n != 0; n = (n - 1) / 5){
    ans.push_back(GetChar(n % 5));
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}