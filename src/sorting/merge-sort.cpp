/*
Time complexity: O(nlogn)
Space complexity: O(n)
*/

/*
Divide and conquer:
- Take the list and divide it into two halves recursivly
- Solve the subproblems (have the function call 
iteself on each half)
- Combine the solutions of the subproblems to get the 
result (merge)

Our final result will have a sum of n+...+(n(n/n))
*/

void merge(int data[], int l, int m, int r) {
	int s1 = m - l + 1;
	int s2 = r - m;
	int* l1 = new int[s1 + 1];
	int* l2 = new int[s2 + 1];

	for (int i = 0; i < s1; ++i)
		l1[i] = data[l + i];
	for (int j = 0; j < s2; ++j)
		l2[j] = data[m + j + 1];

	// https://en.wikipedia.org/wiki/Sentinel_value
	l1[s1] = INT_MAX;
	l2[s2] = INT_MAX;

	int j = 0;
	int k = 0;

	for (int i = l; i <= r; ++i) {
		if (l1[j] < l2[k]) 
            data[i] = l1[j++];
		else 
            data[i] = l2[k++];
	}

	delete[] l1;
	delete[] l2;
}

void mergeSort(int array[], int l, int r) {

    // Sort array if the right index has a greater value than the left index
	if (r > l) {
		int m = (r - l) / 2 + l;    // Integer overflow-safe approach
		mergeSort(array, l, m);		// Sorts the first half
		mergeSort(array, m + 1, r); // Sorts the second half
		merge(array, l, m, r);		// Merges sorted halves
	}
}