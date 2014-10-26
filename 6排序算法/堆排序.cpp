#include<iostream>
using namespace std;
int numsofchange=0;                                       //�������������汣�ֶ����ʵĴ��� 
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

void maxHeapify(int heap[],int i,int heapsize)            //��������������ѵ����� 
{
    numsofchange++;
    int l=2*i,r=2*i+1;
    int largest;
    if(l<=heapsize&&heap[l]>heap[i])
        largest=l;            //�ȱȽ������������� 
    else 
        largest=i;
    if(r<=heapsize&&heap[r]>heap[largest])
         largest=r;      //�ٱȽ������������� 
    if(largest!=i)                                        //����û�֮�������п���Υ���˶ѵ����ʣ���Ҫ����������������ٱ���һ�� 
    {
        swap(heap[i],heap[largest]);
       // printHeap(heap,heapsize);                       //Ϊ�˷���۲죬������ÿһ���Ĺ۲� 
        maxHeapify(heap,largest,heapsize);                //�������û��������������ʱ��� 
    } 
}

void buildMaxHeap(int heap[],int heapsize)                //���� 
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
       printHeap(heap,heapsize);                         //���һ��������������ȷ��� 
    }
}

int main()
{
    printf("������Ҫ����Ĵ�С������������Ԫ�أ�������ж�����:"); 
    int n;
    scanf("%d",&n);
    int nums[100];
    for(int i=1;i<=n;i++)
       scanf("%d",&nums[i]);
    heapSort(nums,n);
    printf("maxHeap����������%d��\n�������:",numsofchange); 
    for(int i=1;i<=n;i++)
       printf("%d ",nums[i]);
    system("pause"); 
    return 0;
}
