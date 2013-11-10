/**
 * \file	Studious.h
 *
 * \brief	Declares the studious class.
 */

#pragma once
#include "Trait.h"

/**
 * \class	Studious
 *
 * \brief	Studious.
 *
 * \author	Hamish Carrier
 * \date	10/11/2013
 */

class Studious : public Trait
{
public:

	/**
	 * \fn	Studious::Studious(void);
	 *
	 * \brief	Default constructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	Studious(void);

	/**
	 * \fn	Studious::~Studious(void);
	 *
	 * \brief	Destructor.
	 *
	 * \author	Hamish Carrier
	 * \date	10/11/2013
	 */

	~Studious(void);
};

