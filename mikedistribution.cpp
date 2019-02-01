#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< piii > v(N);

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i].first.first);

  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i].first.second);

  for(int i = 1; i <= n; i++)
    v[i].second = i;

  sort(v.begin() + 1, v.end(), greater< piii >());

  printf("%d\n", (n + 2) / 2);
  printf("%d ", v[1].second);

  for(int i = 2; i < n; i += 2)
    if(v[i].first.second >= v[i + 1].first.second)
      printf("%d ", v[i].second);
    else
      printf("%d ", v[i + 1].second);

  if(n % 2 == 0)
    printf("%d", v[n].second);
  printf("\n");

  return 0;
}
