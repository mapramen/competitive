#include <bits/stdc++.h>
using namespace std;

// Dancing Links implementation for n*n Sudoku (here n=9)
// Based on Knuth's DLX algorithm for exact cover

static const int SQRTN = 4;
static const int N = SQRTN * SQRTN;
static const int N2 = N * N;
static const int CONSTRAINTS = 4;	 // cell, row, col, block
static const int COLS = N2 * CONSTRAINTS;

struct Node {
	int row, col;
	Node *L, *R, *U, *D;

	Node(int r = 0, int c = 0, Node* l = nullptr, Node* r_ = nullptr, Node* u = nullptr, Node* d = nullptr)
			: row(r), col(c), L(l), R(r_), U(u), D(d) {}
};

struct Column : Node {
	int size;
	string name;

	Column(int s = 0, int c = 0, Node* l = nullptr, Node* r_ = nullptr, Node* u = nullptr, Node* d = nullptr, int sz = 0, const string& n = "")
			: Node(s, c, l, r_, u, d), size(sz), name(n) {}
};

class DLX {
	Column* header;
	vector<Column*> columnList;
	vector<Node*> nodes;
	vector<int> solution;

 public:
	DLX(int cols) {
		header = new Column(0, 0, nullptr, nullptr, nullptr, nullptr, cols, "header");
		header->L = header->R = header;
		columnList.resize(cols);
		for (int i = 0; i < cols; ++i) {
			columnList[i] = new Column(0, i, nullptr, nullptr, nullptr, nullptr, 0, to_string(i));
			columnList[i]->L = header->L;
			columnList[i]->R = header;
			header->L->R = columnList[i];
			header->L = columnList[i];
			columnList[i]->U = columnList[i]->D = columnList[i];
		}
	}

	~DLX() {
		for (auto n : nodes) delete n;
		for (auto c : columnList) delete c;
		delete header;
	}

	void addRow(int r, const vector<int>& cols) {
		Node* first = nullptr;
		for (int c : cols) {
			Node* nd = new Node(r, c, nullptr, nullptr, nullptr, nullptr);
			nodes.push_back(nd);
			Column* col = columnList[c];

			// link vertically
			nd->D = col;
			nd->U = col->U;
			col->U->D = nd;
			col->U = nd;
			col->size++;

			// link horizontally
			if (!first) {
				first = nd;					 // first node in this row
				nd->L = nd->R = nd;	 // circular link
			} else {
				nd->L = first->L;
				nd->R = first;
				first->L->R = nd;
				first->L = nd;
			}

			first = nd;
		}
	}

	void cover(Column* c) {
		c->R->L = c->L;
		c->L->R = c->R;
		for (Node* i = c->D; i != c; i = i->D) {
			for (Node* j = i->R; j != i; j = j->R) {
				j->D->U = j->U;
				j->U->D = j->D;
				columnList[j->col]->size--;
			}
		}
	}

	void uncover(Column* c) {
		for (Node* i = c->U; i != c; i = i->U) {
			for (Node* j = i->L; j != i; j = j->L) {
				columnList[j->col]->size++;
				j->D->U = j;
				j->U->D = j;
			}
		}
		c->R->L = c;
		c->L->R = c;
	}

	bool solve() {
		if (header->R == header) return true;
		// choose column with smallest size
		Column* c = nullptr;
		int minSize = INT_MAX;
		for (Column* j = (Column*)header->R; j != header; j = (Column*)j->R) {
			if (j->size < minSize) {
				minSize = j->size;
				c = j;
			}
		}
		cover(c);
		for (Node* r = c->D; r != c; r = r->D) {
			solution.push_back(r->row);
			for (Node* j = r->R; j != r; j = j->R) cover(columnList[j->col]);
			if (solve()) return true;
			for (Node* j = r->L; j != r; j = j->L) uncover(columnList[j->col]);
			solution.pop_back();
		}
		uncover(c);
		return false;
	}

	vector<int> getSolution() {
		return solution;
	}
};

// Map (r, c, v) to row-index and constraint columns
int rowIndex(int r, int c, int v) {
	return (r * N + c) * N + (v - 1);
}

vector<string> Solve() {
	vector<string> grid(N);
	for (int i = 0; i < N; ++i) cin >> grid[i];

	DLX dlx(COLS);

	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			for (int v = 1; v <= N; ++v) {
				if (grid[r][c] != '-' && grid[r][c] - 'A' + 1 != v) {
					continue;	 // skip if cell already has a different value
				}

				const int rid = rowIndex(r, c, v);

				const vector<int> cols = {
						r * N + c,																									// cell constraint
						N2 + r * N + (v - 1),																				// row constraint
						2 * N2 + c * N + (v - 1),																		// column constraint
						3 * N2 + ((r / SQRTN) * SQRTN + (c / SQRTN)) * N + (v - 1)	// block constraint
				};

				dlx.addRow(rid, cols);
			}
		}
	}

	assert(dlx.solve());

	auto sol = dlx.getSolution();
	vector<string> out = grid;
	for (int rid : sol) {
		int v = rid % N + 1;
		rid /= N;
		int c = rid % N;
		int r = rid / N;
		out[r][c] = 'A' + v - 1;	// convert back to character
	}
	return out;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (const auto& row : Solve()) {
			cout << row << "\n";
		}
	}
	return 0;
}
