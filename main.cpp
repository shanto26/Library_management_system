#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


using namespace std;
fstream myfile;
string s[100];

struct books
{
 //parts of a node.
    string name,authur,type, ISBN ;
    books*link;
        books(){
        link = NULL;
    }
};

class records{

    books *start,*cur,*temp; //using pointers to handle the linklist
    public:
        records(){
            start=NULL;
        }
creat_file (string n,string a,string t, string isbn)  //function to create nodes
{
    //create 1st node...
   if(start==NULL){
        start=new books;
        start->link=NULL;
        start->name=n;
        start->authur=a;
        start->type=t;
        start->ISBN=isbn;
        myfile.open("books library.txt",ios::out | ios::app);
        myfile<<"Name_:_"<<start->name<<"__,__Authur:_"<<start->authur<<"__,__Type_:_"<<start->type<<"__,__ISBN_:_"<<start->ISBN<<endl;
        myfile.close();
   }

   else   //to create new node..
   {
        cur=start;
        while(cur->link!=NULL){
            cur=cur->link;
        }
        temp=new books;
        temp->name=n;
        temp->authur=a;
        temp->type=t;
        temp->ISBN=isbn;
        temp->link=NULL;
        cur->link=temp;
        myfile.open ("books library.txt",ios::out | ios::app);
        myfile<<"Name_:_"<<start->name<<"__,__Authur:_"<<start->authur<<"__,__Type_:_"<<start->type<<"__,__ISBN_:_"<<start->ISBN<<endl;
        myfile.close();
   }

}


void print_now(){//print data of the linklist
     cur=start;
     int c;
    cout<<"Book #"<<" ---> Name\tAuthur\tType"<<endl;
     for(c=1;cur->link!=NULL;c++){
      cout<<"   "<<c<<" ---> "<<cur->name<<"\t"<<cur->authur<<"\t"<<cur->type<<endl;
      cur=cur->link;
     }
      cout<<"   "<<c<<" ---> "<<cur->name<<"\t"<<cur->authur<<"\t"<<cur->type<<endl;
}

void search(string n){
 	int i,k=0;string ss;
 	myfile.open("books library.txt",ios::in);
 	while(!myfile.eof()){
 		myfile>>s[k];
 		k++;
    }
    k--;
    myfile.close();

    for( i=0;i<k;i++){
		if(s[i].find(n)>0 && s[i].find(n)<s[i].length())
		{
			break;
		}
    }
    if(i!=k){
    char mod;
	cout<<"\nWant to modify Book Data ..?? (y/n) ";
	cin>>mod;
	if(mod=='y'|| mod=='Y')
	{
		string n,an,tp, ISBN;
		cout<<"Enter book name ";
		cin>>n;
		cout<<"Enter Authur Name ";
		cin>>an;
		cout<<"Enter Book Type :";
		cin>>tp;
		cout<<"\n\tEnter ISBN\t";
        cin>>ISBN;
        s[i]="Name_:_"+n+"__,__Authur:_"+an+"__,__Type_:_"+tp+"__,__ISBN_:_"+ISBN;

	 myfile.open("books library.txt",ios::out);
	 for(  int j=0;j<k;j++)
	 myfile<<s[j]<<endl;
	 myfile.close();
	 }
}
 else
 {
 	cout<<"\nRecord Not found "<<endl;
 }
}
void print()
{
 	//reads the data from file
 	myfile.open("books library.txt",ios::in);
 	int i=0;
 	while(!(myfile.eof()))
 	{
 		myfile>>s[i];
 		cout<<s[i]<<endl;
 		i++;
	 }
	 myfile.close();
 }
};

int main()
{
    const string adminUsername = "admin";
    const string adminPass = "admin";


     records l1;
    int nooffiles,i,p,ch,k,j;
    string n,an,t, isbn;


    cout<<"Please Choose any option to login: \n"<<endl;
    cout<<" \t 1. Admin "<<endl;
    cout<<" \t 2. Student "<<endl;

    int login;
    cout<< "\n\n Enter Option: "<<endl;
    cin>> login;
    system ("CLS");

    if(login == 1)
    {
        string uname, upass ;
        cout<< "Welcome to Admin Zone: "<<endl;
        cout<< "Enter your username: "<<endl;
        cin>> uname;
        cout<< "Enter your pass: "<<endl;
        cin>> upass;

        if(uname == adminUsername && upass == adminPass){

            cout<<"\n1-Save new Book\n";
            cout<<"2-Delete any book"<<endl;
            cout<<"3-Search and Modify"<<endl;
            cout<<"4-See All list"<<endl;

            int ch;
            cin>>ch;
            system("CLS");


            switch(ch){
                case 1:
                    cout<<"\n\t============================ADD NEW BOOK============================\n\n";
                    cout<<"Enter Book Data to insert in your library"<<endl;

                    cout<<"\nEnter Name \t";
                    //getline(cin,n);
                    cin>>n;
                    cout<<"\nEnter Authur name \t";
                    cin>>an;
                    cout<<"Enter Type \t";
                    cin>>t;
                    cout<<"Enter ISBN \t";
                    cin>>isbn;
                    l1.creat_file(n,an,t, isbn);
                    cout<<"Book "<<n<<" has been Saved in your Library "<<endl;
                        break;
                    case 2:
                    cout<<"\n\t=========================DELETE Book============================\n\n";

                        myfile.open("books library.txt",ios::in);
                        k=0;
                            int del;
                        while(myfile.good()){
                        myfile>>s[k];
                        cout<<k+1<<"-"<<s[k]<<endl;
                        k++; }

                    myfile.close();
                    cout<<"Which Book data you want to delete ..? ";
                    cin>>del;
                    s[del-1]="";

	               cout<<"\nBook record has been deleted "<<endl;
	               myfile.open("books library.txt",ios::out);
	               for(j=0;j<k;j++)
	               myfile<<s[j]<<endl;
	               myfile<<endl;
	               myfile.close();
                   break;

                    case 3:
                        cout<<"\n\t===============SEARCH AND UPDATE BOOK data=====================\n\n";
                        cout<<"Enter NAME of Book to search it from Library\t";
                        cin>>n;
                        l1.search(n);
                        break;
                    case 4:
                        cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
                        l1.print();
                        break;
                        default:
                        cout<<"\t----------Invalid----------"<<endl;
                    }//END SWTICH
                  }//END IF USER PASS OKAY

                else
                    cout<< "Invlid pass"<<endl;
   }//END LOGIN 1


    else if(login == 2){

        system("CLS");
        cout<< "Welcome to student zone"<<endl;
        cout<< "\t\t 1. Show All Books"<<endl;
        cout<< "\t\t 2. Search Book in Google"<<endl;
        int ch;
        cin>>ch;
        system("CLS");




        switch(ch){
            case 1:
                cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
                l1.print();break;
            case 2:
                cout<<"\n\t=====================SEARCH BOOK ONLINE============================\n\n";
                system("cmd/c start https://books.google.com/");
                break;

                default:
                cout<<"\t----------Invalid----------"<<endl;
        }//end switch
    }//end login2

    else {

        cout<< "Invalid Option";
    }



}
