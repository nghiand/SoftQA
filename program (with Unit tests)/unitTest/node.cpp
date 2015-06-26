#include "node.h"

/*!
* Конструктор
*/
node::node(){
	data = -1;
	parent = NULL;
}

/*!
* Конструктор
* \param[in] _data - цифра вершины
*/
node::node(int _data){
	data = _data; 
	parent = NULL;
}

/*!
* Конструктор
* \param[in] _data - цифра вершины
* \param[in] _parent - указатель на родителя
*/
node::node(int _data, node* _parent){
	data = _data;
	parent = _parent;
}

/*!
* Добавить дочери
* \param[in] chi - указатель на дочери
*/
void node::addChild(node* chi){
	if (chi == NULL) return;
	// push new child to childrens array of current node
	children.push_back(chi);
	// pointer of new child to current node
	chi->parent = this;
}

/*!
* Размер дерева
* \return - размер дерева
*/
int node::size(){
	int ret = 1;
	// for each child of current node
	for (int i = 0; i < children.size(); i++){
		// calculate number of children on tree rooted on this children
		// add calculated size to result
		ret += children[i]->size();
	}
	return ret;
}

/*
* Сравнить 2 деревья
* \param[in] root1 - указатель на корень первого дерева
* \param[in] root2 - указатель на корень второго дерева
* \return true - 2 деревья одинаковые
* \return false - в противном случае
*/
bool node::compareTree(node* root1, node* root2){
	if (root1->data != root2->data) return false;
	if (root1->children.size() != root2->children.size()) return false;
	for (int i = 0; i < root1->children.size(); i++)
		if (!compareTree(root1->children[i], root2->children[i])) return false;
	return true;
}

/*!
* Удалить дерево
*/
void node::delTree(){
	if (this == NULL) return;
	for (int i = 0; i < children.size(); i++){
		children[i]->delTree();
	}
	delete this;
}