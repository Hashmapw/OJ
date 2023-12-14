#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
int preorder[N], inorder[N];
int postorder[N], cnt;

bool build(int il, int ir, int pl, int pr, int type)
{
    if (il > ir)
        return true;

    int root = preorder[pl];
    int k;
    if (!type)
    {
        for (k = il; k <= ir; k++)
        {
            if (inorder[k] == root)
                break;
        }
        if (k > ir)
            return false;
    }
    else
    {
        for (k = ir; k >= il; k--)
        {
            if (inorder[k] == root)
                break;
        }
        if (k < il)
            return false;
    }
    bool res = true;
    if (!build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), type))  // 左子树重建成功
        res = false;
    if (!build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, type))  // 右子树重建成功
        res = false;

    postorder[cnt++] = root;
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
        inorder[i] = preorder[i];
    }
    sort(inorder, inorder + n);

    if (build(0, n - 1, 0, n - 1, 0))
    {
        puts("YES");
        cout << postorder[0];
        for (int i = 1; i < n; i++)
            cout << " " << postorder[i];
        cout << endl;
    }
    else
    {
        reverse(inorder, inorder + n);
        cnt = 0;
        if (build(0, n - 1, 0, n - 1, 1))
        {
            puts("YES");
            cout << postorder[0];
            for (int i = 1; i < n; i++)
                cout << " " << postorder[i];
            cout << endl;
        }
        else
            puts("NO");
    }
}