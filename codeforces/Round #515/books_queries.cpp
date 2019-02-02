#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];
char s[2];

int main(){
  int q, l = N - 1, r = l;

  scanf("%d", &q);
  while(q--){
    int i;
    scanf("%s%d", s, &i);
    if(s[0] == 'L'){
      a[i] = l--;
      if(r == l + 1){
        ++r;
      }
    }
    else if(s[0] == 'R'){
      a[i] = r++;
      if(r == l + 1){
        --l;
      }
    }
    else{
      printf("%d\n", min(abs(a[i] - l), abs(a[i] - r)) - 1);
    }
  }

  return 0;
}
