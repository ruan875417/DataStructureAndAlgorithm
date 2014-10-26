#include<iostream>
int num[1000001];
int temp[1000001]; //该空间用来存放合并后的序列

using namespace std;
class UltraQuickSort{
      private:
            int count;
            long long sum;
      public:
            void initial(int n);
            void readCase();
            void merge(int *a,int beg,int mid,int end);
            void mergeSort(int *a,int beg,int end);  
            void output();
};
void UltraQuickSort::initial(int n){
     sum=0;
     count=n;
}
void UltraQuickSort::readCase(){
     for(int i=0;i<count;i++){
         scanf("%d",&num[i]);
     }
}
void UltraQuickSort::merge(int *a,int beg,int mid,int end){
     int i=beg,j=mid+1,k=0;
     while(i<=mid&&j<=end){//比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
         if(a[i]<=a[j]){ 
             temp[k++]=a[i++];
         }else {
             temp[k++] = a[j++];
             sum+=mid-i+1;
         }
     }
     while(i<=mid)    //若第一个序列有剩余，直接拷贝出来粘到合并序列尾
         temp[k++]=a[i++];
     while(j<=end)     //若第二个序列有剩余，直接拷贝出来粘到合并序列尾
         temp[k++]=a[j++];
     for(i=0;i<k;i++)//将排序好的序列拷贝回数组中
         a[beg+i]=temp[i];
} 
void UltraQuickSort::mergeSort(int *a,int beg,int end){
     int mid;
     mid=(beg+end)>>1;
     if(beg<end){
         mergeSort(a,beg,mid);  //左边有序
         mergeSort(a,mid+1,end);//右边有序
         merge(a,beg,mid,end);//再将两个有序数列合并
     }
}
void UltraQuickSort::output(){
     cout<<"交换次数为"<<sum<<endl;
     printf("最终排序结果："); 
     for(int i=0;i<count;i++)
     {
         printf("%d,",num[i]); 
     } 
}
///////////////////////////////////////////////////////////
int main(){
     int n;
     UltraQuickSort x;
     while(cin>>n){
          x.initial(n);
          x.readCase();
          x.mergeSort(num,0,n-1);
          x.output();
     }
     return 0;
 }
