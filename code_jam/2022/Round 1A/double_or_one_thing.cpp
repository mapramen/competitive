#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  string s;
  cin >> s;

  int n = s.size();

  string ans;
  for(int i = 0; i < n; ++i){
    ans.push_back(s[i]);

    int j;
    for(j = i; j < n && s[j] == s[i]; ++j);

    if(j < n && s[j] > s[i]){
      ans.push_back(s[i]);
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve().c_str());
  }
  return 0;
}