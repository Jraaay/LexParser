#include "LexParser.h"

int main(int argc, char *argv[])
{
	clock_t start, end;
	start = clock();
	if (argc < 2)
	{
		cout << endl
			 << "Usage: LexParser <file_to_parse_name> [outfile_name]" << endl
			 << endl;

		return -1;
	}

	string dir;
	dir = argv[1];

	parser myParser(dir);

	if (myParser.file.fail())
	{
		cout << endl
			 << "Error: File to parse open failed." << endl;
		cout << "Usage: LexParser <file_to_parse_name> [outfile_name]" << endl
			 << endl;
		return -1;
	}
	ostringstream outStream;
	outStream << "Tokens:" << endl;
	outStream << myParser.parseFile();
	outStream << endl
			  << "Info:" << endl
			  << "Char count:  " << myParser.countChar() << endl
			  << "Line count:  "
			  << myParser.countLine() << endl;
	outStream << "Error count: "
			  << myParser.errorCount << endl;
	if (argc > 2)
	{
		ofstream outFile;
		string outDir;
		outDir = argv[2];
		outFile.open(outDir);
		if (outFile.fail())
		{
			cout << endl
				 << "Error: Outfile open failed." << endl;
			cout << "Usage: LexParser <file_to_parse_name> [outfile_name]" << endl
				 << endl;
			return -1;
		}
		end = clock();
		outFile << outStream.str() << endl
				<< "Parsing time: " << end - start << "ms" << endl;
	}
	else
	{
		end = clock();
		cout << outStream.str() << endl
			 << "Parsing time: " << end - start << "ms" << endl;
	}
	return 0;
}