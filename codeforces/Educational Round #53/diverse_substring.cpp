#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  string s;

  cin >> n >> s;
  for(int i = 0; i < n - 1; ++i){
    if(s[i] != s[i + 1]){
      printf("YES\n%c%c\n", s[i], s[i + 1]);
      return 0;
    }
  }

  printf("NO\n");

  return 0;
}
