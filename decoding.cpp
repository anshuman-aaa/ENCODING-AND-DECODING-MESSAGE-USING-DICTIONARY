#include <bits/stdc++.h>

using namespace std;

int decode(string binaryString){
	int value = 0;
	int indexCounter = 0;
	for(int i=binaryString.length()-1;i>=0;i--){

	    if(binaryString[i]=='1'){
	        value += pow(2, indexCounter);
	    }
	    indexCounter++;
	}
	return value;
}

int main(){
	string dictionary,str;
	ifstream info("output.txt");
	int length = 5000000;             // num of chars you want to read
	str.resize(length, ' ');     // reserve spaces
	char* begin = &*str.begin();
	info.read(begin, length);
	cout<<str.length()<<endl;
   	

   	ifstream indictfile; 
   	indictfile.open("dictionary.txt");
   	indictfile>>dictionary;
   	int len=0,dist,l;
   	for(int i=0;i<length;){
   		while(str[i]=='0'){
   			len++;
   			i++;
   		}
   		dist=10000-decode(str.substr(i,len))-1;
   		i+=len,len=0;
   		while(str[i]=='0'){
   			len++;
   			i++;
   		}
   		l=decode(str.substr(i,len));
   		i+=len;
   		len=0;
   		std::ofstream outfile;
		outfile.open("decoded.txt", std::ios_base::app); // append instead of overwrite
		outfile << dictionary.substr(dist,l);
		outfile.close();
   	}

}