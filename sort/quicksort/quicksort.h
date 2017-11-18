#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

template<typename T>
void qsort(T* d, int n) {
	if (n < 2)
		return;
	T key = d[0];
	int i=0, j=n;
	do {
		while (i < j && d[--j] >= key);
		d[i] = d[j];
		while (i < j && d[++i] <= key);
		d[j] = d[i];
	} while (i < j);
	d[i] = key;
	qsort(d, i);
	qsort(d+i+1, n-i-1);
}

template<typename T>
void qsort_a(T* d, int n) {
	if (n < 2)
		return;
	T key = d[n-1];
	int i=-1, j=n-1;
	do {
		while (i < j && d[++i] <= key);
		d[j] = d[i];
		while (i < j && d[--j] >= key);
		d[i] = d[j];
	} while (i < j);
	d[i] = key;
	qsort(d, i);
	qsort(d+i+1, n-i-1);
}

template<typename T>
void qsort_b(T* d, int n, int threshold=6) {
	if (n < 2)
		return;
	if (n < threshold) {
		for (int i=1;i<n;++i) {
			int j = i;
			T key = d[i];
			while (--j >= 0 && d[j] > key)
				d[j+1] = d[j];
			d[j+1] = key;
		}
		return;
	}
	T key = d[0];
	int i=0, j=n;
	do {
		while (i < j && d[--j] >= key);
		d[i] = d[j];
		while (i < j && d[++i] <= key);
		d[j] = d[i];
	} while (i < j);
	d[i] = key;
	qsort(d, i);
	qsort(d+i+1, n-i-1);
}

template<typename T>
void qsort_c(T* d, int n) {
	if (n < 2)
		return;
	int l[100];
	int r[100];
	l[0] = 0;
	r[0] = n;
	int k = 0;
	do {
		int left = l[k];
		int right = r[k];
		T key = d[left];
		// if (right-left < 5) {
		// 	for (int i=left+1;i<right;++i) {
		// 		int j = i;
		// 		T key = d[i];
		// 		while (--j >= left && d[j] > key)
		// 			d[j+1] = d[j];
		// 		d[j+1] = key;
		// 	}
		// 	--k;
		// 	continue;
		// }
		int i=left, j=right;
		do {
			while (i < j && d[--j] >= key);
			d[i] = d[j];
			while (i < j && d[++i] <= key);
			d[j] = d[i];
		} while (i < j);
		d[i] = key;
		k--;
		if (i > left + 1) {
			l[k+1] = left;
			r[k+1] = i;
			++k;
		}
		if (i + 2 < right) {
			l[k+1] = i+1;
			r[k+1] = right;
			++k;
		}
	} while (k >= 0);
}

#endif