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
	string dictionary,str,decoded_str;
   time_t start, end;
   time(&start);
	// ifstream info("output.txt");
	// int length = 5000000;             // num of chars you want to read
	// str.resize(length, ' ');     // reserve spaces
	// char* begin = &*str.begin();
	// info.read(begin, length);
	// cout<<str.length()<<endl;

      ifstream outfile;
      outfile.open("output.txt");
      outfile>>str;
   	

   	ifstream indictfile; 
   	indictfile.open("dictionary.txt");
   	indictfile>>dictionary;

   	int len=0,dist,l;
   	for(int i=0;i<str.length();){
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
   		decoded_str+=dictionary.substr(dist,l);
   	}
      std::ofstream outputfile;
      outputfile.open("decoded.txt", std::ios_base::app); // append instead of overwrite
      outputfile << decoded_str;
      outputfile.close();
      time(&end);
      double time_taken = double(end - start); 
       cout << "Time taken by program to decode is : " << fixed 
            << time_taken << setprecision(5); 
       cout << " sec " << endl; 
}