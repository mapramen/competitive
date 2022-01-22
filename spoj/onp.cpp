#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  string s;
  cin >> s;

  string ans, S;
  for(char c: s){
    if('a' <= c && c <= 'z'){
      ans.push_back(c);
      continue;
    }

    if(c == '('){
      continue;
    }

    if(c == ')'){
      ans.push_back(S.back());
      S.pop_back();
      continue;
    }

    S.push_back(c);
  }

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