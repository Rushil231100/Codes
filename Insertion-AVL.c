/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int height(node* root);
int max(int,int);
node * leftrotation( node * x){
    node *y=x->right;
    //node *t1=x->left;
    node *t2=y->left;
    //node *t3=x->right;
     
    y->left=x;
    x->right=t2;
    x->ht=1+max(height(x->left),height(x->right));
    y->ht=1+max(height(y->left),height(y->right));
    return y;
}
node * rightrotation( node * y){
    node *x=y->left;
    //node *t1=y->left;
    node *t2=x->right;
    //node *t3=x->right;
     
    x->right=y;
    y->left=t2;
    y->ht=1+max(height(y->left),height(y->right));
    x->ht=1+max(height(x->left),height(x->right));
    
    return x;
}
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int height(node* root){
    if(root==NULL)
        return -1;
    return root->ht;
}
node * insert(node * root,int val)
{   if(root==NULL){
        node* n=new node();
        n->val=val;
        n->left=n->right=NULL;
        n->ht=0;
        return n;
    }
    if(root->val>val){
        root->left=insert(root->left,val);
    }
    else if(root->val<val){
        root->right=insert(root->right,val);
    }
    else 
        return (root);
    
 root->ht=1+max(height(root->left),height(root->right));
 int bal=0;   
 if(root!=NULL){
        bal=height(root->left)-height(root->right);
    }
    
    //left-left case
    
    if(bal>1 && root->left->val > val){
         return rightrotation(root);   
    }
    //left-right case
    if(bal>1 && root->left->val < val){
            root->left=leftrotation(root->left);
            return rightrotation(root);
    }
    //right right case
    if(bal< -1 && root->right->val < val){
            return leftrotation(root);
    }
    //right left case
    if(bal< -1 && root->right->val > val){
            root->right=rightrotation(root->right);
            return leftrotation(root);
    }
    return root;
}
