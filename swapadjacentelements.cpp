#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];
char s[N];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  scanf("%s", s);

  for(int i = 1; i < n; ++i){
    if(s[i - 1] == '0')
      continue;
    int j = i;
    for( ; j < n && s[j - 1] == '1'; ++j);
    --j;
    sort(a + i, a + j + 2);
    i = j;
  }

  for(int i = 2; i <= n; ++i){
    if(a[i] < a[i - 1]){
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;
}
