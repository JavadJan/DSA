
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

		// obj+ and obj++(Bigint& other)
		
		/* getter and setter */
		const std::string getNum() const;
		void setNum(const std::string _num);
};

std::ostream& operator<<(std::ostream &o, const Bigint& other);


#endif
