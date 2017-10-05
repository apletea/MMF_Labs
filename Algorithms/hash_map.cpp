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

        void delete_node(linked_list * node)
        {

        }
    };


    template <typename K, typename V>
    class hash_map_ll
    {
        std::vector<linked_list<std::pair<K,V>>*> data_storage;

        int get_hash(K key)
        {
            return static_cast<int>(key);
        }

    public:
        hash_map_ll(int val)
        {
            this->data_storage = std::vector<linked_list<std::pair<K,V>> *>(val,NULL);
        }

        void add(K key, V val)
        {
            std::pair<K,V> pr = {key,val};
            if (is_empty(key))
                data_storage[get_hash(key)%data_storage.size()] = new linked_list<std::pair<K,V>>(pr);
            else
                data_storage[get_hash(key)%data_storage.size()].append(pr);
        }

        V find(K key)
        {
            if (is_empty(key))
                return NULL;
            return find_in_ll(data_storage[get_hash(key)%data_storage.size()], key).val.second;
        }

        void remove(K key)
        {
            if (is_empty(key))
                return;
           (data_storage[get_hash(key)%data_storage.size()]).delete_node(find_in_ll(data_storage[get_hash(key)%data_storage.size()], key).val.second);

        }
    private:
        linked_list<std::pair<K,V>> find_in_ll(linked_list<std::pair<K,V>> head, K key)
        {
            while(head && head.val.first != key)
                head = head->next;
            return head;
        }

        bool is_empty(K key)
        {
            return !data_storage[get_hash(key)%data_storage.size()];
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

    std::cout << IRA::find_closest_prime(11) << std::endl;

}
