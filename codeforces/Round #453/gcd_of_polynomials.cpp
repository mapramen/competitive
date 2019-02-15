#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 151

int P[N][N];

void Print(int n){
  cout << n << '\n';
  for(int i = 0; i <= n; ++i)
    cout << P[n][i] << ' ';
  cout << '\n';
}

int main(){
  int n;

  cin >> n;

  P[0][0] = P[1][1] = 1;

  for(int i = 2; i <= n; ++i){
    for(int j = 0; j < N; ++j)
      P[i][j] += P[i - 2][j];

    for(int j = 1; j < N; ++j)
      P[i][j] = (P[i][j] + P[i - 1][j - 1]) % 2;
  }

  Print(n);
  Print(n - 1);

  return 0;
}
