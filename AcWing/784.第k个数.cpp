#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int q[N];

int quick_sort(int l, int r, int k) {
	if (l == r)  return q[l];   //在快速排序中，必须写大于等于，避免出现没有数的情况。

	int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
	while (i < j) {
		while (q[++i] < x);
		while (q[--j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	int s1 = j - l + 1;
	if (k <= s1)  return quick_sort(l, j, k);
	else       return quick_sort(j + 1, r, k - s1);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}
	cout << quick_sort(0, n - 1, k) << endl;
}
