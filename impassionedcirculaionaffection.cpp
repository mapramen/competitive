#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1501
#define B 26

int dp[B][N];

int main(){
  int n, q;
  string s;

  cin >> n >> s >> q;
  while(q--){
    int m, ans = 0;
    char sx[2], c;

    scanf("%d", &m);
    scanf("%s", sx);
    c = sx[0];

    if(dp[c - 'a'][m] == 0){
      for(int i = 0, j = 0, k = 0; i < n; i++){
        for(j = max(i, j); j < n && (k < m || (k == m && s[j] == c)); j++)
        k += (s[j] != c);
        ans = max(ans, j - i);
        k -= (s[i] != c);
      }
      dp[c - 'a'][m] = ans;
    }

    printf("%d\n", dp[c - 'a'][m]);
  }

  return 0;
}
