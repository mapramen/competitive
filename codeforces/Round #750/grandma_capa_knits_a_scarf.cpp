#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];

int Cost(int n, char c){
  int ans = 0, i = 0, j = n - 1;

  while(i < j){
    if(s[i] == s[j]){
      ++i, --j;
      continue;
    }

    if(s[i] == c){
      ++ans, ++i;
      continue;
    }

    if(s[j] == c){
      ++ans, --j;
      continue;
    }

    return INT_MAX;
  }

  return ans;
}

int Solve(){
  int n;
  scanf("%d%s", &n, s);

  int ans = INT_MAX;
  for(char c = 'a'; c <= 'z'; ++c){
    ans = min(ans, Cost(n, c));
  }

  return ans == INT_MAX ? -1 : ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}