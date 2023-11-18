#include<iostream>
#include<map>
#include<string>
#include<queue>
using namespace std;
struct HuffmanNode{
	char ch;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;
	HuffmanNode(char c,int freq)
	{
		ch=c;
		frequency=freq;
		left=nullptr;
		right=nullptr;
	}
};
struct compNode{
	bool operator()(HuffmanNode* lhs,HuffmanNode* rhs)
	{
		return lhs->frequency>rhs->frequency;
	}
};
HuffmanNode* buildTree(map<char,int>&m1)
{
	priority_queue<HuffmanNode*, vector< HuffmanNode* >,compNode >pq;
	for(auto it:m1){
		pq.push(new HuffmanNode(it.first,it.second));
	}
	while(pq.size()>1)
	{
		HuffmanNode* node1=pq.top();
		pq.pop();
		HuffmanNode* node2=pq.top();
		pq.pop();
		HuffmanNode* combineNode=new HuffmanNode('\0',node1->frequency+node2->frequency);
		pq.push(combineNode);
	}
	return pq.top();

}
void generateCode(HuffmanNode* root,map<char,string>m2,string p)
{
	if(root==NULL)
	{
		return;
	}
	if(root->ch!='\0')
	{
		m2[root->ch]=p;
	}
	generateCode(root->left,m2,p+'0');
	generateCode(root->right,m2,p+'1');
}
int main()
{
	int n,value;
	char key;
	cout<<"How many characters you want to enter: \n";
	cin>>n;
	map<char,int>m1;
	while(n--)
	{
		cin>>key>>value;
		m1[key]=value;
	}
	HuffmanNode *root=buildTree(m1);
	map<char,string>m2;
	string p;
	generateCode(root,m2,p);
	for(auto it:m2)
	{
		cout<<it.first<<"->"<<it.second<<"\n";
	}
	return 0;
}
