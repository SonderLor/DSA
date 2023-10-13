#include "BinaryTreeSearch.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BinaryTreeSearch tree;
	int choise = -1;
	std::string name;
	std::cout << "�������� ��������:\n1) �������� ����\n2) ������� ����\n3) ����� ����\n4) �������� �����\n5) ������������ �����\n6) ����� � ������\n7) ������� ����\n8) ������ ������\n0) �����.\n";
	while (choise != 0) {
		std::cin >> choise;
		switch (choise)
		{
		case 0:
			std::cout << "��������� ���������.\n";
			return 0;
		case 1:
			std::cout << "������� ��� ��� ������ ����: ";
			std::cin >> name;
			tree.addNode(name);
			break;
		case 2:
			std::cout << "������� ��� ���������� ����: ";
			std::cin >> name;
			tree.deleteNode(name);
			break;
		case 3:
			std::cout << "������� ��� �������� ����: ";
			std::cin >> name;
			tree.searchNode(name);
			break;
		case 4:
			std::cout << "��������� ������ ��� �������� ������: ";
			tree.reverseBypass(tree.getRoot());
			std::cout << "\n";
			break;
		case 5:
			std::cout << "��������� ������ ��� ������������ ������: ";
			tree.simmetricalBypass(tree.getRoot());
			std::cout << "\n";
			break;
		case 6:
			std::cout << "��������� ������ ��� ������ � ������: ";
			tree.widthBypass();
			std::cout << "\n";
			break;
		case 7:
			std::cout << "������� ��� ����: ";
			std::cin >> name;
			std::cout << "������ ����� ���� = " << tree.getNodeLevel(name) << "\n";
			break;
		case 8:
			std::cout << "������ ������ = " << tree.getHeight() << "\n";
			break;
		default:
			std::cout << "�������� ����\n";
			break;
		}
	}
	return 0;
}