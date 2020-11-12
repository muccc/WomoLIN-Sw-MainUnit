/*
 * powerswitch.hpp
 *
 *  Created on: 01.11.2020
 *      Author: tseeck
 */

#ifndef INC_HSSDRV_HPP_
#define INC_HSSDRV_HPP_

#include "gpio.h"

namespace mainunit::driver
{

enum class HssNr
{
	HSSSWITCH1 = 0x01,
	HSSSWITCH2 = 0x02,
	HSSSWITCH3 = 0x04,
	HSSSWITCH4 = 0x08,
};

class CHSSDrv
{
public:
	CHSSDrv(const GPIO &hssen1, const GPIO &hssen2, const GPIO &hssen3, const GPIO &hssen4);
	virtual ~CHSSDrv();

	void set(HssNr number, bool state);
	const bool get(HssNr number);

private:
	GPIO &m_hssen1;
	GPIO &m_hssen2;
	GPIO &m_hssen3;
	GPIO &m_hssen4;
};

}

#endif /* INC_HSSDRV_HPP_ */
