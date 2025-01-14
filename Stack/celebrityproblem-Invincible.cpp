//APPROACH 2: USING STACK 

// class Solution 
// {
//     private:
    
//     bool knows(vector<vector<int>>&M ,int a ,int b,int n){
//         if(M[a][b]==1){
//             return true;
//         }
//         else{
//             return false;
            
//         }
        
//     }
//     public:
//     //Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& M, int n) 
//     {
//         stack<int> s;
        
//         //step1:push all elements in stack
//         for(int i=0;i<n;i++){
//         s.push(i);
//         }
        
//         //step2:// 2 element uthao stack ke top se aur compare karo 
//         while(s.size()>1){
//             int a=s.top();
//             s.pop();
            
//             int b=s.top();
//             s.pop();
            
//             if(knows(M,a,b,n)){//if a knows b , then b celebrity ho skta hai , a nahi ho skta tooh b ko push krdo vapis stack mai for further checks
//                 s.push(b);
//             }
//             else{//agar upar condtion true nahi hui matlab b nahi ho skta celebrity but shyd a ho skta hai , tooh usko daaldo stack mai for furhter checks
//                 s.push(a);
                
//             }
//         }
        
//         int ans=s.top();//as a index ayega ye 

//         //step3:single element in stack is potenial celebrity
//         //so verify it 
        
//         bool rowcheck=false;
//         int zerocount=0;
        
//         for(int i=0;i<n;i++){
//             if(M[ans][i]==0)
//             zerocount++;
            
//         }
        
//         //all zeros
//         if(zerocount==n){
//             rowcheck=true;
            
//         }
        
//         //column check
//         bool colcheck=false;
//         int onecount=0;
        
//         for(int i=0;i<n;i++){
//             if(M[i][ans]==1){
//                 onecount++;
                
//             }
//         }
        
//         if(onecount==n-1){
//             colcheck=true;
            
//         }
//         if(rowcheck==true && colcheck==true){
//             return ans;
//         }
//         else{
//             return -1;
            
            
//         }
        
        
        
        
//     }
// };

//APPROACH3:MOST OPTIMISED
class Solution  
{ 
    public: 
    //Function to find if there is a celebrity in the party or not. 
    int celebrity(vector<vector<int> >& M, int n)  
    { 
        int start =0, end = n-1; 
         
        while(start<end){ 
            if(M[start][end]==0){  //agar ye condition true hui matlab start end ko nahi jaanta tooh end celebrity nahi ho skta 
                end--; 
            } 
            else{ 
                start++;  //agar vo condition true nahi hui matlab start end ko jaanta hai , end celeb ho skta hai par start nahi ho skta 
            } 
            } 
        } 
         
        int candidate = start; 
         
        for(int i=0;i<n;i++){ 
            if(M[candidate][i]!=0) return -1; 
             
            if(i!=start && M[i][candidate]!=1) return -1; 
        } 
        return candidate; 
    } 

