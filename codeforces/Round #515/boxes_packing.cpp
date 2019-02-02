#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

bool Check(int i, int n, int m, int k){
  --m;
  for(int s = k; i <= n && m >= 0; ++i){
    if(s < a[i]){
      s = k;
      --m;
    }
    s -= a[i];
  }
  return (m >= 0);
}

int BinarySearch(int n, int m, int k){
  int x = min(n, m) + 1, y = n, z = min(n, m);
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n - mid + 1, n, m, k)){
      z = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return z;
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  printf("%d\n", BinarySearch(n, m, k));

  return 0;
}
