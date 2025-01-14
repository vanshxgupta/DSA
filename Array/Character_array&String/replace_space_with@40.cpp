//You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	string temp="";//empty string for now;

	int n=str.length();
	for(int i=0;i<n;i++){
		if(str[i]==' '){
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');

			
		}
		else{
			temp.push_back(str[i]);

		}
	}
	return temp;
}