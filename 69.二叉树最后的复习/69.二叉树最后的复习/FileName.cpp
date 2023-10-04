#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {

	}
};

class Tree {
private:
	TreeNode* root;

	TreeNode* InsertNode(TreeNode* cur, int val) {
		//��һ�����жϵݹ麯���ķ���ֵ����

		if (root == NULL) {
			return new TreeNode(val);
		}//�ڶ�����ȷ����ֹ����

		if (val > cur->val) {
			cur->right = InsertNode(cur->right, val);
		}
		else if (val < cur->val) {
			cur->left = InsertNode(cur->left, val);
		}

		return cur;//���ϴ������ɵĽ��
	}
public:
	void Insert(int val) {
		root = InsertNode(root, val);
	}
};

class Tree {
private:
	TreeNode* root;
	void PreTraversal(TreeNode* cur, vector<int>& result) {
		//�����result�����ã���Ϊ�����ռ����ݵ�
		//�������践��ֵ

		if (cur == NULL) {//��ֹ����
			return;
		}
		result.push_back(cur->val);//��
		PreTraversal(cur->left, result);//��
		PreTraversal(cur->right, result);//��
	}
public:
	vector<int> PreOrder() {//����ӿ�
		vector<int> result;
		PreTraversal(root, result);
		return result;
	}
};

class Tree {//�ݹ鷨
private:
	TreeNode* root;
	void LevelTraversal(TreeNode* cur, vector<vector<int>>& result,int depth) {
		if (cur == NULL) {//��ֹ����
			return;
		}

		if (depth == result.size()) {//�����ȵ���result�е�������˵����ǰ��û�н��б���
			result.push_back(vector<int>());
		}

		result[depth].push_back(cur->val);//��ȷ����һ�в�������
		LevelTraversal(cur->left, result, depth + 1);
		LevelTraversal(cur->right, result, depth + 1);
		//��ݴ���û��ֱ����depth+=1�������ò���+1��ʹ�õ��˻��ݵ�˼��
	}
public:
	vector<vector<int>> LevelOrder() {
		vector<vector<int>> result;
		int depth = 0;//
		LevelTraversal(root, result,depth);
		return result;
	}
};

class Tree {//������
private:
	TreeNode* root;
public:
	vector<vector<int>> LevelOrder() {
		queue<TreeNode*> que;
		if (root) {
			que.push(root);
		}

		vector<vector<int>> result;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			while (size--) {
				TreeNode* temp = que.front();
				que.pop();
				vec.push_back(temp->val);
				if (root->left) {
					que.push(root->left);
				}
				if (root->right) {
					que.push(root->right);
				}
			}
			result.push_back(vec);
		}
		return result;
	}
};

class Tree {//������������߶�
private:
	TreeNode* root;
	int PostTraversal(TreeNode* cur) {
		if (cur == NULL) {//��ֹ����
			return 0;
		}

		int leftdepth = PostTraversal(cur->left);//��ݹ�
		int rightdepth = PostTraversal(cur->right);//��ݹ�
		int depth = max(leftdepth, rightdepth) + 1;//��ǰ�ڵ��������

		return depth;
	}
public:
	int MaxDepth() {
		return PostTraversal(root);
	}
};

class Tree {//���������������
private:
	TreeNode* root;
public:
	int MaxDepth() {
		if (root == NULL) {
			return 0;
		}

		queue<TreeNode*> que;
		que.push(root);
		int depth=0;
		while (!que.empty()) {
			int size = que.size();
			depth++;//�����������Ȼ���ƣ�ֱ�����������
			while (size--) {
				TreeNode* temp = que.front();
				que.pop();
				if (temp->left) {
					que.push(temp->left);
				}
				if (temp->right) {
					que.push(temp->right);
				}
			}
		}
		
		return depth;
	}
};

class Tree {//��С���
private:
	TreeNode* root;
	int PostTraversal(TreeNode* cur) {
		if (cur == NULL) {
			return 0;
		}

		int leftDepth = PostTraversal(cur->left);//��
		int rightDepth = PostTraversal(cur->right);//��

		if (cur->left == NULL && cur->right != NULL) {//����Ҳ���
			return rightDepth + 1;
		}
		else if (cur->left != NULL && cur->right == NULL) {//�ҿ��󲻿�
			return leftDepth + 1;
		}
		else {//���ҽԲ�Ϊ��
			return min(leftDepth, rightDepth) + 1;
		}
	}
public:
	int MinDepth() {
		return PostTraversal(root);
	}
};

class Tree {
private:
	TreeNode* root;
public:
	int MinDepth() {
		if (root == NULL) {
			return 0;
		}

		queue<TreeNode*> que;
		que.push(root);
		int depth = 0;

		while (!que.empty()) {
			int size = que.size();
			depth++;
			while (size--) {
				TreeNode* temp = que.front();
				que.pop();
				if (temp->left) {
					que.push(temp->left);
				}
				if (temp->right) {
					que.push(temp->right);
				}

				if (temp->left == NULL && temp->right == NULL) {
					//һ������Ҷ�ӽڵ���������
					//˵������С���
					return depth;
				}
			}
		}

		return -1;//��װ����
	}
};

class Tree {//��ת��������
private:
	TreeNode* root;
	TreeNode* Invert(TreeNode* cur) {
		if (cur == NULL) {
			return NULL;
		}

		swap(cur->left, cur->right);
		Invert(cur->left);
		Invert(cur->right);
		//����ʹ�õ���ǰ�򣬴��ϵ�С�������ҽڵ㽻��
		//Ҳ����ʹ�ú������Ǵ��µ��Ͻ������ҽڵ㽻��
	}
public:
	TreeNode* InvertTree() {//ֱ����
		return Invert(root);
	}
};

class Tree {//�ж��Ƿ���Գ�
private:
	TreeNode* root;
	bool compare(TreeNode* left, TreeNode* right) {//����ȷ�������뷵��ֵ������
		if (left == NULL && right == NULL) {
			return true;
		}
		else if ((left != NULL && right == NULL) || (left == NULL && right != NULL)) {
			return false;
		}
		else if (left->val != right->val) {
			return false;
		}

		bool outside = compare(left->left, right->right);
		bool inside = compare(left->right, right->left);
		//�Ƚ�����ͬ��ڵ���ڲ������

		return outside && inside;
	}
public:
	bool isSymmetric() {
		if (root == NULL) {
			return true;
		}
		
		return compare(root->left, root->right);
	}
};

class Tree {
private:
	TreeNode* root;
	int Count(TreeNode* cur) {
		if (cur == NULL) {
			return 0;
		}

		int leftCount = Count(cur->left);//��
		int rightCount = Count(cur->right);//��
		
		return leftCount + rightCount + 1;//��
	}
public:
	int CountNodes() {
		if (root == NULL) {
			return 0;
		}

		return Count(root);
	}
};

class Tree {
private:
	TreeNode* root;
public:
	int CountNodes() {
		if (root == NULL) {
			return 0;
		}

		queue<TreeNode*> que;
		que.push(root);
		int count = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				TreeNode* temp = que.front();
				que.pop();
				count++;
				if (temp->left) {
					que.push(temp->left);
				}
				if (temp->right) {
					que.push(temp->right);
				}
			}
		}

		return count;
	}
};

class Tree {
private:
	TreeNode* root;
	int GetHeight(TreeNode* cur) {
		if (cur == NULL) {
			return 0;
		}

		int LeftHeight = GetHeight(cur->left);
		if (LeftHeight == -1) {
			return -1;
		}
		int RightHeight = GetHeight(cur->right);
		if (RightHeight == -1) {
			return -1;
		}
		//������Ѿ�������-1��˵��������ƽ�������������ֱ�����Ϸ���

		if (abs(LeftHeight - RightHeight) > 1) {//�߶Ⱦ���ֵ֮��
			return -1;
		}
		else {
			return max(LeftHeight, RightHeight) + 1;//�������߶�
		}
		

	}
public:
	bool IsBalanced() {
		if (GetHeight(root) == -1) {
			return false;
		}
		else {
			return true;
		}
	}
};

class Tree {
private:
	TreeNode* root;
	void Traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {

		if (cur->left == NULL && cur->right == NULL) {//���������·�����յ㣬��ֹ����
			path.push_back(cur->val);//�������һ������
			string ret;
			for (int i = 0;i < path.size() - 1;i++) {
				ret += to_string(path[i]);
				ret += "->";
			}
			ret += to_string(path[path.size() - 1]);
			result.push_back(ret);
			//path.clear();
			// ������ɾ�����еĵ�ǰ�ڵ�ǰ�����е�����
			//Ϊ��ģ�����ͷָ���Ч��
			return;
		}

		path.push_back(cur->val);//��
		
		//Ҷ�ӽڵ㲻����ݹ飬����Ҫ�����ж����ҽڵ��Ƿ�Ϊ�յ��ж�
		if (cur->left) {//��
			Traversal(cur->left, path, result);
			path.pop_back();
		}
		if (cur->right) {//��
			Traversal(cur->right, path, result);
			path.pop_back();
		}
	}
public:
	vector<string> TreePath() {
		vector<string> result;//���յķ���
		vector<int> path;//������¼ÿһ��·��������
		Traversal(root, path, result);
		return result;
	}
};

class Tree {
private:
	TreeNode* root;
	int LeftSum(TreeNode* cur) {
		if (root == NULL) {
			return 0;
		}
		
		int leftVal = LeftSum(cur->left);//��
		int rightVal = LeftSum(cur->right);//��
		if (cur->left != NULL && cur->left->left == NULL && cur->left->right == NULL) {
			leftVal = root->left->val;
		}//ֻ����������

		return leftVal + rightVal;//��
	}
public:
	int GetLeftSum() {
		return LeftSum(root);
	}
};

class Tree {
private:
	TreeNode* root;
	int result;
	int Maxdepth=-1;
	void LeftBottom(TreeNode* cur, int depth) {
		if (cur->left == NULL && cur->right == NULL) {//�ҵ����½ǵĽڵ㣬�Ͳ�����ݹ���
			if (Maxdepth < depth) {//ֻ�е���ȸ����ʱ��Ż����result
				Maxdepth = depth;
				result = cur->val;
			}
			return;
		}

		if (root->left) {//ע���������ж�Ϊ�յ�����Ҫ��
			LeftBottom(root->left, depth + 1);
		}
		if (root->right) {
			LeftBottom(root->right, depth + 1);
		}//����ʹ�õ��˻���
	}
public:
	int GetLeftBottom() {
		LeftBottom(root, 0);
		return result;
	}
};

class Tree {
private:
	TreeNode* root;
	bool Traversal(TreeNode* cur, int count) {
		if (cur->left == NULL && cur->right == NULL && count == cur->val) {
			return true;
		}
		else if (cur->left == NULL && cur->right == NULL && count != cur->val) {
			return false;
		}

		bool Left,Right;
		if (cur->left) {
			Left = Traversal(cur->left, count - cur->val);
		}
		if (cur->right) {
			Right = Traversal(cur->right, count - cur->val);//�����õ��˻���
		}

		return Left || Right;
	}
public:
	bool HasSum(int sum) {
		if (root == NULL) {
			return false;
		}

		return Traversal(root, sum);
	}
};

class Tree {
private:
	TreeNode* Build(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0) {//��ֹ����
			return NULL;
		}

		int rootValue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootValue);//�õ����ڵ�

		if (postorder.size() == 1) {
			return root;
		}

		int index;
		for (int i = 0;i < inorder.size();i++) {
			if (inorder[i] == rootValue) {
				index = i;
				break;
			}
		}//�ҵ��ָ��

		//�и���������
		vector<int> LeftInorder(inorder.begin(), inorder.begin() + index);
		//[0, index)
		vector<int> RightInorder(inorder.begin() + index, inorder.end());
		//[index + 1, end)

		postorder.erase(postorder.end() - 1);//ɾ��ĩβ�Ľڵ�

		//�и��������
		vector<int> LeftPostorder(postorder.begin(), postorder.begin() + LeftInorder.size());
		vector<int> RightPostorder(postorder.begin() + LeftInorder.size(), postorder.end() - 1);

		root->left = Build(LeftInorder, LeftPostorder);//��ߵ����鹹�ɶ�������֧

		root->right = Build(RightInorder, RightPostorder);//�ұߵ����鹹�ɶ������ķ�֧

	}
public:
	TreeNode* BuildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty()) {
			return NULL;
		}

		return Build(inorder, postorder);
	}
};

class Tree {
private:

	TreeNode* MaxTree(vector<int>& nums){
		if (nums.empty()) {
			return NULL;
		}
		else if (nums.size() == 1) {
			return new TreeNode(nums[0]);
		}//����״���Լ���ֹ����

		int Maxval=nums[0];
		int pos=0;
		for (int i = 0;i < nums.size();i++) {
			if (Maxval < nums[i]) {
				Maxval = nums[i];
				pos = i;
			}
		}
		TreeNode* root = new TreeNode(Maxval);

		vector<int> left(nums.begin(), nums.begin() + pos);
		vector<int> right(nums.begin() + pos + 1, nums.end());
		root->left = MaxTree(left);
		root->right = MaxTree(right);

		return root;

	}
public:
	TreeNode* BuildMaxTree(vector<int>& nums){

		return MaxTree(nums);
	}
};

class Tree {
private:
	TreeNode* Merge(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL) {
			return NULL;
		}
		else if (t1 == NULL && t2 != NULL) {
			return t2;
		}
		else if (t1 != NULL && t2 == NULL) {
			return t1;
		}//��ֹ����

		//���涼�Ѿ���������������ˣ�������ֱ�����ɾͺ�
		TreeNode* cur = new TreeNode(t1->val + t2->val);
		cur->left = Merge(t1->left, t2->right);
		cur->right = Merge(t1->right, t2->right);
			
		return cur;//����һ������cur
	}
public:
	TreeNode* MergeTree(TreeNode* t1, TreeNode* t2) {//ϰ���Ե�ֻ��һ���ӿ�

		return Merge(t1, t2);
	}
};

class Tree {
private:
	TreeNode* root;
	TreeNode* Search(TreeNode*cur,int val) {
		if (cur == NULL) {
			return NULL;
		}
		else if (cur->val == val) {
			return cur;
		}

		TreeNode* result = NULL;
		//���������µ�һ������
		//���ܽ����ӵĽ�����ݵ�cur->left����cur->right�У��������������⣬Ҳ���޸�ԭ���Ķ�����
		//����ʹ��result������һ�㵥������һ���ڵ����ж�
		//��Ϊ�Ƕ������������������ͬʱҪ�����ҽڵ������������
		if (val > cur->val) {
			result = Search(cur->right, val);
		}
		else if (val < cur->val) {
			result = Search(cur->left, val);
		}

		return result;
	}
public:
	TreeNode* SearchTree(int val) {
		return Search(root,val);
	}
};

class Tree {//�ж��Ƿ�Ϊ���������������ж�����������������Ƿ񵥵�����
private:
	TreeNode* root;
	void Traversal(TreeNode* cur,vector<int>& vec) {
		if (cur == NULL) {
			return;
		}

		Traversal(cur->left, vec);
		vec.push_back(cur->val);
		Traversal(cur->right, vec);
	}
public:
	bool IsValidBST() {
		vector<int> result;
		Traversal(root, result);
		for (int i = 0;i < result.size() - 1;i++) {
			if (result[i + 1] <= result[i]) {//ע���������Ҳ����
				return false;
			}
		}

		return true;
	}
};

class Tree {
private:
	TreeNode* root;
	void Traversal(TreeNode* cur, vector<int>& result) {
		if (cur == NULL) {
			return;
		}

		Traversal(cur->left, result);
		result.push_back(cur->val);
		Traversal(cur->right, result);
	}
public:
	int GetMinDiffer() {
		vector<int> result;
		Traversal(root, result);

		if (result.size() < 2) {
			return 0;
		}

		int min = result[1]-result[0];
		for (int i = 1;i < result.size() - 1;i++) {
			if (result[i + 1] - result[i] < min) {
				min = result[i + 1] - result[i];
			}
		}

		return min;
	}
};

class Tree {//��������������
private:
	TreeNode* root;
	void Traversal(map<int, int>& m, TreeNode* cur) {
		if (cur == NULL) {
			return;
		}

		m[cur->val]++;
		Traversal(m,cur->left);
		Traversal(m,cur->right);
	}

	bool compare(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}

public:
	vector<int> FindMost() {
		if (root == NULL) {
			return vector<int>();
		}

		vector<int> result;
		map<int, int> m;
		Traversal(m, root);

		vector<pair<int, int>> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(),compare);

		for (int i = 0;i < vec.size();i++) {
			result.push_back(vec[0].first);
			if (vec[i].second == vec[0].second) {
				result.push_back(vec[i].first);
			}
			else {
				break;
			}
		}

		return result;
	}
};

class Tree {//Ѱ�Ҷ�����������Ĺ�������
private:
	TreeNode* root;
	TreeNode* Ancestor(TreeNode* a, TreeNode* b,TreeNode* cur) {
		if (a == root || b == root) {
			return root;
		}
		if (cur == NULL) {
			return NULL;
		}

		TreeNode* Left = Ancestor(a, b, cur->left);
		TreeNode* Right = Ancestor(a, b, cur->right);

		if (left == NULL && Right == NULL) {//û���ҵ��������ڵ�
			return NULL;
		}
		else if (left == NULL && Right != NULL) {//�Ҳ��ҵ��ˣ����û�ҵ�
			return Right;
		}
		else if (left != NULL && Right == NULL) {//����ҵ��ˣ��Ҳ�û���ҵ�
			return Left;
		}
		else {
			return cur;
		}
		//�����Left�Լ�Right������һ��bool���͵ĸо���ֻ������Ϊ�˷��ϵݹ��Ҫ����޸�������ΪTreeNode* ,ÿһ�������ϼ����ر��ҵ��Ľڵ�
		//Left�Լ�RightΪ�մ���û���ҵ����ǿմ����ҵ��ˡ�ֻ�е�Left��Right���ǿյ�ʱ�򣬲Ż᷵�������Ƚڵ�
		//��Ȼ��������������һ���ڵ�����һ���ڵ�ĸ��ڵ��ʱ��Ҳ�ܷ�����ȷ�Ľڵ�
	}
public:
	TreeNode* LowestAncestor(TreeNode* a, TreeNode* b) {
		if (root == NULL) {
			return NULL;
		}
		return Ancestor(a, b, root);
	}
};

class Tree {
private:
	TreeNode* root;
	TreeNode* Insert(TreeNode* cur, int val) {
		if (cur == NULL) {
			return new TreeNode(val);
		}

		if (val > cur->val) {
			cur->right = Insert(cur->right, val);
		}
		else {
			cur->left = Insert(cur -> left, val);
		}

		return cur;//���ո��ڵ�ķ���
	}
public:
	TreeNode* InsertBST(int val) {
		root = Insert(root,val);
		return root;
	}
};

class Tree {
	//���ź����ǣ�ɾ���ڵ�Ҳ�ᵼ�������������ṹ�ı仯
	//��Ϊleetcode�еĶ�����һ���ǰ���ǰ������ķ�ʽ���д洢��
	// ���п��Խ�ɾ��ǰ�������е�ֵ�����½�������
private:
	TreeNode* root;
	void Traversal(vector<int>& result, TreeNode* cur) {
		if (cur == NULL) {
			return;
		}

		//����һ��Ҫ����ǰ�����浽������
		result.push_back(cur->val);
		Traversal(result, cur->left);
		Traversal(result, cur->right);
	}
	TreeNode* insert(TreeNode* cur, int val) {
		if (cur == NULL) {
			cur = new TreeNode(val);
			return cur;
		}

		if (val > cur->val) {
			cur->right = insert(cur->right, val);
		}
		else {
			cur->left = insert(cur->left, val);
		}

		return cur;
	}
public:
	TreeNode* deleteNode(int key) {
		vector<int> result;
		Traversal(result, root);

		for (int i = 0;i < result.size();i++) {
			if (result[i] == key) {
				result.erase(result.begin() + i);
			}
		}

		TreeNode* newNode = nullptr;
		for (auto it : result) {
			newNode = insert(newNode, it);
		}

		return newNode;
	}
};

class Tree {
private:
	TreeNode* root;
	TreeNode* Delete(TreeNode* root, int key) {
		if (root == NULL) {//û�ҵ�Ҫɾ���Ľڵ�
			return root;
		}
		if (root->val == key) {
			if (root->right == NULL && root->right == NULL) {
				delete root;
				return NULL;
			}
			else if (root->left == NULL && root->right != NULL) {
				TreeNode* temp = root->right;
				delete root;
				return temp;//���غ���Ľڵ㣬ʹ���仹�ܹ���һ��������
			}
			else if (root->left != NULL && root->right == NULL) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			else {//���Ҷ���Ϊ�յ��������Ҫ����λ��
				TreeNode* cur = root->right;
				while (cur->left != NULL) {
					cur = cur->left;
				}
				cur->left = root->right;//��root->left���������root->right����Ҷ������
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}

			if (key < root->val) {//�������ͨ�Ķ��������������Ｔ��
				root->left = Delete(root->left, key);//ÿ�ζ����Ϸ��ؽڵ㣬��󷵻�����������
			}
			if (key > root->val) {
				root->right = Delete(root->right, key);
			}

			return root;
		}
	}
public:
	TreeNode* DeleteNode(int key) {
		root = Delete(root, key);
		return root;
	}
};

class Tree {
private:
	TreeNode* root;
	TreeNode* Trim(TreeNode* cur,int low, int high) {
		if (root == NULL) {
			return NULL;
		}

		if (cur->val < low) {//��Ȼcur�����㣬����cur���ҽڵ��������
			TreeNode* right = Trim(cur->right, low, high);
			return right;
		}
		if (cur->val > high) {//cur����ڵ�Ҳ��������
			TreeNode* left = Trim(cur->left, low, high);
			return left;
		}
		//���ϼ������ڷ�Χ���Left��right�ڵ㣬�����������ɶ�����

		root->left = Trim(root->left, low, high);
		root->right = Trim(root->right, low, high);

		return root;//���յķ���
	}
public:
	TreeNode* TrimTree(int low, int high) {
		return Trim(root,low, high);
	}
};

class Tree {//���������������Ϊ�߶�ƽ��Ķ�����
private:
	TreeNode* root;
	TreeNode* Traversal(vector<int> nums, int left, int right) {
		//������õ�ԭ��������ұ�
		if (left > right) {//��ֹ����
			return nullptr;
		}
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(nums[mid]);//��

		root->left = Traversal(nums, left, mid - 1);//��
		root->right = Traversal(nums, mid + 1, right);//��

		return root;
	}
public:
	TreeNode* GenerateBST(vector<int> nums) {
		TreeNode* root = Traversal(nums, 0, nums.size() - 1);
		return root;
	}
};