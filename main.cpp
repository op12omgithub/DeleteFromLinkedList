#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};
struct node* createNewNode(int value)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = value;
    tmp->next=NULL;
    return tmp;
}

struct node*  addNode(struct node* root,int value)
{
    if(root==NULL){
        root=createNewNode(value);
        return root;
    }
    while(root->next!=NULL)
    {
        root=root->next;
    }
    root->next = createNewNode(value);
    return root;

}

void printList(struct node* root)
{
    while(root!=NULL){
        cout<<root->data<<'\t';
        root=root->next;
    }
    cout<<endl;
}

void /*struct node* */ deleteFromList(struct node* root,int value)
{
    struct node* tmp,*tmp1;
    tmp1 = root;
    while(tmp1->next->data !=value){
        tmp1 = tmp1->next;
    }
    tmp = tmp1->next;
    tmp1->next = tmp->next;
    free(tmp);
    tmp = NULL;
    //return root;
}
int main()
{

    cout<<"welcome delete linked list"<<endl;
    struct node* root=NULL;
    root = addNode(root,10);
    addNode(root,20);
    addNode(root,30);
    addNode(root,40);
    addNode(root,50);
    addNode(root,60);
    addNode(root,70);
    addNode(root,80);
    printList(root);
    deleteFromList(root,40);
    deleteFromList(root,50);
    deleteFromList(root,70);
    printList(root);

    while(root->next!=NULL){
        struct node* tmp;
        tmp =root;
        root = root->next;
        free(tmp);
        tmp=NULL;
    }
    return 0;//a.exec();
}
