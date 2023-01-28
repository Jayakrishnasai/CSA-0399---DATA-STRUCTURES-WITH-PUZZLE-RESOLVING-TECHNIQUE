#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* left;
	struct node* right;
	int height;
};
int gh(struct node* n)
{
	if(n == NULL)
	{
		return 0;
	}
	return n->height;
}
struct node* create(int key)
{
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	n->height = 1;
	return n;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
int balance(struct node* n)
{
	if(n == NULL){
		return 0;
	}
	return gh(n->left) - gh(n->right);
}
struct node* leftrotate(struct node* x)
{
	struct node* y = x->right;
	struct node* T = y->left;
	y->left = x;
	x->right = T;
	x->height = (max(gh(x->left),gh(x->right))) + 1;
	y->height = (max(gh(y->left),gh(y->right))) + 1;
	return y;
}
struct node* rightrotate(struct node* y)
{
	struct node* x = y->left;
	struct node* T = x->right;
	x->right = y;
	y->left = T;
	x->height = (max(gh(x->left),gh(x->right))) + 1;
	y->height = (max(gh(y->left),gh(y->right))) + 1;
	return x;
}
struct node* insert(struct node* n,int key)
{
	if(n == NULL)
	{
		return create(key);
	}
	if(key < n->key)
	{
		n->left = insert(n->left,key);
	}
	else if(key > n->key)
	{
		n->right = insert(n->right,key);
	}
	n->height = (max(gh(n->left),gh(n->right))) + 1;
	int bf = balance(n);
	if(bf > 1 && key < n->left->key)
	{
		return rightrotate(n);
	}
	if(bf < -1 && key > n->right->key)
	{
		return leftrotate(n);
	}
	if(bf > 1 && key > n->left->key)
	{
		n->left = leftrotate(n->left);
		return rightrotate(n);
	}
	if(bf < -1 && key < n->right->key)
	{
		n->right =  rightrotate(n->right);
		return leftrotate(n);
	}
	return n;
}
struct node* minvalue(struct node* n)
{
	struct node* current = n;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
struct node* deleten(struct node* n,int key)
{
	if(n == NULL)
	{
		return n;
	}
	if(key < n->key)
	{
		n->left = deleten(n->left,key);
	}
	else if(key > n->key)
	{
		n->right = deleten(n->right,key);
	}
	else
	{
		if(n->left == NULL || n->right == NULL)
		{
			struct node* temp = n->left ?n->left : n->right;
			if(temp ==  NULL)
			{
				temp = n;
				n = NULL;
			}
			else
			{
				*n = *temp;
				free(temp);
			}
		}
		else
		{
			struct node* temp = minvalue(n->right);
			n->key = temp->key;
			n->right = deleten(n->right,temp->key);
		}
	}
	if(n == NULL)
	{
		return n;
	}
	n->height = (max(gh(n->left),gh(n->right))) + 1;
	int bf = balance(n);
	if(bf > 1 && balance(n->left)>= 0)
	{
		return rightrotate(n);
	}
	if(bf < -1 && balance(n->right)>= 0)
	{
		return leftrotate(n);
	}
	if(bf > 1 && balance(n->left) < 0)
	{
		n->left = leftrotate(n->left);
		return rightrotate(n);
	}
	if(bf < -1 && balance(n->right) < 0)
	{
		n->right =  rightrotate(n->right);
		return leftrotate(n);
	}
	return n;
}
void preorder(struct node* root)
{
	if(root!= NULL)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	struct node* root = NULL;
	root = insert(root,7);
	root = insert(root,4);
	root = insert(root,8);
	root = insert(root,1);
	root = insert(root,19);
	root = insert(root,22);
	root = insert(root,2);
	root = insert(root,27);
	root = insert(root,67);
	root = insert(root,54);
	printf("After Insertion : \n");
	preorder(root);
	root = deleten(root,8);
	root = deleten(root,1);
	root = deleten(root,19);
	root = deleten(root,67);
	printf("\nAfter Deletion : \n");
	preorder(root);
	return 0;
}