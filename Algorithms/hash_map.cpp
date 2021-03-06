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



namespace IRA // yoou go to hell
{

    std::vector<int> siephe_eratosphene(int max)
    {
        std::vector<bool> prime (max+1, true);
        prime[0] = prime[1] = false;
        for (int i=2; i<=max; ++i)
            if (prime[i])
                if (i * 1ll * i <= max)
                    for (int j=i*i; j<=max; j+=i)
                        prime[j] = false;
        std::vector<int> ans;
        for (int i = 0; i < max+1; ++i)
            if (prime[i])
                ans.push_back(i);
        return ans;
    }

    int find_closest_prime(int k)
    {
        std::vector<int> primes = siephe_eratosphene(250);
        int i = 0;
        while(primes[i++]<100);
        while(k--) i++;
        return primes[i];
    }

    template <typename T>
    class linked_list
    {
    public:
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
            this->tail = this->tail->next;
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

        void delete_node(linked_list * node)
        {
            linked_list * runner = this;
            if (runner == node)
            {
                this->val = runner->next->val;
                this->next = runner->next->next;
            }
            while((runner && runner->next != node))
                runner= runner->next;
            if (runner)
            runner->next = runner->next->next;
        }

    };


    template <typename K>
    class hash_map_ll
    {
    private:
        std::vector<linked_list<std::pair<K,K>>*> data_storage;

        linked_list<std::pair<K,K>> * find_in_ll(linked_list<std::pair<K,K>>* head, K key)
        {
            linked_list<std::pair<K,K>> * tmp = head;
            while((tmp) && tmp->val.first != key)
                tmp = tmp->next;
            return tmp;
        }

        bool is_empty(K key)
        {
            return !data_storage[get_hash(key)%data_storage.size()];
        }

        int get_hash(K key)
        {
            return static_cast<int>(key);
        }


        void print(linked_list<std::pair<K,K>> * ll)
        {
            linked_list<std::pair<K,K>> * runner = ll;
            while(runner)
            {
                std::cout << " {"<< runner->val.first << "}  ";
                runner = runner->next;
            }
            std::cout << std::endl;

        }
    public:
        hash_map_ll(int val)
        {
            this->data_storage = std::vector<linked_list<std::pair<K,K>> *>(val,NULL);
        }

        void add(K key, K val = 0)
        {
            val = key;
            std::pair<K,K> pr = {key,val};
            if (is_empty(key))
                data_storage[get_hash(key)%data_storage.size()] = new linked_list<std::pair<K,K>>(pr);
            else
                data_storage[get_hash(key)%data_storage.size()]->append(pr);
        }

        K find(K key)
        {
            if (is_empty(key))
                return NULL;
            return find_in_ll(data_storage[get_hash(key)%data_storage.size()], key)->val.second;
        }

        void remove(K key)
        {
            if (is_empty(key))
                return;
           linked_list<std::pair<K,K>> * list = data_storage[get_hash(key)%data_storage.size()];
           int index = get_hash(key)%data_storage.size();
           data_storage[index]->delete_node(find_in_ll(list, key));

        }


        void print()
        {
            for (int i = 0; i < data_storage.size(); ++i)
            {
                std::cout << "i:=" << i << " :   ";
               (print(data_storage[i]));
            }
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
    std::vector<int> primes = IRA::siephe_eratosphene(200);
    for (int a : primes)
    {
        std::cout << a << std::endl;
    }
    IRA::hash_map_ll<int> mp(IRA::find_closest_prime(1));
//    for (int i = 0; i < 10000; ++i)
//    {
//        mp.add(i,std::rand()%400);
//    }
//    std::cout << "mp after init" << std::endl;
//    mp.print();
//    std::cout << "find in mp vy key from 1 to 10" << std::endl;
//    for (int i = 0; i < 10; ++i)
//    {
//        std::cout << mp.find(i) << std::endl;
//    }
//    std::cout << "after deleting in mp from 1 to 10" << std::endl;
//    for (int i  = 0; i < 10; ++i)
//    {
//        mp.remove(i);
//    }
    mp.add(1);
    mp.add(15);
    mp.print();

}

