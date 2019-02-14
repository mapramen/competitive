#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100005

char a[N], b[N];
int p[N], s[N];

int main(){
  int n, m;
  pii ans = MP(0, 0);

  scanf("%s", a + 1);
  scanf("%s", b + 1);

  n = strlen(b + 1);
  m = strlen(a + 1);

  for(int i = 1, j = 1; i <= n && j <= m; i++){
    for( ; j <= m && a[j] != b[i]; j++)
      p[j] = i - 1;
    if(a[j] == b[i]){
      p[j] = i;
      j++;
    }
  }

  for(int i = m + 1; i > 0; i--)
    s[i] = n + 1;
    
  for(int i = n, j = m; i > 0 && j > 0; i--){
    for( ; j > 0 && a[j] != b[i]; j--)
      s[j] = i + 1;
    if(a[j] == b[i]){
      s[j] = i;
      j--;
    }
  }

  for(int i = 1; i <= m; i++)
    p[i] = max(p[i], p[i - 1]);

  for(int i = m; i > 0; i--)
    s[i] = min(s[i], s[i + 1]);

  for(int i = 0; i <= m; i++){
    if(p[i] < s[i + 1]){
      pii ansx = MP(p[i] + n - s[i + 1] + 1, i);
      ans = max(ans, ansx);
    }
  }

  for(int i = 1; i <= p[ans.second]; i++)
    putchar(b[i]);

  for(int i = s[ans.second + 1]; i <= n; i++)
    putchar(b[i]);

  if(ans.first == 0)
    putchar('-');

  putchar('\n');

  return 0;
}
