#include<iostream>
#include<stdlib.h>

using namespace std;

struct tree{
	int item;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
}*t;

int search_tree(tree *l,int x)
{
	if(l==NULL)
		return -1;

	if(l->item==x)
		return l->item;
	if(x < l->item)
		search_tree(l->left,x);
	else	
		search_tree(l->right,x);
}

void tree_preorder(tree *l)
{
	if(l!=NULL)
	{	
	cout<<l->item<<"  ->  ";
		tree_preorder(l->left);
		tree_preorder(l->right);
		
	}
}

void tree_postorder(tree *l)
{
	if(l!=NULL)
	{		
		tree_postorder(l->left);
		tree_postorder(l->right);
		cout<<l->item<<"  ->  ";
	}
}

void tree_inorder(tree *l)
{
	if(l!=NULL)
	{
		tree_inorder(l->left);
		cout<<l->item<<"  ->  ";
		tree_inorder(l->right);
	}
}

void insert_node(tree **l,int x,tree *parent)
{
	tree *p;
	if(*l == NULL)
	{
		p=new(tree);
		p->item=x;
		p->left=NULL;
		p->right=NULL;
		p->parent=parent;
		*l=p;
		
		return;
	}
	if(x< (*l)->item)
		insert_node(&((*l)->left),x,*l);
	
	else
		insert_node(&((*l)->right),x,*l);
}

int main(){
	t=new(tree);
	t=NULL;
	insert_node(&t,20,NULL);
	insert_node(&t,10,NULL);
	insert_node(&t,30,NULL);
	cout<<"inorder\n";
	tree_inorder(t);cout<<"NULL\n";
	cout<<"preorder\n";
	tree_preorder(t);cout<<"NULL\n";
	cout<<"postorder\n";
	tree_postorder(t);cout<<"NULL\n";

	return 0;
}
