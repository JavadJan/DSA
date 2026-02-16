
#include "./Bigint.hpp"


Bigint::Bigint(long long int n)
{
	// convert integer to string
	std::ostringstream ss;
	ss << n;
	this->num = ss.str();
}

Bigint::Bigint(void){ this->num = "0";}
Bigint::~Bigint(){}
Bigint::Bigint(const Bigint& other)
{
	this->num = other.getNum();
}



void Bigint::setNum(std::string _num)
{
	this->num = _num;
}
const std::string Bigint::getNum() const{
	return this->num;
}

/* operator+ and operator++ */
Bigint::oper



std::ostream& operator<<(std::ostream& o, const Bigint& other)
{
	o << other.getNum();
	return o;
}