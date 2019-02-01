#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int c[N], p[N];

int main(){
  int n, k;
  stack<int> A, S;
  vector<int> a;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= k; ++i){
    scanf("%d", &p[i]);
    c[p[i]] = -1;
    a.PB(p[i]);
  }

  for(int i = k; i > 0; --i)
    A.push(p[i]);

  for(int i = 1; i <= n; ++i)
    ++c[i];

  int x = 1;
  while(!A.empty()){
    if(!S.empty() && S.top() == x){
      S.pop();
      ++x;
      continue;
    }

    while(!A.empty() && A.top() != x){
      if(!S.empty() && A.top() > S.top()){
        printf("-1\n");
        return 0;
      }
      S.push(A.top());
      A.pop();
    }

    if(!A.empty()){
      S.push(A.top());
      A.pop();
    }
  }

  while(!S.empty()){
    for(int y = S.top() - 1; y >= x; --y){
      if(c[y]){
        a.PB(y);
        c[y] = 0;
      }
    }
    x = S.top() + 1;
    S.pop();
  }

  for(int y = n; y > 0; --y){
    if(c[y]){
      a.PB(y);
    }
  }

  for(auto x : a)
    printf("%d ", x);
  printf("\n");

  return 0;
}
