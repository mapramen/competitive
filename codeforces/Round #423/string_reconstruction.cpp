#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000001

vector<string> v;
int stringNo[N];
char s[N];

int main(){
  for(int i = 0; i < N; i++){
    stringNo[i] = -1;
    s[N] = '\0';
  }

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    string t;
    cin >> t;
    v.PB(t);

    int k, l;
    scanf("%d", &k);
    l = t.size();
    while(k--){
      int x;
      scanf("%d", &x);
      x--;
      if(stringNo[x] == -1 || l > v[stringNo[x]].size())
        stringNo[x] = i;
    }
  }

  n = 0;
  for(int i = 0; i < N; i++){
    if(stringNo[i] != -1)
      n = max(n, i + (int)v[stringNo[i]].size());
  }

  for(int i = 0, j = 0; i < n; i++){
    if(stringNo[i] == -1){
      if(s[i] == '\0')
        s[i] = 'a';
    }
    else{
      for( ; j < n && s[j] != '\0'; j++);
      int k = j - i;
      for( ; k < v[stringNo[i]].size(); k++, j++)
        s[j] = v[stringNo[i]][k];
    }
  }

  printf("%s\n", s);

  return 0;
}
