#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> freq, first_index;

pii GetCmpPair(int x){
  return {freq[x], -first_index[x]};
}

int main(){
  int n, c;
  scanf("%d%d", &n, &c);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d ", &x);
  }

  for(int i = n - 1; i != -1; --i){
    ++freq[a[i]], first_index[a[i]] = i;
  }

  sort(a.begin(), a.end(), [](int i, int j) { return GetCmpPair(i) > GetCmpPair(j); });

  for(int& x: a){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}