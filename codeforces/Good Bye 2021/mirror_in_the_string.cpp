#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n;
  string s;

  cin >> n >> s;

  if(n == 1 || s[1] == s[0]){
    return string(2, s[0]);
  }

  int k = 1;
  for( ; k < n && s[k] <= s[k - 1]; ++k);

  for( ; s.size() > k; s.pop_back());

  string t(s);
  reverse(t.begin(), t.end());

  return s + t;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}