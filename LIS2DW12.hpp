/*
 * name:        LIS2DW12
 * description: MEMS digital output motion sensor: high-performance ultra-low-power 3-axis 'femto' accelerometer
 * manuf:       ST Microelectronics
 * version:     Version 0.1
 * url:         http://www.st.com/resource/en/datasheet/lis2dw12.pdf
 * date:        2018-02-05
 * author       https://chisl.io/
 * file:        LIS2DW12.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class LIS2DW12_Base and implement the read and write functions! */

/* LIS2DW12: MEMS digital output motion sensor: high-performance ultra-low-power 3-axis 'femto' accelerometer */
class LIS2DW12_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_T                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_T:
	 * 8.1-2
	 * Temperature output register in 12-bit resolution (r).
	 */
	struct OUT_T
	{
		static const uint16_t __address = 13;
		
		/* Bits TEMP: */
		/*
		 * The temperature sensor output. Sensitivity = 16 LSB/°C.
		 * This forms the output value expressed as a 16-bit word in 2's complement.
		 */
		struct TEMP
		{
			/* MODE r */
			static const uint16_t mask = 0b0000111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11]
		};
	};
	
	/* Set register OUT_T */
	void setOUT_T(uint16_t value)
	{
		write(OUT_T::__address, value, 16);
	}
	
	/* Get register OUT_T */
	uint16_t getOUT_T()
	{
		return read16(OUT_T::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG WHO_AM_I                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG WHO_AM_I:
	 * 8.3
	 * Who_AM_I register (r). This register is a read-only register. Its value is fixed at 44h.
	 */
	struct WHO_AM_I
	{
		static const uint16_t __address = 15;
		
		/* Bits WHO_AM_I: */
		struct WHO_AM_I_
		{
			/* MODE r */
			static const uint8_t dflt = 0b01000100; // 8'b1000100
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register WHO_AM_I */
	void setWHO_AM_I(uint8_t value)
	{
		write(WHO_AM_I::__address, value, 8);
	}
	
	/* Get register WHO_AM_I */
	uint8_t getWHO_AM_I()
	{
		return read8(WHO_AM_I::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG CTRL1                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL1:
	 * Control register 1
	 */
	struct CTRL1
	{
		static const uint16_t __address = 32;
		
		/* Bits ODR: */
		/*
		 * Output data rate and mode selection (see Table 30)
		 * ODR is used to set the power mode and ODR selection. The following table lists the bit
		 * settings for power-down mode and each available frequency.
		 */
		struct ODR
		{
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
			static const uint8_t POWER_DOWN = 0b000; // 
			static const uint8_t MODE_12_5__1_6 = 0b001; // High-Performance / Low-Power mode 12.5/1.6 Hz
			static const uint8_t MODE_12_5 = 0b010; // High-Performance / Low-Power mode 12.5 Hz
			static const uint8_t MODE_25 = 0b011; // High-Performance / Low-Power mode 25 Hz
			static const uint8_t MODE_50 = 0b100; // High-Performance / Low-Power mode 50 Hz
			static const uint8_t MODE_100 = 0b101; // High-Performance / Low-Power mode 100 Hz
			static const uint8_t MODE_200 = 0b110; // High-Performance / Low-Power mode 200 Hz
			static const uint8_t MODE_400__200 = 0b111; // High-Performance / Low-Power mode 400/200 Hz
			static const uint8_t MODE_800__200 = 0b1000; // High-Performance / Low-Power mode 800/200 Hz
			static const uint8_t MODE_1600__200 = 0b1001; // High-Performance / Low-Power mode 1600/200 Hz
		};
		/* Bits MODE: */
		/* Mode selection (see Table 31)   */
		struct MODE
		{
			static const uint8_t mask = 0b00001100; // [2,3]
			static const uint8_t LOW_POWER = 0b00; // Low-Power Mode (12/14-bit resolution)
			static const uint8_t HIGH_PERF = 0b01; // High-Performance Mode (14-bit resolution)
			static const uint8_t SINGLE_DATA = 0b10; // Single data conversion on demand mode (12/14-bit resolution)
			static const uint8_t unused_0 = 0b11; // 
		};
		/* Bits LP_MODE: */
		/* Low-power mode selection (see Table 32)  */
		struct LP_MODE
		{
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t LOW_POWER_MODE_1 = 0b00; // Low-Power Mode 1 (12-bit resolution)
			static const uint8_t LOW_POWER_MODE_2 = 0b01; // Low-Power Mode 2 (14-bit resolution)
			static const uint8_t LOW_POWER_MODE_3 = 0b10; // Low-Power Mode 3 (14-bit resolution)
			static const uint8_t LOW_POWER_MODE_4 = 0b11; // Low-Power Mode 4 (14-bit resolution)
		};
	};
	
	/* Set register CTRL1 */
	void setCTRL1(uint8_t value)
	{
		write(CTRL1::__address, value, 8);
	}
	
	/* Get register CTRL1 */
	uint8_t getCTRL1()
	{
		return read8(CTRL1::__address, 8);
	}
	
};
