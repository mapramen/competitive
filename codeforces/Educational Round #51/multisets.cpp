#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N], c[N];
char s[N];

int main(){
  int n;

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    ++c[a[i]];
  }

  int cur = 0;
  for(int i = 0; i < n; ++i){
    if(c[a[i]] > 1){
      continue;
    }
    s[i] = 'A' + cur;
    cur = 1 - cur;
  }

  if(cur){
    int i;
    for(i = 0; i < n && c[a[i]] <= 2; ++i);
    if(i == n){
      printf("NO\n");
      return 0;
    }
    s[i] = 'A' + cur;
  }

  for(int i = 0; i < n; ++i){
    if(s[i] != 'A' && s[i] != 'B'){
      s[i] = 'A';
    }
  }

  printf("YES\n%s\n", s);

  return 0;
}
