#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 100001

class Node{
  public:
  Node(int _l, int _r){
    l = _l, r = _r, val = INT_MAX;

    if(l == r){
      leftChild = NULL, rightChild = NULL;
    }
    else{
      int mid = (l + r) / 2;
      leftChild = new Node(l, mid), rightChild = new Node(mid + 1, r);
    }
  }

  void Update(int i, int x){
    if(i < l || r < i){
      return;
    }

    if(l == i && r == i){
      val = x;
      return;
    }

    leftChild->Update(i, x), rightChild->Update(i, x);
    val = min(leftChild->val, rightChild->val);
  }

  int Query(int ql, int qr){
    if(qr < ql || qr < l || r < ql){
      return INT_MAX;
    }

    if(ql <= l && r <= qr){
      return val;
    }

    return min(leftChild->Query(ql, qr), rightChild->Query(ql, qr));
  }

  private:
  int l;
  int r;
  int val;

  Node* leftChild;
  Node* rightChild;
};

vector<vector<int>> adj(N), chains(N);
int parent[N], startTime[N], startTimeToVertex[N], subtreeSize[N], chainNumber[N], chainLeader[N], chainPosition[N], timer = 0;
bool colored[N];
Node* st[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    adj[i].clear();
    chains[i].clear();
    chainNumber[i] = i;
    colored[i] = false;
  }

  timer = 0;
}

void DFS(int i, int p){
  parent[i] = p;
  startTime[i] = ++timer;
  startTimeToVertex[startTime[i]] = i;
  subtreeSize[i] = 1;

  int heavyChild = 0;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DFS(j, i);
    subtreeSize[i] += subtreeSize[j];

    if(subtreeSize[j] > subtreeSize[heavyChild]){
      heavyChild = j;
    }
  }

  if(heavyChild == 0){
    heavyChild = i;
  }

  chainNumber[i] = chainNumber[heavyChild];
  chains[chainNumber[i]].push_back(i);
}

void PreProcess(int n){
  DFS(1, 0);

  for(int chainNo = 1; chainNo <= n; ++chainNo){
    vector<int>& chain = chains[chainNo];
    if(chain.empty()){
      continue;
    }
    reverse(chain.begin(), chain.end());

    chainLeader[chainNo] = chain.front();

    int chainPos = 0;
    for(int i: chain){
      chainPosition[i] = ++chainPos;
    }

    st[chainNo] = new Node(1, chainPos);
  }
}

void Update(int i){
  colored[i] = !colored[i];
  st[chainNumber[i]]->Update(chainPosition[i], colored[i] ? startTime[i] : INT_MAX);
}

int Query(int i){
  int ans = INT_MAX;

  while(i != 0){
    ans = min(ans, st[chainNumber[i]]->Query(1, chainPosition[i]));
    i = parent[chainLeader[chainNumber[i]]];
  }

  return ans == INT_MAX ? -1 : startTimeToVertex[ans];
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n);

  while(q--){
    int t, i;
    scanf("%d%d", &t, &i);
    
    if(t == 0){
      Update(i);
    }
    else{
      printf("%d\n", Query(i));
    }
  }

  return 0;
}