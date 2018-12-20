#include <stdio.h>

struct TREE{
       int key;
       TREE *parent;
       char color;
       TREE *left;
       TREE *right;
};

typedef struct TREE tree;
	tree *root = NULL;
	tree *q = NULL;         
	void RB_Insert();
	void RB_Insert_Fixup(tree *);
	void Left_rotate(tree *);
	void Right_rotate(tree *);
	void RB_Delete_Fixup(void);
	tree *Successor(tree *);
	void RB_Delete_Fixup(tree *);
	int RB_Minimum(void);
	int RB_Maximum(void);
	void Display(tree *);
	void Search(void);

void RB_Insert(){
	int z, i = 0;
    printf("\nEnter key of the tree to be inserted: ");
    scanf("%d", &z);
    tree *p,*q;
    tree *t = new tree;
    t->key = z;
    t->left = NULL;
    t->right = NULL;
    t->color = 'r';
    p = root;
    q = NULL;
    if(root == NULL){
    	root = t;
       t->parent = NULL;
    }
    else{
        while(p != NULL){
             q = p;
             if(p->key < t->key)
                 p = p->right;
             else
                 p = p->left;
        }
        t->parent = q;
        if(q->key < t->key)
             q->right = t;
        else
             q->left = t;
    }
    RB_Insert_Fixup(t);
}

void RB_Insert_Fixup(tree *t){
	tree *u;
    tree *g;
    if(root == t){
        t->color = 'b';
        return;
    }
	while(t->parent != NULL && t->parent->color == 'r'){
    	g = t->parent->parent;
        if(g->left == t->parent){
        	if(g->right != NULL){
            	u = g->right;
                if(u->color == 'r'){
                	t->parent->color = 'b';
                    u->color = 'b';
                    g->color = 'r';
                    t = g;
                }
            }
            else{
            	if(t->parent->right == t){
                    t = t->parent;
                    Left_rotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                Right_rotate(g);
            }
        }
		else{
			if(g->left != NULL){
				u = g->left;
				if(u->color == 'r'){
                   	t->parent->color = 'b';
                	u->color = 'b';
                    g->color = 'r';
                    t = g;
                }
            }
            else{
            	if(t->parent->left == t){
                	t = t->parent;
                    Right_rotate(t);
                }
                t->parent->color = 'b';
                g->color = 'r';
                Left_rotate(g);
            }
        }
        root->color = 'b';
    }
}

void RB_Delete(void){
    if(root == NULL){
		printf("\n Empty Tree.");
        return;
    }
    int x;
    printf("\n Enter the key of the node to be deleted: ");
    scanf("%d",&x);
    tree *p;
    p = root;
    tree *y = NULL;
    tree *q = NULL;
    int found = 0;
    while(p != NULL && found == 0){
    	if(p->key == x)
        	found = 1;
        if(found == 0){
        	if(p->key < x)
            	p = p->right;
            else
                p = p->left;
        }
    }
    if(found == 0){
		printf("\n Element Not Found.");
        return ;
    }
    else{
        printf("\n Deleted Element: %d",p->key);
        printf("\n Colour: ");
        if(p->color == 'b')
     		printf("Black\n");
    	else
     		printf("Red\n");
        if(p->parent != NULL)
        	printf("\n Parent: %d",p->parent->key);
        else
            printf("\n There is no parent of the node. ");
        if(p->right != NULL)
            printf("\n Right Child: %d",p->right->key);
        else
            printf("\n There is no right child of the node. ");
        if(p->left!=NULL)
            printf("\n Left Child: %d",p->left->key);
        else
            printf("\n There is no left child of the node. ");
        printf("\nNode Deleted.");
        if(p->left == NULL || p->right == NULL)
            y = p;
        else
            y = Successor(p);
        if(y->left != NULL)
            q = y->left;
        else{
            if(y->right != NULL)
            	q = y->right;
            else
                q = NULL;
        }
        if(q != NULL)
            q->parent = y->parent;
        if(y->parent == NULL)
            root = q;
        else{
            if(y == y->parent->left)
            	y->parent->left = q;
            else
                y->parent->right = q;
        }
        if(y != p){
            p->color = y->color;
            p->key = y->key;
        }
        if(y->color == 'b')
    		RB_Delete_Fixup(q);
    }
}

void RB_Delete_Fixup(tree *p){
	tree *s;
    while(p != root && p->color == 'b'){
    	if(p->parent->left == p){
        	s = p->parent->right;
            if(s->color == 'r'){
	        	s->color = 'b';
                p->parent->color = 'r';
                Left_rotate(p->parent);
                s = p->parent->right;
            }
            if(s->right->color == 'b' && s->left->color == 'b'){
                s->color = 'r';
                p = p->parent;
            }
            else{
                if(s->right->color == 'b'){
                	s->left->color == 'b';
                    s->color = 'r';
                    Right_rotate(s);
                    s = p->parent->right;
                }
                s->color = p->parent->color;
                p->parent->color = 'b';
                s->right->color = 'b';
                Left_rotate(p->parent);
                p = root;
            }
        }
        else{
            s = p->parent->left;
            if(s->color == 'r'){
                s->color = 'b';
                p->parent->color = 'r';
                Right_rotate(p->parent);
                s = p->parent->left;
            }
            if(s->left->color == 'b' && s->right->color == 'b'){
                s->color = 'r';
                p = p->parent;
            }
            else{
                if(s->left->color == 'b'){
                    s->right->color = 'b';
                    s->color = 'r';
                    Left_rotate(s);
                    s = p->parent->left;
                }
            	s->color = p->parent->color;
                p->parent->color = 'b';
                s->left->color = 'b';
                Right_rotate(p->parent);
                p = root;
            }
        }
    	p->color = 'b';
    	root->color = 'b';
    }
}

void Left_rotate(tree *p){
    if(p->right == NULL)
    	return;
    else{
        tree *y = p->right;
        if(y->left != NULL){
        	p->right = y->left;
            y->left->parent = p;
        }
        else
            p->right = NULL;
        if(p->parent != NULL)
        	y->parent = p->parent;
        if(p->parent == NULL)
            root = y;
        else{
            if(p == p->parent->left)
            	p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->left = p;
        p->parent = y;
    }
}

void Right_rotate(tree *p){
	if(p->left == NULL)
   		return;
    else{
        tree *y = p->left;
        if(y->right != NULL){
        	p->left = y->right;
            y->right->parent = p;
        }
        else
        	p->left = NULL;
        if(p->parent != NULL)
            y->parent = p->parent;
        if(p->parent == NULL)
            root = y;
        else{
            if(p == p->parent->left)
            	p->parent->left = y;
            else
                p->parent->right = y;
        }
        y->right = p;
        p->parent = y;
    }
}

tree* Successor(tree *p){
	tree *y = NULL;
    if(p->left != NULL){
    	y = p->left;
        while(y->right != NULL)
        	y = y->right;
    }
    else{
        y = p->right;
        while(y->left != NULL)
        	y = y->left;
    }
    return y;
}

tree* Predecessor(tree *p){
	tree *y = NULL;
    if(p->right != NULL){
    	y = p->right;
        while(y->left != NULL)
        	y = y->left;
    }
    else{
        y = p->left;
        while(y->right != NULL)
        	y = y->right;
    }
    return y;
}

int RB_Minimum(void){
	tree *x = root;
	while(x != 0 && x->left != 0)
		x = x->left;
	return x->key;
}

int RB_Maximum(void){
	tree *x = root;
	while(x != 0 && x->right != 0)
		x = x->right;
	return x->key;
}

void Disp(){
     Display(root);
}

void Display(tree *p){
	if(root == NULL){
    	printf("\n Empty Tree.");
        return;
    }
    if(p!=NULL){
        printf("\n\t NODE: ");
        printf("\n Key: %d", p->key);
        printf("\n Colour: ");
    	if(p->color == 'b')
    		printf("Black");
    	else
    		printf("Red");
    	if(p->parent != NULL)
    	    printf("\n Parent: %d",p->parent->key);
    	else
    		printf("\n There is no parent of the node. ");
    	if(p->right != NULL)
        	printf("\n Right Child: %d",p->right->key);
   		else
        	printf("\n There is no right child of the node. ");
    	if(p->left != NULL)
        	printf("\n Left Child: %d", p->left->key);
    	else
        	printf("\n There is no left child of the node. \n");
    	if(p->left){
        	printf("\n\nLeft:\n");
    		Display(p->left);
    	}
		if(p->right){
    		printf("\n\nRight:\n");
    		Display(p->right);
    	}
    }
}

void Search(void){
    if(root == NULL){
    	printf("\nEmpty Tree\n" );
        return;
    }
    int x;
    printf("\n Enter key of the node to be searched: ");
    scanf("%d", &x);
    tree *p = root;
    int found = 0;
    while(p != NULL && found == 0){
    	if(p->key == x)
            found = 1;
        if(found == 0){
        	if(p->key < x)
                p = p->right;
            else
                p = p->left;
        }
    }
    if(found == 0)
    	printf("\n Element Not Found.");
    else{
        printf("\n\t FOUND NODE: ");
        printf("\n Key: %d", p->key);
        printf("\n Colour: ");
    	if(p->color == 'b')
     		printf("Black");
    	else
     		printf("Red");
        if(p->parent != NULL)
            printf("\n Parent: %d", p->parent->key);
        else
            printf("\n There is no parent of the node. ");
        if(p->right != NULL)
        	printf("\n Right Child: %d", p->right->key);
        else
            printf("\n There is no right child of the node. ");
        if(p->left != NULL)
            printf("\n Left Child: %d", p->left->key);
        else
            printf("\n There is no left child of the node. \n");
	}
}

int main(void){
    int choose, flag=0;
	while (flag != 1){
		printf("\n\t -------------- " );
    	printf("\n\t RED BLACK TREE " );
		printf("\n\t -------------- " );
    	printf("\n 1. Insert in the tree ");
        printf("\n 2. Delete a node from the tree");
        printf("\n 3. Search for an element in the tree");
        printf("\n 4. Search for a minimum element in the tree");
        printf("\n 5. Search for a maximum element in the tree");
        printf("\n 6. Display the tree ");
        printf("\n 7. Exit " );
        printf("\n -------------------- " );
		printf("\n Enter Your Choice: ");
        scanf("%d",&choose);
        switch(choose){
        	case 1 : 
				RB_Insert();
                printf("\nNode Inserted.\n");
                break;
            case 2 : 
				RB_Delete();
                break;
            case 3 : 
				Search();
                break;
            case 4:
            	printf("\n A minimum element: %d",RB_Minimum());
				break;
            case 5:
            	printf("\n A maximum element: %d",RB_Maximum());
				break;
			case 6 : 
				Disp();
                break;
            case 7 : 
				flag = 1;
                break;
            default : 
				printf("\nEnter a Valid Choice.");
        }
        printf("\n");
    }
    return 0;
}
