// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Print the maximum possible minimum distance.



bool ispsbl(vector<int>& stalls,int k, int mid){
    int cowcount=1;
    int lastpos=stalls[0];//last position vo wali position hai jaha prevous cow place ki thi 
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=mid){
            //agar ye condtion meet karti hai tooh next cow 
            //ko udhr place kar do , place kese karenge?cowcountbadha denge
            cowcount++;
            if(cowcount==k){//agar cowcount pura ho gaya matlab apna kaam ho gaya tooh return kardo true
                return true;

            }
            lastpos=stalls[i];

        }
    }
    return false;//nahi tooh esa mid possible nahi hai , 
    



    
}



int aggressiveCows(vector<int> &stalls, int k)
{  

    sort(stalls.begin(),stalls.end());//sort the array in ascending order

    
    int s=0;
    int maxi=-1;//min de diya isko abhi 
    for(int i=0;i<stalls.size();i++){
        maxi=max(maxi,stalls[i]);

    }
    int e=maxi;
    int ans=-1;

    int mid=s+(e-s)/2;
    while(s<=e){
        if(ispsbl(stalls,k,mid)){
            ans=mid;
            s=mid+1;

        }
        else{
            e=mid-1;

        }
        mid=s+(e-s)/2;
    }
    return ans;
    

    
}