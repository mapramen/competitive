#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define L 21

map< string, int > dictionary;
int parent[N], color[N];
char sraw[L];

int FindParent(int i){
	if(i == parent[i])
		return i;

	int p = parent[i];

	parent[i] = FindParent(parent[i]);
	color[i] = color[i] ^ color[p];

	return parent[i];
}

void UnionParent(int i, int j, int k){
	int p1 = FindParent(i);
	int p2 = FindParent(j);

	if(p1 > p2)
    swap(p1, p2);

	parent[p2] = p1;
	color[p2] = k ^ color[i] ^ color[j];
}

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; i++){
    scanf("%s", sraw);
    dictionary[string(sraw)] = i;
    parent[i] = i;
  }

  while(m--){
    int t;
    scanf("%d", &t);

    scanf("%s", sraw);
    int i = dictionary[string(sraw)];

    scanf("%s", sraw);
    int j = dictionary[string(sraw)];

    int pi = FindParent(i), pj = FindParent(j);
    t--;

    if(pi == pj){
      if((color[i] ^ color[j]) == t)
        printf("YES\n");
      else
        printf("NO\n");
    }
    else{
      UnionParent(i, j, t);
      printf("YES\n");
    }
  }

  while(q--){
    int ans;
    scanf("%s", sraw);
    int i = dictionary[string(sraw)];

    scanf("%s", sraw);
    int j = dictionary[string(sraw)];

    int pi = FindParent(i), pj = FindParent(j);

    if(pi != pj)
      ans = 3;
    else
      ans = 1 + (color[i] ^ color[j]);

    printf("%d\n", ans);
  }

  return 0;
}
