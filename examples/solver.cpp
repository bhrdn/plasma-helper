/*
* bhrdn (bhrdn@protonmail.ch)
* Task: MissingInteger
*/

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
	auto f = [](int x, int y, vector<int> &A) {
		int temp = A[x];
		A[x] = A[y];
		A[y] = temp;
	};

	int n;
	while (n++ < A.size()-1) {
		while (0 < A[n] && A[n]-1 < A.size() && A[n] != n+1 && A[n] != A[A[n]-1]) {
			f(n, A[n]-1, A);
		}
	}

	while (n--) {
		if (A[n] != n+1) return n+1;
	}

	return A.size()+1;
}

int main() {
	int n; cin >> n;
	vector<int> A(n);

	while(n--) cin >> A[n];
	cout << solution(A);
}