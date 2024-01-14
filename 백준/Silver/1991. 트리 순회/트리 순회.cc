#include <cstdio>

struct Node {
  char data;
  Node *left, *right;

  Node(char ch, char l, char r) : data(ch) {
    if (l == '.') {
      left = nullptr;
    } else {
      left = new Node(l, '.', '.');
    }

    if (r == '.') {
      right = nullptr;
    } else {
      right = new Node(r, '.', '.');
    }
  }
};

Node *root = nullptr;

Node * find(char ch, Node *node = root) {  
  if (node == nullptr || node->data == ch) {
    return node;
  }

  Node *tmp = find(ch, node->left);
  if (tmp != nullptr) {
    return tmp;
  }

  tmp = find(ch, node->right);
  if (tmp != nullptr) {
    return tmp;
  }

  return nullptr;
}

void preorder(Node *node = root) {
  if (node == nullptr || node->data == '.') {
    return;
  }

  printf("%c", node->data);
  preorder(node->left);
  preorder(node->right);
}

void inorder(Node *node = root) { 
  if (node == nullptr || node->data == '.') {
    return;
  }
    
  inorder(node->left);
  printf("%c", node->data);
  inorder(node->right);
}

void postorder(Node *node = root) {
  if (node == nullptr || node->data == '.') {
    return;
  }

  postorder(node->left);
  postorder(node->right);
  printf("%c", node->data);
}

int main() {
  int N;
  scanf(" %d", &N);

  while (N--) {
    char ch, left, right;
    scanf(" %c %c %c", &ch, &left, &right);

    if (root == nullptr) {
      root = new Node(ch, left, right);
      continue;
    }

    Node *node = find(ch);
    node->left = new Node(left, '.', '.');
    node->right = new Node(right, '.', '.');
  }

  preorder();
  printf("\n");
  inorder();
  printf("\n");
  postorder();

  return 0;
}