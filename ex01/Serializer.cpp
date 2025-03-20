#include "Serializer.hpp"

// Orthodox Canonical Form
Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) { *this = src; }

Serializer &Serializer::operator=(Serializer const & src) {
	if (this != &src) {}
	return (*this);
}
Serializer::~Serializer() {}

//////////////////////////////////////////////////////////////////////////////////

uintptr_t Serializer::serialize(Data* ptr){
    std::cout << "Serializing information" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    std::cout << "Deserializing information" << std::endl;
    return reinterpret_cast<Data *>(raw);
}