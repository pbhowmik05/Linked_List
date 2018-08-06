#include<iostream>

using namespace std;

struct node{
    string mystring;
    int data;
    node *next;
};

class list{
private:
    node *head, *tail;
public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    void createFirstNode(string name, int value)
    {
        node *temp = new node;
        temp ->mystring = name;
        temp ->data = value;
        temp->next = head;
        head = temp;

        if(head == NULL)
            tail = temp;
    }
    void createnode(string name, int value)
    {
        node *temp =new node;
        temp ->mystring = name;
        temp ->data = value;
        temp ->next = NULL;
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            temp= NULL;
        }
        else
        {
            tail ->next = temp;
            tail = temp;
            temp= NULL;
        }
    }

    void display()
    {

        node *temp = new node;
        temp = head;
        while(temp!= NULL)
        {
            cout<<" "<<temp->mystring  <<" "   << temp-> data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
    int length()
    {
        int counter =0;
        node *temp = new node;
        temp = head;
        while(temp!= NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void createvariablenode(int position, string name, int value) {
        node *perviousPos;
        node *currentPos;
        node *temp = new node;

        temp ->mystring = name;
        temp ->data = value;
        int x = length();
        if (x > position) {
            int counter = 1;
            currentPos = head;
            while (counter< position) {
                counter++;
                perviousPos= currentPos;
                currentPos = currentPos->next;
            }
            perviousPos->next = temp;
            temp->next =currentPos;

        } else {
            cout << "out of range" << endl;
        }
    }

    void deletefirstnode()
    {
        node *temp =new node;
        temp =head;
        head = head->next;
        temp =NULL;
    }

    void deletelastnode()
    {
        node *current;
        node *previos = new node;
        current =head;
        while(current->next!=NULL) {
            previos = current;
            current = current->next;
        }
            tail = previos;
            previos->next = NULL;
            delete current;
    }

    void deleteanynode(int position){

        node *currentnode;
        node *previousnode;
        currentnode = head;

        for(int i=0; i<position;i++){
            previousnode = currentnode;
            currentnode = currentnode->next;
        }
            previousnode->next = currentnode->next;
            delete currentnode;
    }

};

int main()
{
    cout<<"start!!"<<endl;
    list mylinklist;
    mylinklist.createnode("Book", 1);
    mylinklist.createnode("Pen", 2);
    mylinklist.createnode("Pencil", 3);
    mylinklist.createnode("Campus", 4);
    mylinklist.createnode("School", 5);
    mylinklist.createnode("Library", 6);

    mylinklist.createFirstNode("College", 7);
    mylinklist.display();
    mylinklist.createvariablenode(3, "Laptop", 8);
    mylinklist.display();
    mylinklist.deletefirstnode();

    mylinklist.display();
    mylinklist.deletelastnode();
    mylinklist.display();
    mylinklist.deleteanynode(3);
    mylinklist.deleteanynode(3);
    mylinklist.display();

    cout<<"link list length  ="<<mylinklist.length()<<endl;

    cout<<"endofcode"<<endl;
    return 0;
}
	
