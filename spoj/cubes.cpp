#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int main(){
  for(int a = 2; a < N; ++a){
    for(int b = 2; b < a; ++b){
      for(int c = b; c < a; ++c){
        for(int d = c; d < a; ++d){
          if(a * a * a == b * b * b + c * c * c + d * d * d){
            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
          }
        }
      }
    }
  }
  return 0;
}