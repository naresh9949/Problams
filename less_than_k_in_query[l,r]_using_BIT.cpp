#include<iostream>

using namespace std;

class FenwickTree
{
	int size;
	int *Tree;
	int *ar;

public:
	FenwickTree(int n)
	{
		Tree = new int[n+1];

		size = n+1;
		memset(Tree,0,size);
		
	}


	int GetSum(int index)
	{
		int pos = index+1;
		int sum = 0;
		while(pos!=0)
		{
			sum+=Tree[pos];
			pos = GetParent(pos);
		}
		return sum;
	}


	void Update(int index,int value)
	{
		Update_Util(index,value);
	}

	void Update_Util(int index,int value)
	{
		int pos = index+1;

		while(pos<size)
		{
			Tree[pos] = Tree[pos]+value;
			pos = GetNext(pos);
		}
	}

	void show()
	{
			cout<<"BIT :";
			for(int i=0;i<size;i++)
				cout<<Tree[i]<<" ";
			cout<<endl;

			cout<<"ARR ";

			for(int i=0;i<size-1;i++)
				cout<<ar[i]<<" ";
			cout<<endl;
	}

	int GetNext(int k)
	{
		return k + (k & -k);
	}

	int GetParent(int k)
	{
		return k - (k & -k);
	}

};

struct ArrEle
{
  int idx,val;  
};

struct Query
{
  int l,r,x,idx;  
};


bool com1(ArrEle a1,ArrEle a2)
{
    return a1.val<a2.val;
}

bool com2(Query a1,Query a2)
{
    return a1.x<a2.x;
}

void ans(ArrEle a[],Query Q[],int n,int q)
{
    sort(a,a+n,com1);

    sort(Q,Q+q,com2);
    
    int cur = 0;

    int ans[q];

    FenwickTree bit(n);

    for(int i=0;i<q;i++)
    {
    	while(a[cur].val<=Q[i].x && cur<n)
    	{
    		bit.Update(a[cur].idx+1,1);
    		cur++;
    	}

    	ans[Q[i].idx] = bit.GetSum(Q[i].r+1)-bit.GetSum(Q[i].l);
    }

    for(int i=0;i<q;i++)
    	cout<<ans[i]<<" ";
    cout<<endl;



}

int main()
{
	
	ArrEle a[5];
	
	a[0].val = 2; 
    a[0].idx = 0; 
    a[1].val = 3; 
    a[1].idx = 1; 
    a[2].val = 4; 
    a[2].idx = 2; 
    a[3].val = 5; 
    a[3].idx = 3; 
    a[4].val = -5; 
    a[4].idx = 4; 
    
    Query Q[2];
    
    Q[0].l = 0; 
    Q[0].r = 2; 
    Q[0].x = 2; 
    Q[0].idx = 0; 
    
    Q[1].l = 0; 
    Q[1].r = 3; 
    Q[1].x = 5; 
    Q[1].idx = 1; 
    
    ans(a,Q,5,2);

    FenwickTree f(5);
    f.Update(1,1);
}