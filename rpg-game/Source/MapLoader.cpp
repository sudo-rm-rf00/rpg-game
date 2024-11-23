#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::Load(std::string filename)
{
	std::string line;
	std::ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (!isMapValid)
			{
				if (line == "[Map]")
				{
					isMapValid = true;
					continue;
				}
				else
				{
					std::cout << "rmap file is not valid!\n";
					break;
				}
			}

			if (isMapValid)
			{
				int count = line.find('=');
				std::string variable = line.substr(0, count);
				std::string value = line.substr(count + 1, line.length() - count);
				std::cout << variable << '\n';
				std::cout << value << '\n';
				break;
			}
		}

		file.close();
	}
	else
	{
		std::cout << "Unable to load open " << filename << '\n';
	}
}
