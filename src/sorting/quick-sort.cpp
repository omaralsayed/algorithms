/* 
Time complexity: O(n^2)
Space complexity: O(log(n))
*/

/*
This algorithm works by picking a midpoint and having the 
function call itself on each half until the array is sorted
*/

void quickSort(int data[], int l, int r) {
	int i = l; // i starts at the left index, l
	int j = r; // j starts at the right index, r
	int temp;
	int pivot = data[l + ((r - l) / 2)]; // Integer overflow-safe approach

	while (i <= j) {
		while (data[i] < pivot) {
			i++; // Increment index
		}

		while (data[j] > pivot) {
			j--; // Decrement index
		}

        // If elements are unsorted:
		// swap then update indices
		if (i <= j) {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
			j--;
		}
	}

	if (l < j) {
		quickSort(data, l, j); // Recursively sort the first section
	}

	if (i < r) {
		quickSort(data, i, r); // Recursively sort the second section
	}
}