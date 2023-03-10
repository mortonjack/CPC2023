#include <string>
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

class SegmentTreeNode {
private:
    // Unopened/unclosed brackets
    int unopened;
    int unclosed;
    // Valid bracket combinations
    int valid;
    // Left/right bounds
    int left_bound;
    int right_bound;
    // Child nodes
    SegmentTreeNode* left;
    SegmentTreeNode* right;
public:
    SegmentTreeNode(string& s): SegmentTreeNode(s, 0, s.length()-1) {}

    SegmentTreeNode(string& s, int i, int j) {
        left_bound = i;
        right_bound = j;
        if (i == j) {
            unclosed = s[i] == '(';
            unopened = s[i] == ')';
            valid = 0;
            left = nullptr;
            right = nullptr;
        } else {
            int k = i + (j-i)/2;
            left = new SegmentTreeNode(s, i, k);
            right = new SegmentTreeNode(s, k+1, j);
            valid = min(left->get_unclosed(), right->get_unopened());
            unopened = left->get_unopened() + right->get_unopened() - valid;
            unclosed = left->get_unclosed() + right->get_unclosed() - valid;
            valid += left->get_valid() + right->get_valid();
        }
    }

    int get_valid() {
        return valid;
    }

    int get_unopened() {
        return unopened;
    }

    int get_unclosed() {
        return unclosed;
    }

    int leftbound() {
        return left_bound;
    }

    int rightbound() {
        return right_bound;
    }
    
    // Returns {unclosed, valid, unopened}
    array<int, 3> query(int l, int r) {
        // Base case
        if (l == leftbound() && r == rightbound()) {
            return {unclosed, valid, unopened};
        }
        if (l >= right->leftbound()) return right->query(l, r);
        if (r <= left->rightbound()) return left->query(l, r);
        auto left_res = left->query(l, left->rightbound());
        auto right_res = right->query(right->leftbound(), r);
        
        array<int, 3> res = {0, 0, 0};
        int newvalid = min(left_res[0], right_res[2]);
        res[0] = left_res[0] + right_res[0] - newvalid;
        res[2] = left_res[2] + right_res[2] - newvalid;
        res[1] = left_res[1] + right_res[1] + newvalid;
        return res;
    }

    ~SegmentTreeNode() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }

    /*void print() {
        if (left) left->print();
        if (right) right->print();
        cout << '(' << left_bound << ", " << right_bound << "): {" << unclosed << ", " << valid << ", " << unopened << "}\n";
    }*/
};

class Segtree {
private:
    SegmentTreeNode * root;
public:
    Segtree(string& s) {
        root = new SegmentTreeNode(s);
    }

    int query(int l, int r) {
        auto res = root->query(l-1, r-1);
        return res[1];
    }

    /*void print() {
        root->print();
    }*/

    ~Segtree() {
        delete root;
    }
};

int main() {
    string s;
    cin >> s;
    Segtree segtree(s);
    /*segtree.print();
    cout << "ans: " << '\n';*/
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << 2*segtree.query(l, r) << '\n';
    }
    return 0;
}
