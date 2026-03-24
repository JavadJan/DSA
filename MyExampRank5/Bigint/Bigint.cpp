
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
Bigint& Bigint::operator=(const Bigint& other)
{
	if(this != &other)
		this->setNum(other.getNum());
	return (*this);
}

long long int Bigint::to_int(std::string num)
{
	long long int n = 0;
	for (size_t i = 0; i < num.size(); i++)
	{
		n = n * 10 + (num[i] - '0');
	}
	return n;
}
void Bigint::setNum(std::string n)
{
	this->num = n;
}
const std::string& Bigint::getNum() const{
	return this->num;
}

/* operator+ and operator++ */
Bigint Bigint::operator+(const Bigint& other) const // X + y
{
	Bigint res(*this);
	res.addition(other.getNum());
	return (res);
}

Bigint &Bigint::operator++()
{
	addition("1");
	return *this;
}

// ++ postfix --------------------------------------------------
const Bigint Bigint::operator++(int)
{
	Bigint tmp(*this);
	addition("1");
	return tmp;
}
// =+ ----------------
Bigint& Bigint::operator+=(const Bigint& other)
{
	//Bigint res(*this);
	addition(other.getNum()); // add *this =+ other
	return (*this);
}
void Bigint::addition(const std::string &_num)
{
    std::string a = _num;
    std::string b = num;

    // pad shorter string
	// 99 => 0099
    while (a.size() < b.size())
		a.insert(0, "0");
    while (b.size() < a.size())
		b.insert(0, "0");

    int carry = 0;
    std::string res(a.size(), '0'); // init
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10; // 12 / 10 = 1
        res[i] = char('0' + (sum % 10)); // add 2
    }

    if (carry)
        res.insert(0, "1");

    this->num = res;
}

Bigint Bigint::operator<<(int n) const
{
	Bigint shifted(*this);
	shifted.shiftLeft(n); 
	return (shifted);
}
//Bigint Bigint::operator>>(int n) const
//{
//	Bigint shift(*this);
//	shift.shiftRight(n);
//	return (shift);
//}
Bigint& Bigint::operator<<=(int n)
{
	this->shiftLeft(n);
	return *this;
}
Bigint& Bigint::operator>>=(const Bigint& b)
{
	std::string s = b.getNum();
	//long long shift = 0;
	//for (size_t i = 0; i < s.size(); i++)
	//{
	//	shift = (shift * 10) + s[i] - '0';
	//}
	long long int shift = to_int(s);
	this->shiftRight(shift);
	return (*this);
}
// 10 << 4 => 100000
void Bigint::shiftLeft(int num)
{
	std::string res = this->getNum();
	if (num > 0)
		res.append(static_cast<size_t>(num), '0');
	this->setNum(res);
}

void Bigint::shiftRight(int n)
{
	//std::string res = this->getNum();
	int len = this->num.length() - 1;

	this->num.erase(len - n, n);
}


/* Coparsion operator: <, >, <=, >=, ==, !=,  */
bool Bigint::operator<(const Bigint& other)
{
	//long long int a = this->to_int(this->getNum());
	//long long int b = this->to_int(other.getNum());
	if (this->getNum().compare(other.getNum()) > 0)
		return true;
	return false;
	//return (this->getNum() < other.getNum());
}
bool Bigint::operator>(const Bigint& other)
{
	//long long int a = this->to_int(this->getNum());
	//long long int b = this->to_int(other.getNum());
	return (!(*this < other));
}
bool Bigint::operator>=(const Bigint& other)
{
	//long long int a = this->to_int(this->getNum());
	//long long int b = this->to_int(other.getNum());
	
	return (!(*this <= other));
}
bool Bigint::operator<=(const Bigint& other)
{
	//long long int a = this->to_int(this->getNum());
	//long long int b = this->to_int(other.getNum());
	if (*this == other)
		return true;
	return (*this < other);
}
bool Bigint::operator==(const Bigint& other)
{
	//long long int a = this->to_int(this->getNum());
	//long long int b = this->to_int(other.getNum());
	if (this->getNum().compare(other.getNum()) == 0)
		return true;
	return false;
	//return (a == b);
}
bool Bigint::operator!=(const Bigint& other)
{
	//long long int a = this->to_int(this->getNum());
	//long long int b = this->to_int(other.getNum());

	return (!(*this == other));
}


std::ostream& operator<<(std::ostream& o, const Bigint& other)
{
	o << other.getNum();
	return o;
}