#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<string> s;
  for(int i = 1; i <= n; ++i){
    string t;
    cin >> t;
    s.push_back(t);
  }

  vector<int> C(m + 1);
  for(int j = 2; j <= m; ++j){
    for(int i = 2; i <= n; ++i){
      if(s[i - 1][j - 2] == 'X' && s[i - 2][j - 1] == 'X'){
        C[j] = 1;
      }
    }
  }

  for(int j = 2; j <= m; ++j){
    C[j] += C[j - 1];
  }

  int q;
  scanf("%d", &q);
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%s\n", (C[l] == C[r]) ? "YES" : "NO");
  }
  
  return 0;
}