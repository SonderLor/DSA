#include "BinaryTreeSearch.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BinaryTreeSearch tree;
	int choise = -1;
	std::string name;
	std::cout << "Выберите действие:\n1) Добавить узел\n2) Удалить узел\n3) Поиск узла\n4) Обратный обход\n5) Симметричный обход\n6) Обход в ширину\n7) Уровень узла\n8) Высота дерева\n0) Выход.\n";
	while (choise != 0) {
		std::cin >> choise;
		switch (choise)
		{
		case 0:
			std::cout << "Программа завершена.\n";
			return 0;
		case 1:
			std::cout << "Введите имя для нового узла: ";
			std::cin >> name;
			tree.addNode(name);
			break;
		case 2:
			std::cout << "Введите имя удаляемого узла: ";
			std::cin >> name;
			tree.deleteNode(name);
			break;
		case 3:
			std::cout << "Введите имя искомого узла: ";
			std::cin >> name;
			tree.searchNode(name);
			break;
		case 4:
			std::cout << "Структура дерева при обратном обходе: ";
			tree.reverseBypass(tree.getRoot());
			std::cout << "\n";
			break;
		case 5:
			std::cout << "Структура дерева при симметричном обходе: ";
			tree.simmetricalBypass(tree.getRoot());
			std::cout << "\n";
			break;
		case 6:
			std::cout << "Структура дерева при обходе в ширину: ";
			tree.widthBypass();
			std::cout << "\n";
			break;
		case 7:
			std::cout << "Введите имя узла: ";
			std::cin >> name;
			std::cout << "Высота этого узла = " << tree.getNodeLevel(name) << "\n";
			break;
		case 8:
			std::cout << "Высота дерева = " << tree.getHeight() << "\n";
			break;
		default:
			std::cout << "Неверный ввод\n";
			break;
		}
	}
	return 0;
}