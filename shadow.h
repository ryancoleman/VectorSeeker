#ifndef SHADOW_H
#define SHADOW_H

#include "pin.H"
#include "instlib.H"
#include <map>

const int cacheLineSize = 128;

class CacheLine
{
private:
	enum elementSizes {one, two, four};
	elementSizes elementSize;
	void *memory;
public:
	//read
	long read(unsigned int offset);
	//write
	void write(unsigned int offset, long value);
	//
	CacheLine();
	~CacheLine();
};

class ShadowMemory
{
private:
	long shadowRegisters[XED_REG_LAST]; // Register Memory
//	map<ADDRINT,long> shadowMemory;
	map<ADDRINT,CacheLine> cacheShadowMemory;
public:
	//Access Memory
	long readMem(ADDRINT address);
	//Access Register
	long readReg(size_t reg);
	//Set Memory
	void writeMem(ADDRINT address, long depth);
	//Set Register
	void writeReg(size_t reg, long depth);
	//Reset Region
	
	//Clear
	void clear();
};

#endif
