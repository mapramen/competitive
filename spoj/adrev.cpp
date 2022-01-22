#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  string a, b;
  cin >> a >> b;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string c;
  for(int carry = 0; carry != 0 || !a.empty() || !b.empty(); carry /= 10){
    if(!a.empty()){
      carry += (a.back() - '0');
      a.pop_back();
    }

    if(!b.empty()){
      carry += (b.back() - '0');
      b.pop_back();
    }

    c.push_back('0' + carry % 10);
  }

  reverse(c.begin(), c.end());
  for( ; c.back() == '0'; c.pop_back());
  reverse(c.begin(), c.end());

  return c;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}