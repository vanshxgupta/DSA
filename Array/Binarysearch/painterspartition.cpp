// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

bool ispsbl(vector<int> &boards, int k,int mid){
    int pcount=1;//painter count
    int boardsum=0;
    for(int i=0;i<boards.size();i++){
        if(boards[i]+boardsum<=mid){
            boardsum+=boards[i];

        }
        else{
            pcount++;
            if(pcount>k || boards[i]>mid){
                return false;

            }
            boardsum=boards[i];


        }
    }
    return true;

}




int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    int ans=-1;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];


    }
    int e=sum;
    int mid=s+(e-s)/2;
    
    while(s<=e){
        if(ispsbl(boards,k,mid)){
            ans=mid;

            e=mid-1;

        }
        else{
            s=mid+1;

        }
        mid=s+(e-s)/2;

    }
    return ans;
}