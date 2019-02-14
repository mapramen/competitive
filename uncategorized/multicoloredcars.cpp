#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int c[N];
bool valid[N];

int main(){
  int n, A, B = -1;

  for(int i = 1; i < N; i++)
    valid[i] = 1;

  scanf("%d%d", &n, &A);
  while(n--){
    int i;
    scanf("%d", &i);
    if(i != A && c[i] < c[A])
      valid[i] = 0;
    c[i]++;
  }

  for(int i = 1; i < N && B == -1; i++){
    if(i == A)
      continue;

    if(valid[i])
      valid[i] = (c[i] >= c[A]);

    if(valid[i])
      B = i;
  }

  printf("%d\n", B);

  return 0;
}
