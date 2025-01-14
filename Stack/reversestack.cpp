void insertatbottom(stack<int>&stack,int x){
    //basecase
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int num=stack.top();
    stack.pop();

    //recursive call
    insertatbottom(stack, x);
    
    stack.push(num);
}


void reverseStack(stack<int> &stack) {

        //base case
        if(stack.empty()){
            return ;
        }

        int num=stack.top();
        stack.pop();

        //recursive call
        reverseStack(stack);

        insertatbottom(stack,num);

}