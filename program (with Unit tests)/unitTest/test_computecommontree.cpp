#include "test_computecommontree.h"
#include "functions.h"

/*!
* Вершина root1 и вершина root2 держат разные цифры
*/
void test_computeCommonTree::differentNumbersInRoots(){
	// первое дерево
	node* root1 = new node(4);
	// второе дерево
	node* root2 = new node(6);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 0);
	QVERIFY(commonRoot == NULL);

	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
}

/*!
* У вершины root1 нет дочерей
*/
void test_computeCommonTree::nonSubTreeOnFirstRoot(){
	// первое дерево
	node* root1 = new node(4);
	// второе дерево
	node* root2 = new node(4);
	node* node5 = new node(5);
	root2->addChild(node5);
	node* node6 = new node(6);
	root2->addChild(node6);
	node* node7 = new node(7);
	root2->addChild(node7);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 1);
	// Ожидаемые результаты
	node* expectedRoot = new node(4);

	QVERIFY(node::compareTree(commonRoot, expectedRoot));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
	expectedRoot->delTree();
}

/*!
* У вершины root2 нет дочерей
*/
void test_computeCommonTree::nonSubTreeOnSecondRoot(){
	// первое дерево
	node* root1 = new node(4);
	node* node5 = new node(5);
	root1->addChild(node5);
	node* node6 = new node(6);
	root1->addChild(node6);
	node* node7 = new node(7);
	root1->addChild(node7);
	// второе дерево
	node* root2 = new node(4);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 1);
	// Ожидаемые результаты
	node* expectedRoot = new node(4);

	QVERIFY(node::compareTree(commonRoot, expectedRoot));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
	expectedRoot->delTree();
}

/*!
* У вершины root1 и вершины root2 нет пар дочерей с одинаковыми цифрами
*/
void test_computeCommonTree::notExistsPairOfMatchedChild(){
	// первое дерево
	node* root1 = new node(1);
	node* node2_ = new node(2);
	root1->addChild(node2_);
	node* node3_ = new node(3);
	root1->addChild(node3_);
	node* node4_ = new node(4);
	node2_->addChild(node4_);
	// второе дерево
	node* root2 = new node(1);
	node* node5 = new node(4);
	root2->addChild(node5);
	node* node6 = new node(5);
	root2->addChild(node6);
	node* node7 = new node(6);
	root2->addChild(node7);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 1);
	// Ожидаемые результаты
	node* expectedRoot = new node(1);

	QVERIFY(node::compareTree(commonRoot, expectedRoot));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
	expectedRoot->delTree();
}

/*!
* Поддеревья с корнями в вершинах root1 и root2 похожи друг на друга
*/
void test_computeCommonTree::twoTreesEqual(){
	// первое дерево
	node* root1 = new node(1);
	node* node2_ = new node(2);
	root1->addChild(node2_);
	node* node3_ = new node(3);
	root1->addChild(node3_);
	node* node4_ = new node(4);
	node2_->addChild(node4_);
	// второе дерево
	node* root2 = new node(1);
	node* node2 = new node(2);
	root2->addChild(node2);
	node* node3 = new node(3);
	root2->addChild(node3);
	node* node4 = new node(4);
	node2->addChild(node4);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 4);
	// Ожидаемые результаты
	node* expectedRoot = root1;

	QVERIFY(node::compareTree(commonRoot, expectedRoot));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
}

/*!
* Cлучайный тест 1
*/
void test_computeCommonTree::randomTest1(){
	// первое дерево
	node* root1 = new node(10);
	node* node1 = new node(1);
	root1->addChild(node1);
	node* node5 = new node(5);
	root1->addChild(node5);
	node* node7 = new node(7);
	root1->addChild(node7);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node6 = new node(6);
	node5->addChild(node6);
	node* node4 = new node(4);
	node7->addChild(node4);
	node* node8 = new node(8);
	node7->addChild(node8);
	// второе дерево
	node* root2 = new node(10);
	node* node1_ = new node(1);
	root2->addChild(node1_);
	node* node6_ = new node(6);
	root2->addChild(node6_);
	node* node7_ = new node(7);
	root2->addChild(node7_);
	node* node4_ = new node(4);
	root2->addChild(node4_);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node8_ = new node(8);
	node7_->addChild(node8_);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 5);

	// Ожидаемые результаты
	node* expectedRoot = new node(10);
	node* enode1 = new node(1);
	expectedRoot->addChild(enode1);
	node* enode7 = new node(7);
	expectedRoot->addChild(enode7);
	node* enode3 = new node(3);
	enode1->addChild(enode3);
	node* enode8 = new node(8);
	enode7->addChild(enode8);

	node* expectedRoot_ = new node(10);
	node* enode1_ = new node(1);
	expectedRoot_->addChild(enode1_);
	node* enode7_ = new node(7);
	expectedRoot_->addChild(enode7_);
	node* enode2_ = new node(2);
	enode1_->addChild(enode2_);
	node* enode8_ = new node(8);
	enode7_->addChild(enode8_);


	QVERIFY(node::compareTree(commonRoot, expectedRoot) || node::compareTree(commonRoot, expectedRoot_));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
	expectedRoot->delTree();
	expectedRoot_->delTree();
}

/*!
* Cлучайный тест 2
*/
void test_computeCommonTree::randomTest2(){
	// первое дерево
	node* root1 = new node(12);
	node* node1 = new node(1);
	root1->addChild(node1);
	node* node5 = new node(5);
	root1->addChild(node5);
	node* node7 = new node(7);
	root1->addChild(node7);
	node* node11 = new node(11);
	root1->addChild(node11);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node6 = new node(6);
	node5->addChild(node6);
	node* node4 = new node(4);
	node7->addChild(node4);
	node* node8 = new node(8);
	node7->addChild(node8);
	node* node9 = new node(9);
	node11->addChild(node9);
	node* node10 = new node(10);
	node11->addChild(node10);
	// второе дерево
	node* root2 = new node(12);
	node* node11_ = new node(11);
	root2->addChild(node11_);
	node* node1_ = new node(1);
	root2->addChild(node1_);
	node* node6_ = new node(6);
	root2->addChild(node6_);
	node* node7_ = new node(7);
	root2->addChild(node7_);
	node* node4_ = new node(4);
	root2->addChild(node4_);
	node* node9_ = new node(9);
	node11_->addChild(node9_);
	node* node10_ = new node(10);
	node11_->addChild(node10_);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node8_ = new node(8);
	node7_->addChild(node8_);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 5);
	// Ожидаемые результаты
	node* expectedRoot = new node(12);
	node* enode1 = new node(1);
	expectedRoot->addChild(enode1);
	node* enode7 = new node(7);
	expectedRoot->addChild(enode7);
	node* enode3 = new node(3);
	enode1->addChild(enode3);
	node* enode8 = new node(8);
	enode7->addChild(enode8);

	node* expectedRoot_ = new node(12);
	node* enode1_ = new node(1);
	expectedRoot_->addChild(enode1_);
	node* enode7_ = new node(7);
	expectedRoot_->addChild(enode7_);
	node* enode2_ = new node(2);
	enode1_->addChild(enode2_);
	node* enode8_ = new node(8);
	enode7_->addChild(enode8_);


	QVERIFY(node::compareTree(commonRoot, expectedRoot) || node::compareTree(commonRoot, expectedRoot_));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
	expectedRoot->delTree();
	expectedRoot_->delTree();
}

/*!
* Cлучайный тест 3
*/
void test_computeCommonTree::randomTest3(){
	// первое дерево
	node* root1 = new node(12);
	node* node1 = new node(1);
	root1->addChild(node1);
	node* node5 = new node(5);
	root1->addChild(node5);
	node* node7 = new node(7);
	root1->addChild(node7);
	node* node11 = new node(11);
	root1->addChild(node11);
	node* node2 = new node(2);
	node1->addChild(node2);
	node* node3 = new node(3);
	node1->addChild(node3);
	node* node6 = new node(6);
	node5->addChild(node6);
	node* node4 = new node(4);
	node7->addChild(node4);
	node* node8 = new node(8);
	node7->addChild(node8);
	node* node9 = new node(9);
	node11->addChild(node9);
	node* node10 = new node(10);
	node11->addChild(node10);
	// второе дерево
	node* root2 = new node(12);
	node* node6_ = new node(6);
	root2->addChild(node6_);
	node* node1_ = new node(1);
	root2->addChild(node1_);
	node* node11_ = new node(11);
	root2->addChild(node11_);
	node* node7_ = new node(7);
	root2->addChild(node7_);
	node* node4_ = new node(4);
	root2->addChild(node4_);
	node* node9_ = new node(9);
	node11_->addChild(node9_);
	node* node10_ = new node(10);
	node11_->addChild(node10_);
	node* node3_ = new node(3);
	node1_->addChild(node3_);
	node* node2_ = new node(2);
	node1_->addChild(node2_);
	node* node8_ = new node(8);
	node7_->addChild(node8_);
	// результирующее дерево
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 6);
	// Ожидаемые результаты
	node* expectedRoot = new node(12);
	node* enode1 = new node(1);
	expectedRoot->addChild(enode1);
	node* enode11 = new node(11);
	expectedRoot->addChild(enode11);
	node* enode3 = new node(3);
	enode1->addChild(enode3);
	node* enode9 = new node(9);
	enode11->addChild(enode9);
	node* enode10 = new node(10);
	enode11->addChild(enode10);

	node* expectedRoot_ = new node(12);
	node* enode1_ = new node(1);
	expectedRoot_->addChild(enode1_);
	node* enode11_ = new node(11);
	expectedRoot_->addChild(enode11_);
	node* enode2_ = new node(2);
	enode1_->addChild(enode2_);
	node* enode9_ = new node(9);
	enode11_->addChild(enode9_);
	node* enode10_ = new node(10);
	enode11_->addChild(enode10_);

	QVERIFY(node::compareTree(commonRoot, expectedRoot) || node::compareTree(commonRoot, expectedRoot_));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
	expectedRoot->delTree();
	expectedRoot_->delTree();
}

/*!
* Cлучайный тест 4
*/
void test_computeCommonTree::randomTest4(){
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
	node* commonRoot;
	// возвращаемое значение
	int ret = computeCommonTree(root1, root2, commonRoot);
	QCOMPARE(ret, 9);
	// Ожидаемые результаты
	QVERIFY(node::compareTree(commonRoot, root1));
	root1->delTree();
	root2->delTree();
	commonRoot->delTree();
}