#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 4
#define MOD 1000000007

typedef struct node{
  int leftEnd;
  int rightEnd;
  bool valid;
  int prefixLE;
  int suffixLE;
  ll data[B][B];
  node* leftChild;
  node* rightChild;
}node;

int a[N], T[N], cnt[N], pLE[N], sLE[N], inds[N];
vector< vector<int> > prefixLE(N), suffixLE(N);
node *root[N];

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd, int rootNo){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;

  for(int i = 0; i < B; i++)
    for(int j = 0; j < B; j++)
      temp->data[i][j] = 0;

  temp->valid = 0;

  if(leftEnd == rightEnd){
    temp->valid = 1;
    temp->prefixLE = prefixLE[rootNo][leftEnd];
    temp->suffixLE = suffixLE[rootNo][leftEnd];

    for(int i = 0; i < B; i++)
      temp->data[i][i] = 1;

    temp->data[0][1] = temp->prefixLE;
    temp->data[2][3] = temp->suffixLE;
    temp->data[1][2] = 1;
  }

  return temp;
}

void MergeData(ll a[B][B], ll b[B][B], ll c[B][B]){
  for(int i = 0; i < B; i++)
    for(int j = i; j < B; j++){
      c[i][j] = 0;
      for(int k = i; k < B; k++)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    }
}

node* BuildSegmentTree(int leftEnd, int rightEnd, int rootNo){
  node *temp = CreateNode(leftEnd, rightEnd, rootNo);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid, rootNo);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd, rootNo);
    MergeData(temp->leftChild->data, temp->rightChild->data, temp->data);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void UpdateLeafNode(node *leafNode){
  leafNode->valid = 1 ^ leafNode->valid;
  leafNode->data[0][1] = leafNode->valid * leafNode->prefixLE;
  leafNode->data[2][3] = leafNode->valid * leafNode->suffixLE;
  leafNode->data[1][2] = leafNode->valid;
}

void UpdateNode(node *currentNode, int i){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && currentNode->rightEnd == i)
      UpdateLeafNode(currentNode);
    else{
      UpdateNode(currentNode->leftChild, i);
      UpdateNode(currentNode->rightChild, i);
      MergeData(currentNode->leftChild->data, currentNode->rightChild->data, currentNode->data);
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void BITUpdate(int i, int n){
  for( ; i <= n; i += (i & -i))
    T[i]++;
}

int BITQuery(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

int CoordinateCompress(int n){
  int m;
  vector<int> v;

  for(int i = 1; i <= n; i++)
    v.PB(a[i]);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i <= n; i++)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

  m = v.size();

  return m;
}

int Initialisation(int n){
  int m = CoordinateCompress(n);

  for(int i = 1; i <= n; i++){
    pLE[i] = BITQuery(a[i]);
    BITUpdate(a[i], m);
  }

  for(int i = 1; i <= m; i++)
    T[i] = 0;

  for(int i = n; i > 0; i--){
    sLE[i] = BITQuery(a[i]);
    BITUpdate(a[i], m);
  }

  for(int i = 1; i <= m; i++){
    prefixLE[i].PB(0);
    suffixLE[i].PB(0);
  }

  for(int i = 1; i <= n; i++){
    int j = a[i];
    cnt[j]++;
    inds[i] = cnt[j];
    prefixLE[j].PB(pLE[i]);
    suffixLE[j].PB(sLE[i]);
  }

  for(int i = 1; i <= m; i++){
    int treeSize = cnt[i];
    root[i] = BuildSegmentTree(1, treeSize, i);
  }

  return m;
}

ll Query(int k){
  return root[k]->data[0][3];
}

ll Update(int i){
  int k = a[i];
  ll ansChange = - Query(k);
  UpdateNode(root[k], inds[i]);
  ansChange = (Query(k) + ansChange + MOD) % MOD;
  return ansChange;
}

int main(){
  int n, q, totalRoots;
  ll ans = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  totalRoots = Initialisation(n);

  for(int i = 1; i <= totalRoots; i++)
    ans = (ans + Query(i)) % MOD;

  scanf("%d", &q);

  while(q--){
    int t, x;
    scanf("%d%d", &t, &x);
    ans = (ans + Update(x)) % MOD;
    printf("%lld\n", ans);
  }

	return 0;
}
