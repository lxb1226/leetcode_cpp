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
 * @算法描述
 * 1.比较相邻的元素。如果第一个比第二个大，就交换
 * 2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数。
 * 3.针对所有的元素重复以上的步骤，除了最后一个
 * 4.重复步骤1~3，直到排序完成
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
 * @算法描述
 * 1.在未排序序列中找到最小(大)元素，存放到排序序列的起始位置
 * 2.从剩余未排序元素中继续寻找最小(最大)元素，然后放到已排序序列的末尾
 * 3.重复第二步，直到所有元素均排序完毕
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
 * @算法描述
 * 1.把待排序的数组分成已排序和未排序两部分，初始的时候把第一个元素认为是已排好序的
 * 2.从第二个元素开始，在已排好序的子数组中寻找到该元素合适的位置并插入该位置
 * 3.重复上述过程直到最后一个元素被插入有序子数组中
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
 * @算法描述
 * 1.选择一个增量序列t1,t2,...,tk，其中ti > tj,tk=1；
 * 2.按增量序列个数k，对序列进行k趟排序
 * 3.每趟排序，根据对应的增量ti，将待排序列分割成若干个长度为m的子序列，分别对各子表进行直接插入排序。
 * 仅增量因子为1时，整个序列作为一个表来处理，表长度即为整个序列的长度
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
 * @算法描述
 * *递归法（Top-Down）
 * 1.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
 * 2.设定两个指针，最初位置分别为两个已经排序序列的起始位置
 * 3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
 * 4.重复步骤3直到某一指针到达序列尾
 * 5.将另一序列剩下的所有元素直接复制到合并序列尾
 * 
 * *迭代法
 * 1.将序列每相邻两个数字进行归并操作，形成ceil(n/2)个序列，排序后每个序列包括两/一个元素
 * 2.若此时序列数不是1个则将上述序列再次归并，形成ceil(n/4)个序列，每个序列包含四/三个元素
 * 3.重复步骤2，直到所有元素排序完毕，即序列数为1
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
 * @算法描述
 * 1.从数列中挑出一个元素，称为“基准”(pivot)
 * 2.重新排序数列，所有比基准值小的元素摆放到基准前面，所有比基准值大的元素摆在基准后面*(相同的数可以到任何一边)。
 * 在这个分区结束之后，该基准就处于数列的中间位置。这个称为分区操作
 * 3.递归地把小于基准值元素的子数列和大于基准值元素的子数列排序。
 * 
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


// 向下调整堆
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

/**
 * @brief 计数排序
 * 
 * @原理 计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为见存储在额外开辟的数组空间中。
 * 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
 * 
 * @算法描述
 * 1.找出待排序的数组中最大和最小的元素；
 * 2.统计数组中每个值为i的元素出现的次数，存入数组count的第i项
 * 3.对所有计数累加（从count中的第一个元素开始，每一项和前一项相加）
 * 4.反向填充目标数组：将每个元素i放在新数组的第count(i)项，每放一个元素就将C(i)减去1
 * 
 * @param arr 
 */
void countSort(vector<int>& arr){
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    vector<int> b(arr.size(), 0);
    vector<int> count(max_val - min_val + 1, 0);

    // 统计数组中每个值为i的元素出现的次数，存入数组C的第i项
    for(int i = 0; i < arr.size(); ++i){
        count[arr[i] - min_val]++;  
    }

    for(int num = min_val + 1; num <= max_val; ++num){
        // 加总数组元素的值为计数数组对应元素及左边所有元素的值的总和
        count[num - min_val] += count[num - min_val - 1];
    }

    for(int i = 0; i < arr.size(); ++i){
        int num = arr[i];   // 源数组第i位的值
        int idx = count[num - min_val] - 1; // 加总数组中对应元素的下标
        b[idx] = num;   // 将该值存入存储数组对应下标中
        count[num - min_val]--; // 加总数组中，该值的总和减1
    }

    // 将存储数组的值赋给源数组
    arr = b;
}

/**
 * @brief 桶排序
 * 
 * @原理 桶排序又称为箱排序，是计数排序的升级版，它的工作原理是将数组分到有限数量的桶子里，
 * 然后每个桶子再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序），
 * 最后将各个桶中的数据有序的合并起来。
 * 
 * @算法描述：
 * 1.找出待排序数组中的最大值max以及最小值min
 * 2.创建桶，桶的数量为(max - min) / arr.size() + 1
 * 3.遍历数组arr，计算每个元素arr[i]所在的桶的下标，并将其放入到相应的桶中
 * 4.各个桶各自排序，同时将排好序的元素放回到源数组
 * 
 * @时间复杂度：
 * 
 * @param arr 
 */
void bucketSort(vector<int>& arr){
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    int bucketNum = (max_val - min_val) / arr.size() + 1;
    vector<vector<int>> bucketArr(bucketNum, vector<int>());
    
    for(int i = 0; i < arr.size(); ++i){
        int num = (arr[i] - min_val) / arr.size();
        bucketArr[num].push_back(arr[i]);
    }
    
    int cnt = 0;
    // 对每个桶进行排序
    for(int i = 0; i < bucketArr.size(); ++i){
        sort(bucketArr[i].begin(), bucketArr[i].end());
        for(auto & num : bucketArr[i]){
            arr[cnt++] = num;
        }
    }
}

// 打印vector
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

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "count sort : " << endl; 
    countSort(arr);
    print(arr);

    arr = {3,5,3,0,8,6,1,5,8,6,2,4,9,4,7,0,1,8,9,7,3,1,2,5,9,7,4,0,2,6};
    cout << "bucket sort : " << endl; 
    bucketSort(arr);
    print(arr);

    return 0;
}