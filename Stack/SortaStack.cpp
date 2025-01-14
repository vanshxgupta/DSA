void sortedinsert(stack<int>&stack,int num){
    //base case
    if(stack.empty() || (!stack.empty() && stack.top()<num)){//ya tooh jab stack empty ho tabh insert kardo ya fir jab
        stack.push(num);
        return;
    }

    int n=stack.top();
    stack.pop();

    //recusive call
    sortedinsert(stack,num);
    stack.push(n);
}

void sortStack(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();

    //recursive call
    sortStack(stack);

    sortedinsert(stack,num);

}