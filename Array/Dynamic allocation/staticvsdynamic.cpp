/*
static collection-->memory automatically release
while(true){
    int i=5;//4 byte lega aur , chalega fir iski memory dlete ho jayegi 
}

dynamic-->memory manually release karni pdhti hai 
while(true){
    int*p=new int;//size-->8+4+4+4....
    //isme baar baar program chlne ke saath memory dlete nahi hogi aur program fat skta hai , tooh humko uski memmory manually free karni padegi

}



*/

/*Deletion of dynamic memory

int*i=new int
delete i;//for single element deletion

int *arr=new int[50];
delete []arr;//for array deletion;

*/





