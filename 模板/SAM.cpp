const int maxn=1e5+5;
struct SAM
{
	struct node
	{
		int to[26];
		int len,link;
	}t[2*maxn];
	int sz,lst,len;
	char s[maxn];
	int cnt[maxn],top[maxn*2];
	int cc[2*maxn],ans[2*maxn];
	int newnode(int len)
	{
		mem(t[sz].to,0);
		t[sz].len=len;
		t[sz].link=-1;
		return sz++;
	}
	void init()
	{
		sz=lst=len=0;
		newnode(0);
		mem(cnt,0);
		mem(top,0);
	}
	void add(char w)
	{
	    s[++len]=w;
	    int c=w-'a';
		int p=lst;
		int now=newnode(t[p].len+1);
		while(p!=-1&&!t[p].to[c])
		{
			t[p].to[c]=now;
			p=t[p].link;
		}
		if(p==-1)
			t[now].link=0;
		else
		{
			int q=t[p].to[c];
			if(t[p].len+1==t[q].len)
				t[now].link=q;
			else
			{
				int clone=newnode(t[p].len+1);
				t[clone].link=t[q].link;
				for(int i=0;i<26;++i)
					t[clone].to[i]=t[q].to[i];
				t[q].link=clone;
				t[now].link=clone;
				while(p!=-1&&t[p].to[c]==q)
				{
					t[p].to[c]=clone;
					p=t[p].link;
				}
			}
		}
		lst=now;
	}
	void topsort()
	{
	    for(int i=0;i<sz;++i)
            ++cnt[t[i].len];
        for(int i=0;i<=len;++i)
            cnt[i]+=cnt[i-1];
        for(int i=sz-1;~i;--i)
            top[cnt[t[i].len]--]=i;
        
        for(int i=0;i<sz;++i)
            ans[i]=t[i].len;
	}
	void run(char s[])//多串LCS
	{
	    mem(cc,0);
	    int n=strlen(s);
	    int p=1,l=0;
	    for(int i=0;i<n;++i)
        {
            int c=s[i]-'a';
            while(p!=-1&&!t[p].to[c])
                p=t[p].link,l=t[p].len;
            if(p==-1)
                p=1,l=0;
            else p=t[p].to[c],cc[p]=max(cc[p],++l);

        }
        for(int i=sz-1;~i;--i)
        {
            int x=top[i];
            cc[t[x].link]=max(cc[t[x].link],cc[x]);
        }
        for(int i=0;i<sz;++i)
            ans[i]=min(ans[i],cc[i]);
	}
	int res()
	{
	    int r=0;
	    for(int i=0;i<sz;++i)
            r=max(r,ans[i]);
        return r;
	}
}sam;
