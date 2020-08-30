/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#ifndef DRIVER_BOARD_BME680DRV_H_
#define DRIVER_BOARD_BME680DRV_H_

#include "ext/bme680.h"
#include "i2c.h"

#include <string>

class CBme680Drv
{
public:
	CBme680Drv(const CI2C &i2c);
	virtual ~CBme680Drv();

	bool init();

	std::string getTemperature();
	std::string getPressure();
	std::string getHumidity();
	std::string getGas();

	bool read();

private:
	static int8_t writeInterface(void *ptrclass, uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
	static int8_t readInterface(void *ptrclass, uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
	int8_t writeTosensor(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);
	int8_t readFromsensor(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len);

	//std::string tostring()

private:
	static constexpr int  BME680_ADDR { 0x76 };
	struct bme680_dev m_sensor;
	struct bme680_field_data m_data;
	CI2C &m_pi2c;
};



#endif /* DRIVER_BOARD_BME680DRV_H_ */
