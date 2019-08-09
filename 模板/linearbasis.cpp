struct linearbasis
{
    ll base[64];
    int sz,tol;
    linearbasis(){mem(base,0);sz=0;tol=0;}
    bool ins(ll v)
    {
        for(int i=64;~i;--i)
            if(v&(1LL<<i))
            {
                if(!base[i])
                {
                    base[i]=v;
                    ++tol;
                    ++sz;
                    return 1;
                }
                else
                    v^=base[i];
            }
        return 0;
    }
    void rebuild()
    {
        for(int i=64;~i;--i)
            for(int j=i-1;~j;--j)
                if(base[i]&(1LL<<j))
                    base[i]^=base[j];
    }
    ll kth(ll v,ll k)
    {
        if(k>=(1LL<<sz))
            return -1;
        ll tp[64];
        int cnt=0;
        for(int i=0;i<64;++i)
            if(base[i])
                tp[cnt++]=base[i];
        for(int i=63;~i;--i)
            if(k&(1LL<<i))
                v^=tp[i];
        return v;
    }
    linearbasis union(const linearbasis &t)const
    {
        linearbasis r;
        for(int i=0;i<64;++i)
            r.ins(base[i]),r.ins(t.base[i]);
        return r;
    }
    linearbasis intersection(const linearbasis &t)
    {

    }
    void show()
    {
        cout<<sz<<endl;
        for(int i=0;i<64;++i)
            cout<<i<<' '<<(bitset<50>)base[i]<<endl;
    }
};
