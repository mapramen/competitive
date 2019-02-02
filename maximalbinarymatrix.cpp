#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N][N];

int main(){
  int n, m;

  cin >> n >> m;

  if(m > n * n){
    printf("-1\n");
  }
  else{
    for(int i = 1; i <= n && m > 0; i++){
      a[i][i] = 1;
      m--;
      for(int j = i + 1; j <= n && m >= 2; j++, m -= 2)
        a[i][j] = a[j][i] = 1;
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++)
        printf("%d ", a[i][j]);
      printf("\n");
    }
  }

  return 0;
}
