#include "test_findnodewithdata.h"
#include "functions.h"

/*!
* Вершина с цифрой data не существует в поддереве currentNode
*/
void test_findNodeWithData::nodeWithDataDoesNotExist(){
	// указатель на коренную вершину поддерева
	node* currentNode = new node(1);
	node* node2 = new node(2);
	currentNode->addChild(node2);
	node* node5 = new node(5);
	currentNode->addChild(node5);
	node* node3 = new node(3);
	node2->addChild(node3);
	// цифра, которую надо найти
	int data = 4;
	// возвращаемое значение
	node* ret = findNodeWithData(currentNode, data);
	QVERIFY(ret == NULL);
	currentNode->delTree();
}

/*!
* Вершина currentNode держит цифру data
*/
void test_findNodeWithData::dataInCurrentNode(){
	// указатель на коренную вершину поддерева
	node* currentNode = new node(1);
	node* node2 = new node(2);
	currentNode->addChild(node2);
	node* node5 = new node(5);
	currentNode->addChild(node5);
	node* node3 = new node(3);
	node2->addChild(node3);
	// цифра, которую надо найти
	int data = 1;
	// возвращаемое значение
	node* ret = findNodeWithData(currentNode, data);
	QVERIFY(node::compareTree(ret, currentNode));
	currentNode->delTree();
}

/*!
* Цифра data в одной вершине, которая в поддереве вершины currentNode
*/
void test_findNodeWithData::dataOnSubTree(){
	// указатель на коренную вершину поддерева
	node* currentNode = new node(1);
	node* node2 = new node(2);
	currentNode->addChild(node2);
	node* node5 = new node(5);
	currentNode->addChild(node5);
	node* node3 = new node(3);
	node2->addChild(node3);
	// цифра, которую надо найти
	int data = 2;
	// возвращаемое значение
	node* ret = findNodeWithData(currentNode, data);
	// Ожидаемые результаты
	node* expectedNode = new node(2);
	node* node3_ = new node(3);
	expectedNode->addChild(node3_);

	QVERIFY(node::compareTree(expectedNode, ret));
	currentNode->delTree();
	expectedNode->delTree();
}