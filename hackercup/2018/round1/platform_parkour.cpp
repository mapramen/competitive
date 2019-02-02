#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 200001
#define M 1000001
#define MAX_ITER 50

int h[N];
pii L[N], R[N];
double A[N], B[N];
bool visited[N];

bool Check(int n, double m){
  bool check = 1;
  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    A[i] = max(0.0, h[i] - m);
    B[i] = h[i] + m;
    visited[i] = 0;
    Q.push(i);
  }

  while(!Q.empty() && check == 1){
    int i = Q.front();
    Q.pop();

    visited[i] = 1;

    for(int j = i - 1; j <= i + 1; j += 2){
      if(j < 1 || j > n){
        continue;
      }

      int u, d;

      if(j < i){
        tie(d, u) = L[i];
      }
      else{
        tie(d, u) = R[i];
      }

      double a = max(0.0, A[i] - d), b = B[i] + u;

      if(a <= A[j] && B[j] <= b){
        continue;
      }

      A[j] = max(A[j], a);
      B[j] = min(B[j], b);

      if(A[j] > B[j]){
        check = 0;
        break;
      }

      if(visited[j]){
        Q.push(j);
        visited[j] = 0;
      }
    }
  }

  return check;
}

double BinarySearch(int n){
  double x = 0, y = M;
  for(int iter = 0; iter < MAX_ITER; ++iter){
    double mid = x + (y - x) / 2;
    if(Check(n, mid)){
      y = mid;
    }
    else{
      x = mid;
    }
  }
  return (x + y) / 2;
}

double Solve(){
  int n, m;
  ll W, X, Y, Z;

  scanf("%d%d", &n, &m);

  scanf("%d%d%lld%lld%lld%lld", &h[1], &h[2], &W, &X, &Y, &Z);

  for(int i = 1; i <= n; ++i){
    L[i] = MP(M, M);
    R[i] = MP(M, M);
  }

  while(m--){
    int a, b, u, d;
    scanf("%d%d%d%d", &a, &b, &u, &d);

    if(a < b){
      for(int i = a; i < b; ++i){
        R[i].first = min(R[i].first, d);
        R[i].second = min(R[i].second, u);
        L[i + 1].first = min(L[i + 1].first, u);
        L[i + 1].second = min(L[i + 1].second, d);
      }
    }
    else{
      for(int i = a; i > b; --i){
        L[i].first = min(L[i].first, d);
        L[i].second = min(L[i].second, u);
        R[i - 1].first = min(R[i - 1].first, u);
        R[i - 1].second = min(R[i - 1].second, d);
      }
    }
  }

  for(int i = 3; i <= n; ++i){
    h[i] = (W * h[i - 2] + X * h[i - 1] + Y) % Z;
  }

  return BinarySearch(n);
}

int main(){
  int t;

  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %.9lf\n", k, Solve());
  }

  return 0;
}
