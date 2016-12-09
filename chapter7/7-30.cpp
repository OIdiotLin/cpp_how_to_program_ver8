// Author:	LHD
// System:	Win 10
// Problem:	7.30 (Bucket Sort)

#include <iostream>
#include <cmath>
using namespace std;

#define BUCKET_SIZE 10
#define length(x)  x[0]
#define EMPTY INT_MIN

inline void mallocError();
void bucketSort(int*, int, int);
inline int getNum(int, int);
inline int getInsertIndex(int**, int);
void rewriteArr(int**, int*, int);

int main() {
	int n;
	cin >> n;
	int *arr = new(nothrow) int[n];
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	bucketSort(arr, n, 1);
	for (int i = 0;i < n;i++)
		cout << arr[i] << " ";
	cout << endl;
}

inline void mallocError() {
	cout << "memory allocation error" << endl;
}

inline int getNum(int num, int pos) {
	return num / (int)pow(10, pos - 1);
}

inline int getInsertIndex(int **bucket, int curRow) {
	int i;
	for (i = 0;bucket[curRow][i] != EMPTY;i++);
	return i;
}

void rewriteArr(int **bucket, int *arr, int len) {
	int idx = 0;
	for (int i = 0;i < 10;i++)
		for (int subIdx = 0;bucket[i][subIdx] != EMPTY && subIdx < len;idx++, subIdx++)
			arr[idx] = bucket[i][subIdx];
}

void bucketSort(int *arr, int len, int depth) {
	int isFinished = true;		// if this bucket contains only one number

	int *bucket[BUCKET_SIZE];
	for (int i = 0;i < BUCKET_SIZE;i++) {
		bucket[i] = new(nothrow) int[len];
		if (bucket[i] == nullptr) {		// print errInfo when mem alloc err
			mallocError();
			return;
		}
		length(bucket[i]) = EMPTY;
	}

	for (int i = 0;i < len;i++) {
		int curNum = getNum(arr[i], depth);
		int curDigit = curNum % 10;
		if (curNum)
			isFinished = false;

		int insIdx = getInsertIndex(bucket, curDigit);
		bucket[curDigit][insIdx] = arr[i];
		if (insIdx < len - 1)
			bucket[curDigit][insIdx + 1] = EMPTY;
		
	}

	rewriteArr(bucket, arr, len);
	if (isFinished) return;
	bucketSort(arr, len, depth + 1);

	for (int i = 0;i < 10;i++)
		delete[] bucket[i];
}