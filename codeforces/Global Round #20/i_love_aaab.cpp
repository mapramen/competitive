#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;

  int b_count = 0, a_count = 0;
  for(char c: s){
    if(c == 'A'){
      ++a_count;
      continue;
    }

    if(a_count < ++b_count){
      return false;
    }
  }

  return s.back() == 'B';
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}