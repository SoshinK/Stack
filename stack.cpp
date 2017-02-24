#include <iostream>
#include <cstdlib>
#include <fstream>
#define CAPACITY 100
#define ASSERT_OK 	if(!ok()) \
						{ \
						dump(); \
						std::exit(1); \
						}

typedef double dtype;

class Stack
	{
	public:
		Stack();
		~Stack();
		bool ok() const;
		bool dump() const;

		size_t ssize() const;
		bool print(std::ostream & out) const;

		bool push(dtype val);
		dtype pop();
		dtype peek() const;
	private:
		dtype data_[CAPACITY];
		size_t size_;
	};

Stack::Stack():
	size_(0)
	{
	ASSERT_OK;
	}

Stack::~Stack() {} //???

bool Stack::ok() const
	{
	return((data_ && size_ < CAPACITY) || ((!data_ && !size_)));
	}

bool Stack::dump() const
	{
	std::cout << "\n***Dump has been called***\n" << __DATE__ << ' ' << __TIME__ << '\n';
	std::cout << "CAPACITY = " << CAPACITY << '\n';
	std::cout << "size_ = " << size_ << '\n';
	std::cout << "data_ = " << data_ << '\n';
	std::cout << "----------\n";
	std::cout << "Content:\n";
	size_t t;
	for(t = 0; t < size_; ++t)
		{
		std::cout << data_[t] << '\n';
		}
	std::cout << "----------\n";
	}

size_t Stack::ssize() const
	{
	return size_;
	}

bool Stack::push(dtype val)
	{
	ASSERT_OK;
	this->data_[this->size_++] = val;
	ASSERT_OK;
	return true;
	}

bool Stack::print(std::ostream & out) const
	{
	if(out.fail())
		{
		std::cout << "***Cant print content***\n";
		dump();
		std::exit(2);
		}
	if(ok())
		{
		int i;
		for(i = 0; i <size_; ++i)
			{
			out << data_[i] << '\n';
			}
		return true;
		}
	out << "***Cant print content. Stack if full or broken***\n";
	return false;
	}

dtype Stack::pop()
	{
	ASSERT_OK;
	if(size_ == 0)
		{
		std::cout << "***Stack is empty***\n";
		return 0;
		}
	return data_[--size_];
	}

dtype Stack::peek() const
	{
	ASSERT_OK;
	if(size_ == 0)
		{
		std::cout << "***Stack is empty***\n";
		return 0;
		}
	return data_[size_ - 1];
	}

int main()
	{
	std::ofstream f("stack content.txt");
	Stack s;
	if(s.ok())
		{
		std::cout << s.ssize() << '\n';
		}
	s.push(6.789);
	s.push(9990);
	s.push(-13.7890);
	std::cout << "Size:" << s.ssize() << '\n';
	s.dump();
	std::cout << s.peek() << '\n';
	std::cout << s.pop() << '\n';
	s.dump();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.dump();
	int i;
	for(i = 0; i < 99; ++i)
		{
		s.push(i * i);
		}
	s.print(std::cout);
	s.print(f);
	std::cout << s.pop() << '\n';
	return 0;
	}
