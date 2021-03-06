#ifndef TRACER_H
#define TRACER_H
#include <set>
#include <map>
#include <list>
#include "instlib.H"
#include "shadow.h"
#include "resultvector.h"

struct instructionLocationsData
{
	instructionLocationsData(){ip=0;execution_count=0;line_number=0;col_number=0;logged = FALSE;};
	vector<xed_reg_enum_t> registers_read;
	vector<xed_reg_enum_t> registers_written;
	long execution_count;
	list<long long> loopid;
	ADDRINT ip;
	string file_name;
	int line_number;
	int col_number;
	bool logged;
	string instruction;
	string rtn_name;
};

struct instructionDebugData
{
	string file_name;
	int line_number;
	int col_number;
	bool logged;
	string instruction;
};

// Globals
extern xed_decode_cache_t xedDecodeCache;
extern ShadowMemory shadowMemory;
extern map<ADDRINT,instructionLocationsData > instructionLocations;
extern FILE * trace;


VOID clearState();

#endif
