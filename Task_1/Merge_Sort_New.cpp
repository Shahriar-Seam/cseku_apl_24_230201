#include <bits/stdc++.h>

using namespace std;

// Function to perform merge sort on a portion of the vector
// Parameters:
// - v: Reference to the vector of integers to be sorted
// - temp: Temporary vector used for merging
// - low: Starting index of the portion to be sorted
// - high: Ending index of the portion to be sorted
void merge_sort(vector<int> &v, vector<int> &temp, int low, int high)
{
    // Base case: if the portion has one or no elements, return
    if (high - low <= 1) {
        return;
    }

    int i, j, k, mid;

    // Calculate the midpoint of the current portion
    mid = low + (high - low) / 2;

    // Recursively sort the two halves
    merge_sort(v, temp, low, mid);
    merge_sort(v, temp, mid, high);

    // Merge the sorted halves into the temporary vector
    for (i = low, j = mid, k = low; k < high; k++) {
        if (i < mid && j < high) {
            if (v[i] < v[j]) {
                temp[k] = v[i++]; // Take from the left half
            } else {
                temp[k] = v[j++]; // Take from the right half
            }
        } else if (i < mid) {
            temp[k] = v[i++]; // Copy remaining elements from the left half
        } else {
            temp[k] = v[j++]; // Copy remaining elements from the right half
        }
    }

    // Copy the sorted elements back into the original vector
    for (k = low; k < high; k++) {
        v[k] = temp[k];
    }
}

// Function to initiate merge sort on the entire vector
// Parameters:
// - v: Reference to the vector of integers to be sorted
void merge_sort(vector<int> &v)
{
    vector<int> temp(v.size()); // Temporary vector for merging
    merge_sort(v, temp, 0, v.size()); // Call the recursive merge sort
}

// Main function to handle input/output and initiate sorting
int main()
{
    // Optimize input/output
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int n; // Variable for the number of elements in the vector

    // Read the number of elements
    cin >> n;

    vector<int> v(n); // Vector to hold the input integers

    // Read the elements into the vector
    for (auto &it : v) {
        cin >> it;
    }

    // Perform merge sort on the vector
    merge_sort(v);

    // Output the sorted vector
    for (auto it : v) {
        cout << it << " ";
    }

    return 0; // Indicate that the program ended successfully
}
