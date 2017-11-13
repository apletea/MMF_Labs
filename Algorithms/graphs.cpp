//███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█ 
//████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█ 
//███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█ 
//████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█ 
//███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█ 
//████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█ 
//███▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█ 
//████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█ 
//███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█ 
//█████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█ 
//█████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██ 
//█████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██ 
//████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██ 
//████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██ 
//█████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██ 
//█████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███ 
//██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███ 
//███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████ 
//███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████ 
//████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████ 
//█████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████ 
//██████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓███████ 
//███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████ 
//██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████ 
//███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████

#include <bits/stdc++.h>


namespace gf_graph
{
class graph
{
public:
    
    std::list<graph*> neignbohrs;
    int val;
    
    static graph* create_undirected()
    {
        return nullptr;
    }
    
    static graph* create_directed()
    {
        return nullptr;
    }
    
    std::map<std::pair<int,int>,short int> get_maze()
    {
        
    }
    
    std::vector<graph*> find_euler_path()
    {
        std::set<graph*> is_visited;
        if(this->is_valid_euler(this,is_visited)>2)
            return {};
        std::stack<graph*> st;
        std::vector<int> ans;
        st.push(this);
        while(!st.empty())
        {
            
            graph* v = st.top();
            graph* tmp;
            st.pop();
            for (auto neighbor : v->neignbohrs)
            {
                
            }
        }
        
        
    }
    
    bool is_bound_graph()
    {
        
    }
    
    int dejkstra()
    {
        
    }
    
    std::vector<int> find_path()
    {
        
    }
private:
    static int is_valid_euler(graph* edge ,std::set<graph*> & is_visitetd)
    {
       int ans = 0;
       if (is_visitetd.find(edge)==is_visitetd.end())
            return 0;
       for(auto  neignhbor : edge->neignbohrs)
       {
           is_visitetd.insert(edge);
           ans +=is_valid_euler(neignhbor, is_visitetd);
       }
       return ans+edge->neignbohrs.size()%2;
    }
    
    void delete_neighbor()
    {
        
    }
};


}


int main(int argc, char ** argv)
{
    
}
