#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200000

int a[N];

int main(){
  int n, k;
  stack<int> s;

  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sort(a, a + n);

  for(int i = 0; i < n; ++i){
    int x = a[i];
    while(!s.empty() && s.top() < x && x <= s.top() + k)
      s.pop();
    s.push(x);
  }

  printf("%lu\n", s.size());

  return 0;
}
