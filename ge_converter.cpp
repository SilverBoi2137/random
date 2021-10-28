#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::string input, subinput;
	short choice;
	std::cout<<"What type of input/output would you like?\n";
	std::cout<<"=================================================================\n";
	std::cout<<"[1] Console -> Console\n";
	std::cout<<"[2] Console -> File\n";
	std::cout<<"[3] File -> Console\n";
	std::cout<<"[4] File -> File\n";
	std::cout<<"=================================================================\n";
	std::cout<<"Your choice: ";
	std::cin>>choice;
	std::cout << "=================================================================\n";
	switch (choice) {
	case 1:
		std::cout << "From now on everything you write will be shortened\n";
		std::cout << "Input \"EXIT\" to stop the program\n";
		std::cout << "=================================================================\n";
		while (true) {
			std::getline(std::cin >> std::ws, input);
			if (input == "EXIT") break;
			input += " ";
			do {
				subinput = input.substr(0, input.find(" ") + 1);
				if (subinput.length() == 3 || subinput.length() == 2) subinput = ".";
				else subinput = subinput.substr(0, 3) + ".";
				std::cout << subinput << " ";
				input = input.substr(input.find(" ") + 1);
			} while (input.find(" ") != std::string::npos);
			std::cout << "\n";
		}
		break;
	case 2: 
	{
		std::ofstream output("output.txt");
		std::cout << "From now on everything you write will be shortened\n";
		std::cout << "Input \"EXIT\" to stop the program\n";
		std::cout << "=================================================================\n";
		while (true) {
			std::getline(std::cin >> std::ws, input);
			if (input == "EXIT") break;
			input += " ";
			do {
				subinput = input.substr(0, input.find(" ") + 1);
				if (subinput.length() == 3 || subinput.length() == 2) subinput = ".";
				else subinput = subinput.substr(0, 3) + ".";
				output << subinput << " ";
				input = input.substr(input.find(" ") + 1);
			} while (input.find(" ") != std::string::npos);
			output << "\n";
		}
		output.close();
		std::cout << "=================================================================\n";
		std::cout << "output.txt can be found in the same directory as the .exe file\n";
		break; 
	}
	case 3:
	{	
		std::cout << "Please input the name of the file you want to read the data from\n";
		std::cout << "Example: \"input.txt\" (no quotation marks, only .txt files)\n";
		std::cout << "=================================================================\n";
		std::string filename;
		std::cin.clear();
		std::getline(std::cin >> std::ws, filename);
		std::cout << "=================================================================\n";
		std::ifstream input;
		input.open(filename);
		if (!input.good()) {
			std::cout << "This file does not exist!\n";
			break;
		}
		std::string contents;
		while (std::getline(input, contents)) {
			contents += " ";
			do {
				subinput = contents.substr(0, contents.find(" ") + 1);
				if (subinput.length() == 3 || subinput.length() == 2) subinput = ".";
				else subinput = subinput.substr(0, 3) + ".";
				std::cout << subinput << " ";
				contents = contents.substr(contents.find(" ") + 1);
			} while (contents.find(" ") != std::string::npos);
			std::cout << "\n";
		}
		input.close();
		break;
	}
	case 4:
	{	
		std::cout << "Please input the name of the file you want to read the data from\n";
		std::cout << "Example: \"input.txt\" (no quotation marks, only .txt files)\n";
		std::cout << "=================================================================\n";
		std::string filename;
		std::cin.clear();
		std::getline(std::cin >> std::ws, filename);
		std::cout << "=================================================================\n";
		std::ifstream input;
		std::ofstream output("output.txt");
		input.open(filename);
		if (!input.good()) {
			std::cout << "This file does not exist!\n";
			break;
		}
		std::string contents;
		while (std::getline(input, contents)) {
			contents += " ";
			do {
				subinput = contents.substr(0, contents.find(" ") + 1);
				if (subinput.length() == 3 || subinput.length() == 2) subinput = ".";
				else subinput = subinput.substr(0, 3) + ".";
				output << subinput << " ";
				contents = contents.substr(contents.find(" ") + 1);
			} while (contents.find(" ") != std::string::npos);
			output << "\n";
		}
		input.close();
		output.close();
		std::cout << "output.txt can be found in the same directory as the program\n";
		break;
	}
	default:
		std::cout<<"\nYou are a horrible human being";
	}
	std::cout << "=================================================================\n";
	std::cout << "\nge\n";
	std::cin.get();
}

