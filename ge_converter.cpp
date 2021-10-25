#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::string input, subinput;
	std::ofstream output("ge.txt");
	short choice;
	std::cout<<"Would you like the output be in console or in a seperate file?\n";
	std::cout<<"==============================================================\n";
	std::cout<<"[1] Console\n";
	std::cout<<"[2] Seperate file\n";
	std::cout<<"==============================================================\n";
	std::cout<<"Your choice: ";
	std::cin>>choice;
	std::cout << "==============================================================\n";
	std::cout << "From now on everything you write will be shortened\n";
	switch (choice) {
	case 1:
		std::cout << "Input \"EXIT\" to stop the program\n";
		std::cout << "==============================================================\n";
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
		std::cout << "ge.txt can be found in the same directory as the program\n";
		std::cout << "Input \"EXIT\" to stop the program\n";
		std::cout << "==============================================================\n";
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
		break;
	default:
		std::cout<<"\nYou are a horrible human being";
	}
	std::cout << "\nge\n";
	std::cin.get();
}

