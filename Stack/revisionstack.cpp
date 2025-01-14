if(stack.empty()){
    return;

}

int num=stack.top();
stack.pop();
//recursive call
sortstack(stack);

sortedinsert(stack,num);