class TrieNode{
    public:
    TrieNode*children[2];//0 or 1
};

TrieNode* getnode(){
    TrieNode*root=new TrieNode();
    for(int i=0;i<2;i++){
        root->children[i]=NULL;
    }
    return root;
}

class Trie{
    public:
    TrieNode*root=getnode();

    void insert(int num){
        TrieNode*crawler=root;
        for(int i=31;i>=0;i--){
            //num ki ith bit wala ya tooh 0 hoga ya 1 hoga ,
            int val=(num>>i)&1;//1 hua tooh 1 dega , vrna 0
            if(crawler->children[val]==NULL){
                crawler->children[val]=getnode();
            }
            crawler=crawler->children[val];
        }
    }

    int getmax(int x){//x number se xor krna hai , xor tabh max hoga jab x ki ith position pe jo hai uske complementary kuch aaye tooh , jese ith bit of x pr 1 hai tooh trie mai jis raste pr 0 hoga vo lenge apn , agar 0 vala null hua tooh , humko 1 lena hi padega 

    TrieNode*crawler=root;
    int maxi=0;
    for(int i=31;i>=0;i--){
        int val=(x>>i)&1;
        int comp=1-val;
        if(crawler->children[comp]==NULL){//that means complementary tooh present nahi hai , matlab ,iss position ki bit 0 hi rahegi ,
            crawler=crawler->children[val];//comp nahi hai tooh val wali pr hi aage chalo
        }
        else{
            //complementary bit present hai tooh turn on krdo maxi ki bhi iss position ki bit ko

            //TURN-ON ese krte hai 
            maxi=(maxi | (1<<i));
            crawler=crawler->children[comp];
        }
    }
    return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();

        //for every element , we will be finding the maximum xor from all the elements of the arr
        // i.e we will be finding max value of (x^arr[i])->we shoud get it in o(1)
        //so when we traverse the whole array i.e x value from arr[0] to arr[n-1]->then complexity will become o(1)*o(n);

        //we will put all the numbers in the nums in the trie first (bit by bit , we will put them )->O(32);

        Trie*t=new Trie();
        for(int i=0;i<n;i++){
            t->insert(nums[i]);
        }

        //now check for the maxi xor 
        int maxi=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int maxixor=t->getmax(x);
            maxi=max(maxi,maxixor);
        }

        return maxi;

    }
};