#ifndef _ERROR_
#define _ERROR_
#include <qstring.h>
#include <qdebug.h>

/*!
* Список ошибок
*/
enum errorType {
				WRONG_FILE_FORMAT,		/**< Файл не правильный  */
				COULD_NOT_OPEN_FILE,	/**< Файл не может открыто  */
				EXISTS_NOT_NUMBER,		/**< Существует вершина, которая содержит не цифру */
				OVER_SIZE,				/**< Количество одного дерева превышают максимальный размер  */
				COINCIDED_NUMBERS,		/**< В одном дереве существуют несколько вершины, которые содержат одинаковые цифры */
				WRONG_TREE_ID			/**< Идентификатор дерева не правильный */
};

/*!
* \brief Класс опишет ошибки, возникающие когда считывает вводный файл
*/
class error{
public:
	errorType type;			/**< Тип ошибки  */
	int treeID;				/**< Идентификатор дерева, в котором возникает ошибка  */
	QString errorString;	/**< Сообщение о вершине или о дереве, в которых возникает ошибка  */

	/*!
	* Конструктор
	*/
	error();
	/*!
	* Конструктор
	* \param[in] _type - тип ошибки
	* \param[in] _treeID - идентификатор дерева, в котором возникает ошибка
	* \param[in] _message - сообщение о вершине или о дереве, в которых возникает ошибка
	*/
	error(errorType _type, int _treeID, QString _message);
	/*!
	* Напечатать сообщение о ошибке
	*/
	void printMessage() const;
};


#endif