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

        BST * find(int to_find,BST * root)
        {
            if (!root)
                return root;
            else if (root->val == to_find)
                return root;
            else if(root->val > to_find)
                return find(to_find, root->left);
            else
                return find(to_find, root->right);
        }
        
        void insert(int val)
        {
           
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

