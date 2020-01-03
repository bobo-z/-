#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	int height;
	TreeNode* lch;
	TreeNode* rch;
	TreeNode(int x, int y):val(x),height(y),lch(nullptr),rch(nullptr){}
};
int n;
int getH(TreeNode* p)
{
	if (p)
		return p->height;
	return -1;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
TreeNode* LL_rotation(TreeNode* root)
{
	TreeNode* temp;
	temp = root->lch;
	root->lch = temp->rch;
	temp->rch = root;

	root->height = max(getH(root->lch), getH(root->rch))+1;
	temp->height = max(getH(temp->lch), getH(temp->rch))+1;
	return temp;
}
TreeNode* RR_rotation(TreeNode* root)
{
	TreeNode* temp;
	temp = root->rch;
	root->rch = temp->lch;
	temp->lch = root;

	root->height = max(getH(root->lch), getH(root->rch))+1;
	temp->height = max(getH(temp->lch), getH(temp->rch))+1;
	return temp;
}
TreeNode* LR_rotation(TreeNode* root)
{
	root->lch = RR_rotation(root->lch);
	return LL_rotation(root);
}
TreeNode* RL_rotation(TreeNode* root)
{
	root->rch = LL_rotation(root->rch);
	return RR_rotation(root);
}
TreeNode* insert(TreeNode* root, int val)
{
	if (root == nullptr)
		root = new TreeNode(val, 0);
	else if (val < root->val)
	{
		root->lch = insert(root->lch, val);
		if (getH(root->lch) - getH(root->rch) == 2)
		{
			if (root->lch->val > val)//LL
				root = LL_rotation(root);
			else
				root = LR_rotation(root);
		}
	}
	else
	{
		root->rch = insert(root->rch, val);
		if (getH(root->lch) - getH(root->rch) == -2)
		{
			if (root->rch->val < val)
				root = RR_rotation(root);
			else
				root = RL_rotation(root);
		}
	}
	root->height = max(getH(root->lch), getH(root->rch)) + 1;
	return root;
}
void print(TreeNode* root)
{
	if (root)
		cout << root->val << " ";
	else
		return;
	print(root->lch);
	print(root->rch);
}
int main()
{
	cin >> n;
	int temp;
	TreeNode* root = nullptr;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		root = insert(root, temp);
	}
	print(root);
	return 0;
}