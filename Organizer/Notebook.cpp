#include "Notebook.h"
#include <fstream>
#include <sstream>

void Notebook::readF(string file)
{
	auto stream = fstream(file, ios_base::in);

	if (stream.is_open())
	{
		auto delimetr = ';';
		string line;

		while (getline(stream, line))
		{
			stringstream streamLine(line);
			string topic;
			string note;
			

			getline(streamLine, topic, delimetr);
			getline(streamLine, note, delimetr);

			auto newNote = CreateNote(topic, note);
		
			list.push_back(newNote);
		}
	}
	else
	{
		char yes;
		cout << "Ошибка открытия файла\n"
			<< "Создать файл?\n"
			<< "y/ n\n";
		cin >> yes;
		if (yes == 'y')
			writeF(file);
	}

	stream.close();
}

void Notebook::add_note()
{
	string topic;
	string note;

	cout << "Тема заметки:\n";
	getline(cin, topic);
	getline(cin, topic);

	if (topic.length() == 0)
	{
		return;
	}

	cout << "Описание заметки:\n";
	getline(cin, note);

	auto newNote = CreateNote(topic, note);

	list.push_back(newNote);
	
}

Note Notebook::CreateNote(string topic, string note)
{
	return Note{ topic, note };
}

void Notebook::edit_note()
{
	//маленько не дописал
}

void Notebook::remove_note()
{
	int number;
	
	try
	{
	cout << "Введите номер удаляемой заметки: ";
	cin >> number;

	if (number < 0 || number >= list.size())
		throw number;
	
		list.erase(list.begin() + number - 1);

	}
	catch (...)
	{
		cout << "Неверно указан номер\n";
	}
}

void Notebook::find_note()
{
	string topic;

	cout << "Введите имя для поиска: ";
	getline(cin, topic);
	getline(cin, topic);

	int id = find_place(topic);

	if (id == -1)
	{
		cout << "заметка не найдена";
	}
	else
	{
		cout << id+1 << ") ";
		cout << list[id].topic << " : " << list[id].note << endl;
	}
	
}

int Notebook::find_place(string topic)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (!list[i].topic.compare(topic))
			return i;
	}
	return -1;
}


void Notebook::print_all()
{
	int i = 1;
	for (auto& note : list)
	{
		cout << i << ") ";
		cout << note.topic << " : " << note.note << endl;
		i++;
	}

	cout << endl;
}

void Notebook::writeF(string file)
{
	auto stream = fstream(file, ios_base::out);

	if (stream.is_open())
	{
		for (auto& note : list)
		{
			stream << note.topic << " ; " << note.note << endl;
		}
	}
	else
	{
		cout << "Ошибка записи файла\n";
	}

	stream.close();
}


