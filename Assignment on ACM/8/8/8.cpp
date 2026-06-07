#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low, j = high;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;  
        if (i < j) arr[i++] = arr[j];
        while (i < j && arr[i] <= pivot) i++;  
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    return i;  
}


void quickSortNonRecursive(int arr[], int n) {
    stack<pair<int, int>> s;   
    s.push({ 0, n - 1 });

    while (!s.empty()) {
        auto [low, high] = s.top(); s.pop();
        if (low >= high) continue;

        int pivotPos = partition(arr, low, high);

        if (pivotPos - low > high - pivotPos) {
            s.push({ low, pivotPos - 1 });
            s.push({ pivotPos + 1, high });
        }
        else {
            s.push({ pivotPos + 1, high });
            s.push({ low, pivotPos - 1 });
        }
    }
}



void rearrange(int arr[], int n) {
    int i = 0, j = n - 1;   
    int temp;              

    while (i < j) {
        while (i < j && arr[i] < 0) i++;   
        while (i < j && arr[j] >= 0) j--;  

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
}

int findKthLargest_1(vector<int>& nums, int k) {
    make_heap(nums.begin(), nums.end());

    for (int i = 1; i < k; i++) {
        pop_heap(nums.begin(), nums.end());  
        nums.pop_back();                     
    }

    return nums.front();
}

int findKthLargest_2(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);           
        }
        else if (num > minHeap.top()) {
            minHeap.pop();            
            minHeap.push(num);       
        }
        
    }
    return minHeap.top();  
}



void findPairs_N2(vector<int>& arr, int k) {
    int n = arr.size();
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  
            if (arr[i] + arr[j] == k) {
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                found = true;
            }
        }
    }
    if (!found) cout << "No such pair." << endl;
}

void findPairs_NlogN(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());  

    int left = 0, right = arr.size() - 1;
    bool found = false;

    while (left < right) {      
        int sum = arr[left] + arr[right];
        if (sum == k) {
            cout << "(" << arr[left] << ", " << arr[right] << ")" << endl;
            found = true;
            left++;   
            right--;
        }
        else if (sum < k) {
            left++;  
        }
        else {
            right--;  
        }
    }
    if (!found) cout << "No such pair." << endl;
}