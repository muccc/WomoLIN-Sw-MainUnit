/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef INC_IGPIO_HPP_
#define INC_IGPIO_HPP_

namespace mainunit::driver
{

class IGPIO
{
public:
	virtual ~IGPIO() {};
	virtual void setHigh() = 0;
	virtual void setLow() = 0;
	virtual void toggle() = 0;
	virtual bool getState() = 0;
};

}

#endif /* INC_IGPIO_HPP_ */
