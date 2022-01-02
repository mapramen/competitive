#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];
int p[N];
bool marked[N];
 
void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  scanf("%s", s);
  
  int m = 0;
  for(int i = 0; i < n; ++i){
    m += s[i] == '0';
  }

  for(int i = 1; i <= n; ++i){
    if(s[i - 1] == '0' && p[i] > m){
      p[i] = 0;
    }

    if(s[i - 1] == '1' && p[i] <= m){
      p[i] = 0;
    }

    marked[p[i]] = true;
  }

  for(int i = 1, k = 1; i <= n; ++i){
    if(s[i - 1] == '1' || p[i] != 0){
      continue;
    }
    for( ; marked[k]; ++k);
    marked[k] = true;
    p[i] = k++;
  }

  for(int i = 1, k = 1; i <= n; ++i){
    if(s[i - 1] == '0' || p[i] != 0){
      continue;
    }
    for( ; marked[k]; ++k);
    marked[k] = true;
    p[i] = k++;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", p[i]);
    marked[i] = false;
  }
  printf("\n");
}
 
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}