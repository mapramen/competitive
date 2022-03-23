#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N], t[N];
int f[N];

int ComputeFailure(int k, char c){
  while(k != 0 && s[k] != c){
    k = f[k];
  }
  return k + (s[k] == c);
}

void Solve(){
  scanf("%s%s", t, s);

  int n = strlen(s);
  for(int i = 2; i <= n; ++i){
    f[i] = ComputeFailure(f[i - 1], s[i - 1]);
  }

  vector<int> v;
  for(int i = 0, m = strlen(t), k = 0; i < m; ++i){
    k = ComputeFailure(k, t[i]);
    if(k == n){
      v.push_back(i - n + 2);
      k = f[k];
    }
  }

  if(v.empty()){
    printf("Not Found\n");
    return;
  }

  printf("%lu\n", v.size());
  for(int i: v){
    printf("%d ", i);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
    if(t != 0){
      printf("\n");
    }
  }
  return 0;
}