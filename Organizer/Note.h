#pragma once
#include <iostream>
using namespace std;

class Note
{
public:
	string topic;
	string note;

	Note() {}
	Note(string topic, string note) :topic{topic}, note { note } {}
	
};

