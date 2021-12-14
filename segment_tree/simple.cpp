#include <bits/stdc++.h>

using namespace std;


constexpr int n = 10;
vector<int> tree(31);   // 1 + 2 + 4 + 8 + 16

void update(int pos, int val, int tree_pos, int l, int r) {
    if(l == r) {
        tree[tree_pos] = val;
        return;
    }

    int m = (l + r) >> 1;
    if(pos <= m)
        update(pos, val, tree_pos << 1, l, m);
    else
        update(pos, val, (tree_pos << 1) + 1, m + 1, r);

    tree[tree_pos] = max(tree[tree_pos << 1], tree[(tree_pos << 1) + 1]);
}

int query(int l, int r, int tree_pos, int L, int R) {
    if(l == L && r == R)
        return tree[tree_pos];

    int m = (L + R) >> 1;
    if(r <= m)
        return query(l, r, tree_pos << 1, L, m);
    else if(l > m)
        return query(l, r, (tree_pos << 1) + 1, m + 1, R);

    return max(query(l, m, tree_pos << 1, L, m), query(m + 1, r, (tree_pos << 1) + 1, m + 1, R));
}

int main() {

    for(int i = 0; i < n; ++i)
        update(i, i+1, 1, 0, n-1);     // 1 ~ n

    cout << query(2, 6, 1, 1, n-1) << endl;
    
    return 0;
}
