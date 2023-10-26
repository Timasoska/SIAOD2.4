#include <iostream>
#include <Windows.h>
using namespace std;
//Узел дерева
class Tree {
public:
	struct node {
		//int key;
		int info;
		node* l, * r; //Левая и правая части дерева
	};

	node* T = NULL;

	void push(int a, node** t) { //Запись элемента в дерево
		//Если дерева нет, то формируем корень
		if ((*t) == NULL) {
			(*t) = new node; //Выделяем память
			(*t)->info = a; //Вносим значение узла
			(*t)->l = (*t)->r = NULL; //Очищаем память для следующего роста
			return;
		}
		//Дерево есть
		/*if (a > (*t)->info)
			push(a, &(*t)->r); //Если а больше текущего элемента, кладём его вправо
		else
			push(a, &(*t)->l); //Иначе - влево */
		//New
		else {
		if (tree_height((*t)->l) <= tree_height((*t)->r)) {
			push(a,&(*t)->l);
		}
		else {
			push(a, &(*t)->r);
		}
	}
	}

	void print(node* t, int u) {
		if (t == NULL) return;  //Если дерево пустое - выходим
		else {
			print(t->l, ++u); // Рекурсивно идём в левое поддерево
			for (int i = 0; i < u; ++i) cout << "|";
			cout << t->info << endl; //Показываем элемент
			u--;
		}
		print(t->r, ++u); //Рекурсивно идём в правое поддерево
	}
	void getrun() {
		run();
	}
private:
	
	int tree_height(node* t) {
		if (t == NULL) {
			return 0;
		}

		int left_height = tree_height(t->l);
		int right_height = tree_height(t->r);

		// Возвращаем максимум из высоты левого и правого поддерева, увеличенный на 1
		return max(left_height, right_height) + 1;
	}

	int path_length(node* t) {
		if (t == NULL) {
			return 0;
		}
		else {
			int left_length = path_length(t->l);
			int right_length = path_length(t->r);
			return left_length + right_length + 1;
		}
	}

	int getCount(node* t) { //Вычисляет  количество узлов
		if (t == NULL) {
			return 0;
		}
		else {
			return getCount(t->l) + getCount(t->r) + 1;
		}
	}

	double getAverage(node* t) { //Вычисляет среднее значение
		if (t == NULL) {
			return 0;
		}
		else {
			double sum = t->info;
			int count = 1;

			if (t->l != NULL) {
				sum += getAverage(t->l) * getCount(t->l);
				count += getCount(t->l);
			}

			if (t->r != NULL) {
				sum += getAverage(t->r) * getCount(t->r);
				count += getCount(t->r);
			}

			return sum / count;
		}
	}

	void run() {
		setlocale(LC_ALL, "RU");

		int n; //Кол-во узлов в дереве
		int s; //Число, которое передаем в дерево
		cout << "Enter number of elements" << endl;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cout << "Enter number" << endl;
			cin >> s;  //Считываем элементы
			push(s, &T);  //Каждый элемент сохраняем в дерево
		}
		cout << "Дерево: " << endl;
		print(T, 0);

		cout << "The height: " << tree_height(T) << endl;
		cout << "The path length: " << path_length(T) << endl;
		cout << "The average: " << getAverage(T) << endl;
	}
};
int main() {
	Tree tree;
	tree.getrun();
	return 0;
}
