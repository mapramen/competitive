#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf 20000

vector<int> ReadArray(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  vector<int> a(n + 2);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  a[0] = -inf, a[n + 1] = inf;

  return a;
}

int Solve(){
  vector<int> a = ReadArray();
  vector<int> b = ReadArray();

  int ans = 0;
  
  for(int n = a.size(), m = b.size(), i = 0, j = 0, suma = 0, sumb = 0; i < n && j < m; ){
    if(a[i] == b[j]){
      ans += max(suma, sumb) + a[i];
      suma = 0, sumb = 0, ++i, ++j;
      continue;
    }

    if(a[i] < b[j]){
      suma += a[i], ++i;
    }
    else{
      sumb += b[j], ++j;
    }
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}