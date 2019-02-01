#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int n, T[N];

void Update(int i, int x){
  for( ; i <= n; i += (i&-i))
    T[i] += x;
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i&-i))
    ans += T[i];
  return ans;
}

int BinarySearch(int k){
  int x = 1, y = n, z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    int q = Query(mid);
    if(q < k){
      x = mid + 1;
    }
    else if(q == k){
      z = mid;
      y = mid - 1;
    }
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int t;

  scanf("%d", &t);

  while(t--){
    int k, x;
    scanf("%d%d", &n, &k);

    if(k < 0)
      x = -1;
    else
      x = 1;

    k = abs(k);

    for(int i = 1; i <= n; i++)
      T[i] = 0;

    for(int i = 1; i <= n; i++)
      Update(i, 1);

    int i = 1;
    ll kx = k;
    for(int m = n; m > 1; m--, kx += k, x = -x){
      int j = (kx - 1) % m + 1;
      int qi = Query(i);
      if(x == -1){
        if(j <= qi)
          i = BinarySearch(qi - j + 1);
        else
          i = BinarySearch(m - (j - qi) + 1);
      }
      else{
        if(j <= m - qi + 1)
          i = BinarySearch(qi + j - 1);
        else
          i = BinarySearch(j - (m - qi + 1));
      }
      Update(i, -1);
      qi = Query(i);

      if(x == -1){
        if(qi == m - 1)
          i = BinarySearch(1);
        else
          i = BinarySearch(qi + 1);
      }
      else{
        if(qi == 0)
          i = BinarySearch(m - 1);
        else
          i = BinarySearch(qi);
      }
    }

    printf("%d\n", i);
  }

  return 0;
}
