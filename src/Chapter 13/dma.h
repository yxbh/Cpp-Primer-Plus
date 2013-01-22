// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA_abc
{
private:
	char * label;
	int rating;
public:
	DMA_abc(const char * l = "null", int r = 0);
	DMA_abc(const DMA_abc & rs);
	virtual ~DMA_abc();
	virtual void View(void) const = 0;
	virtual DMA_abc & operator=(const DMA_abc & rs) = 0;
	friend std::ostream & operator<<(std::ostream & os,
		const DMA_abc & rs);
};


//  Base Class Using DMA
class baseDMA : public DMA_abc
{
private:    
public:
	baseDMA(const char * l = "null", int r = 0);
	baseDMA(const baseDMA & rs);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, 
		const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public DMA_abc
{
private:
	enum { COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null",
		int r = 0);
	lacksDMA(const char * c, const DMA_abc & rs);
	friend std::ostream & operator<<(std::ostream & os, 
		const lacksDMA & rs);
};

// derived class with DMA
class hasDMA :public DMA_abc
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null",
		int r = 0);
	hasDMA(const char * s, const DMA_abc & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & rs);  
	friend std::ostream & operator<<(std::ostream & os, 
		const hasDMA & rs);
};

#endif
