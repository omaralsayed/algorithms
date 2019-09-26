/** 
 * Reference:
 * GeeksforGeeks (geeksforgeeks.org)
 */

/**
 * Time complexity: O(nlog(n))
 * Space complexity: O(n)
*/

/**
 * Merge Sort is a Divide and Conquer algorithm. It divides input
 * array in two halves, calls itself for the two halves and then 
 * merges the two sorted halves. The merge() function is used for 
 * merging two halves. The merge(a, l, m, r) is key process that 
 * assumes that a[l .. m] and a[m + 1 .. r] are sorted and merges 
 * the two sorted sub-arrays into one.
*/

void merge(int a[], int l, int m, int r) {
	int s1 = m - l + 1;
	int s2 = r - m;
	int* l1 = new int[s1 + 1];
	int* l2 = new int[s2 + 1];

	for (int i = 0; i < s1; ++i)
		l1[i] = a[l + i];
	for (int j = 0; j < s2; ++j)
		l2[j] = a[m + j + 1];

	// https://en.wikipedia.org/wiki/Sentinel_value
	l1[s1] = INT_MAX;
	l2[s2] = INT_MAX;

	int j = 0;
	int k = 0;

	for (int i = l; i <= r; ++i) {
		if (l1[j] < l2[k]) 
            a[i] = l1[j++];
		else 
            a[i] = l2[k++];
	}

	delete[] l1;
	delete[] l2;
}

void mergeSort(int array[], int l, int r) {
    // Sort array if the right index has a greater value than the left index
	if (r > l) {
		int m = (r - l) / 2 + l;    // Integer overflow-safe approach
		mergeSort(array, l, m);		// Sort the first half
		mergeSort(array, m + 1, r); // Sort the second half
		merge(array, l, m, r);		// Merge sorted halves
	}
}