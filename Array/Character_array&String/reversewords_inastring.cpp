// You are given a string 'str' of length 'N'.
// Your task is to reverse the original string word by word.
// There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.


//Solution-https://www.youtube.com/watch?v=vhnRAaJybpA

string reverseString(string &str){
	string result;
	int i=0;
	int n= str.length();
	while(i<n){
		while(i<n && str[i]==' '){//jo words ke shuru ke spaces hai usko hatana , 
			i++;	
		}
		if(i>=n){
			break;

		}
		int j=i+1;//ek aur j intialise kara jo ki word ke second letter se start hoga 

		while(j<n && str[j]!=' '){//jbh bhi word end hoga loop khatam
			j++;
			

		}
		string word=str.substr(i,j-i);//kaha se kaha tak chahiye substring ;
		if(result.length()==0) result=word;
		else{
			result=word+' '+ result;

		}
		i=j+1;



	}
	return result;
	
}