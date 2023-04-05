#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<char, string> table;
class Tree
{
public:
    pair<int, char> p;
    Tree *left;
    Tree *right;

    Tree()
    {
        p = {};
        left = NULL;
        right = NULL;
    }
};

Tree *createTreeNode(pair<int, char> p)
{
    Tree *treeNode = new Tree();
    treeNode->p = p;

    return treeNode;
}

class Compare
{
public:
    // operator overloading
    bool operator()(Tree *t1, Tree *t2)
    {
        if (t1->p.first != t2->p.first)
        {
            return t1->p.first > t2->p.first;
        }

        return t1->p.second > t2->p.second;
    }
};

void prefix_table_inorder(Tree *tree, string str)
{
    if (tree == NULL)
        return;

    prefix_table_inorder(tree->left, str + '0');

    if (tree->left == NULL && tree->right == NULL)
    {

        table[tree->p.second] = str;
    }

    prefix_table_inorder(tree->right, str + '1');
}

void huffman_encoding(string &data)
{

    unordered_map<char, int> freq{};
    int n = data.size();
    for (int i = 0; i < n; i++)
    {
        freq[data[i]]++;
    }

    priority_queue<Tree *, vector<Tree *>, Compare> pq;

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        pair<int, char> pr = {it->second, it->first};
        Tree *tree = createTreeNode(pr);
        pq.push(tree);
    }

    while (pq.size() > 1)
    {
        Tree *t1 = pq.top();
        pq.pop();
        Tree *t2 = pq.top();
        pq.pop();

        int new_freq = t1->p.first + t2->p.first;
        Tree *t = createTreeNode({new_freq, '\0'});
        t->left = t1;
        t->right = t2;
        pq.push(t);
    }

    Tree *root = pq.top();
    prefix_table_inorder(root, "");
    return;
}

int main()
{
    cout << "\n\n----------Huffman Encoding----------\n\n";

    cout << "Enter the data to be transferred: ";

    string data;

    cin >> data;

    huffman_encoding(data);

    cout << "\n\nPrefix Code Rule is as follow: \n";

    for (auto prefix_code : table)
    {
        cout << prefix_code.first << " ----> " << prefix_code.second << endl;
    }

    cout << "\n\n-----Number of bits to be transferred-----\n\n";

    int initial_bits = 0, character_bits = 0;
    for (auto it : table)
    {
        initial_bits += 4 + it.second.size();
    }

    for (auto ch : data)
    {
        character_bits += table[ch].size();
    }

    cout << "\nInitially(with prefix table): " << initial_bits + character_bits << endl; // along with prefix table(initial_bits)

    cout << "\nAfter first transfer(without prefix table): " << character_bits << endl<<endl;

    return 0;
}