#include<iostream>
using namespace std;

struct Node{
	int roll_no;
	struct Node* next;
	Node(int x){
		roll_no=x;
	}
};
class LinkedList{
		public:
				

			Node* create(Node* head){
				
				int x;
				cout<<"Enter the roll_no:";
				cin>>x;
				cout<<"\n";
				struct Node* newnode=new Node(x);
			
				if (head==NULL){
					head=newnode;
				}
				else{
					struct Node* temp=head;
					while(temp->next!=nullptr){
						temp=temp->next;
					}
					temp->next=newnode;
				}
				return head;
			}

			Node* addnode(int x,Node* head){
				
				struct Node* newnode=new Node(x);
				if(head==NULL){
					head=newnode;
				}
				else{
					struct Node* temp=head;
					while(temp->next!=nullptr){
						temp=temp->next;
					}
					temp->next=newnode;
				}
				return head;


			}
		
			Node* intersect(Node* head1,Node* head2){
				Node* temp1=head1;
				Node* temp2=nullptr;
				Node* head=nullptr;

				while(temp1!=nullptr){
					if(isPres(temp1->roll_no,head2)){
						head=addnode(temp1->roll_no,head);

					}
					
					temp1=temp1->next;
				}
				return head;

			}


			Node* unionn(Node* head1,Node*head2){
				Node* temp1=head1;
				Node* temp2=head2;
				Node* head=nullptr;

				while(temp1!=nullptr){
					head=addnode(temp1->roll_no,head);
					temp1=temp1->next;
				}
				while(temp2!=nullptr){
					if(isPres(temp2->roll_no,head));
					else{
						head=addnode(temp2->roll_no,head);
					}
					temp2=temp2->next;
				}
				return head;

			}

			bool isPres(int x,Node* head){
				Node* temp=head;
				while(temp!=nullptr){
					if(temp->roll_no==x){
						return true;
					
					}
					temp=temp->next;
				}
				return false;
			}


			Node* diff(Node* head1,Node* head2){
				Node* temp1=head1;
				Node* temp2=head2;
				Node* head=nullptr;
                                

				while(temp1!=nullptr){
					
					if(isPres(temp1->roll_no,head2));
					else{
					      head=addnode(temp1->roll_no,head);
	                    }
				        temp1=temp1->next;	
				}
				
				return head;

			}
			Node* compL(Node* head1,Node* head2,Node* head){
				Node* temp1=head1;
				Node* temp2=head2;
				Node* resultc=NULL;
				while(temp1!=nullptr){
					if(isPres(temp1->roll_no,head));
					else{
						resultc=addnode(temp1->roll_no,resultc);
					}
					temp1=temp1->next;
				}
				while(temp2!=nullptr){
					if(isPres(temp2->roll_no,head));
					else{
						resultc=addnode(temp2->roll_no,resultc);
					}
					temp1=temp2->next;
				}
				return resultc;


			}
			int count(Node* head){
				int counts=0;
				Node* temp=head;
				while(temp!=nullptr){
					counts++;
					temp=temp->next;
				}
				return counts;
			}


			void printLL(Node* head){
				Node* temp=head;
				while(temp->next!=nullptr){
					cout<<temp->roll_no<<"->";
					temp=temp->next;
				}
				cout<<temp->roll_no<<endl;
			}

};


int main(){
	LinkedList obj;
	Node* head=NULL;
	cout<<"Enter the strength of students:";
	int x;
	cin>>x;
	cout<<endl;
	for(int i=0;i<x;i++){
		head=obj.create(head);

	}
	Node* head1=NULL;
	Node* head2=NULL;
	cout<<"Enter the set vanilla elements size."<<endl;
	int A;
	cin>>A;
	for(int i=0;i<A;i++){

		head1=obj.create(head1);
	
	}
	cout<<"SET vanilla"<<endl;
	obj.printLL(head1);

	cout<<"Enter the set Butterscotch elemnets size"<<endl;
	int B;
	cin>>B;
	for(int i=0;i<B;i++){
		head2=obj.create(head2);
	}
	cout<<"SET Butterscotch"<<endl;
	obj.printLL(head2);

    //declarations
    Node* unionRes=NULL;
	Node* inter=NULL;
	Node* diff1=NULL;
	Node* diff2=NULL;
	Node* comp=NULL;
	Node* comply=NULL;
	Node* di1=NULL;
	Node* di2=NULL;
	int q;


    //menu

	cout<<"enter the choice Y/n\n";
	char ch;
	cin>>ch;
	while(ch=='y'|| ch=='Y'){
		cout<<"Enter the choice\n1. Set of students who like either vanilla or butterscotch or both\n2. Set of students who like both vanilla and butterscotch\n3. Set of students who like only vanilla not butterscotch\n4. Set of students who like only butterscotch not vanilla\n5. Number of students who like neither vanilla nor butterscotch\n";
        int  choice;
		cin>>choice;
		switch(choice){
			case 1:
			unionRes=obj.unionn(head1,head2);
			cout<<"Set of students who like either vanilla or butterscotch or both"<<endl;
			obj.printLL(unionRes);
			break;



			case 2:
			inter=obj.intersect(head1,head2);
			cout<<"Set of students who like both vanilla and butterscotch"<<endl;
			obj.printLL(inter);
			break;


			case 3:
			diff1=obj.diff(head1,head2);
			cout<<"Set of students who like only vanilla not butterscotch"<<endl;
			obj.printLL(diff1);
			break;



			case 4:
			diff2=obj.diff(head2,head1);
			cout<<"Set of students who like only butterscotch not vanilla"<<endl;
			obj.printLL(diff2);
			break;


  			case 5:
                       
	        comp=obj.unionn(head1,head2);
			comply=obj.diff(head,comp);
			obj.printLL(comply);
			 q=obj.count(comply);
			cout<<"Number of students who like neither vanilla nor butterscotch:"<<q<<endl;
			break;


			default:
			cout<<"Invalid choice\n";
			break;

		}
			cout<<"enter the choice Y/n\n";
			
			cin>>ch;

	}
		return 0;

}

	
		     


	
    

	
	





