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
		cout << "������ �������� �����\n"
			<< "������� ����?\n"
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

	cout << "���� �������:\n";
	getline(cin, topic);
	getline(cin, topic);

	if (topic.length() == 0)
	{
		return;
	}

	cout << "�������� �������:\n";
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
	//�������� �� �������
}

void Notebook::remove_note()
{
	int number;
	
	try
	{
	cout << "������� ����� ��������� �������: ";
	cin >> number;

	if (number < 0 || number >= list.size())
		throw number;
	
		list.erase(list.begin() + number - 1);

	}
	catch (...)
	{
		cout << "������� ������ �����\n";
	}
}

void Notebook::find_note()
{
	string topic;

	cout << "������� ��� ��� ������: ";
	getline(cin, topic);
	getline(cin, topic);

	int id = find_place(topic);

	if (id == -1)
	{
		cout << "������� �� �������";
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
		cout << "������ ������ �����\n";
	}

	stream.close();
}


