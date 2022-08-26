#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<char> S;

bool Solve(){
  string s;
  cin >> s;

  S.clear();
  for(char c: s){
    if(c == '1' || S.size() < 2){
      S.push_back(c);
      continue;
    }

    int n = S.size();
    if(c == '0' && S[n - 2] == '1' && S[n - 1] == '0'){
      S.pop_back(), S.pop_back();
    }
    else{
      S.push_back(c);
    }
  }

  return S.empty();
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %s\n", k, Solve() ? "yes" : "no");
  }
  return 0;
}