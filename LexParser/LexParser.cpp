#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "You have not specified a file to parse." << endl;
		cout << "Usage: LexParser \"<filename>\"" << endl;

		return -1;
	}

	string dir;
	dir = argv[1];

	cout << dir;

	return 0;
}