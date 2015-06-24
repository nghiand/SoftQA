#ifndef _NODE_
#define _NODE_

#include <qvector.h>

/*!
* \brief Класс, сохраняющий информации вершины дерева
*/
class node{
public:
	int data;					/**< Цифра вершины  */
	QVector<node*> children;	/**< Список дочерних вершин  */
	node* parent;				/**< Указатель на родителя этой вершины  */

	/*!
	* Конструктор
	*/
	node();
	/*!
	* Конструктор
	* \param[in] _data - цифра вершины
	*/
	node(int _data);
	/*!
	* Конструктор
	* \param[in] _data - цифра вершины
	* \param[in] _parent - указатель на родителя
	*/
	node(int _data, node* _parent);
	/*!
	* Добавить дочери
	* \param[in] chi - указатель на дочери
	*/
	void addChild(node* chi);
	/*!
	* Размер дерева
	* \return - размер дерева
	*/
	int size();
	/*!
	* Удалить дерево
	*/
	void delTree();
	/*!
	* Сравнить 2 деревья
	* \param[in] root1 - указатель на корень первого дерева
	* \param[in] root2 - указатель на корень второго дерева
	*/
	static bool compareTree(node* root1, node* root2);
};

#endif
