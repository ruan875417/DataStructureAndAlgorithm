#include<iostream>
using namespace std;
int numsofchange=0;                                       //用这个标记来储存保持堆性质的次数 
void swap(int& a,int& b)
{
    int t=a;a=b;b=t;
}

void printHeap(int heap[],int heapsize)
{
    for(int i=1;i<=heapsize;i++)
    {
        printf("%d ",heap[i]);
    } 
    printf("\n");
}

void maxHeapify(int heap[],int i,int heapsize)            //用这个来保持最大堆的性质 
{
    numsofchange++;
    int l=2*i,r=2*i+1;
    int largest;
    if(l<=heapsize&&heap[l]>heap[i])
        largest=l;            //先比较左子树的数字 
    else 
        largest=i;
    if(r<=heapsize&&heap[r]>heap[largest])
         largest=r;      //再比较右子树的数字 
    if(largest!=i)                                        //如果置换之后子树有可能违反了堆的性质，就要对下面的所有子树再保持一次 
    {
        swap(heap[i],heap[largest]);
       // printHeap(heap,heapsize);                       //为了方便观察，设置了每一步的观察 
        maxHeapify(heap,largest,heapsize);                //对做了置换的子树进行性质保持 
    } 
}

void buildMaxHeap(int heap[],int heapsize)                //建堆 
{
    for(int i=heapsize/2;i>=1;--i)
    {
        maxHeapify(heap,i,heapsize);     
    }    
}

void heapSort(int heap[],int heapsize)                    
{
    buildMaxHeap(heap,heapsize);    
    int last=heapsize;
    for(int i=heapsize;i>=2;--i)
    {
        swap(heap[1],heap[i]);
        last--;
        maxHeapify(heap,1,last);
       printHeap(heap,heapsize);                         //最后一次输出结果便是正确结果 
    }
}

int main()
{
    printf("请输入要数组的大小，和输入数组元素，下面进行堆排序:"); 
    int n;
    scanf("%d",&n);
    int nums[100];
    for(int i=1;i<=n;i++)
       scanf("%d",&nums[i]);
    heapSort(nums,n);
    printf("maxHeap函数调用了%d次\n排序后结果:",numsofchange); 
    for(int i=1;i<=n;i++)
       printf("%d ",nums[i]);
    system("pause"); 
    return 0;
}
