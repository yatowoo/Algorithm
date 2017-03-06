// Red-Black Tree
// Brief : Practice Code for Intro. to Algorithm
// Author : YatoWoo, 2017.03.05

#ifndef YATO_RBTree_h
#define YATO_RBTree_h

class RbNode
{

public:
  RbNode(int key, char data);
  int Key() { return fKey; };
  char Data() { return fData; };
private:
  int fKey;
  char fData;

public:
  bool IsRed;
  RbNode *Parent;
  RbNode *Left;
  RbNode *Right;
};
typedef RbNode Node_t;
RbNode::RbNode(int key, char data)
    : fKey(key), fData(data),
      IsRed(false), Parent(NULL), Left(NULL), Right(NULL)
{
}

const int MAX_CAPACITY = 20;

class RBTree
{

public:
  RBTree(Node_t *node);
  virtual ~RBTree();

public:
  bool Insert(Node_t *node);
  void InsertFixup(Node_t *node);
  void Print();
  void Traverse();
  void TraverseMid(Node_t *);
  void TraverseLeft(Node_t *);
  void TraverseRight(Node_t *);
  bool Delete(int key);
  bool RotateLeft(Node_t *);
  bool RotateRight(Node_t *);

public: // Only for DEBUG
  Node_t *fRoot;
  Node_t *fNIL;
  unsigned short fPtrNow;
  Node_t *fTree[MAX_CAPACITY];
};

RBTree::RBTree(Node_t *node)
{
  fTree[0] = node;
  fRoot = node;
  fPtrNow = 1;

  fNIL = new Node_t(-1,'\0');

  fRoot->IsRed = false;
  fRoot->Parent = fNIL;
  fRoot->Left = fNIL;
  fRoot->Right = fNIL;


}

RBTree::~RBTree()
{
  delete fNIL;
  for (int i = 0; i < fPtrNow; i++)
    delete fTree[i];
}

bool RBTree::Insert(Node_t *node)
{
  if (fPtrNow >= MAX_CAPACITY)
  {
    cout << "[X] WARNNING - MAX_CAPACITY" << endl;
    return false;
  }
  fTree[fPtrNow] = node;
  fPtrNow++;
  Node_t *parent = fRoot;
  Node_t *location = parent;
  do
  {
    parent = location;
    if (node->Key() <= parent->Key())
      location = parent->Left;
    else
      location = parent->Right;
  } while (location != fNIL);

  node->Parent = parent;
  if (node->Key() <= parent->Key())
    parent->Left = node;
  else
    parent->Right = node;

  node->IsRed = true;
  node->Left = fNIL;
  node->Right = fNIL;

  InsertFixup(node);

  return true;
}

void RBTree::InsertFixup(Node_t *node)
{
  while (node->Parent->IsRed)
  {
    if (node->Parent == node->Parent->Parent->Left)
    {
      // case 1
      Node_t *ptr = node->Parent->Parent->Right;
      if (ptr->IsRed)
      {
        node->Parent->IsRed = false;
        ptr->IsRed = false;
        node = node->Parent->Parent;
        node->IsRed = true;
      }
      else
      {
        if (node == node->Parent->Right)
        {
          // case 2
          node = node->Parent;
          RotateLeft(node);
        }
        // case 3
        node->Parent->IsRed = false;
        node->Parent->Parent->IsRed = true;
        RotateRight(node->Parent->Parent);
      }
    } // node parent IS left child
    else
    {
      // case 1
      Node_t *ptr = node->Parent->Parent->Left;
      if (ptr->IsRed)
      {
        node->Parent->IsRed = false;
        ptr->IsRed = false;
        node = node->Parent->Parent;
        node->IsRed = true;
      }
      else
      {
        if (node == node->Parent->Left)
        {
          // case 2
          node = node->Parent;
          RotateRight(node);
        }
        // case 3
        node->Parent->IsRed = false;
        node->Parent->Parent->IsRed = true;
        RotateLeft(node->Parent->Parent);
      } 
    }// node parent IS right child
  }// while node->Parent->IsRed
  fRoot->IsRed = false;
}// InsertFixup

void RBTree::Print()
{
  for (int i = 0; i < fPtrNow; i++)
  {
    cout << "("
         << fTree[i]->Key() << "," << fTree[i]->Data()
         << "," << fTree[i]->IsRed
         << ") "
         << " : ";
    cout << fTree[i]->Parent->Key()
      << " , "
      << fTree[i]->Left->Key()
      << " , "
      << fTree[i]->Right->Key();
    cout << endl;
  }
}

void RBTree::Traverse()
{
  TraverseLeft(fRoot);
}

void RBTree::TraverseLeft(Node_t *node)
{
  if (node->Left != fNIL)
    TraverseLeft(node->Left);
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  if (node->Right != fNIL)
    TraverseLeft(node->Right);
}

void RBTree::TraverseRight(Node_t *node)
{
  if (node->Right != fNIL)
    TraverseRight(node->Right);
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  if (node->Left != fNIL)
    TraverseRight(node->Left);
}

void RBTree::TraverseMid(Node_t *node)
{
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  if (node->Left != fNIL)
    TraverseMid(node->Left);
  else
    cout << "NULL" << endl;
  if (node->Right != fNIL)
    TraverseMid(node->Right);
  else
    cout << "NULL" << endl;
}

bool RBTree::RotateLeft(Node_t *node)
{
// DEBUG
  cout << "[+] DEBUG - RotateLeft Begin" << endl;
  cout << "RotateNode : ";
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  cout << "Tree Now :";
  TraverseMid(fRoot);
  cout << "[-] DEBUG - END" << endl;
// DEBUG
  if (node->Right == fNIL)
    return false;
  Node_t *ptr = node->Right;
  
  node->Right = ptr->Left;
  if(ptr->Left != fNIL)
    ptr->Left->Parent = node;
  ptr->Left = node;

  ptr->Parent = node->Parent;
  if(node->Parent != fNIL){
    if(node == node->Parent->Left)
      node->Parent->Left = ptr;
    else
      node->Parent->Right = ptr;
  }
  node->Parent = ptr;
  
  if (fRoot == node)
    fRoot = ptr;
// DEBUG
  cout << "[+] DEBUG - RotateLeft Over" << endl;
  cout << "RotateNode : ";
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  cout << "Tree Now :";
  TraverseMid(fRoot);
  cout << "[-] DEBUG - END" << endl;
// DEBUG
  return true;
}

bool RBTree::RotateRight(Node_t *node)
{
// DEBUG
  cout << "[+] DEBUG - RotateRight Begin" << endl;
  cout << "RotateNode : ";
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  cout << "Tree Now :";
  TraverseMid(fRoot);
  cout << "[-] DEBUG - END" << endl;
// DEBUG
  if (node->Left == fNIL)
    return false;
  Node_t *ptr = node->Left;

  node->Left = ptr->Right;
  if(ptr->Right != fNIL)
    ptr->Right->Parent = node;
  ptr->Right = node;
  ptr->Parent = node->Parent;
  if(node->Parent != fNIL){
    if(node == node->Parent->Left)
      node->Parent->Left = ptr;
    else
      node->Parent->Right = ptr;
  }
  node->Parent = ptr;
  if (fRoot == node)
    fRoot = ptr;
// DEBUG
  cout << "[+] DEBUG - RotateRight Over" << endl;
  cout << "RotateNode : ";
  cout << "(" << node->Key() << "," << node->Data() 
    << "," << node->IsRed << ")" << endl;
  cout << "Tree Now :";
  TraverseMid(fRoot);
  cout << "[-] DEBUG - END" << endl;
// DEBUG
  return true;
}

#endif // YATO_RBTree_h
