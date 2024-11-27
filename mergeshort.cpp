#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int r, int mid) {

	int left_size = mid - l + 1, right_size = r - mid;
	int left[left_size + 1], right[right_size + 1];

	for (int i = l, j = 0; i <= mid; i++, j++) left[j] = a[i];
	for (int i = mid + 1, j = 0; i <= r; i++, j++) right[j] = a[i];

	left[left_size] = right[right_size] = INT_MAX;

	int lp = 0, rp = 0;

	for (int i = l; i <= r; i++)
		left[lp] < right[rp] ? a[i] = left[lp++] : a[i] = right[rp++];
}

void mergeshort(int a[], int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	mergeshort(a, l, mid);
	mergeshort(a, mid + 1, r);
	merge(a, l, r, mid);
}

int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	mergeshort(a, 0, n-1);
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
