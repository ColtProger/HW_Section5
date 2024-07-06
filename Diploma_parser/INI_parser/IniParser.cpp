#include"IniParser.h"

IniParser::IniParser(const std::string& filename)// �����������
    {
        this->parseFromFile(filename);
    };

   
void IniParser::parseFromFile(const std::string& filename) {
    std::ifstream ifs;
    std::string line;
    std::string section, key, value;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }


    while (std::getline(file, line)) {
        //������� ������� � ��������

        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        auto  pos = line.find(';');
        if (pos != std::string::npos) { line.erase(pos, line.length() + 1); }

        if (line.empty())
        {
            continue;
        }
        else {

            if (line[0] == '[' && line.back() == ']') {

                section = line.substr(line.find("[") + 1, line.find("]") - 1);
                if (section.empty()) {
                    throw std::runtime_error("Empty section name encountered.");
                }
                //std::cout << section << std::endl;

                continue;
            }
            auto  pos = line.find('=');

            key = line.substr(0, pos);
            value = line.substr(pos + 1, line.length());
            //std::cout << key << " " << value << std::endl;


        }

        ini_data[section][key] = value;
    }

    ifs.close();
};

   
  std::string IniParser::getString(const std::string& key, const std::string& section) const // ����� ��������� ��������
    {
        std::string result;
        auto it = ini_data.find(section);
        if (it != ini_data.end())
        {
            std::map<std::string, std::string> contain = ini_data.at(section);

            auto it = contain.find(key);
            if (it != contain.end())
            {
                result = contain[key]; //������� ������ 
            }
            else {
                std::map<std::string, std::string> contain = ini_data.at(section);
                std::cout << "May be you are looking for keys: ";
                for (auto const& elem : contain) { std::cout << elem.first << " "; }// ������� �� ������
                std::cout << "\n";
            }
        }
        else
        {
            std::cout << "Section " << section << " no exists or is empty." << std::endl;
        }

        return result;   
    };



