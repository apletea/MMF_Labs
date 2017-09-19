#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <chrono>
#include <bits/stdc++.h>

bool is_sorted(std::vector<int> & arr, int l, int r)
{
    int i;
    for( i = l; i < r; ++i )
    {
        if (arr[i] < arr[i+1])
            continue;
        break;
    }
    if (i == r)
        return true;
    return false;

}

void buble_sort(std::vector<int> & arr, int l, int r)
{
    if (is_sorted(arr,l,r))
        return;
    for (int i = l, step = 0; i < r; ++i,step++)
    {
        for (int j = l; j < r-step; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void merge(std::vector<int> & arr, int l, int m, int r)
{

    int i = 0, j = 0, k = l;
    int n1 = m - l +1;
    int n2  = r - m;
    int L[n1], R[n2];

    std::memcpy(L,&arr[l],sizeof(arr[0])*n1);
    std::memcpy(R,&arr[m+1],sizeof(arr[0])*n2);

    while (i < n1 && j < n2)
    {
        arr[k++] = L[i] < R[j] ? L[i++] : R[j++];
    }

    i == n1 ? std::memcpy(&arr[k],(R+j),sizeof(arr[0])*(n2-j)) : std::memcpy(&arr[k],(L+i),sizeof(arr[0])*(n1-i));

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

void quick_sort(std::vector<int> & arr,int left, int right,int N = 20, int depth = 0)
{

    if (depth > N)
        buble_sort(arr,left,right);
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

void quick_sort(std::vector<int> & arr,int left, int right)
{
    quick_sort(arr,left,right,INT32_MAX,INT32_MIN);
}

int main()
{
    std::vector<int> arr(500000);
    std::vector<std::string> files = {"/home/davinci/numbers.txt2","/home/davinci/numbers3.txt","/home/davinci/numbers4.txt"};
    for (auto file : files)
    {
        std::ifstream in(file);
        int ans = 0;
        double time = INT_MAX;
        for (volatile int i = 2; i < 150; ++i)
        {
            for (volatile int j = 0; j < 500000; ++j)
            {
                in >> arr[j];
            }

            std::clock_t start = std::clock();
            quick_sort(arr,0,499999,i);
            double ttime = std::clock();
            ttime = (double)(ttime - start)/CLOCKS_PER_SEC;
            if (ttime < time )
            {
                std::cout << i << std::endl;
                ans = i;
                time = ttime;
            }
            std::cout << ttime << " and min =" << time<<"  depth=" <<  ans<<std::endl;

        }
        std::cout << "the best depth =" << ans << "  for length =" << 500000 << std::endl;
    }
    return 0;
}
