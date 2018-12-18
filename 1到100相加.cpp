class csum
{
public:
	csum()
	{
		_count++;
		_sum += _count;
	}
	static size_t getsum()
	{
		return _sum;
	}
	static size_t resetsum()
	{
		_sum = 0;
		_count = 0;
	}


private:
	static size_t _sum;
	static size_t _count;
};

size_t csum::_sum = 0;
size_t csum::_count = 0;

size_t sum(size_t n)
{
	csum::resetsum();
	csum s[100];
	return csum::getsum();
}