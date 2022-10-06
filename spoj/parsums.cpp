#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2000001

int A[N];
deque<int> Q;

int Solve(){
  int n;
  scanf("%d", &n);

  if(n == 0){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &A[i]);
    A[i + n] = A[i];
  }

  int ans = 0;
  for(int i = 1; i < 2 * n; ++i){
    A[i] += A[i - 1];
    while(!Q.empty() && A[Q.back()] >= A[i]){
      Q.pop_back();
    }

    while(!Q.empty() && i - Q.front() >= n){
      Q.pop_front();
    }

    Q.push_back(i);

    ans += (i >= n && A[Q.front()] >= A[i - n]);
  }

  Q.clear();

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}