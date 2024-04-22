#include <iostream>
#include <fstream>

int	main(int ac, char*av[]) {
	std::ifstream ifs;
	std::ofstream ofs;
	std::string infile;
	std::string outfile;
	std::string line;
	std::string s1;
	std::string s2;

	int s1_len;
	int s2_len;

	if (ac != 4) {
		std::cout << "arguments error" << std::endl;
		return (1);
	}

	infile = av[1];
	s1 = av[2];
	s2 = av[3];
	s1_len = s1.length();
	s2_len = s2.length();
	if (infile.length() == 0 || s1_len == 0 || s2_len == 0) {
		std::cout << "arguments error" << std::endl;
		return (1);
	}

	ifs.open(infile.c_str());
	ofs.open((infile + ".replace").c_str());
	if (ifs.fail() || ofs.fail()) {
		std::cout << "file error" << std::endl;
		return (1);
	}

	while (true) {
		std::getline(ifs, line);
		size_t pos = 0;

		while (true)
		{
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break;
			line.erase(pos, s1_len);
			line.insert(pos, s2);
			pos += s2_len;
		}
		ofs << line;
		if (ifs.eof())
			break;
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();

}