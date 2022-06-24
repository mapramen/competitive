#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> Decimal2NegativeBinary(int n){
  if(n == 0){
    return {0};
  }

  vector<int> v;
  while(n != 0){
    int r = n % -2;
    n /= -2;

    if(r < 0){
      r += 2;
      n++;
    }

    v.push_back(r);
  }

  return v;
}

int main(){
  int n;
  scanf("%d", &n);

  vector<int> v = Decimal2NegativeBinary(n);
  for(int i = v.size() - 1; i != -1; --i){
    printf("%d", v[i]);
  }
  printf("\n");

  return 0;
}