#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

int a[N];

int main(){
  int n, i, j;

  scanf("%d", &n);

  for(i = 1, j = 0; i <= n; i++){
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
    if(a[i] != 0 && j == 0)
      j = i;
  }

  if(j == 0)
    printf("NO\n");
  else{
    printf("YES\n");

    if(a[n] != 0)
      printf("1\n1 %d\n", n);
    else{
      for(j = 1; j < n && a[j] == a[n]; j++);
      printf("2\n1 %d\n%d %d\n", j, j + 1, n);
    }
  }

	return 0;
}
