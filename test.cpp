#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	string line, str;
	vector<string> strings;
	while(getline(cin, line)){
		istringstream f(line);
		while(f>>str){
			cout<<str.c_str()<<endl;
			strings.push_back(str);
		}
	}
	
	return 0;

}