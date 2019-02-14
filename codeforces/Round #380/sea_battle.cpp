#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200010

char s[N];
int b, total;
priority_queue< pii > q;
queue<int> ans;

void CheckAndPush(int l, int i){
  if(l >= b){
    // printf("Add %d %d\n", l, i);
    q.push(MP(l, i));
    total += (l / b);
  }
}

void RemoveTop(){
  int l = q.top().first, i = q.top().second;
  // printf("Remove %d %d\n", l, i);
  q.pop();
  total -= (l / b);
  CheckAndPush(l - b, i + b);
  ans.push(i + b - 1);
}

int main(){
  int n, i, j, k, a;

  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", s);

  for(i = 0; s[i] != '\0'; i = j + 1){
    for(j = i; s[j] != '\0' && s[j] == '0'; j++);
    CheckAndPush(j - i, i + 1);
  }

  while(total >= a)
    RemoveTop();

  printf("%d\n", (int)ans.size());

  while(!ans.empty()){
    printf("%d ", ans.front());
    ans.pop();
  }
  printf("\n");

  return 0;
}
