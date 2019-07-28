const int maxn=1e5+5;
struct SAM
{
	struct node
	{
		int to[26];
		int len,link;
	}t[2*maxn];
	int sz,lst;
	int newnode(int len)
	{
		mem(t[sz].to,0);
		t[sz].len=len;
		t[sz].link=-1;
		return sz++;
	}
	void init()
	{
		sz=0;
		lst=0;
		newnode(0);
	}
	void add(int c)
	{
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
	ll butongzichuanzongchang()
	{
		ll res=0;
		for(int i=1;i<sz;++i)
		{
			ll tp=t[i].len-t[t[i].link].len;
			res+=(t[i].len+(t[i].len-tp+1))*tp/2;
		}
		return res;
	}
}sam;
