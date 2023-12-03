#include<iostream>
#include<string>
using namespace std;



class Stack{
	public:
		int top=-1;
		int size=30;
		void push(char stack[],char x){
			
			if(top==size-1){
				cout<<"Stack Overflow\n";
			}else{
				top++;
				stack[top]=x;
			}
		}


		void pop(char stack[]){
			if(top==-1){
				cout<<"Stack Underflow\n";
			}
			else{
				
				top--;
			}
		}

		bool check(string exp,char stack[]){

			for(int i=0;i<exp.length();i++){
				if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
					push(stack,exp[i]);
				}
				else{
					if(top==-1){
						return false;
					}
					else if((exp[i]==')' && stack[top]=='(') || (exp[i]=='}' && stack[top]=='{') || (exp[i]==']' && stack[top]=='[')){
						pop(stack);
					}
					else{
						return false;
					}
				}
			}
			if(top==-1){
				return true;
			}
			else{
				return false;
			}
		}
};


int main(){
	char ch;
		cout<<"Enter choice y/n \n";
		cin>>ch;

	while(ch=='y' || ch=='Y'){
		cout<<"Enter the string"<<endl;
		string s;
		cin>>s;
		char stack[30];
		Stack obj;
		bool ret=obj.check(s,stack);
		if(ret==true){
			cout<<"balanced parenthesised"<<endl;
		}
		else{
			cout<<"unbalanced parenthesis"<<endl;
		}
		cout<<"Enter choice y/n \n";
		cin>>ch;

	}




	return 0;
}
