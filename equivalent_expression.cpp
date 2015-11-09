#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;


int calculateRPN(string s, map<char, int> grade_list){
    stack<int> stack1;
    int i = 0;
    while(s[i]!='\0'){
        if(isalpha(s[i])){
            stack1.push(grade_list[s[i]]);
        }else if(isdigit(s[i])){
            int ia = s[i] - '0';
            stack1.push(ia);
        }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            int num1, num2;
            num1 = stack1.top();
            stack1.pop();
            num2 = stack1.top();
            stack1.pop();
            if(s[i]=='+'){
                //cout<<"Now doing "<<num2<<" + "<<num1<<endl;
                stack1.push(num1+num2);
            } else if(s[i]=='-'){
                //cout<<"Now doing "<<num2<<" - "<<num1<<endl;
                stack1.push(num2-num1);
            } else if(s[i]=='*'){
                //cout<<"Now doing "<<num2<<" * "<<num1<<endl;
                stack1.push(num1*num2);
            } else if(s[i]=='/'){
                //cout<<"Now doing "<<num2<<" / "<<num1<<endl;
                stack1.push(num2/num1);
            }
        }
        i++;
    }
    return stack1.top();
}

string processExp(string str1){
    int j = 0;
    string newStr1 = "";
    stack<char> stack1;
    while(str1[j]!='\0'){
        //cout<<str1[j]<<endl;
        if(str1[j]==' '||str1[j]=='\t'){

            j++;
            continue;

        }

        if(isalnum(str1[j])){

            newStr1 = newStr1+str1[j];

        } else if(str1[j] == '+'||str1[j] == '-'){
            //cout<<str1[j]<<endl;
            //cout<<stack1.empty()<<endl;
            while(!stack1.empty() && (stack1.top()=='*' || stack1.top()=='/' ||stack1.top()=='+' || stack1.top()=='-')){
                newStr1 = newStr1+stack1.top();
                stack1.pop();
            }
            stack1.push(str1[j]);
        } else if(str1[j]=='*' ||str1[j] == '/'){
            while(!stack1.empty() && (stack1.top()=='*' || stack1.top()=='/')){
                newStr1 = newStr1+stack1.top();
                stack1.pop();
            }
            stack1.push(str1[j]);
        } else if(str1[j]=='('){
            stack1.push('(');

        } else if(str1[j]==')'){
            while(!stack1.empty() && stack1.top()!='('){
                newStr1 = newStr1+stack1.top();
                stack1.pop();
            }
            if(stack1.top()=='('){
                stack1.pop();
            }
        }
        j++;
    }

    while(!stack1.empty()){
        newStr1 = newStr1+stack1.top();
        stack1.pop();
    }

    return newStr1;
}

int main(){
    int n;
    cin >> n;
    cin.ignore(10000, '\n');

    for(int i=0; i<n;i++){
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        string s1 = processExp(str1);
        string s2 = processExp(str2);
        map <char, int> grade_list;

        grade_list['a'] = rand()%10+1;
        grade_list['b'] = rand()%10+1;
        grade_list['c'] = rand()%10+1;
        grade_list['d'] = rand()%10+1;
        grade_list['e'] = rand()%10+1;

        int j=0;
        for(j=0;j<3;j++){
            //cout<<s1<<endl;
            //cout<<s2<<endl;
            int n1 = calculateRPN(s1, grade_list);
            int n2 = calculateRPN(s2, grade_list);
            /*
            cout<<grade_list['a']<<endl;
            cout<<grade_list['b']<<endl;
            cout<<grade_list['c']<<endl;
            cout<<grade_list['d']<<endl;
            cout<<grade_list['e']<<endl;*/

            //cout << n1 <<" "<<n2<<endl;
            if(n1!=n2){
                break;
            }
            grade_list['a'] = rand()%10+1;
            grade_list['b'] = rand()%10+1;
            grade_list['c'] = rand()%10+1;
            grade_list['d'] = rand()%10+1;
            grade_list['e'] = rand()%10+1;
        }

        if(j==3){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}