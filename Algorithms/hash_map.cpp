/*
_______$$$$$
______$$$$$$$____$$$
______$$$$$$$___$$$$$
__$$$$_$$$$$$__$$$$$$$
$$$$$$$_$$$$$_$$$$$$$$
$$$$$$$$_$$$$_$$$$$$
$$$$$$$$$$$$$_$$$$_$$$$$
__$$$$$$$$$$$_$$$$$$$$$$$
____________$_$$$$$$$$$$$
__$$$$$$$$$$$___$$$$$$$$
_$$$$$$$$_$$$_$
_$$$$$$$_$$$$$_$
__$$$$$_$$$$$$_$$
_______$$$$$$$__$$$
_______$$$$$$_____$$$$
________$$$$_________$$
*/

#include <bits/stdc++.h>

namespace IRA
{
    
    template <typename K, typename V>
    class hash_map_ll
    {
        
    };
    
    template <typename T>
    class linked_list
    {
        linked_list * next;
        linked_list * tail;
        T val;
        linked_list(T val)
        {
            this->next = NULL;
            this->tail = this;
            this->val = val;
        }
        
        void append(T val)
        {
            this->tail->next = new linked_list(val);
        }
        
        linked_list * find(T val)
        {
            linked_list * node = this;
            while (node || node->val!= val)
            {
                node = node->next;
            }
            return node;
        }
    };
}

namespace init
{
    void fill_file(std::vector<int> & arr, std::ofstream & out)
    {
        for (int i = 0 ; i < arr.size(); ++i)
        {
            out << arr[i] << std::endl;
        }
    }

    std::vector<std::string> get_files_path(int num_of_files)
    {
        std::vector<std::string> ans(num_of_files);
        for (int i = 0; i < num_of_files; ++i)
        {
            ans[i] = "numbers_" + std::to_string(i) + ".txt";
        }
        return ans;
    }

    std::vector<int>  create_sort_arr(int N, int range = 1*9*9*7*8*4*4)
    {
        std::vector<int> arr(N);
        for (int i = 0; i < N; ++i)
        {
            arr[i] =  std::rand()%range - range / 2 ;
        }
        std::sort(arr.begin(), arr.end());
        return arr;
    }

    void create_files(const std::vector<std::string> & pathes, int N = 1*9*9*7*8*4)
    {
        for (auto path : pathes)
        {
            std::ofstream file(path);
            std::vector<int> arr = create_sort_arr(N);
            fill_file(arr,file);
            file.close();
        }
    }

    std::vector<int> get_arr(std::string file)
    {
        std::ifstream in(file);
        std::vector<int> arr;
        while (!in.eof())
        {
            int tmp;
            in >> tmp;
            arr.push_back(tmp);
        }
        in.close();
        return arr;
    }

}




int main()
{
   

}
