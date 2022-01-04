#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>

using namespace std;

/**
 * @brief 冒泡排序
 * 
 * @原理 冒泡排序在扫描过程中两两比较相邻记录，如果反序则交换，最终，最大记录就被“沉到”了序列的最后一个位置，
 * 第二遍扫描将第二大记录“沉到”了倒数第二个位置，重复上述操作，直到n-1遍扫描后，整个序列就排好序了。
 * 
 * @时间复杂度 O(n^2)
 * 
 * @param arr 
 */
void bubbleSort(vector<int>& arr){
    bool flag = false;
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i){
        flag = false;
        for(int j = 0; j < n - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}


/**
 * @brief 选择排序
 * @原理 初始时在序列中找到最小(最大)元素，放到序列的起始位置作为已排序序列，然后再从剩余未排序元素中继续寻找最小(最大)元素，
 * 放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。
 * 
 * @时间复杂度 O(n^2)
 * 
 * @param arr 
 */
void selectSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i){
        int min = INT_MAX, idx;
        for(int j = i + 1; j < n; ++j){
            // 寻找到最小元素
            if(arr[j] < min){
                min = arr[j];
                idx = j;
            }
        }
        swap(arr[i], arr[idx]);
    }
}

/**
 * @brief 插入排序
 * 
 * @原理 其工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后往前扫描
 * 找到相应位置并插入。
 * 
 * @时间复杂度 O(n^2)
 * 
 * @param arr 
 */
void insertSort(vector<int>& arr){
    int n = arr.size();
    int tmp, j;
    for(int i = 1; i < n; ++i){
        tmp = arr[i];
        for(j = i; j > 0 && arr[j - 1] > tmp; j--){
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

// 希尔排序
/**
 * @brief 希尔排序
 * 
 * @原理 将整个待排序的记录序列分割成为若干个子序列分别进行直接插入排序
 * 
 * @时间复杂度 
 * 
 * @param arr 
 */
void shellSort(vector<int>& arr){
    int n = arr.size();
    for(int increment = n / 2; increment > 0; increment /= 2){
        for(int i = increment; i < n; ++i){
            for(int j = i; j >= increment && arr[j] < arr[j - increment]; j -= increment){
                swap(arr[j], arr[j - increment]);
            }
        }
    }
}


// 将arr[L..M]和arr[M + 1..R]归并
void merge(vector<int>& arr, int L, int M, int R){
    int left_size = M - L + 1;
    int right_size = R - M;

    vector<int> left(arr.begin() + L, arr.begin() + M + 1);
    vector<int> right(arr.begin() + M + 1, arr.begin() + R + 1);

    int i = 0, j = 0, k = L;
    while(i < left_size && j < right_size){
        if(left[i] > right[j]){
            arr[k++] = right[j++];
        }else{
            arr[k++] = left[i++];
        } 
    }

    while(i < left_size) arr[k++] = left[i++];
    while(j < right_size) arr[k++] = right[j++];
}

/**
 * @brief 归并排序
 * 
 * @原理 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法的一个非常典型的应用。
 * 将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序，若将两个有序表合并成一个有序表，称为2-路归并。
 * 
 * @时间复杂度
 * @param arr 
 * @param L 
 * @param R 
 * 左闭右闭
 */
void merge_sort(vector<int>& arr, int L, int R){
    if(L == R) return;
    int M = (L + R) / 2;
    merge_sort(arr, L, M); // arr[L, M]
    merge_sort(arr, M + 1, R);  // arr[M + 1, R]
    merge(arr, L, M, R);
}


/**
 * @brief 快速排序
 * 
 * @原理 通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小
 * 则可分别对这两部分继续进行排序，以达到整个序列有序
 * 
 * @param arr 
 * @param begin 
 * @param end 
 */
void quickSort(vector<int>& arr, int begin, int end){
    int i, j, t, pivot;

    if(begin > end) return;
    i = begin;
    j = end;
    pivot = arr[begin];

    while(i < j){
        while(arr[j] >= pivot && i < j)
            j--;
        while(arr[i] <= pivot && i < j)
            i++;
        
        if(i < j)
            swap(arr[i], arr[j]);
    }

    arr[begin] = arr[i];
    arr[i] = pivot;

    quickSort(arr, begin, i - 1);
    quickSort(arr, i + 1, end);
}



void adjustHeap(vector<int>& arr, int i, int n){
    int k = 2 * i + 1;
    while(k <= n){
        if(k + 1 <= n && arr[k] < arr[k + 1])
            k++;
        if(arr[i] > arr[k])
            return;
        else{
            swap(arr[i], arr[k]);
            i = k;
            k = 2 * i + 1;
        }
    }
}


void buildHeap(vector<int>& arr, int n){
    for(int i = n / 2; i >= 0; --i){
        adjustHeap(arr, i, n);
    }
}

/**
 * @brief 堆排序
 * 
 * @原理 堆排序是指利用堆这种数据结构所设计的一种排序算法，它是选择排序的一种。
 * 可以利用数组的特点快速定位指定索引的元素。堆排序就是把最大堆堆顶的最大数取出，
 * 将剩余的堆继续调整为最大堆，再次将堆顶的最大数取出，这个过程持续到剩余数只有一个时结束。
 * 
 * @param arr 
 * @param n 
 */
void heapSort(vector<int>& arr, int n){
    buildHeap(arr, n);
    for(int i = n; i > 0; i--){
        swap(arr[0], arr[i]);
        adjustHeap(arr, 0, i - 1);
    }
}


void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]){
    vector<int> arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "origin data : " << endl;
    print(arr);

    cout << "bubble sort : " << endl; 
    bubbleSort(arr);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "select sort : " << endl; 
    selectSort(arr);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "insert sort : " << endl; 
    insertSort(arr);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "shell sort : " << endl; 
    shellSort(arr);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "merge sort : " << endl; 
    merge_sort(arr, 0, arr.size() - 1);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "quick sort : " << endl; 
    quickSort(arr, 0, arr.size() - 1);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "heap sort : " << endl; 
    heapSort(arr, arr.size() - 1);
    print(arr);

    return 0;
}