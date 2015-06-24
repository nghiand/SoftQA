#include "test_findrootmaxcommontree.h"
#include "functions.h"

/*!
* В поддеревьях root1 и root2 нет пар вершин с одинаковыми цифрами
*/
void test_findRootMaxCommonTree::notExistsPairOfMatchedNodes(){
	node* root1 = new node(4);
	node* root2 = new node(6);
	// результирующее дерево
	node* retRoot;
	// возвращаемое значение
	int ret = findRootMaxCommonTree(root1, root2, retRoot);
	QCOMPARE(ret, 0);
	// Ожидаемые результаты
	QVERIFY(retRoot == NULL);
	root1->delTree();
	root2->delTree();
	retRoot->delTree();
}

/*!
* Вершина root1 и вершина root2 держат одинаковые цифры
*/
void test_findRootMaxCommonTree::dataInRootsEqual(){
	// первое дерево
	node* root1 = new node(1);
	node* node2 = new node(2);
	root1->addChild(node2);
	node* node3 = new node(3);
	node2->addChild(node3);
	node* node4 = new node(4);
	node2->addChild(node4);
	node* node5 = new node(5);
	node2->addChild(node5);
	node* node6 = new node(6);
	node4->addChild(node6);
	node* node7 = new node(7);
	node4->addChild(node7);
	node* node8 = new node(8);
	node6->addChild(node8);
	node* node9 = new node(9);
	node6->addChild(node9);
	// второе дерево
	node* root2 = new node(1);
	node* node11_ = new node(11);
	root2->addChild(node11_);
	node* node2_ = new node(2);
	root2->addChild(node2_);
	node* node3_ = new node(3);
	node2_->addChild(node3_);
	node* node4_ = new node(4);
	node2_->addChild(node4_);
	node* node5_ = new node(5);
	node2_->addChild(node5_);
	node* node6_ = new node(6);
	node4_->addChild(node6_);
	node* node7_ = new node(7);
	node4_->addChild(node7_);
	node* node8_ = new node(8);
	node6_->addChild(node8_);
	node* node9_ = new node(9);
	node6_->addChild(node9_);
	// результирующее дерево
	node* retRoot;
	// возвращаемое значение
	int ret = findRootMaxCommonTree(root1, root2, retRoot);
	QCOMPARE(ret, 9);
	// Ожидаемые результаты
	QVERIFY(node::compareTree(retRoot, root1));

	root1->delTree();
	root2->delTree();
	retRoot->delTree();
}

/*!
* Вершина root1 и вершина root2 держат разные цифры
*/
void test_findRootMaxCommonTree::dataInRootsAreDifferent(){
	// первое дерево
	node* root1 = new node(2);
	node* node3 = new node(3);
	root1->addChild(node3);
	node* node4 = new node(4);
	root1->addChild(node4);
	node* node1 = new node(1);
	root1->addChild(node1);
	node* node6 = new node(6);
	node4->addChild(node6);
	node* node7 = new node(7);
	node4->addChild(node7);
	node* node8 = new node(8);
	node6->addChild(node8);
	node* node9 = new node(9);
	node6->addChild(node9);
	// второе дерево
	node* root2 = new node(1);
	node* node11_ = new node(11);
	root2->addChild(node11_);
	node* node2_ = new node(2);
	root2->addChild(node2_);
	node* node3_ = new node(3);
	node2_->addChild(node3_);
	node* node4_ = new node(4);
	node2_->addChild(node4_);
	node* node5_ = new node(5);
	node2_->addChild(node5_);
	node* node6_ = new node(6);
	node4_->addChild(node6_);
	node* node7_ = new node(7);
	node4_->addChild(node7_);
	node* node8_ = new node(8);
	node6_->addChild(node8_);
	node* node9_ = new node(9);
	node6_->addChild(node9_);
	// результирующее дерево
	node* retRoot;
	// возвращаемое значение
	int ret = findRootMaxCommonTree(root1, root2, retRoot);
	QCOMPARE(ret, 7);
	// Ожидаемые результаты
	node* expectedRoot = new node(2);
	node* enode3 = new node(3);
	expectedRoot->addChild(enode3);
	node* enode4 = new node(4);
	expectedRoot->addChild(enode4);
	node* enode6 = new node(6);
	enode4->addChild(enode6);
	node* enode7 = new node(7);
	enode4->addChild(enode7);
	node* enode8 = new node(8);
	enode6->addChild(enode8);
	node* enode9 = new node(9);
	enode6->addChild(enode9);
	QVERIFY(node::compareTree(retRoot, expectedRoot));

	root1->delTree();
	root2->delTree();
	retRoot->delTree();
}