#include<bits/stdc++.h>

using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class TreeNode{
public:
	int data;
	vector<TreeNode*> Children;

	TreeNode(int data){
		this->data = data;
	}

	~TreeNode(){
		for(int i = 0; i < Children.size() ; i++){
			delete Children[i];
		}
	}
};


////   Taking Input normally;
// TreeNode* getTree(){

// 	int rootData;
// 	cout<<"Enter Root Data :";
// 	cin>>rootData;

// 	TreeNode *root = new TreeNode(rootData);

// 	cout<<"\nEnter the No. of child :";
// 	int child;
// 	cin>>child;

// 	FOR(i,child){
// 		TreeNode* head = getTree();
// 		root->Children.push_back(head);
// 	}
// 	return root;
// }


////   Taking Input in a Level
TreeNode* getTree(){

	cout<<"Enter the root-data :";
	int rootData;
	cin>>rootData;
	TreeNode *root = new TreeNode(rootData);

	queue< TreeNode*> pending;
	pending.push(root);

	while(!pending.empty()){

		TreeNode *ptr = pending.front();
		pending.pop();

		int child;
		cout<<"\nEnter the No. of Child for "<< ptr->data<<" :";
		cin>>child;

		FOR(i,child){
			cout<< "\nEnter "<< i + 1<<"th child of :"<<ptr->data <<" :";
			int val;
			cin>>val;
			TreeNode *temp = new TreeNode(val);
			ptr->Children.push_back(temp);
			pending.push(temp);
		}
	}

	return root;
}

void Display(TreeNode* root){

	cout<<root->data<<" :";
	FOR(i,root->Children.size()){
		cout<<root->Children[i]->data<<",";
	}
	cout<<"\n";

	FOR(i,root->Children.size()){
		Display(root->Children[i]);
	}

}

int getCount(TreeNode* root){
    int ans = 1;
    
    FOR(i,root->Children.size()){
        ans += getCount(root->Children[i]);
    }
    return ans;
}

int leafCount(TreeNode* root){
	if( root  == NULL) return 0;

	if(root->Children.size() == 0) return 1;

	int count = 0;
	for( int i = 0; i < root->Children.size() ; i++){
		count += leafCount(root->Children[i]);
	}

	return count;
}

int main()
{

    TreeNode *root = getTree();

    Display(root);

    cout<<"\n Number OF Nodes in a tree :"<<getCount(root);
    
    cout<<"\n Number OF Leaf Node : "<<leafCount(root);

    return 0;
}
