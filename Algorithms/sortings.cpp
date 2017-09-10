#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <cstring>



void merge(std::vector<int> & arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l +1;
    int n2  = r - m;
    
    int L[n1], R[n2];
    
    std::memcpy(L,arr.);
    std::memcpy();
    
    i = 0;
    j = 0;
    k = l;
    
}


void merge_sort(std::vector<int> & arr ,int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;
 
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

void quick_sort(std::vector<int>& arr,int left, int right,int N = 20, int depth = 0)
{

    if (depth > N)
        merge_sort(arr,left,right);
    int i = left, j = right;
    int mid = arr[(i+j)/2];
    while ( i <= j )
    {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;
        if ( i <= j )
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (i < right)
        quick_sort(arr,i,right,depth+1);
    if (j > left)
        quick_sort(arr,left,j,depth+1);
}

int main()
{
    const int N = 4;
    int length = 0;
    std::cin >> length;
    std::vector<int32_t> arr(length,0);
    for (int i = 0; i < length; ++i)
    {
        arr[i] = std::rand()%(length*150)-50;
    }
    int ans = 0;
    int best_time = INT32_MAX;
    quick_sort(arr,0,length-1,10000);
//    while ( N < length)
//    {
//        std::clock_t start = std::clock();
//        quick_sort(arr,0,length-1,N);
//        double time = (double)(std::clock()-start)/CLOCKS_PER_SEC;

//        if (best_time > time)
//        {
//            ans = start;
//            best_time  = start;
//        }
//        std::cout << time << std::endl;
//    }
//    std::cout << "Best depth is" << ans << "  for array length of " << length <<   std::endl;
    for (auto num : arr)
    {
        std::cout << num << std::endl;
    }
    return 0;
}
