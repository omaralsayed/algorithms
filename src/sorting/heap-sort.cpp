/**
 * Time complexity: O(nlogn)
 * Space complexity: O(1)
*/

/**
 * Heap sort is a comparison based sorting routine 
 * based on a heap data structure.
 * 
 * We find the maximum element and we put it at 
 * the end. We repeat the same operation on the 
 * remaining elements until the array is sorted.
 * 
 * We can heapify a node only if its children nodes
 * are heapified.
 */

void swap(int& v1, int& v2) {
  int tmp = v1;
  v1 = v2;
  v2 = tmp;
}

void heapify(int arr[], int i, int n) {
  int max = i; // Init as root
  int l   = 2 * i + 1;
  int r   = 2 * i + 2;

  // If left child is larger than root
  if (l < n && arr[l] > arr[max])
    max = l;

  // If right child is larger than current max
  if (r < n && arr[r] > arr[max])
    max = r;

  if (max != i) {
    swap(arr[i], arr[max]);
    heapify(arr, max, n);
  }
}

void heapSort(int arr[], int n) {
  // Build heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, i, n);

  // Extract from heap
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, 0, i);
  }
}