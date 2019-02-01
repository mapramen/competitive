#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001

int a[N], b[N];
set<int> s;

int main(){
  int n, ans = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    s.insert(a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
    s.insert(b[i]);
  }

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      ans += (s.find(a[i] ^ b[j]) != s.end());

  if(ans % 2)
    printf("Koyomi\n");
  else
    printf("Karen\n");

  return 0;
}
