#include <iostream>

using namespace std;

int main()
{
	struct TNode
	{
		char* name;
		TNode** nodes = nullptr;
		TNode* next = nullptr;
		int amount_of_nodes = 0;

		TNode* AddNode(TNode* p, char* key)
		{
			TNode* node = new TNode;
			node->name = key;
			if (!p->nodes)
			{
				TNode** mas = new TNode * [1];
				mas[p->amount_of_nodes] = node;
				p->nodes = mas;
				p->amount_of_nodes += 1;
			}
			else
			{
				TNode** mas = new TNode * [amount_of_nodes + 1];
				for (int i = 0; i < p->amount_of_nodes; i++)
				{
					mas[i] = p->nodes[i];
				}
				mas[p->amount_of_nodes - 1]->next = node;
				mas[p->amount_of_nodes] = node;
				delete p->nodes;
				p->nodes = mas;
				p->amount_of_nodes += 1;
			}
			return node;
		}

		TNode* FindNode(TNode* p, char* key)
		{
			if (p == nullptr) return nullptr;
			if (p->name == key) return p;
			if (p->nodes == nullptr) return nullptr;
			TNode** mas = p->nodes;
			for (int i = 0; i < p->amount_of_nodes; i++)
			{
				if (mas[i]->name == key) return mas[i];
			}
			return nullptr;
		}

		TNode* DelTree(TNode* p)
		{
			if (p == nullptr) return nullptr;
			else
			{
				amount_of_nodes = p->amount_of_nodes;
				if (p->nodes == nullptr) return nullptr;
				TNode** mas = p->nodes;
				delete p;
				for (int i = 0; i < amount_of_nodes; i++)
				{
					if (mas[i]->nodes == nullptr) delete mas[i];
					else DelTree(mas[i]);
				}
			}
			return nullptr;
		}

		void PrintTree(TNode* p)
		{
			if (p == nullptr) cout << "Derevo pustoe";
			cout << p->name << ' ';
			if (p->nodes != nullptr)
			{
				TNode** mas = p->nodes;
				for (int i = 0; i < p->amount_of_nodes; i++)
				{
					PrintTree(mas[i]);
				}
			}
		}
	};


	TNode* root = new TNode;
	char root_name[10] = "MainNode";
	root->name = root_name;
	cout << root->name;
	cout << endl;
	char node1[10] = "Node1";
	char node2[10] = "Node2";
	char node3[10] = "Node3";
	char node4[10] = "Node4";
	root->AddNode(root, node1);
	root->AddNode(root, node2);
	root->AddNode(root, node3);
	root->AddNode(root, node4);
	TNode* test;
	test = root->FindNode(root, node3);
	if (test != nullptr) cout << test->name;
	cout << endl;
	root->PrintTree(root);
	root->DelTree(root);
	cout << endl << "Derevo udasleno";
	return 0;
}