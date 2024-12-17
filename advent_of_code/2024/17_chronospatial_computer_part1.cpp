#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

tuple<int, int, int, vector<int>> ReadInput() {
	int a, b, c;
	scanf("Register A: %d\n", &a);
	scanf("Register B: %d\n", &b);
	scanf("Register C: %d\n", &c);

	scanf("Program: ");

	string line;
	cin >> line;

	vector<int> instructions;
	stringstream ss(line);
	string item;
	while (getline(ss, item, ',')) {
		instructions.push_back(stoi(item));
	}

	return make_tuple(a, b, c, instructions);
}

int GetLiteralOperand(const int a, const int b, const int c, const int i) {
	assert(0 <= i && i <= 7);
	return i;
}

int GetComboOperand(const int a, const int b, const int c, const int i) {
	assert(0 <= i && i <= 7);

	if (i < 4) {
		return i;
	}

	if (i == 4) {
		return a;
	}

	if (i == 5) {
		return b;
	}

	if (i == 6) {
		return c;
	}

	assert(false);
}

int CalculateDivision(const int a, const int b, const int c, const int operand) {
	int numerator = a;
	for (int i = GetComboOperand(a, b, c, operand); i > 0 && numerator > 0; --i) {
		numerator /= 2;
	}
	return numerator;
}

tuple<int, int, int, int> ExecuteInstruction(const vector<int>& instructions, const int a, const int b, const int c, const int ip, vector<int>& output) {
	assert(0 <= ip && ip < instructions.size());

	int opcode = instructions[ip];

	if (opcode == 0) {
		const int new_a = CalculateDivision(a, b, c, instructions[ip + 1]);
		return {new_a, b, c, ip + 2};
	}

	if (opcode == 1) {
		return {a, b ^ GetLiteralOperand(a, b, c, instructions[ip + 1]), c, ip + 2};
	}

	if (opcode == 2) {
		return {a, GetComboOperand(a, b, c, instructions[ip + 1]) % 8, c, ip + 2};
	}

	if (opcode == 3) {
		if (a == 0) {
			return {a, b, c, ip + 2};
		}

		return {a, b, c, GetLiteralOperand(a, b, c, instructions[ip + 1])};
	}

	if (opcode == 4) {
		return {a, b ^ c, c, ip + 2};
	}

	if (opcode == 5) {
		output.push_back(GetComboOperand(a, b, c, instructions[ip + 1]) % 8);
		return {a, b, c, ip + 2};
	}

	if (opcode == 6) {
		const int new_b = CalculateDivision(a, b, c, instructions[ip + 1]);
		return {a, new_b, c, ip + 2};
	}

	if (opcode == 7) {
		const int new_c = CalculateDivision(a, b, c, instructions[ip + 1]);
		return {a, b, new_c, ip + 2};
	}

	assert(false);
}

int main() {
	auto [a, b, c, instructions] = ReadInput();

	vector<int> output;
	for (int ip = 0; ip < instructions.size();) {
		tie(a, b, c, ip) = ExecuteInstruction(instructions, a, b, c, ip, output);
	}

	for (int i = 0; i < output.size(); ++i) {
		printf("%d", output[i]);
		if (i + 1 < output.size()) {
			printf(",");
		}
	}
	printf("\n");

	return 0;
}