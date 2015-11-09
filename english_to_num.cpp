#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int convertStr(string str, map<string, int> engNum){
    stack<string> numberStrings;
    string sCur;
    istringstream f(str);
    int result=0;
    while(f>>sCur){
        numberStrings.push(sCur);
    }
    int unit = 1;
    while(!numberStrings.empty()){
        if(numberStrings.top() == "million"||numberStrings.top() == "thousand"||numberStrings.top() == "hundred"){
            if(engNum[numberStrings.top()]>unit){
                unit = engNum[numberStrings.top()];
                numberStrings.pop();

            } else if(engNum[numberStrings.top()]<unit){
                unit = engNum[numberStrings.top()]*unit;
                numberStrings.pop();
            }
        } else if(numberStrings.top() != "negative") {
            result += engNum[numberStrings.top()]*unit;
            numberStrings.pop();
        } else{
            result = -1*result;
            numberStrings.pop();
        }
    }
    return result;
}
int main(){
    map<string, int> engNum;
    engNum["negative"] = -1;
    engNum["zero"] = 0;
    engNum["one"] = 1;
    engNum["two"] = 2;
    engNum["three"] = 3;
    engNum["four"] = 4;
    engNum["five"] = 5;
    engNum["six"] = 6;
    engNum["seven"] = 7;
    engNum["eight"] = 8;
    engNum["nine"] = 9;
    engNum["ten"] = 10;
    engNum["eleven"] = 11;
    engNum["twelve"] = 12;
    engNum["thirteen"] = 13;
    engNum["fourteen"] = 14;
    engNum["fifteen"] = 15;
    engNum["sixteen"] = 16;
    engNum["seventeen"] = 17;
    engNum["eighteen"] = 18;
    engNum["nineteen"] = 19;
    engNum["twenty"] = 20;
    engNum["thirty"] = 30;
    engNum["forty"] = 40;
    engNum["fifty"] = 50;
    engNum["sixty"] = 60;
    engNum["seventy"] = 70;
    engNum["eighty"] = 80;
    engNum["ninety"] = 90;
    engNum["hundred"] = 100;
    engNum["thousand"] = 1000;
    engNum["million"] = 1000000;

    string str;
    getline(cin, str);
    vector<int> results;
    while(!str.empty()){
        results.push_back(convertStr(str, engNum));
        getline(cin, str);
    }
    for(vector<int>::iterator it = results.begin(); it != results.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}