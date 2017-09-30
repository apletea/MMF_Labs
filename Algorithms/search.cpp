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
               }
               out << std::endl;
           }
       }
       
       void rotation()
       {
           
       }
       
       void ideal_balance(std::vector<int> & arr = {}, BST * root = this)
       {
           if (!root)
               return;
           ideal_balance(arr,root->left);
           arr.push_back(root->val);
           ideal_balance(arr,root->right);
           if (!root->left & !root->right)
               this = create_min_bst(arr,0,arr.size()-1);
       }
       
       
    private:
       
       static BST * create_min_bst(static std::vector<int> & arr, int start, int end)
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
    void create_files(int N)
    {

    }
}

int main()
{
    int a = 1;
    std::cout << a << std::endl;
    return 0;
}
