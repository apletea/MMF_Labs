/*
── ── ██ ██ ── ── ── ── ── ── ── ██ ██ ── ──
── ██ ░░ ░░ ██ ██ ██ ██ ██ ▓▓ ▓▓ ░░ ░░ ██ ──
── ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ▓▓ ▓▓ ▓▓ ▓▓ ██ ──
── ── ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ▓▓ ▓▓ ── ──
── ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ██ ──
── ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ██ ──
██ ██ ░░ ░░ ██ ░░ ░░ ░░ ░░ ░░ ██ ░░ ░░ ██ ██
── ██ ░░ ░░ ██ ░░ ░░ ░░ ░░ ░░ ██ ░░ ░░ ██ ──
██ ██ ░░ ░░ ░░ ░░ ░░ ▌▌ ░░ ░░ ░░ ░░ ░░ ██ ██
── ── ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ██ ── ──
── ██ ░░ ██ ░░ ░░ ░░ ░░ ░░ ░░ ░░ ██ ░░ ██ ──
── ── ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ── ──
── ██ ▒▒ ▒▒ ▓▓ ▓▓ ▒▒ ▒▒ ▒▒ ▓▓ ▓▓ ▒▒ ▒▒ ██ ──
██ ▒▒ ▒▒ ▒▒ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▒▒ ▒▒ ▒▒ ██
██ ░░ ░░ ██ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ██ ░░ ░░ ██
██ ░░ ░░ ██ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ██ ░░ ░░ ██
── ██ ██ ██ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ██ ██ ██ ──
── ── ── ██ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ▓▓ ██ ── ── ──
── ── ── ██ ██ ██ ██ ██ ██ ██ ██ ██ ── ── ──
── ── ── ██ ░░ ░░ ░░ ██ ░░ ░░ ░░ ██ ── ── ──
── ── ── ── ██ ██ ██ ██ ██ ██ ██ ── ── ── ──
*/

#include <bits/stdc++.h>

namespace hello_search
{

    int binary_search_mp(const std::vector<int> & arr, int l, int r,int to_find = 0)
    {
        return l + (r-l)/2;
    }

    int interpolation_search_mp(const std::vector<int> arr, int l, int r, int to_find)
    {
        return l + ((to_find - arr[l]) * (r - l))/(arr[r] - arr[l]);
    }

    std::pair<int,int> search(const std::vector<int> & arr, int l, int r, int to_find, std::function<int (std::vector<int>,int,int,int)> midle_picker = binary_search_mp, int  depth = 0)
    {
        if (r - l < 2)
            return {-1,depth};
        int mid = midle_picker(arr, l , r , to_find);
        if (arr[mid] == to_find)
            return {mid,depth};
        if (arr[mid] < to_find)
            return search(arr,mid+1,r,to_find,midle_picker,depth+1);
        else
            return search(arr,l,mid-1,to_find, midle_picker,depth+1);
    }

    class BST
    {
    public:

        int val;
        BST * left;
        BST * right;

        BST(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }

        static BST * find(int to_find,BST * root,BST * prev = NULL)
        {
            if (!root)
                return prev;
            else if (root->val == to_find)
                return root;
            else if(root->val > to_find)
                return find(to_find, root->left, root);
            else
                return find(to_find, root->right, root);
        }

        void insert(int val)
        {
           BST * node = find(val,this);
           if (node->val == val)
               return;
           else
           {
               if (node->val < val)
                   node->right = new BST(val);
               else
                   node->left = new BST(val);
           }
        }

       void print(std::ofstream & out)
       {
           std::vector<std::vector<int>> vals;
           this->dfs(this,vals);
           int N = vals.size();
           for (int i = 0;i < N; ++i)
           {
               out << "level:" << i << " values: ";
               int M = vals[i].size();
               for (int j = 0; j < M ; ++j)
               {
                   out << vals[i][j];
                   out << "   ";
               }
               out << std::endl;
           }
       }

       void rotation()
       {

       }

       BST * ideal_balance(std::vector<int> & arr, BST * root)
       {
           if (!root)
               return NULL;
           ideal_balance(arr,root->left);
           arr.push_back(root->val);
           ideal_balance(arr,root->right);
           if (arr.size() == 51)
               return create_min_bst(arr,0,arr.size()-1);
       }


    private:

       static BST * create_min_bst( std::vector<int> & arr, int start, int end)
       {
           if (end < start)
               return NULL;
           int mid = start + (end - start)/2;
           BST * node = new BST(arr[mid]);
           node->left = create_min_bst(arr,start,mid-1);
           node->right = create_min_bst(arr, mid+1, end);
           return node;
       }

       void dfs(BST * root,std::vector<std::vector<int>> & arr,int depth = 0)
       {
           if (!root)
               return;
           if (arr.size() == depth)
           {
               std::vector<int> t;
               arr.push_back(t);
           }
           arr[depth].push_back(root->val);
           dfs(root->left, arr, depth+1);
           dfs(root->right, arr, depth+1);
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


void bst_trash()
{
    hello_search::BST * tree = new hello_search::BST(1);
    std::vector<int> arr= init::get_arr("numbers_9.txt");
    for (int i = 0; i < 50 ;++i)
    {
        tree->insert(arr[std::rand()%arr.size()]);
    }
    std::ofstream out("not_balanced.txt");
    tree->print(out);
    std::vector<int> tmp;
    tree = tree->ideal_balance(tmp,tree);
    out.close();
    out.open("balanced.txt");
    tree->print(out);
    out.close();
}

int main()
{
    int N = 10;
    bst_trash();
    std::vector<std::string> files = init::get_files_path(N);
    init::create_files(files);
    std::ofstream output("out.txt");
    output << "bs" << "                  " << "is" << std::endl;
    for (auto file : files)
    {
        std::vector<int> arr = init::get_arr(file);
        int bs_depth = 0, is_depth = 0;
        for (int i  = 0; i < 10 ; ++i)
        {
            int to_find = std::rand()% 1*9*9*7*8*4;
            std::pair<int,int> bs_pr = hello_search::search(arr,0,arr.size()-1,to_find,hello_search::binary_search_mp);
            std::pair<int,int> is_pr = hello_search::search(arr,0,arr.size()-1,to_find,hello_search::interpolation_search_mp);
            bs_depth+=bs_pr.second;
            is_depth+=is_pr.second;
        }
        int bs_avg = bs_depth/10, is_avg = is_depth/10;
        output << bs_avg << "               " << is_avg << std::endl;
    }

}
