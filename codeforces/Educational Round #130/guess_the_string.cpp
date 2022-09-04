#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char ch[2];

char QueryCharacter(int i){
  printf("? 1 %d\n", i);
  fflush(stdout);
  scanf("%s", ch);
  return ch[0];
}

int QueryDistinctCharCount(int l, int r){
  printf("? 2 %d %d\n", l, r);
  fflush(stdout);

  int cnt;
  scanf("%d", &cnt);
  return cnt;
}

int main(){
  int n;
  scanf("%d", &n);

  string ans;
  vector<int> distinct_char_pos;

  for(int i = 1; i <= n; ++i){
    int x = 0, y = (int)distinct_char_pos.size() - 1, z = -1;
    while(x <= y){
      int mid = (x + y) / 2;
      int j = distinct_char_pos[mid];
      if(QueryDistinctCharCount(j, i) == distinct_char_pos.size() - mid){
        z = mid, x = mid + 1;
      }
      else{
        y = mid - 1;
      }
    }

    if(z != -1){
      ans.push_back(ans[distinct_char_pos[z] - 1]);
      distinct_char_pos[z] = i;
      sort(distinct_char_pos.begin(), distinct_char_pos.end());
      continue;
    }

    ans.push_back(QueryCharacter(i));
    distinct_char_pos.push_back(i);
  }

  printf("! %s\n", ans.c_str());
  fflush(stdout);

  return 0;
}