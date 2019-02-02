#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tlll tuple<ll,ll,ll>
#define PB push_back
#define MP make_pair
#define MT make_tuple

vector< tlll > rings;
vector<ll> compressedX;

typedef struct node{
  int leftEnd;
  int rightEnd;
  ll ans;
  node* leftChild;
  node* rightChild;
}node;

int CoordinateCompression(){
  set<ll> s;
  s.insert(LLONG_MIN);

  for(auto ring : rings){
    ll a, b, h;
    tie(b, a, h) = ring;
    s.insert(a);
    s.insert(b);
  }

  for(auto x : s)
    compressedX.PB(x);

  s.clear();

  return compressedX.size() - 1;
}

int GetCompressedValue(ll x){
  return lower_bound(compressedX.begin(), compressedX.end(), x) - compressedX.begin();
}

ll GetOriginalValue(ll i){
  return compressedX[i];
}

//----------------------------------------- Segment Tree -----------------------------------------//
node* CreateNode(int leftEnd, int rightEnd){
  node *temp = new node;

  temp->leftEnd = leftEnd;
  temp->rightEnd = rightEnd;
  temp->ans = 0;

  return temp;
}

node* BuildSegmentTree(int leftEnd, int rightEnd){
  node *temp = CreateNode(leftEnd, rightEnd);

  if(leftEnd != rightEnd){
    int mid = (leftEnd + rightEnd) / 2;
    temp->leftChild = BuildSegmentTree(leftEnd, mid);
    temp->rightChild = BuildSegmentTree(mid + 1, rightEnd);
  }
  else
    temp->leftChild = temp->rightChild = NULL;

  return temp;
}

void Update(node *currentNode, int i, ll x){
  if(i < currentNode->leftEnd || currentNode->rightEnd < i)
    return ;
  else{
    if(i == currentNode->leftEnd && currentNode->rightEnd == i)
      currentNode->ans = max(currentNode->ans, x);
    else{
      Update(currentNode->leftChild, i, x);
      Update(currentNode->rightChild, i, x);
      currentNode->ans = max(currentNode->leftChild->ans, currentNode->rightChild->ans);
    }
  }
}

ll Query(node *currentNode, int l, int r){
  if(r < l || r < currentNode->leftEnd || currentNode->rightEnd < l)
    return 0;
  else{
    l = max(l, currentNode->leftEnd);
    r = min(r, currentNode->rightEnd);

    if(l == currentNode->leftEnd && r == currentNode->rightEnd)
      return currentNode->ans;
    else
      return max(Query(currentNode->leftChild, l, r), Query(currentNode->rightChild, l, r));
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, m;
  node *root;
  ll ans = 0;

  scanf("%d", &n);
  while(n--){
    ll a, b, h;
    scanf("%lld%lld%lld", &a, &b, &h);
    rings.PB(MT(b, a, h));
  }

  m = CoordinateCompression();
  root = BuildSegmentTree(1, m);

  sort(rings.begin(), rings.end());

  for(auto ring : rings){
    ll a, b, h;
    tie(b, a, h) = ring;
    int ca = GetCompressedValue(a), cb = GetCompressedValue(b);
    ll ansx = h + Query(root, ca + 1, cb);
    Update(root, cb, ansx);
    ans = max(ans, ansx);
  }

  cout << ans << '\n';
  
  return 0;
}
