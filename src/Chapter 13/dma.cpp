// dma.cpp --dma class methods
#include "dma.h"
#include <cstring>
#pragma warning (disable : 4996) // strcpy() unsafe warning

// DMA_abc class abstract base class
DMA_abc::DMA_abc(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

DMA_abc::DMA_abc(const DMA_abc & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

DMA_abc::~DMA_abc()
{
    delete [] label;
}

DMA_abc & DMA_abc::operator=(const DMA_abc & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const DMA_abc & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}


// baseDMA methods
baseDMA::baseDMA(const char * l, int r)
	: DMA_abc(l, r)
{}

baseDMA::baseDMA(const baseDMA & rs)
	: DMA_abc(rs)
{}

baseDMA::~baseDMA()
{}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
	DMA_abc::operator=(rs);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	return os << (const DMA_abc &)rs;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : DMA_abc(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA_abc & rs)
    : DMA_abc(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const baseDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : DMA_abc(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA_abc & rs)
         : DMA_abc(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : DMA_abc(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    DMA_abc::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const DMA_abc &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
