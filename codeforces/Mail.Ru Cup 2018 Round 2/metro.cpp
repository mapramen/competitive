#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int a[N], b[N];

int main(){
  int n, s;

  cin >> n >> s;

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int i = 1; i <= n; ++i){
    cin >> b[i];
  }

  for(int i = 1, j = b[s] == 0 ? n : s - 1; i <= j; ++i){
    b[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    if(a[1] == 1 && a[i] == 1 && (i == s || b[i] == 1)){
      printf("YES\n");
      return 0;
    }
  }

  printf("NO\n");

  return 0;
}
