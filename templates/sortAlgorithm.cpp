#include<vector>
#include<algorithm>

using namespace std;

// 冒泡排序
void bubbleSort(vector<int>& arr){
    bool bExchange = false; // 交换标志
    int n = arr.size();
    for(int i = 0; i < n; ++i){
        bExchange = false;
        for(int j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j + 1], arr[j]);
                bExchange = true;
            }
        }
        if(!bExchange)
            return;
    }
}


// 选择排序
void selectSort(vector<int>& arr){
    int minIndex = 0;

    int n = arr.size();
    for(int i = 0; i < n - 1; ++i){
        minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            swap(arr[minIndex], arr[i]);
        }
    }
}

// 插入排序
void insertSort(vector<int>& arr){
    int i, j, tmp;
    int n = arr.size();
    for(i = 1; i < n; ++i){
        tmp = arr[i];
        for(j = i; j > 0 && arr[j - 1] > tmp; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
}

// 希尔排序
void shellSort(vector<int>& arr){
    int i, j, tmp, increment;
    int n = arr.size();
    for(increment = n / 2; increment > 0; increment /= 2){
        for(i = increment; i < n; ++i){
            tmp = arr[i];
            for(j = i - increment; j >= 0 && tmp < arr[j]; j -= increment){
                arr[j + increment] = arr[j];
            }
            arr[j + increment] = tmp;
        }
    }
}

// 归并排序
// 将arr[L..M]和arr[M+1..R]归并
void merge(vector<int>& arr, int L, int M, int R){
    int left_size = M - L + 1;
    int right_size = R - M;
    vector<int> left(arr.begin() + L, arr.begin() + M);
    vector<int> right(arr.begin() + M, arr.begin() + R);

    int i = 0, j = 0, k = L;
    while(i < left_size && j < right_size) arr[k++] = left[i] < right[j] ? left[i++] : right[j++];
    while(i < left_size) arr[k++] = left[i++];
    while(j < right_size) arr[k++] = right[j++];
    
}

// 归并排序
void merge_sort(vector<int>& arr, int L, int R){
    if(L == R) return;
    int M = (L + R) / 2;
    merge_sort(arr, L, M);
    merge_sort(arr, M + 1, R);
    merge(arr, L, M, R);
}

// 快速排序
void quickSort(vector<int>& arr, int begin, int end){
    int i, j, t, pivot;

    if(begin > end) return;

    pivot = arr[begin];
    i = begin;
    j = end;
    while(i != j){
        while(arr[j] >= pivot && i < j)
            j--;
        while(arr[i] <= pivot && i < j)
            i++;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    arr[begin] = arr[i];
    arr[i] = pivot;
    quickSort(arr, begin, i - 1);
    quickSort(arr, i + 1, end);
}

// 堆排序

void heapify(vector<int>& arr, int n, int i){
    if(i >= n) return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(left < n && arr[left] > arr[max]) max = left;
    if(right < n && arr[right] > arr[max]) max = right;
    if(max != i){
        swap(arr[max], arr[i]);
        heapify(arr, n, max);
    }
}

void build_heap(vector<int>& arr){
    int n = arr.size();
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;
}