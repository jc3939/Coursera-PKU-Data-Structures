#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string* dealString(string s, int len);

string addition(string s1, string s2);

string to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

string formatNum(string s, int len){
	while (len > s.size()){
		s = "0"+s;
	}
	return s;
}

string intMultiple(string s1, string s2){
	//cout<<s1<<" "<<s2<<endl;
	int length = max(s1.size(), s2.size());
	s1 = formatNum(s1, length);
	s2 = formatNum(s2, length);
	if(s1.size()<=2 && s2.size()<=2){
		int terminalRecur = atoi(s1.c_str())*atoi(s2.c_str());
		return to_string(terminalRecur);
	}
	int sizeA = length/2;
	int sizeB = length - sizeA;
	int maxSize = max(sizeB, sizeA);
	//Split each string into A, B, C, D
	string A = s1.substr(0, sizeA);
	string B = s1.substr(sizeA, sizeB);
	string C = s2.substr(0, sizeA);
	string D = s2.substr(sizeA, sizeB);

	//Get B*D, then its high position bd
	//Get B*C + A*D + bd, then its higher position abcd
	//Get A*C + abcd, then we get ac AC
	//Result should be ac AC' ABCD' BD'
	string BD = intMultiple(B, D);
	string BC = intMultiple(B, C);
	string AD = intMultiple(A, D);
	string AC = intMultiple(A, C);
	//return the fixed length part and higher position numbers.
	string *sBD = dealString(BD, sizeB);

	string BCAD = addition(BC, AD);

	if(sBD[1]!="0"){
		BCAD = addition(BCAD, sBD[1]);
	}

	//get higher positions of BCAD
	string *sBCAD = dealString(BCAD, maxSize);

	//AC plus higher position of BCAD
	AC = addition(AC, sBCAD[1]);

	//final result
	string str = AC+sBCAD[0]+sBD[0];
	return str;
}

//Get higher positions
string* dealString(string s, int len){
	string* str = new string[2];
	if(len<s.size()){
		int t = s.size() - len;
		str[0] = s.substr(t);
		str[1] = s.substr(0, t);
	}
	else{
		str[0] = formatNum(s, len);
		str[1] = "0";
	}
	return str;
}

string addition(string s1, string s2){
	string str = "";
	int maxSize = max(s1.size(), s2.size());
	s1 = formatNum(s1, maxSize);
	s2 = formatNum(s2, maxSize);

	int flag = 0;

	for(int i = maxSize-1; i>=0; i--){
		int s1i = s1[i]-'0';
		int s2i = s2[i] - '0';
		int add = s1i + s2i + flag;
		if (add>9){
			flag = 1;
			add = add - 10;
		}
		else{
			flag = 0;
		}
		//combine them
		str = "" + to_string(add) + str;
	}
	if(flag!=0){
		str = ""+to_string(flag)+str;
	}
	return str;
}

int main(){
	string first, last;

	getline(cin, first);
	getline(cin, last);

	string result = intMultiple(first, last);

	int flag = 0;
	int i = 0;
	while(flag == 0){
		if(result[i] != '0'){
			flag = 1;
		}
		i++;
	}

	result = result.substr(i-1,result.size()-i+1);

	cout<<result<<endl;

	return 0;
}