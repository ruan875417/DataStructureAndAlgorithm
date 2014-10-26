#include<iostream>
int num[1000001];
int temp[1000001]; //�ÿռ�������źϲ��������

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
     while(i<=mid&&j<=end){//�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��
         if(a[i]<=a[j]){ 
             temp[k++]=a[i++];
         }else {
             temp[k++] = a[j++];
             sum+=mid-i+1;
         }
     }
     while(i<=mid)    //����һ��������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β
         temp[k++]=a[i++];
     while(j<=end)     //���ڶ���������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β
         temp[k++]=a[j++];
     for(i=0;i<k;i++)//������õ����п�����������
         a[beg+i]=temp[i];
} 
void UltraQuickSort::mergeSort(int *a,int beg,int end){
     int mid;
     mid=(beg+end)>>1;
     if(beg<end){
         mergeSort(a,beg,mid);  //�������
         mergeSort(a,mid+1,end);//�ұ�����
         merge(a,beg,mid,end);//�ٽ������������кϲ�
     }
}
void UltraQuickSort::output(){
     cout<<"��������Ϊ"<<sum<<endl;
     printf("������������"); 
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
