#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string str;

	cin >> n;
	cin.ignore(10000, '\n');

	for(int i = 0;i<n;i++){
		getline(cin, str);
		int j = 0;
		while(str[j]!='\0'){
			if(!isalpha(str[j])){
				j+=1;
				continue;
			}
			if(str[j] == 'Z'){
				str[j] = 'A';
			} else if (str[j] == 'z'){
				str[j] = 'a';
			} else {
				str[j] += 1;
			}
			j+=1;
		}
		cout<<str<<endl;
	}
	return 0;
}