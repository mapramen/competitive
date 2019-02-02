#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector< pii > > v(N);
int a[N], total;
priority_queue< pii > Q;

void CheckAndPop(int &k, int b){
  if(total < b || k == 0)
    return ;
  int totalx = b;
  while(totalx > 0){
    auto p = Q.top();
    Q.pop();
    if(p.second <= totalx){
      totalx -= p.second;
    }
    else{
      p.second -= totalx;
      totalx = 0;
      Q.push(p);
    }
  }
  total -= b;
  --k;
}

int GetCount(int n, int m, int b){
  int k1 = (n + 1) / 2, k2 = n / 2 - m, p = (n + 1) / 2;

  total = 0;
  while(!Q.empty())
    Q.pop();

  for(int i = n; i > 0; --i){
    for(auto p : v[i]){
      total += p.second;
      Q.push(p);
    }

    if(i > p)
      CheckAndPop(k2, b);
    else
      CheckAndPop(k1, b);

    while(!Q.empty() && Q.top().first >= i){
      total -= Q.top().second;
      Q.pop();
    }
  }

  if(k2 != 0)
    k1 = INT_MAX;

  return k1;
}

int BinarySearch(int n, int b){
  int x = 0, y = n / 2;
  while(y - x > 2){
    int k2 = x + (y - x) / 2;
    int k1 = GetCount(n, k2, b);

    if(k1 == INT_MAX)
      x = k2 + 1;

    if(k1 >= k2)
      x = k2;
    else
      y = k2;
  }

  int ans = (n + 1) / 2;
  for(int k = x; k <= y; ++k)
    ans = min(ans, max(k, GetCount(n, k, b)));

  return ans;
}

int GetLeftEnd(int i, int n, int d){
  int x = 1, y = i, z = i;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(i - mid <= 1ll * d * mid)
      z = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return z;
}

int GetRightEnd(int i, int n, int d){
  int x = i, y = n, z = i;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(mid - i <= 1ll * d * (n - mid + 1))
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int n, d, b;

  scanf("%d%d%d", &n, &d, &b);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; ++i){
    int l = GetLeftEnd(i, n, d);
    int r = GetRightEnd(i, n, d);
    v[r].PB(MP(l, a[i]));
  }

  printf("%d\n", BinarySearch(n, b));

  return 0;
}
