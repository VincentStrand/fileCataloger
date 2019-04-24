#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "sha.h"
#include "atoh.h"
namespace fs = std::experimental::filesystem;

int main()
{
	sha256 hash;
	std::fstream output;
	output.open("mainDatabase.txt");
	std::string dir;
	std::cout << "Enter Full Directory Path: ";
	getline(std::cin, dir);
	std::cout << "This may take several minutes...";
	for (const auto & entry : fs::recursive_directory_iterator(dir))
	{
		std::string path = entry.path().string();
		hash.hashfile(path);
		std::string hashstr = std::string(atoh(hash.hash, 32), 64);
		output << entry.path() << "  |  " << hashstr << std::endl;
		
	}
	output.close();

	
}










