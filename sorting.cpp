#include<iostream>
using namespace std;
class algo{
public:
    int a[10];
    int b[10];
    int c[10];
    int d[10];
    int e[10];
    int f[10];
    int g[10];
    int h[10];
    int arr[10];
    int n;
    int x;
    int y;
    int l;
    int m;
    int r;
    int exp;
    int high;
    int low;
    void takearr();
    void printarr(int arrr[]);
    void selectionsort();
    void bubble();
    void gnomesort();
    void insertionsort();
    void swaps(int& x,int& y);
    void mergee(int e[],int l, int m, int r);
    void mergesort(int e[],int l, int r);
    int partitions (int f[], int low, int high);
    void quicksort(int f[], int low, int high);
    int shellsort();
    void copyy(int arrr[],int ar[]);
    int getmax(int h[],int n);
    void countsort(int h[],int n ,int exp);
    void radixsort(int h[],int n);
};
void algo::copyy(int arrr[], int ar[])
{
    int i,n;
    int s=sizeof(arrr);
    for(i=0;i<s+1;i++)
    {
        ar[i]=arrr[i];
    }
}
void algo::swaps(int& x, int& y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
void algo::takearr()
{
    cout<<"enter the value of n"<<endl;
    cin>>n;
    cout<<"enter the values in array"<<endl;
        int i;
    for(i=0;i<n;i++)
    {
        {
            cin>> arr[i];
        }
    }
}

void algo::printarr(int arrr[])
{
    for(int i=0;i<n;i++)
    {
        cout<<arrr[i]<<endl;
    }
}
void algo::selectionsort()
{
    int i,j,imin;
    copyy(arr,a);
    for(i=0;i<n-1;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
            {
                swaps(a[j],a[imin]);
            }

        }
    }
    printarr(a);
}
void algo::bubble()
    {
        copyy(arr,b);
    for(int p=0;p<n;p++)
    {
        for(int i=0;i<n-1;i++)
        {
            if (b[i]>b[i+1])
            {
                swaps(b[i],b[i+1]);
            }
        }
    }
    printarr(b);
    }

void algo::gnomesort()

{
    copyy(arr,c);
    int i= 0;

    while (i < n) {
        if (i == 0)
            i++;
        if (c[i] >= c[i - 1])
            i++;
        else {
            swaps(c[i], c[i - 1]);
            i--;
        }
        }
        printarr(c);

}
void algo::insertionsort()

{
    copyy(arr,d);
    int i, j,key;
    for (i = 1; i < n; i++) {
        key = d[i];
        j = i - 1;

        while (j >= 0 && d[j] > key) {
            d[j + 1] = d[j];
            j = j - 1;
        }
        d[j + 1] = key;
    }
printarr(d);
}




void algo::mergee(int e[], int l, int m, int r)
{
    copyy(arr,e);
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


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
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void algo::mergesort(int e[], int l, int r)
{copyy(arr,e);
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergesort(e, l, m);
        mergesort(e, m+1, r);

        mergee(e, l, m, r);
    }
}

int algo::partitions (int arr[], int low, int high)
{
    copyy(arr,f);
    int pivot = f[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (f[j] <= pivot)
        {
            i++;
            swaps(f[i], f[j]);
        }
    }
    swaps(f[i + 1], f[high]);
    return (i + 1);
}
void algo::quicksort(int f[], int low, int high)
{ copyy(arr,f);
    if (low < high)
    {

        int pi = partitions(f, low, high);


        quicksort(f, low, pi - 1);
        quicksort(f, pi + 1, high);
    }
}

int algo:: shellsort()
{
    copyy(arr,g);

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = g[i];
            int j;
            for (j = i; j >= gap && g[j - gap] > temp; j -= gap)
                g[j] = g[j - gap];
            g[j] = temp;
        }
    }
    printarr(g);
    return 0;
}

int algo:: getmax(int arr[], int n)
{
    copyy(arr,h);
    int mx = h[0];
    for (int i = 1; i < n; i++)
        if (h[i] > mx)
            mx = arr[i];
    return mx;
}

void algo:: countsort(int h[], int n, int exp)
{
    copyy(arr,h);
    int output[n];
    int i, counts[10] = {0};

    for (i = 0; i < n; i++)
        counts[ (h[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        counts[i] += counts[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[counts[ (h[i]/exp)%10 ] - 1] = h[i];
        counts[ (h[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        h[i] = output[i];
}
void algo:: radixsort(int h[], int n)
{ copyy(arr,h);
    int m = getmax(h, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countsort(h, n, exp);
}




int main()
{
    algo p;
    p.takearr();
    cout<<endl<<endl;
    cout<<"After merge sort:"<<endl;
    int t=p.n-1,low ,high,n;
    p.mergesort(p.e,0,t);
    p.printarr(p.e);
    cout<<endl<<"insertion sort"<<endl;
    p.insertionsort();
    cout<<"selectionsort"<<endl;
    p.selectionsort();
   cout<<"bubblesort"<<endl;
    p.bubble();
    cout<<"gnome sort"<<endl;
    p.gnomesort();
    cout<<"quicksort"<<endl;
    p.quicksort(p.f,low,high);
    p.printarr(p.f);
    cout<<"shellsort"<<endl;
    p.shellsort();
    cout<<"radix sort"<<endl;
    p.radixsort(p.h,p.n);
    p.printarr(p.h);
    return 0;
}
