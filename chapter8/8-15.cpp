// Author:	LHD
// System:	Win 10
// Problem:	8.15 (Quick Sort)

#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int *arr, int l, int r);
int partition(int *arr, int l, int r);
inline void swap(int &a, int &b) { int t = a;a = b;b = t; }
inline int ran(const int &l, const int &r) {
	return l + (int)((r - l + 1)*rand() / (RAND_MAX + 1));
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	quickSort(arr, 0, n - 1);
	for (int i = 0;i < n;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int partition(int *arr, int l, int r) {
	int x = arr[r];
	int i = l - 1;
	for(int j=l;j<r;j++)
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

int randPartition(int * arr, int l, int r) {
	int x = ran(l, r);
	swap(arr[x], arr[r]);
	return partition(arr, l, r);
}

void quickSort(int *arr, int l, int r) {
	if (l < r) {
		int mid = randPartition(arr, l, r);
		quickSort(arr, l, mid - 1);
		quickSort(arr, mid + 1, r);
	}
}