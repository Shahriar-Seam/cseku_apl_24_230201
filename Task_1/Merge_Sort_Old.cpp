#include <bits/stdc++.h>

using namespace std;

void merge_sort(vector <int> &v, vector <int> &temp, int low, int high)
{
    if (high - low == 1) {
        return;
    }

    int i, j, k, mid;

    mid = low + (high - low) / 2;

    merge_sort(v, temp, low, mid);
    merge_sort(v, temp, mid, high);

    for (i = low, j = mid, k = low; k < high; k++) {
        if (i < mid && j < high) {
            if (v[i] < v[j]) {
                temp[k] = v[i++];
            }
            else {
                temp[k] = v[j++];
            }
        }
        else if (i < mid) {
            temp[k] = v[i++];
        }
        else {
            temp[k] = v[j++];
        }
    }

    for (k = low; k < high; k++) {
        v[k] = temp[k];
    }
}

void merge_sort(vector <int> &v)
{
    vector <int> temp(v.size());

    merge_sort(v, temp, 0, v.size());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    merge_sort(v);

    for (auto it : v) {
        cout << it << " ";
    }

    return 0;
}