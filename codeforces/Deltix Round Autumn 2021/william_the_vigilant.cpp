#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char s[N];
char ch[2];

int Check(int i){
  return s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c';
}

int Update(int n, int k){
  int ans = 0;
  for(int i = max(2, k); i < min(n, k + 3); ++i){
    ans += Check(i);
  }
  return ans;
}

int main(){
  int n, q;
  scanf("%d%d%s", &n, &q, s);

  int ans = 0;
  for(int i = 2; i < n; ++i){
    ans += Check(i);
  }

  while(q--){
    int k;
    scanf("%d%s", &k, ch);

    --k;
    ans -= Update(n, k);

    s[k] = ch[0];
    ans += Update(n, k);

    printf("%d\n", ans);
  }

  return 0;
}