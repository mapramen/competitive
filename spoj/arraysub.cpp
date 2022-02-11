#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  int k;
  scanf("%d", &k);

  deque<int> Q;
  for(int i = 0; i < n; ++i){
    int x = a[i];

    while(!Q.empty() && a[Q.back()] <= x){
      Q.pop_back();
    }

    while(!Q.empty() && i - Q.front() >= k){
      Q.pop_front();
    }

    Q.push_back(i);
    
    if(i >= k - 1){
      printf("%d ", a[Q.front()]);
    }
  }
  printf("\n");
  
  return 0;
}