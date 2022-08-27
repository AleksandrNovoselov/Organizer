#include <iostream>
#include "Notebook.h"

void endWork(bool& flag)
{
	flag = false;
}

void menu(Notebook& list)
{
	bool flag{ true };
	char choice;
	while (flag)
	{
		
		cout << "> Что будем делать? <\n"
			<< "1 – добавить заметку\n"
			<< "2 – изменить заметку\n"
			<< "3 – удалить\n"
			<< "4 – поиск\n"
			<< "5 – показать всё\n"
			<< "6 - выход\n";

		cin >> choice;
		
		switch (choice)
		{
		case '1':
			list.add_note();
			break;
		case '2':
			list.edit_note();
			break;
		case '3':
			list.remove_note();
			break;
		case '4':
			list.find_note();
			break;
		case '5':
			list.print_all();
			break;
		case '6':
			endWork(flag);
			break;
		default:
			cout << "Неверный ввод\n";
			break;
		}
	}
};


int main()
{
	setlocale(0, "");
	Notebook notebook;
	string file;
	
	cout << ">>> Добро пожаловать <<<\n";
	//cout << "Введите имя файла для откытия\n";
	//cin >> file;
	file = "file.csv";
	
	notebook.readF(file);

	menu(notebook);

	notebook.writeF(file);

	return 0;

}

