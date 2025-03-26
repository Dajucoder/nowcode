/**
 * 算法工具库
 * 包含常用算法和数据结构的实现
 */

#ifndef ALGORITHM_UTILS_H
#define ALGORITHM_UTILS_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

/**
 * 快速幂算法
 * 计算 base^exponent % mod
 */
long long fast_power(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

/**
 * 最大公约数 (GCD)
 */
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

/**
 * 最小公倍数 (LCM)
 */
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

/**
 * 判断一个数是否为素数
 */
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

/**
 * 埃氏筛法求素数
 * 返回小于等于n的所有素数
 */
std::vector<int> sieve_of_eratosthenes(int n) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    std::vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

/**
 * 二分查找
 * 返回目标值在有序数组中的索引，如果不存在则返回-1
 */
int binary_search(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}

/**
 * 并查集实现
 */
class UnionFind {
private:
    std::vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

#endif // ALGORITHM_UTILS_H