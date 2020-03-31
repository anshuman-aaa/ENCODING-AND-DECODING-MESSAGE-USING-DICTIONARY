#include <bits/stdc++.h>
// #include <fstream>
// #include <time.h>

using namespace std;
#define MAX 8

string encodeMatchedMessage(int length,int distance){
	string res,dist,len;
	while(distance!=0){
		res+='0';
		dist+=to_string(distance%2);
		distance/=2;
	}
	reverse(dist.begin(),dist.end());
	res+=dist;
	while(length!=0){
		res+='0';
		len+=to_string(length%2);
		length/=2;
	}
	reverse(len.begin(),len.end());
	res+=len;
	return res;
}

int main(){
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h' };
	string dictionary,message;
	int len_dictionary = 10000;
	int len_message = 1000000;
	string encoded;
	time_t start, end;
	time(&start);
	//generating dictionary
	// for (int i = 0; i < len_dictionary; i++)
	// {  
	//     dictionary += alphabet[rand() % MAX];   
	// }

	// //generating message
	// for (int i = 0; i < len_message; i++)
	// {  
	//     message += alphabet[rand() % MAX];   
	// }


	//reading from the txt file
	//reding dictionary
	ifstream indictfile; 
   	indictfile.open("dictionary.txt");
   	indictfile>>dictionary;

   	//reading from message
	ifstream inmessfile; 
   	inmessfile.open("message.txt");
   	inmessfile>>message;

	// saving output to files
	// ofstream myfile;
	// myfile.open ("dictionary.txt");
	// myfile <<dictionary<< "\n";
	// myfile.close();
	// myfile.open ("message.txt");
	// myfile <<message<< "\n";
	// myfile.close();
	//matching the patterns
	int distance=0;
	string match_message;
	char match_char;
	int message_iterator=0;
	int last_index = len_dictionary;
	int message_len = len_message;
	int startIndex=0;
	while(message_len>=1)
	{
		char match=message[startIndex];
		int k=last_index-1;
		while(k>=1){
			for(k=last_index-1;k>=0;k--){
				if(match == dictionary[k]){
					last_index=k;
					break;
				}
			}
			int j = last_index;
			string curr;
			message_iterator=0;
			while(1){
				match_char = message[startIndex+message_iterator++];
				if(match_char!=dictionary[j++])
				{
					message_iterator=0;
					break;
				}
				else 
				{
					curr+=match_char;
				}
			}

			//distance of matched sequence calculation
			distance=(curr.length()>match_message.length()) 
			 ? (len_dictionary-1-last_index) 
			 : distance;
	
			//updating the matched_sequence
			match_message= (curr.length()>match_message.length())
			 ? curr
			 : match_message;	
		}

		last_index= len_dictionary;
		message_len=message_len-match_message.length();
		startIndex += match_message.length();
		encoded+=encodeMatchedMessage(match_message.length(),distance);
		// std::ofstream outfile;
		// // outfile.open("output.txt", std::ios_base::app); // append instead of overwrite
		// // outfile << match_message <<" "<<encoded<<endl;
		// outfile.close();

		//making match_message null
		match_message="";
	}
	std::ofstream outfile;
	outfile.open("output.txt");
	outfile<<encoded<<endl;
	outfile.close();
	time(&end);
	double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
}