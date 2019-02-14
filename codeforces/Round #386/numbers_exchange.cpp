#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N];

int main(){
  int n, m, i, j, k, evenrem, oddrem, ans;
  set<int> s;
  queue<int> q;
  scanf("%d%d", &n, &m);

  for(i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(i = 1, evenrem = oddrem = n / 2; i <= n; i++){
    int x = a[i];

    if((x % 2 == 1 && oddrem == 0) || (x % 2 == 0 && evenrem == 0))
      q.push(i);
    else{
      if(s.find(x) == s.end()){
        s.insert(x);
        if(x % 2)
          oddrem--;
        else
          evenrem--;
      }
      else
        q.push(i);
    }
  }

  ans = q.size();

  i = 1;
  while(!q.empty() && i <= m){
    j = q.front();
    q.pop();

    if(s.find(i) == s.end()){
      if(evenrem != 0 && i % 2 == 0){
        a[j] = i;
        evenrem--;
        s.insert(i);
      }
      else if(oddrem != 0 && i % 2 == 1){
        a[j] = i;
        oddrem--;
        s.insert(i);
      }
      else
        q.push(j);
    }
    else
      q.push(j);

    i++;
  }

  if(!q.empty() || n % 2 == 1)
    printf("-1\n");
  else{
    printf("%d\n", ans);
    for(i = 1; i <= n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }

  return 0;
}
