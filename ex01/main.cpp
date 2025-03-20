#include "Serializer.hpp"

int main(int argc, char **argv){
    if (argc != 3){
        std::cout << "Usage: serializer <Name> <Surname>" << std::endl;
        return 1;
    }
    Data person;
    person.name = std::string(argv[1]);
    person.surname = std::string(argv[2]);
    std::cout << MAGENTA << "Before serialization" << RESET << std::endl;
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Surname: " << person.surname << YELLOW << BOLD << std::endl << std::endl;

    Data *personAfterSerialization = Serializer::deserialize(Serializer::serialize(&person));

    std::cout << RESET << MAGENTA << std::endl << "After serialization" << RESET << std::endl;
    std::cout << "Name: " << personAfterSerialization->name << std::endl;
    std::cout << "Surname: " << personAfterSerialization->surname << std::endl << std::endl;
}
