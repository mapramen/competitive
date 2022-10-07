#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int a[N];
char s[N];
int f[N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

bool Solve(){
  int m;
  scanf("%d", &m);

  for(int i = 1; i <= m; ++i){
    scanf("%d", &a[i]);
  }

  scanf("%s", s);
  int n = strlen(s);

  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  int k = 0;
  for(int i = 2; i <= m && k != n; ++i){
    char c = a[i - 1] == a[i] ? 'E' : a[i - 1] < a[i] ? 'G' : 'L';
    k = ComputeFailure(k, c);
  }

  return k == n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}