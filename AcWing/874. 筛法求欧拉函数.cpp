#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;

int primes[N], cnt;     // primes[]存储所有素数
int euler[N];           // 存储每个数的欧拉函数
bool st[N];             // st[x]存储x是否被筛掉

void get_eulers(int n) {
	euler[1] = 1;
	for (int i = 2; i <= n; i ++ ) {
		if (!st[i]) {
			primes[cnt ++ ] = i;
			euler[i] = i - 1;     // i为质数
		}
		for (int j = 0; primes[j] <= n / i; j ++ ) {
			int t = primes[j] * i;
			st[t] = true;
			if (i % primes[j] == 0) { // i为合数且pj为i的质因子
				euler[t] = euler[i] * primes[j];
				break;
			}
			euler[t] = euler[i] * (primes[j] - 1);  // i为合数且pj不为i的质因子
		}
	}
}

int main() {
	int n;
	cin >> n;

	get_eulers(n);

	LL res = 0;
	for (int i = 1; i <= n; i++) {
		res += euler[i];
	}
	cout << res << endl;
}
