class Solution {
public:
    vector<int> parent;
    vector<int> size;
    
    int find(int x)
    {
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void unionBySize(int x , int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if( x_parent == y_parent) return ;

        if(size[x_parent] >= size[y_parent])
        {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent]; 
        }else{
            parent[x_parent] = y_parent;
            size[y_parent]  += size[x_parent];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        size.resize(26 , 1);
        for(int i =0 ; i< 26 ; i++)
        {
            parent[i] = i;
        }
        for(string &equation:equations)
        {
            if(equation[1] == '=')
            {
                int x = equation[0] -'a';
                int y = equation[3] -'a';
                unionBySize(x , y);
            }
        }
        for(string &equation:equations)
        {
            if(equation[1] == '!')
            {
                int x = equation[0]-'a';
                int y = equation[3]-'a';
                int x_parent = find(x);
                int y_parent = find(y);

                if( x_parent == y_parent) return false;
            }
        }

        return true;
    }
};