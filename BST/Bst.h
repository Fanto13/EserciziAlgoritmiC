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

void inzializzaBstTree(BstTree *K);
void inzializzaBstTreeNode(BstTreeNode *node);

//**********************************************************//

//------------------------ FUNCTION ------------------------//

//--->  Insert new node;
void TreeinsertBst(BstTree *T, int z);

//--->  Search key;
BstTreeNode *TreesearchBst( BstTreeNode *current, int key);

//--->  Orderly print;
void InOrderTreeWalk(BstTreeNode *current);

//---> Minium
BstTreeNode *TreeMinimumBst(BstTreeNode *current);

//---> Maximum
BstTreeNode *TreeMaximumBst(BstTreeNode *current);

//--->  Successor;
BstTreeNode *TreeSuccessorBst(BstTreeNode *current);

//--->  Predecessor;
BstTreeNode *TreePredeccessorBst(BstTreeNode *current);

//--->  Trasplant;
void Trasplant(BstTree *Tree, BstTreeNode *delete, BstTreeNode *deleteRight);

//--->  Delete;
void TreeDelete(BstTree *Tree, BstTreeNode *delete);

//--->  Free
void TreeFree(BstTreeNode *current);