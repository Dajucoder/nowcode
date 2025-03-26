/**
 * 数据结构工具库
 * 包含常用数据结构的实现
 */

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <queue>
#include <stack>

/**
 * 链表节点定义
 */
template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode* next) : val(x), next(next) {}
};

/**
 * 二叉树节点定义
 */
template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * 字典树（Trie）实现
 */
class Trie {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);
    }
    
    void clear(TrieNode* node) {
        if (!node) return;
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        
        delete node;
    }
    
    void insert(const std::string& word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        
        node->isEnd = true;
    }
    
    bool search(const std::string& word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        
        return node->isEnd;
    }
    
    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        
        return true;
    }
};

/**
 * 线段树实现
 * 用于区间查询和更新
 */
class SegmentTree {
private:
    std::vector<int> tree;
    std::vector<int> lazy;
    std::vector<int> arr;
    int n;
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            
            lazy[node] = 0;
        }
        
        if (start > end || start > r || end < l) {
            return;
        }
        
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    int queryRange(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) {
            return 0;
        }
        
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            
            lazy[node] = 0;
        }
        
        if (start >= l && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        int p1 = queryRange(2 * node, start, mid, l, r);
        int p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
        
        return p1 + p2;
    }
    
public:
    SegmentTree(const std::vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        
        build(1, 0, n - 1);
    }
    
    void update(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
    }
    
    int query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

#endif // DATA_STRUCTURES_H