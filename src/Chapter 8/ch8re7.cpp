
template <typename T>
static T larger(const T, const T);

void ch8re7(void)
{

}

template<typename T>
static T larger(const T x, const T y)
{
	return (x > y) ? x : y;
}