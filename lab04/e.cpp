#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void addEdge(map<int, Node*>& nodes, int parent, int child, int isRight) {
    if (nodes.find(parent) == nodes.end()) {
        nodes[parent] = new Node(parent);
    }
    if (nodes.find(child) == nodes.end()) {
        nodes[child] = new Node(child);
    }
    if (isRight) {
        nodes[parent]->right = nodes[child];
    } else {
        nodes[parent]->left = nodes[child];
    }
}

int getMaxWidth(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        for (int i = 0; i < count; ++i) {
            Node* node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    map<int, Node*> nodes;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(nodes, x, y, z);
    }

    Node* root = nodes[1];
    cout << getMaxWidth(root) << endl;

    return 0;
}
