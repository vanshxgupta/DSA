// //BETTER 
// class Solution {
//   public:
//     int totalFruits(int N, vector<int> &fruits) {
//         int l=0;
//         int r=0;
//         int maxlen=0;
//         map<int,int>mp;
        
//         while(r<fruits.size()){
//             mp[fruits[r]]++;
//             if(mp.size()>2){
//                 while(mp.size()>2){
//                     mp[fruits[l]]--;
//                     if(mp[fruits[l]]==0){
//                         mp.erase(fruits[l]);
                        
//                     }
//                     l++;
                    
//                 }
//             }
//             if(mp.size()<=2){
//                 maxlen=max(maxlen,r-l+1);
                
//             }
//             r++;
            
//         }
//         return maxlen;
        
        
//     }
// };


//OPTIMAL
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int l=0;
        int r=0;
        int maxlen=0;
        map<int,int>mp;
        
        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                if(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                        
                    }
                    l++;
                    
                }
            }
            if(mp.size()<=2){
                maxlen=max(maxlen,r-l+1);
                
            }
            r++;
            
        }
        return maxlen;
        
        
    }
};