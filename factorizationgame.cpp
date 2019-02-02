#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

int leastPrime[N];

int main(){
  for(int i = 2; i < N; ++i){
    if(leastPrime[i])
      continue;
    for(int j = i; j < N; j += i)
      if(leastPrime[j] == 0)
        leastPrime[j] = i;
  }

  int t;
  scanf("%d", &t);
  while(t--){
    int n, ans = 0;
    map<int,int> m;

    scanf("%d", &n);
    while(n--){
      int i;
      scanf("%d", &i);
      while(i > 1){
        m[leastPrime[i]]++;
        i /= leastPrime[i];
      }
    }

    for(auto it : m)
      ans ^= (it.second);

    if(ans)
      printf("Mancunian\n");
    else
      printf("Liverbird\n");
  }

  return 0;
}
