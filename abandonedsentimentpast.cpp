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
  int n, k, b;

  cin >> n >> k;

  if(k > 1){
    printf("Yes\n");
  }
  else{
    for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);

    scanf("%d", &b);

    for(int i = 1; i <= n; i++){
      if(a[i] == 0)
        a[i] = b;

      if(a[i] < a[i - 1]){
        printf("Yes\n");
        return 0;
      }
    }

    printf("No\n");
  }
  
  return 0;
}
