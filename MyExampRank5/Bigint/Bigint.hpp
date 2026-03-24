
#ifndef BIGINT_HPP
# define BIGINT_HPP
# include "iostream"
# include "sstream"

class Bigint
{
	private:
		std::string num;
	public:
		Bigint(void);
		~Bigint();
		Bigint(const Bigint& other);
		Bigint(long long int _num);
		Bigint& operator=(const Bigint& other);

		// obj+ and obj++(Bigint& other)
		Bigint operator+(const Bigint& other) const; // x + y
		Bigint& operator++(void); // ++x
		const Bigint operator++(int); // x++
		Bigint& operator+=(const Bigint& other); // x+= y;

		/* shifts */
		Bigint operator<<(int num) const;
		//Bigint operator>>(int num) const;
		Bigint& operator<<=( int num); // x = x*10^num
		Bigint& operator>>=(const Bigint& b); // x = x/10^num

		/* comparsion operator */
		bool operator>(const Bigint& b);
		bool operator<(const Bigint& b);
		bool operator>=(const Bigint& b);
		bool operator<=(const Bigint& b);
		bool operator==(const Bigint& b);
		bool operator!=(const Bigint& b);
		/* getter and setter */
		const std::string &getNum() const;
		void setNum(const std::string _num);

		// utils method
		void addition(const std::string &_num);
		void shiftLeft(int num);
		void shiftRight(int num);
		long long int to_int(std::string num);
};

std::ostream& operator<<(std::ostream &o, const Bigint& other);


#endif
