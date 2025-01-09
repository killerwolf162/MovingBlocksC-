#include "Block.h"
#include <iostream>
#include <utility>

Block::Block(int size, std::string name) : name(name), size(size) {
	std::cout << "CTOR Block '" << name << "' @" << this << std::endl;
	this->data = new int[size];
}

Block::~Block() noexcept {
	std::cout << "DTOR Block '" << this->name << "' @" << this << std::endl;
	delete[] data;
}

Block::Block(const Block& other) : name(other.name), size(other.size) {
	std::cout << "CCTOR Block '" << other.name << "' @" << this << std::endl;
	this->data = new int[size];

	std::copy(other.data, other.data + other.size, data);
}

Block& Block::operator=(const Block& other) {
	std::cout << "Assignment opr Block '" << this->name << "' @" << this << std::endl;
	if (this == &other) return *this;

	this->name = other.name;
	this->size = other.size;
	this->data = new int[size];
	std::copy(other.data, other.data + other.size, data);
	return *this;
}



#ifdef MOVESEMANTICS

// move-constructor
Block::Block(Block&& other) noexcept {
	std::cout << "MCTOR from Block '" << other.name << "' @" << &other << " to Block @" << this << std::endl;
	name = std::move(other.name);
	data = other.data;
	size = other.size;

	// 'reset' 't originele object
	other.name = "(nodata: has been moved)";
	other.size = 0;
	other.data = nullptr;
}

//TODO: move - assignment operator
Block& Block::operator=(Block&& other) noexcept
{
	std::cout << "Move Assignment opr Block '" << this->name << "' @" << this << std::endl;
	if (this == &other) return *this;

	delete[] data;

	data = other.data;
	name = std::move(other.name);
	size = other.size;

	other.data = nullptr;
	other.size = 0;
	other.name = "(nodata: has been moved)";

	return *this;
}


#endif

std::ostream& operator<<(std::ostream& os, const Block& block) {
	os << "Block @" << &block << " name:" << block.name << " size:" << block.size;
	return os;
}
