#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5002

char s[N];
int c[N];

int main(){
  int n;

  scanf("%s", s);

  n = strlen(s);

  for(int i = 1; i <= n; ++i)
    c[i] = c[i - 1] + (s[i - 1] == 'a');

  int ans = c[n];
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      int ansx = c[i - 1] + c[n] - c[j] + (j - i + 1 - (c[j] - c[i - 1]));
      ans = max(ans, ansx);
    }
  }

  printf("%d\n", ans);

  return 0;
}
