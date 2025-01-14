#include<iostream>
using namespace std;

//In this we have not followed 0 based indexing
class heap{
    public:
    int arr[100];
    int size=0;



    //constructor
    heap(){
        arr[0]=-1;
        size=0;
    }


    //INSERTION
    void insert(int val){
        //MAX HEAP 


        //1st step- insert at end

        size=size+1;//size badha lo
        int index=size;//fir index ko vaha le jao jaha daalna hai i.e at last position
        arr[index]=val;//fir us index pe value ko daaldo


        //2nd step- sahi jghe par leke jao us element ko
        while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){//kyunki max heap bana rahe hhai tooh parent ki value jyada honi chahiye ,
            // tooh agar jo element dala hai uski value jyada hai tooh swap kardo uski aur parent ki value
                swap(arr[parent],arr[index]);
                index=parent;//index ko parent par point karva do , jo ki hoga naya element kyunki aage aur bhi checks krne hai humko parent ka parent ke liye bhi ,tooh 
            }
            else{
                return ;

            }
        }
    }


    //PRINTING
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";

            }
            cout<<endl;

        }
    


    //DELETION
    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }


        //step 1:first(root) node mai last node ki value daaldo
        arr[1]=arr[size];

        //step 2 :aur last node delete kardo
        size--;


        //step 3:take root node to its correct postion(according to the max heap)

        int i=1;
        while(i<=size){
            int leftindex=2*i;
            int rightindex=2*i+1;

            if(leftindex<=size && arr[i]<arr[leftindex] && arr[leftindex] > arr[rightindex]){//ye bhi jrur dekhna ke left wala right wale se bada honda chahiye , nahi tooh niche wale mai daalo               //agar child bada hai idhr tooh swap krdo
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }

            else if(rightindex<=size && arr[i]<arr[rightindex]&& arr[leftindex] < arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return ;
            }
        }


    }

};


//Heapify 
void heapify(int arr[],int n,int i){

    int largest=i; //Initialize largest as root
    int left=2*i;
    int right=2*i+1;

    // If left child is larger than root
    if(left<=n&& arr[largest]<arr[left]){
        largest=left;

    }
    // If right child is larger than root
    if(right<=n&&arr[largest]<arr[right]){
        largest=right;
    }

    // If largest is not root
    if(largest!=i){
        swap(arr[largest],arr[i]);

        // Recursively heapify the affected sub-tree
        heapify(arr,n,largest);
    }

}


//Heap sort
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        //step1: swap
        swap(arr[size],arr[1]);
        size--;

        //step 2:
        heapify(arr,size,1);//1 ilsiye kyunki hamesha root node ko heapify krke sahi jaghe le jaana hai 

    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"printnig the array now "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

    //heapsort
    heapsort(arr,n);
       cout<<"printnig sorted array now "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;


    return 0;
}