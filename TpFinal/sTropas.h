///////////////////////////////////////////////////////////
//  sTropas.h
//  Implementation of the Class sTropas
//  Created on:      01-jun.-2021 20:42:41
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_16832452_7150_48ab_8768_4A696FA2296E__INCLUDED_)
#define EA_16832452_7150_48ab_8768_4A696FA2296E__INCLUDED_

#include "cTropa.h"

class sTropas
{

public:
	sTropas();
	virtual ~sTropas();
	unsigned int Tropa1;
	unsigned int Tropa2;
	cTropa *m_cTropa;

private:
	unsigned int Tropa3;

};
#endif // !defined(EA_16832452_7150_48ab_8768_4A696FA2296E__INCLUDED_)
