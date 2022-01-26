#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Check(vector<string>& words){
  set<string> S;

  for(string& s: words){
    if(s.size() == 1){
      return true;
    }

    string t = string(s);
    reverse(t.begin(), t.end());

    if(s == t || S.count(t) != 0){
      return true;
    }

    t.pop_back();
    if(S.count(t) != 0){
      return true;
    }

    S.insert(s);
  }

  return false;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<string> s(n);
  for(string& sx: s){
    cin >> sx;
  }

  if(Check(s)){
    return true;
  }

  for(string& sx: s){
    reverse(sx.begin(), sx.end());
  }
  reverse(s.begin(), s.end());

  return Check(s);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}