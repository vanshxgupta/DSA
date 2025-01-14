                                                 
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
            deque<long long int > dq;
            vector<long long>ans;
            
            //process first window of  k size 
            
            for(int i=0;i<K;i++){
                if(A[i]<0){
                    dq.push_back(i);//agar negative element milta hai tooh uska index store kara lo 
                }
            }
            
            //store answer of first k sized window 
            if(dq.size()>0){
                ans.push_back(A[dq.front()]);//bhale hi dq mai kitne bhi negative element aa jaye par dq ka front element hi lenge apn bas ,kyunki vahi first negative hoga 
            }
            else{
                ans.push_back(0);
            }
            
            //process remaining windows 
            for(int i=K;i<N;i++){
                //removal 
                if(!dq.empty() && dq.front() == i-K){
                    dq.pop_front();
                }
                
                //addition 
                if(A[i]<0){
                    dq.push_back(i);
                }
                
                //ans store
                if(!dq.empty()){
                    ans.push_back(A[dq.front()]);
                }
                else{
                    ans.push_back(0);
                }
            }
            return ans;
}