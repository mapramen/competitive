#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26

string Solve(){
  string s;
  cin >> s;

  vector<int> C(B);
  for(char c: s){
    ++C[c - 'a'];
  }

  reverse(s.begin(), s.end());
  while(C[s.back() - 'a'] > 1){
    --C[s.back() - 'a'];
    s.pop_back();
  }
  reverse(s.begin(), s.end());

  return s;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}