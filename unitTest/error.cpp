#include "error.h"

/*!
* Конструктор
*/
error::error(){
}

/*!
* Конструктор
* \param[in] _type - тип ошибки
*/
error::error(errorType _type){
	type = _type;
	treeID = 0;
	errorString = "";
}

/*!
* Конструктор
* \param[in] _type - тип ошибки
* \param[in] _treeID - идентификатор дерева, в котором возникает ошибка
* \param[in] _message - сообщение о вершине или о дереве, в которых возникает ошибка
*/
error::error(errorType _type, int _treeID, QString _message){
	type = _type;
	treeID = _treeID;
	errorString = _message;
}

/*!
* Напечатать сообщение о ошибке
*/
void error::printMessage(){
	switch (type){
	case COULD_NOT_OPEN_FILE:
		printf("Ошибка - возникла проблемма с записыванием файла с именем %s\n", errorString.toAscii().data());
		break;

	case EXISTS_NOT_NUMBER:
		printf("Ошибка - существует вершина, не являющаяся числом.\n");
		printf("Дерево: %d\n", treeID);
		printf("Неверная вершина: %s\n", errorString.toAscii().data());
		break;

	case OVER_SIZE:
		printf("Ошибка - количество вершин дерева превышает максимальный размер.\n");
		printf("Дерево: %d\n", treeID);
		break;

	case COINCIDED_NUMBERS:
		printf("Ошибка - существуют несколько вершин с одинаковыми цифрами.\n");
		printf("Дерево: %d\n", treeID);
		printf("Повторяющаяся цифра: %s\n", errorString.toAscii().data());
		break;

	case WRONG_TREE_ID:
		printf("Ошибка - номер дерева неверный.\n");
		printf("Дерево: %d\n", treeID);
		printf("Номер: %s\n", errorString.toAscii().data());
		break;
	};
}