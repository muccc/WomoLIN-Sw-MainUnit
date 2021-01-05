/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Tilo Seeck <tiloseeck@web.de> */

#include "bme680drv.h"

namespace mainunit::driver
{

CBme680Drv::CBme680Drv(const CI2C &i2c) : m_pi2c(const_cast<CI2C&>(i2c))
{
	m_sensor.dev_id = BME680_ADDR;
	m_sensor.intf = BME680_I2C_INTF;
	m_sensor.read = &CBme680Drv::readInterface;
	m_sensor.write = &CBme680Drv::writeInterface;
	m_sensor.ptrclass = this;
	m_sensor.delay_ms = HAL_Delay;
}

CBme680Drv::~CBme680Drv()
{

}

bool CBme680Drv::init()
{
	int8_t ret = BME680_OK;

	ret = bme680_init(&m_sensor);
	if(ret != BME680_OK)
		return false;

	return true;
}

bool CBme680Drv::read()
{
	int8_t ret = BME680_OK;

	/* Select the power mode */
	/* Must be set before writing the sensor configuration */
	m_sensor.power_mode = BME680_FORCED_MODE;

	uint16_t settings_sel;

	/* Set the temperature, pressure and humidity & filter settings */
	m_sensor.tph_sett.os_hum = BME680_OS_1X;
	m_sensor.tph_sett.os_pres = BME680_OS_16X;
	m_sensor.tph_sett.os_temp = BME680_OS_2X;

	settings_sel = BME680_OST_SEL | BME680_OSP_SEL | BME680_OSH_SEL | BME680_GAS_SENSOR_SEL;

	uint16_t profile_dur = 0;
	bme680_get_profile_dur(&profile_dur, &m_sensor);

	ret = bme680_set_sensor_settings(settings_sel, &m_sensor);
	if (ret == BME680_OK) {

		ret = bme680_set_sensor_mode(&m_sensor); /* Trigger a measurement */

		m_sensor.delay_ms(profile_dur); /* Wait for the measurement to complete */

		ret = bme680_get_sensor_data(&m_data, &m_sensor);
	}

	if (ret != BME680_OK)
		return false;

	return true;
}

std::string CBme680Drv::getTemperature()
{
	std::string ret = std::to_string(m_data.temperature / 100) + "." + std::to_string(m_data.temperature % 100);
	return ret;
}

std::string CBme680Drv::getPressure()
{
	std::string ret = std::to_string(m_data.pressure);
	return ret;
}

std::string CBme680Drv::getHumidity()
{
	std::string ret = std::to_string(m_data.humidity / 1000) + "." + std::to_string(m_data.humidity % 1000);
	return ret;
}

std::string CBme680Drv::getGas()
{
	return std::to_string(m_data.gas_resistance);
}

int8_t CBme680Drv::writeTosensor(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	std::vector<uint8_t> towrite;
	towrite.push_back(reg_addr);

	for(uint16_t i = 0; i < len; i++) {
		towrite.push_back(reg_data[i]);
	}

	m_pi2c.write(dev_id, towrite);

	//return (len + 1);
	return 0;
}

int8_t CBme680Drv::readFromsensor(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	std::vector<uint8_t> toread;

	toread.push_back(reg_addr);

	// Read data.
	m_pi2c.read(dev_id, toread, len);

	for(size_t i = 0; i < toread.size(); i++) {
		reg_data[i] = toread[i];
	}

	//return toread.size();
	return 0;
}

int8_t CBme680Drv::writeInterface(void *ptrclass, uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	CBme680Drv *sensor = (CBme680Drv *)ptrclass;

	return sensor->writeTosensor(dev_id, reg_addr, reg_data, len);
}

int8_t CBme680Drv::readInterface(void *ptrclass, uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
	CBme680Drv *sensor = (CBme680Drv *)ptrclass;

	return sensor->readFromsensor(dev_id, reg_addr, reg_data, len);
}

}

