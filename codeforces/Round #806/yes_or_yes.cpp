#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  string s;
  cin >> s;
  return toupper(s[0]) == 'Y' && toupper(s[1]) == 'E' && toupper(s[2]) == 'S';
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}