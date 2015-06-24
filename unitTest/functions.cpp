#include "functions.h"

/*!
* Считать открывающий тег вершины, создав её или, считать закрывающий тег вершины, в зависимости от положения в потоке
* \param[in] xmlStream - покок чтения на вводный XML-файл
* \param[in] treeNum - номер дерева, которое считываются
* \param[out] newNode - указатель на новую вершину
* \return 1 - при считывал открывающий тег и новая вершина создалась
* \return -1 - при считывал закрывающий тег
* \return 0 - при других случах.
*/
int readNode(QXmlStreamReader& xmlStream, int treeNum, node*& newNode){
	newNode = NULL;
	QXmlStreamAttributes attr;
	// 1. Считать тег из потока
	xmlStream.readNext();
	// 2. Если открывающий тег <node> считан, то
	if (xmlStream.isStartElement()){
		// 3.1 Получить атрибуты из тега <node>
		attr = xmlStream.attributes();
		QString value = attr.value("value").toString();
		int data = value.toInt();

		// 3.2. Если значение атрибута не является цифрой, то выбросить исключение (ошибка EXIST_NOT_NUMBER)
		if (QString::number(data) != value)
			throw error(EXISTS_NOT_NUMBER, treeNum == 1 ? 1 : 2, value);

		// 3.3. Иначе создать новую вершину newNode с цифрой data
		newNode = new node(data);
		// 3.4. Вернуть 1
		return 1;
	} else if (xmlStream.isEndElement())
		// 4. Если закрывающий тег </node> считан, то вернуть -1
		return -1;
	// 5. Иначе вернуть 0
	return 0;
}

/*!
* Считать и построить дерево
* \param[in] xmlStream - покок чтения на вводный XML-файл
* \param[in] treeNum - номер дерева, которое считываются
* \param[out] root - указатель на корень входного дерева
*/
void readTree(QXmlStreamReader& xmlStream, node*& root, int treeNum){
	QXmlStreamAttributes attr;
	root = NULL;

	QSet<int> setOfData;
	// Размер дерева
	int treeSize = 0;

	// 1. Проверить верный ли идентификатор дерева. Если нет, то выбросить исключение (ошибка WRONG_TREE_ID)
	xmlStream.readNext();
	attr = xmlStream.attributes();
	QString treeID = attr.value("id").toString();
	if (treeNum == 1 && treeID != "1" || treeNum == 2 && treeID != "2")
		throw error(WRONG_TREE_ID, treeNum == 1 ? 1 : 2, treeID);
	xmlStream.readNext();
	// 2. Создать указатель current - указатель на текущую вершину
	node *current = NULL;

	// 3. Считать каждую вершину дерева с помощью функции readNode
	for (int cnt = 0;;){
		node* newNode = NULL;
		int newDepth;
		try{
			newDepth = readNode(xmlStream, treeNum, newNode);
		} catch (error e){
			// 3.1. Если возникла ошибка, то выбросить исключение
			throw e;
		}

		// 3.2. Если новая вершина создана
		if (newDepth == 1){
			// 3.1.1. Увеличить размер дерева
			treeSize++;
			// 3.1.2. Если цифра новой вершины уже существует, то выбросить исключение (ошибка COINCIDED_NUMBERS)
			if (setOfData.contains(newNode->data))
				throw error(COINCIDED_NUMBERS, treeNum == 1 ? 1 : 2, QString::number(newNode->data));
			// 3.1.3. Добавить новую вершину в дерево, его родитель будет вершина current
			setOfData.insert(newNode->data);
			if (root == NULL)
				root = newNode;
			else
				current->addChild(newNode);
			// 3.1.4. Установить указатель current на новую вершину
			current = newNode;
			cnt++;
		} else 
		// 3.3. Иначе вернуть указатель current на его родителя
		if (newDepth == -1){
			if (current == NULL){
				xmlStream.readNext();
				return;
			}
			current = current->parent;
			cnt--;
		}

		// Если глубина текущей вершины равен 0, это показывает, что текущее дерево было прочитать
		// затем закончить читать текущее дерево
		if (cnt == 0){
			xmlStream.readNext();
			break;
		}
	}

	// 4. Проверить количество вершин дерева. Если превышает максимальный размер, то выбросить исключение (ошибка OVER_SIZE)
	if (treeSize > MAX_TREE_SIZE)
		throw error(OVER_SIZE, treeNum == 1 ? 1 : 2, QString::number(treeSize));

	xmlStream.readNext();
	xmlStream.readNext();
}

/*!
* Считать данные из XML-файла и построить деревья
* \param[in] filename - имя входного файла
* \param[out] root1 - указатель на корень первого дерева
* \param[out] root2 - указатель на корень второго дерева
*/
void readXML(QString filename, node*& root1, node*& root2){
	QFile input(filename);
	
	// 1. Открыть XML файл с именем filename с режимом чтения. Если файл не может открыт, то выбросить исключение (ошибка COULD_NOT_OPEN_FILE) 
	if (!input.open(QFile::ReadOnly | QFile::Text))
		throw error(COULD_NOT_OPEN_FILE, 0, filename);

	QXmlStreamAttributes attr;

	// создать XML поток
	QXmlStreamReader xmlStream;
	xmlStream.setDevice(&input);
	xmlStream.readNext();
	xmlStream.readNext();
	xmlStream.readNext();
	
	// 2. Считать данные из XML-файла средствами библиотеки Qt методом потокового чтения с использованиемм класса QXmlStreamReader и при помощи функции readTree.
	try{
		readTree(xmlStream, root1, 1);
		readTree(xmlStream, root2, 2);
	} catch(error e){
		// 3. Если возникла ошибка, выбросить эту ошибку
		throw e;
	}
}

/*!
* Найти вершину в поддереве с корнем в вершине currentNode, которая содержит цифру data
* \param[in] currentNode - указатель на коренную вершину поддерева
* \param[in] data - цифра, которую надо найти
* \return - указатель на вершину, которая держит цифру data. Если не существует эта вершина, то вернуть NULL
*/
node* findNodeWithData(node* currentNode, int data){
	if (currentNode == NULL) return NULL;
	// 1. Если цифра в вершине currentNode равна data, то вернуть эту вершину
	if (currentNode->data == data) return currentNode;

	node* ret = NULL;
	// 2. Вызвать рекурсивно себя для всех дочерей вершины currentNode, до тех по пока не нашли результирующую вершину
	for (int i = 0; i < currentNode->children.size(); i++){
		ret = findNodeWithData(currentNode->children[i], data);
		if (ret != NULL) return ret;
	}
	// 3. Если вершина не найдена, то вернуть NULL
	return ret;
}

/*!
* Рассчитать максимальный размер общего поддерева с корнем в вершине с цифрой k, когда размеры общих поддеревьев с корнями в дочернях известны
* \param[in] list1 - массив дочерей вершины с цифрой k в первом дереве
* \param[in] list2 - массив дочерей вершины с цифрой k во втором дереве
* \param[in] size - массив размеров общих поддеревьев с корнями в дочерях вершины с цифрой k в первом дереве
* \param[in] rootList - массив корней максимальных общих поддеревьев, найдены в дочерях вершины с цифрой k в первом дереве
* \param[out] res - список дочерей, которые в общем дереве
* \return - максимальный размер общего дерева
*/
int computeMaxCommonSubTree(const QVector<node*>& list1, const QVector<node*>& list2, const QVector<int>& size, const QVector<node*>& rootList, QVector<node*>& res){
	// размер массив list1
	int m = list1.size();
	// размер массив list2
	int n = list2.size();
	// 1. Если массив list1 или list2 пустые, то вернуть 0
	if (m == 0 || n == 0){
		res.clear();
		return 0;
	}

	// 2. Динамическая программа
	//	  Пусть dp[i][j] – максимальный общий размер, если считать до i-ой дочерней в первом массиве и j-ой дочерней во втором массиве.
	//			2.1. Инициализация
	//				2.1.1. Создать массив dp[m + 1][n + 1].
	//				2.1.2. dp[i][0] = 0 (0 ≤ i ≤ m).
	//				2.1.3. dp[0][j] = 0 (0 ≤ j ≤ n).
	QVector<QVector<int> > dp(m + 1, QVector<int>(n + 1, 0));
	//			2.2. Произвести заполнение массива по следующей формуле:
	//				2.2.1. dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]).
	//				2.2.2. Если цифра i-ой дочери в первом массиве равна цифре j-ой дочери во втором массиве,
	//				то есть list1[i]->data == list2[j]->data, то dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + размер(a[i])).
	//				Где размер[i] - максимальные размеры поддерева с корнем в вершине, которая находится в i-ом месте, то есть size[i]

	// Для кождого элемента массива list1
	for (int i = 1; i <= m; i++){
		// Для кождого элемента массива list2
		for (int j = 1; j <= n; j++){

			dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

			// Если цифра i-ой дочери в первом массиве равна цифре j-ой дочери во втором массиве
			if (list1[i - 1]->data == list2[j - 1]->data)
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + size[i - 1]);
		}
	}
	//			2.3. Максимальный размер общего поддерева будет храниться в dp[m][n]
	int maxSize = dp[m][n];


	// 3. Сохранить все подвершины, которые находятся в общем дереве, в массив res с помощью массива dp.
	//    Элемент в правом нижнем углу показывает размер наибольшего общего поддерева. 
	//    Для построения искомой последовательности нужно пройти по таблице в обратную сторону.
	//			3.1. Создать массив res для сохранения дочерей.
	res.clear();
	//			3.2. Пройти от правого нижнего угла до левого верхнего угла массива dp
	int u = m, v = n;
	
	while (u > 0 && v > 0){
		// 3.2.1. Если элемент получен как максимум от двух префиксов – перейти в позицию с наибольшим префиксом. То есть перейти влево или вверх
		if (dp[u][v] == dp[u - 1][v]) u--;
		else if (dp[u][v] == dp[u][v - 1]) v--;
		else{
		// 3.2.2. Если элемент получен прибавлением единицы к соседу по диагонали – перейти в эту позицию и добавить соответствующую вершину в массив res.
			res.push_back(rootList[u - 1]);
			u--; v--;
		}
	}

	// 3.3. Перевернуть массив resList, чтобы получить последовательность дочерних вершин в максимальном общем поддереве с порядком.
	std::reverse(res.begin(), res.end());

	return maxSize;
}

/*!
* Рассчитать размер максимального общего поддерева 2 деревьев, у которой корень в вершине root1 в первом дереве и в вершине root2 во втором дереве. Цифры в 2 вершинах root1 и root2 одинаковые
* \param[in] root1 - указатель на вершину в первом дереве
* \param[in] root2 - указатель на вершину во втором дереве
* \param[out] commonRoot - указатель на корень максимального общего поддерева
* return - максимальный размер общего поддерева
*/
int computeCommonTree(node* root1, node* root2, node*& commonRoot){
	if (root1 == NULL || root2 == NULL || root1->data != root2->data){
		commonRoot = NULL;
		return 0;
	}
	// массив размеров корней общих поддеревьев в дочерях вершины root1 
	QVector<int> size;
	// массив корней общих поддеревьев в дочерях вершины root1
	QVector<node*> rootList;

	// 1. Для каждой дочери вершины root1 с цифрой data.
	for (int i = 0; i < root1->children.size(); i++){
		int c = 0;
		node* newRoot = NULL;
		// 1.1. Найти дочери вершины root2, так что у которых одинаковые цифры
		for (int j = 0; j < root2->children.size(); j++){
			// 1.2. Если эта дочь вершины root2 найдена, 
			if (root1->children[i]->data == root2->children[j]->data){
				// то вызвать рекурсивно эту же функцию, чтобы найти максимальный размер общего поддерева в найденных дочерях.
				c = computeCommonTree(root1->children[i], root2->children[j], newRoot);
				break;
			}
		}
		// 1.3. Если нет то общий размер равен 0
		// 1.4. Добавить рассчитанный размер в массив size и указатель на корень поддерева с максимальным размером в массив rootList
		size.push_back(c);
		rootList.push_back(newRoot);
	}

	// массив дочерьей в найболшем общем поддереве с корнем в вершине root1
	QVector<node*> childrenInMaxCommonTree;

	// 2. Рассчитать максимальный размер общего поддерева с функцией computeMaxCommonSubTree.
	// Максимальный размер общего поддерева равен результату функции computeMaxCommonSubTree плюс 1.
	int ret = computeMaxCommonSubTree(root1->children, root2->children, size, rootList, childrenInMaxCommonTree);

	commonRoot = new node(root1->data);

	// Сохранить список дочерей, которые находятся в общем поддереве, в массив list.
	for (int i = 0; i < childrenInMaxCommonTree.size(); i++)
		commonRoot->addChild(childrenInMaxCommonTree[i]);

	return ret + 1;
}

/*!
* Найти вершину, цифра, присвоенная которой присутствует в обоих деревьях, и размер общего поддерева в которой максимальный
* \param[in] root1 - указатель на корень первого дерева
* \param[in] root2 - указатель на корень второго дерева
* \param[out] retRoot - указатель на корень найденного максимального общего поддерева
* \return - максимальный размер общего поддерева двух деревьев
*/
int findRootMaxCommonTree(node* root1, node* root2, node*& retRoot){
	if (root1 == NULL || root2 == NULL){
		retRoot = NULL;
		return 0;
	}

	retRoot = NULL;
	int retSize = 0;

	// 1. Найти вершину sameData в дереве root2, которая содержит цифру, одинаковую с цифрой в вершине root1, с помощью функции findNodeWithData
	node* sameData = findNodeWithData(root2, root1->data);

	// 2. Если соответственная вершина найдена, то
	if (sameData != NULL){
		node* temp;
		// 2.1. Вызвать функцию computeCommonTree, чтобы найти максимальное общее поддерево с корнем в вершине, которая содержит цифру в вершинах root1 и sameData
		int c = computeCommonTree(root1, sameData, temp);
		// 2.2. Сохранить корень с максимальным размером
		if (c > retSize){
			retSize = c;
			retRoot = temp;
		}
	}

	// 3. Для каждой дочери вершины root1 с цифрой, которую не содержат дочери вершины sameData
	for (int i = 0; i < root1->children.size(); i++){
		node* temp = NULL;
		// флаг - дочери вершины sameData содержат ли цифрой, которую содержит i-ая дочь
		bool check = false;
		// Для каждой дочери вершины sameData 
		for (int j = 0; j < sameData->children.size(); j++)
			if (sameData->children[j]->data == root1->children[i]->data){
				// флаг - истинный
				check = true;
				break;
			}
		if (!check){
			// 3.1. Вызвать рекурсивно эту же функцию, чтобы найти максимальное общее поддерево с корнем в этих подвершинах.
			int c = findRootMaxCommonTree(root1->children[i], root2, temp);
			// 3.2. Сравнить с текущим максимальным размером. Если новый считающий размер больше, то сохранить корень общего поддерева с максимальным размером.
			if (c > retSize){
				retSize = c;
				retRoot = temp;
			}
		}
	}

	return retSize;
}

/*!
* Напечатать цифру вершины результирующего дерева на XML-файл
* \param[in] stream - покок записи на выводный XML-файл
* \param[in] currentNode - указатель на вершину результающего дерева, которую надо напечать
*/
void printNode(QXmlStreamWriter& stream, node* currentNode){
	if (currentNode == NULL) return;
	// 1. Печатать открывающий тег <node> с атрибутом value, равно цифре в вершине currentNode, с потоком stream
	stream.writeStartElement("node");
	stream.writeAttribute("value", QString::number(currentNode->data));
	// 2. Вызвать рекурсивно printNode для каждой из дочерей вершины currentNode
	for (int i = 0; i < currentNode->children.size(); i++)
		printNode(stream, currentNode->children[i]);
	stream.writeEndElement();
}

/*!
* Напечатать результируюющее дерево на XML-файл
* \param[in] filename - название выходного файла
* \param[in] root - указатель на корень результирующего дерева
*/
void printResult(QString filename, node* root){
	// 1. Открыть XML файл с именем filename с режимом записи.
	QFile output(filename);
	output.open(QIODevice::WriteOnly);
 
	// 2. Создать поток stream для записи на XML file
	QXmlStreamWriter xmlStream(&output);
	xmlStream.setAutoFormatting(true);
	// <?xml>
	xmlStream.writeStartDocument();

	// <test>
	xmlStream.writeStartElement("test");

	// 3. Напечатать размер максимального общего поддерева двух входных деревьев между парой тегов <result> и </result>
	xmlStream.writeStartElement("result");
	xmlStream.writeCharacters(root == NULL ? "0" : QString::number(root->size()));
	xmlStream.writeEndElement();

	// <tree>
	xmlStream.writeStartElement("tree");
	// 4. Вызвать функцию printNode с аргументами stream и root, чтобы напечатать каждую вершину общего поддерева
	printNode(xmlStream, root);

	xmlStream.writeEndElement();
	xmlStream.writeEndDocument();
}

void createTree(int numNode){
	srand(time(NULL));
	QFile output("in.xml");
	output.open(QIODevice::WriteOnly);
	QXmlStreamWriter xmlStream(&output);
	xmlStream.setAutoFormatting(true);
	xmlStream.writeStartDocument();

	xmlStream.writeStartElement("test");

	node* root1 = new node (1);
	for (int i = 2; i <= numNode; i++){
		root1->addChild(new node(i));
	}
 

	// <tree>
	xmlStream.writeStartElement("tree");
	xmlStream.writeAttribute("id", "1");
	printNode(xmlStream, root1);

	xmlStream.writeEndElement();

	node* root2 = new node (1);
	for (int i = 2; i <= numNode; i++){
		root2->addChild(new node(i));
	}

	xmlStream.writeStartElement("tree");
	xmlStream.writeAttribute("id", "2");
	printNode(xmlStream, root2);

	xmlStream.writeEndElement();
	xmlStream.writeEndDocument();

}