#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int n;
  scanf("%d", &n);

  int ans1 = 0, ans2 = 0, ans3 = 0;
  
  while(n--){
    int cost1, cost2, cost3;
    scanf("%d%d%d", &cost1, &cost2, &cost3);

    int new_ans1 = cost1 + min(ans2, ans3);
    int new_ans2 = cost2 + min(ans1, ans3);
    int new_ans3 = cost3 + min(ans1, ans2);

    ans1 = new_ans1, ans2 = new_ans2, ans3 = new_ans3;
  }

  return min(ans1, min(ans2, ans3));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}