#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int k[3];

int main(){
  for(int i = 0; i < 3; ++i)
    scanf("%d", &k[i]);

  sort(k, k + 3);

  if(k[0] == 1 || k[1] == 2 || (k[0] == 2 && k[1] == 4 && k[2] == 4) || (k[0] == 3 && k[2] == 3))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
