#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char ch, int freq)
        : ch(ch)
        , freq(freq)
        , left(nullptr)
        , right(nullptr)
    {
    }
    Node(char ch, int freq, Node* left, Node* right)
        : ch(ch)
        , freq(freq)
        , left(left)
        , right(right)
    {
    }
};

struct compare {
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

void printCompress(Node * root, string str, unordered_map<char, string>& huffmanCode){
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    printCompress(root->left, str + "0", huffmanCode);
    printCompress(root->right, str + "1", huffmanCode);
}

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

void deleteTree(Node* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ifstream file("../sample/messages.txt");
    if (!file) {
        cout << "Error opening messages.txt\n";
        return 1;
    }
    string text;
    getline(file, text);
    file.close();
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto p : freq) {
        pq.push(new Node(p.first, p.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('$',
                                left->freq + right->freq,
                                left,
                                right);

        pq.push(parent);
    }
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);
    cout << "Character\tFrequency\tCode\n";
    cout << "-------------------------------------\n";
    for (auto p : freq) {
        cout << p.first << "\t\t"
             << p.second << "\t\t"
             << huffmanCode[p.first] << endl;
    }
    string encoded = "";
    for (char c : text) {
        encoded += huffmanCode[c];
    }
    cout << "\nOriginal Message:\n";
    cout << text << endl;
    cout << "\nEncoded Message:\n";
    cout << encoded << endl;
    deleteTree(root);
    return 0;
}