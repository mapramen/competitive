#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > v(N);
int a[N], p[N];

int main(){
  int n, s = 0;

  scanf("%d", &n);

  bool perfect = 1;
  for(int i = 0; i <= n; ++i){
    scanf("%d", &a[i]);
    perfect &= (a[i] == 1 || (i > 0 && a[i - 1] == 1));
    s += a[i];
  }

  if(perfect){
    printf("perfect\n");
  }
  else{
    printf("ambiguous\n");
    v[0].PB(1);
    for(int i = 1, m = 2; i <= n; ++i){
      int x = a[i];
      while(x--){
        p[m] = v[i - 1].front();
        v[i].PB(m++);
      }
    }

    for(int i = 1; i <= s; ++i)
      printf("%d ", p[i]);
    printf("\n");

    for(int i = 1; i <= n; ++i){
      if(a[i] > 1 && a[i - 1] > 1){
        p[v[i].front()] = v[i - 1].back();
        break;
      }
    }

    for(int i = 1; i <= s; ++i)
      printf("%d ", p[i]);
    printf("\n");
  }

  return 0;
}
