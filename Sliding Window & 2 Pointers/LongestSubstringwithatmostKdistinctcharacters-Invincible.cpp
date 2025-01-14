//Brute force

int lengthoflongestsubstringKdistinct(string s ,int k){
    int maxlen=0;
    map<char,int>mpp;
    for(int i=0;i<n;i++){
        mpp.clear();

        for(j=i;i<n;j++){
            mpp[s[i]]++;
            if(mpp.size()<=k){
                maxlen=max(maxlen,j-i+1);

            }
            else{
                break;

            }
        }
        return maxlen;
    }
}


//BETTER
int lengthoflongestsubstringKdistinct(string s ,int k){


    int l=0;
    int r=0;
    int maxlen=0;
    int n=s.length();
    map<char,int> mp;
    while(r<n){

        mp[s[r]]++;
        
        while(map.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l])
                }
                l++;
            }
        if(mp.size()<=k){
                maxlen=max(maxlen,r-l+1);
        }
        
        r++;

    }
    return maxlen;
}



//OPTIMAL
int lengthoflongestsubstringKdistinct(string s ,int k){


    int l=0;
    int r=0;
    int maxlen=0;
    int n=s.length();
    map<char,int> mp;
    while(r<n){

        mp[s[r]]++;
        
        while(map.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l])
                }
                l++;
            }
        if(mp.size()<=k){
                maxlen=max(maxlen,r-l+1);
        }
        
        r++;

    }
    return maxlen;
}


