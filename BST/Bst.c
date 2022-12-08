#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SEED 100
//-----------------------  STRUCTS ------------------------//
struct BstTreeNode{
    int key;
    struct BstTreeNode *parent;
    struct BstTreeNode *left;
    struct BstTreeNode *right;
};

typedef struct BstTreeNode BstTreeNode;

struct BstTree{
    BstTreeNode *root;
    int cardinality;
};

typedef struct BstTree BstTree;

//**********************************************************//

//-------------------- INIZIALIZZAZIONE --------------------//

void inzializzaBstTree(BstTree *K)
{
  K->root =NULL;
}
void inzializzaBstTreeNode(BstTreeNode *node)
{
  node->parent=NULL;
  node->left=NULL;
  node->right=NULL;
}

//**********************************************************//

//------------------------ FUNCTION ------------------------//

//--->  Insert new node;
void TreeinsertBst(BstTree *T, int z)
{
  BstTreeNode *newNode=(BstTreeNode *)(malloc(sizeof( BstTreeNode))); inzializzaBstTreeNode(newNode); newNode->key=z;
  BstTreeNode *y=NULL;
  BstTreeNode *x;

  x = T->root;
  while ( x )
  {
      y=x;
      if(newNode->key < x->key)
        x=x->left;
      else
        x=x->right;
  }
  newNode->parent=y;
  if ( !y )
  {
    T->root=newNode;
  }
  else
    if(newNode->key>=y->key)
      {
        y->right=newNode;
      }
    else
      {
        y->left=newNode;
      }
}
//**********************************************************

//--->  Search key;
BstTreeNode *TreesearchBst( BstTreeNode *current, int key)
{
  // Parte aggiunta da me
  if (!current)
  {
    printf("\nATTENTION --> key not found\nreturn NULL;\n");
    return NULL;
  }
  //***********************************************************
  else
    if(current->key==key)
      return current;
    else
      if (key < current->key )
        return TreesearchBst(current->left,key);
      else
        return TreesearchBst(current->right,key);
}
//**********************************************************


//--->  Orderly print;
void InOrderTreeWalk(BstTreeNode *current)
{
  if(current)
  {
    InOrderTreeWalk(current->left);
    printf("%d ",current->key);
    InOrderTreeWalk(current->right);
  }
}
//**********************************************************

//---> Minium
BstTreeNode *TreeMinimumBst(BstTreeNode *current)
  {
    // parte aggiunta da me
    if (!current)
    {
      printf("ATTENTION --> Empty Tree;\nreturn NULL;\n");
      return NULL;
    }
    //*******************************************************
    else
      if (current->left)
        TreeMinimumBst(current->left);
      else
        return current;
  }
//**********************************************************

//---> Maximum
BstTreeNode *TreeMaximumBst(BstTreeNode *current)
  {
    // parte aggiunta da me
    if (!current)
    {
      printf("\nATTENTION --> Empty tree;\nreturn NULL;\n");
      return NULL;
    }
    //*********************************************
    if (current->right)
      TreeMaximumBst(current->right);
    else
      return current;
  }
//**********************************************************

//--->  Successor;
BstTreeNode *TreeSuccessorBst(BstTreeNode *current)
{
  if (current->right)
    return TreeMinimumBst(current->right);
  else
  {
    BstTreeNode *y=current->parent;
    while( y && current== y->right)
    {
      current=y;
      y=y->parent;
    }
    // parte aggiunta da me
    if (!y)
      printf("\nATTENTION --> Successor not found;\nreturn NULL;\n");
    //***************************************************
    return y;
  }
}
//**********************************************************


//--->  Predecessor;
BstTreeNode *TreePredeccessorBst(BstTreeNode *current)
{
  if (current->left)
    return TreeMaximumBst(current->left);
  else
  {
    BstTreeNode *y=current->parent;
    while( y && current== y->left)
    {
      current=y;
      y=y->parent;
    }
    // parte aggiunta da me
    if (!y)
      printf("\nATTENTION --> Predecessor not found;\nreturn NULL;\n");
    //***************************************************
    return y;
  }
}
//**********************************************************//

//--->  Trasplant;
void Trasplant(BstTree *Tree, BstTreeNode *delete, BstTreeNode *deleteRight)
{
  if ( !delete->parent)
    Tree->root=deleteRight;
  if ( delete->parent && delete== delete->parent->left )
    delete->parent->left = deleteRight;
  if ( delete->parent && delete== delete->parent->right )
    delete->parent->right = deleteRight;
  if ( deleteRight )
    deleteRight->parent=delete->parent;

}
//**********************************************************//

//--->  Delete;
void TreeDelete(BstTree *Tree, BstTreeNode *delete)
{
  if ( !delete->left )
    Trasplant(Tree,delete,delete->right);
  if ( delete->left && !delete->right)
    Trasplant(Tree,delete,delete->left);
  if ( delete->left && delete->right)
  {
    BstTreeNode *y= TreeMinimumBst(delete->right);
    if (y->parent != delete)
    {
      Trasplant(Tree,y,y->right);
      y->right=delete->right;
      y->right->parent=y;
    }
    Trasplant(Tree,delete,y);
    y->left=delete->left;
    y->left->parent=y;
  }
}
//**********************************************************//

//--->  Free;
void TreeFree( BstTreeNode *current)
{
  if (current)  
  {
    TreeFree(current->left);
    TreeFree(current->right);
    free(current);
  }
}
//**********************************************************//


int main()
{
  srand(SEED);

  BstTree T;
  inzializzaBstTree(&T);
  for (int i=0;i<20;i++)
  {
    int z= rand()%100;
    TreeinsertBst(&T,z);
  }



  /*  prova stampa
  BstTreeNode *stampa = TreesearchBst(T.root,60);
  if(stampa)
  printf("%d",stampa);
  else
  printf("error\n");
  */

  /* prova minimo
  InOrderTreeWalk(T.root);
  BstTreeNode *minimo = TreeMinimumBst(T.root);
  if(minimo)
  printf("\n\nMinimo: %d\n\n",minimo->key);
  else
  printf("error\n");
  minimo->key=999;
  */

  /*  prova massimo
  InOrderTreeWalk(T.root);
  BstTreeNode *massimo = TreeMaximumBst(T.root);
  if(massimo)
  printf("\n\nMinimo: %d\n\n",massimo->key);
  else
  printf("error\n");
  massimo->key=999;
  */

  /*/ prova successore
  InOrderTreeWalk(T.root);
  printf("\ninserisci elemento di cui vuoi successore: ");
  int elemento;
  scanf("%d",&elemento);
  BstTreeNode *x=TreesearchBst(T.root,elemento);

  BstTreeNode *successor = TreeSuccessorBst(x);
  if(successor)
  printf("\n\nSuccessor: %d\n\n",successor->key);
  else
  printf("\nerror\n");
  successor->key=999;
  //*/

  /* prova successore
  InOrderTreeWalk(T.root);
  BstTreeNode *x=TreesearchBst(T.root,55);

  BstTreeNode *predeccessor = TreePredeccessorBst(x);
  if(predeccessor)
  printf("\n\nPredeccessor: %d\n\n",predeccessor->key);
  else
  printf("\nerror\n");
  predeccessor->key=999;
  */

  /*/  prova delete
  InOrderTreeWalk(T.root);
  printf("\ninserisci elemento da eliminare: ");
  int keyDelete;
  scanf("%d",&keyDelete);
  BstTreeNode *address= TreesearchBst(T.root,keyDelete);
  TreeDelete(&T, address );
  */


  /*  prova free
  InOrderTreeWalk(T.root);
  printf("\nFaccio Free\n");
  TreeFree(T.root);
  printf("stampa dopo free\n");
  if(T.root==NULL)
    printf("E' vuota");
  */

  InOrderTreeWalk(T.root);
return 0;
}
