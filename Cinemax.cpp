#include<iostream>
using namespace std;


struct Node{
	char data;
	struct Node* next=NULL;
	struct Node* prev=NULL;
	Node(char s){
		data=s;
	}

};


class Cinemax{
	public:
		Node* arr[10]={NULL};

	void create(){

		for(int i=0;i<10;i++){
			Node* head=NULL;
			for(int j=0;j<7;j++){
				Node* newnode=new Node('E');
				if(head==NULL){
					head=newnode;
					head->next=newnode;
					head->prev=newnode;
				}
				else{
					newnode->next=head;
					newnode->prev=head->prev;
					head->prev->next=newnode;
					head->prev=newnode;
					
				}
				
			}
			arr[i]=head;			
    	}

	}


	void Book(char row,int col){
		int column=col;
		if(row>'J' || col>7 || row<'A' || col<0){
			cout<<"Invalid choice of seat"<<endl;
			
		}
		else{
			Node* head=arr[row-'A'];
			Node* temp=head;
			
			while(col-1){
				temp=temp->next;
			    col--;
			}
			if(temp->data=='E'){
				temp->data='B';
			    cout<<"Succesfully Booked::"<<row<<column<<"\n\n";
				
				
			}
			else{
				cout<<"Seat already Booked try another\n";
				
			}
			
		}
	}


	void Cancel(char row,int col){
		if(row>'J' || col>7 || row<'A' || col<0){
			cout<<"Invalid choice of seat"<<endl;
			
		}
		else{
			int column=col;
			Node* head=arr[row-'A'];
			Node* temp=head;
			while(col-1){
				temp=temp->next;
			    col--;
			}
			if(temp->data=='B'){
				temp->data='E';
	            cout<<"Succesfully Cancelled::"<<row<<column<<"\n\n";
				
			}
			else{
				cout<<"Seat not  Booked try another\n";
				
			}
			
			
		}

	}
	int display(){
		
		char row='A';		
		for(int i=0;i<10;i++){
			int col=1;
						
			Node* head=arr[i];
			Node* temp=head;
			while(temp->next!=head){
				
				cout<< row<<col<<"|"<<temp->data<<"|"<<"   ";
				temp=temp->next;
				col++;
				
		    }
			cout<<row<<col<<"|"<<temp->data<<"|"<<endl;
			cout<<"_____________________________________________________\n";
		    row++;
		}
		cout<<"______________________________________________________________\n";
		cout<<"                            SCREEN                             \n";
		cout<<"______________________________________________________________\n";
		return 0;

	}

	



};

int main(){
	Cinemax obj;
	obj.create();
	char ch;
	cout<<"Enter the choice to perform operations Y/n\n";
	cin>>ch;
	while(ch=='y' || ch=='Y'){
		cout<<"Enter the choice\n1.Display the Seats\n2.Book Seat\n3.Cancel Seat\n";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:obj.display();
			break;
			case 2:
			char a;
			int b;
			cout<<"Enter row(A-J) and column(1-7)\n";
			cin>>a;
			cin>>b;
			obj.Book(a,b);
			break;
			case 3:
			char x;
			int y;
			cout<<"Enter row(A-J) and column(1-7)\n";
			cin>>x;
			cin>>y;
			obj.Cancel(x,y);
			break;
			default:cout<<"Inavlid Choice\n";
		}

		cout<<"Enter the choice to perform operations Y/n\n";
		
		cin>>ch;
		
	}	
	return 0;
}

















