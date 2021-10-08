#include <iostream>
using namespace std;
int A[150][150], n;

int maxRow () {
	int res = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += A[i][j];
		res = max(sum,res);
	}
	return res;
}

int maxCol () {
	int res = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += A[j][i];
		res = max(sum,res);
	}
	return res;
}

int main () {
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		int SumArr = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> A[i][j];
				SumArr += A[i][j];
			}
		}
		int MAX = max(maxCol(), maxRow());
		int ans = MAX*2*n - 2*SumArr;
		cout << ans/2 <<endl;
	}
}
