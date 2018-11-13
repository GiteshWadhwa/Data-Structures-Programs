#include<iostream>
using namespace std;

class mAndsSort
{
	public:
	void Sort(int a1[],int a2[],int s1,int s2)
	{
		selectionSort(a1,s1);
		selectionSort(a2,s2);

		int merged[s1+s2];

		for(int i=0;i<s1;i++) {

			merged[i] = a1[i];
		}

		int j = 0;
		for(int i=s1;i<s1+s2;i++) {

			merged[i] = a2[j];
			j++;
		}

		mergeSort(merged,0,s1 + s2);
		for(int i=0;i<s1+s2;i++) {

			cout<<merged[i]<<"\t";
		}
		cout<<endl;

	}

	void selectionSort(int a[],int s) {

		int min_ind;
		for(int i=0;i<s;i++) {

			min_ind = i;
			for(int j=i+1;j<s;j++)
			{
				if(a[min_ind]>a[j])
				{
					min_ind = j;
					break;
				}
			}

			int temp = a[min_ind];
			a[min_ind] = a[i];
			a[i] = temp;

		}
	}
	void mergeSort(int arr[], int low, int high)
	{
    		if (low < high)
	    	{
	        	int mid = (low+high)/2;

	        	mergeSort(arr, low, mid);
	        	mergeSort(arr, mid+1, high);

	  	      	combine(arr, low, mid, high);
	  	}
	}

	void combine(int arr[], int l, int m, int h)
	{
    	int n1 = m - l + 1;
		int n2 =  h - m;
		int L[n1], R[n2];

  		int i,j,k;
  		for (i = 0; i < n1; i++)
	        	L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
		        R[j] = arr[m + 1+ j];

		i = 0;
		j = 0;
		k = l;
	    	while (i < n1 && j < n2)
	    	{
        		if (L[i] <= R[j])
        		{
        	    	arr[k] = L[i];
	        	    i++;
        		}
        		else
        		{
        		    arr[k] = R[j];
        		    j++;
        		}
        		k++;
    		}

	    while (i < n1)
		{
		    arr[k] = L[i];
		    i++;
		    k++;
		}

		while (j < n2)
	    {void getArr()
		{
			cout<<"Enter size of Array\n";
			cin>>size;
			arr=new int[size];
			cout<<"Enter elements for Array\n";
			for(int i=0;i<size;i++)
			{
				cin>>*(arr+i);
			}
		}
		void binarySearch()
		{
			int val,flag=0,mid;
			int ub=size;
			int lb=0;
			bubbleSort();
			cout<<"Enter element to search in the array\n";
			cin>>val;
			while(lb<=ub)
			{
				mid=int((ub+lb)/2);
				if(arr[mid]==val)
				{
					cout<<"Element found at "<<mid<<" index\n";
					flag=1;
					break;
				}
				else
				{
					if(val<arr[mid])
					{
						ub=mid-1;
					}
					else
					{
						lb=mid+1;
					}
				}
			}
			if(flag==0)
			{
				cout<<"Element not found\n";
			}
		}
		void printArr()
		{
			for(int i=0;i<size;i++)
			{
				cout<<*(arr+i)<<" ";
			}
			cout<<endl;
		}

		void bubbleSort()
		{
			for(int i=0;i<size;i++)
			{
				for(int j=1;j<(size-i);j++)
				{
					if(arr[j-1] > arr[j])
					{
						int temp = arr[j-1];
						arr[j-1] = arr[j];
						arr[j] = temp;
					}
				}
			}
			printArr();
		}
		    arr[k] = R[j];
		    j++;
		    k++;
		}
	}
};

int main()
{
	int size1,size2;
	cout<<"Enter size of first Array\n";
	cin>>size1;
	cout<<"Enter size of second Array\n";
	cin>>size2;
	int arr1[size1];
	int arr2[size2];
	cout<<"Enter elements in first array\n";
	for(int i=0;i<size1;i++)
	{
		cin>>arr1[i];
	}
	cout<<"Enter elements in second array\n";
	for(int i=0;i<size2;i++)
	{
		cin>>arr2[i];
	}

	mAndsSort s;
	s.Sort(arr1,arr2,size1,size2);
}
