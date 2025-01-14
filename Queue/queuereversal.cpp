//METHOD 1:USE OF STACK 

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
      stack<int> s;
      while(!q.empty()){
          int element=q.front();
          q.pop();//queue se ek ek karke element nikalke 
          s.push(element);//stack mai daalte raho 
          
      }
      
      //fir vapis se stack se nikalke queue mai daaldo tooh reversed queue aa jayega 
      
      while(!s.empty()){
          int element=s.top();
          s.pop();
          q.push(element);
      }
      
      return q;
    }
};


//METHOD 2:RECURSION
class Solution
{
    public:
    
    void solve(queue<int> &q){
            if(q.empty()){
            return ;
        }
        int element = q.front();
        q.pop();
        solve(q);
        q.push(element);
    }
    queue<int> rev(queue<int> q)
    {
        solve(q);
         return q;
    }
};