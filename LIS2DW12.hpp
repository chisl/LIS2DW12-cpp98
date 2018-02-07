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
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG CTRL2                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL2:
	 * 8.5
	 * Control register 2
	 */
	struct CTRL2
	{
		static const uint16_t __address = 33;
		
		/* Bits BOOT: */
		/*
		 * Boot enables retrieving the correct trimming parameters from nonvolatile memory
		 * into registers where trimming parameters are stored.
		 * Once the operation is over, this bit automatically returns to 0.
		 */
		struct BOOT
		{
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits reserved_0: */
		/* This bit must be set to ‘0’ for the correct operation of the device.  */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits SOFT_RESET: */
		/* Soft reset acts as reset for all control registers, then goes to 0.  */
		struct SOFT_RESET
		{
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits CS_PU_DISC: */
		/* Disconnect CS pull-up.  */
		struct CS_PU_DISC
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t CONNECTED = 0b0; // pull-up connected to CS pin;
			static const uint8_t DISCONNECTED = 0b1; // pull-up disconnected to CS pin)
		};
		/* Bits BDU: */
		/*
		 * Block data update.
		 * The BDU bit is used to inhibit the update of the output registers until both upper and lower
		 * register parts are read. In default mode (BDU = ‘0’) the output register values are updated continuously. When the BDU is activated (BDU = ‘1’), the content of the output registers is not updated until both MSB and LSB are read which avoids reading values related to different sample times.
		 */
		struct BDU
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t CONTINUOUS_UPDATE = 0b0; // continuous update
			static const uint8_t NOT_UPDATED_UNTIL_READ = 0b1; // output registers not updated until MSB and LSB read
		};
		/* Bits IF_ADD_INC: */
		/* Register address automatically incremented during multiple byte access with a serial interface (I2C or SPI).  */
		struct IF_ADD_INC
		{
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits I2C_DISABLE: */
		/* Disable I2C communication protocol.  */
		struct I2C_DISABLE
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t SPI_I2C_ENABLED = 0b0; // SPI and I2C interfaces enabled
			static const uint8_t I2C_ENABLED = 0b1; // I2C mode disabled
		};
		/* Bits SIM: */
		/* SPI serial interface mode selection.  */
		struct SIM
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t SPI_4_WIRE = 0b0; // 
			static const uint8_t SPI_3_WIRE = 0b1; // 
		};
	};
	
	/* Set register CTRL2 */
	void setCTRL2(uint8_t value)
	{
		write(CTRL2::__address, value, 8);
	}
	
	/* Get register CTRL2 */
	uint8_t getCTRL2()
	{
		return read8(CTRL2::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG CTRL3                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL3:
	 * 8.6
	 * COntrol register 3
	 */
	struct CTRL3
	{
		static const uint16_t __address = 34;
		
		/* Bits ST: */
		struct ST
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t NORMAL = 0b00; // Normal mode (self-test disabled)
			static const uint8_t POSITIVE_SIGN = 0b01; // Positive sign self-test
			static const uint8_t NEGATIVE_SIGN = 0b10; // Negative sign self-test
			static const uint8_t unused_0 = 0b11; // 
		};
		/* Bits PP_OD: */
		/* Push-pull/open-drain selection on interrupt pad.  */
		struct PP_OD
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t PUSH_PULL = 0b0; // push-pull
			static const uint8_t PPEN_DRAIN = 0b1; // open-drain
		};
		/* Bits LIR: */
		/*
		 * Latched Interrupt. Switches between latched ('1'-logic) and pulsed ('0'-logic) mode for function source
		 * signals and interrupts routed to pins (wakeup, single/double-tap).
		 */
		struct LIR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t NOT_LATCHED = 0b0; // interrupt request not latched
			static const uint8_t LATCHED = 0b1; // interrupt request latched
		};
		/* Bits H_LACTIVE: */
		/* Interrupt active high, low.  */
		struct H_LACTIVE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t ACTIVE_HIGH = 0b0; // active high
			static const uint8_t ACTVE_LOW = 0b1; // active low
		};
		/* Bits unused_0: */
		struct unused_0
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits SLP_MODE_SEL: */
		/* Single data conversion on demand mode selection  */
		struct SLP_MODE_SEL
		{
			/* MODE rw */
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t WITH_EXTERNAL_TRIG = 0b0; // enabled with external trigger on INT2
			static const uint8_t BY_I2C_SPI = 0b1; // enabled by I2C/SPI writing SLP_MODE_1 to 1.
		};
		/* Bits SLP_MODE_1: */
		/*
		 * Single data conversion on demand mode enable. When SLP_MODE_SEL = '1' and this bit is set to '1' logic,
		 * single data conversion on demand mode starts. When XL data are available in the registers, this bit is set
		 * to '0' automatically and the device is ready for another triggered session.
		 */
		struct SLP_MODE_1
		{
			/* MODE rw */
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register CTRL3 */
	void setCTRL3(uint8_t value)
	{
		write(CTRL3::__address, value, 8);
	}
	
	/* Get register CTRL3 */
	uint8_t getCTRL3()
	{
		return read8(CTRL3::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                     REG CTRL4_INT1_PAD_CTRL                                      *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL4_INT1_PAD_CTRL:
	 * 8.7
	 * Control register 4
	 */
	struct CTRL4_INT1_PAD_CTRL
	{
		static const uint16_t __address = 35;
		
		/* Bits INT1_6D: */
		/* 6D recognition is routed to INT1 pad.  */
		struct INT1_6D
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_SINGLE_TAP: */
		/* Single-tap recognition is routed to INT1 pad.  */
		struct INT1_SINGLE_TAP
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_WU: */
		/* Wakeup recognition is routed to INT1 pad.  */
		struct INT1_WU
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_FF: */
		/* Free-fall recognition is routed to INT1 pad.  */
		struct INT1_FF
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_TAP: */
		/* Double-tap recognition is routed to INT1 pad.  */
		struct INT1_TAP
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_DIFF5: */
		/* FIFO full recognition is routed to INT1 pad.  */
		struct INT1_DIFF5
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_FTH: */
		/* FIFO threshold interrupt is routed to INT1 pad.  */
		struct INT1_FTH
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT1_DRDY: */
		/* Data-Ready is routed to INT1 pad.  */
		struct INT1_DRDY
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
	};
	
	/* Set register CTRL4_INT1_PAD_CTRL */
	void setCTRL4_INT1_PAD_CTRL(uint8_t value)
	{
		write(CTRL4_INT1_PAD_CTRL::__address, value, 8);
	}
	
	/* Get register CTRL4_INT1_PAD_CTRL */
	uint8_t getCTRL4_INT1_PAD_CTRL()
	{
		return read8(CTRL4_INT1_PAD_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                     REG CTRL5_INT2_PAD_CTRL                                      *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL5_INT2_PAD_CTRL:
	 * 8.8
	 * Control register 4
	 */
	struct CTRL5_INT2_PAD_CTRL
	{
		static const uint16_t __address = 36;
		
		/* Bits INT2_SLEEP_STATE: */
		/* Enable routing of SLEEP_STATE on INT2 pad.   */
		struct INT2_SLEEP_STATE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_SLEEP_CHG: */
		/* Sleep change status routed to INT2 pad.  */
		struct INT2_SLEEP_CHG
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_BOOT: */
		/* Boot state routed to INT2 pad.  */
		struct INT2_BOOT
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_DRDY_T: */
		/* Temperature data-ready is routed to INT2.  */
		struct INT2_DRDY_T
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_OVR: */
		/* FIFO overrun interrupt is routed to INT2 pad.  */
		struct INT2_OVR
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_DIFF5: */
		/* FIFO full recognition is routed to INT2 pad.  */
		struct INT2_DIFF5
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_FTH: */
		/* FIFO threshold interrupt is routed to INT2 pad.  */
		struct INT2_FTH
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits INT2_DRDY: */
		/* Data-ready is routed to INT2 pad.  */
		struct INT2_DRDY
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'd0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
	};
	
	/* Set register CTRL5_INT2_PAD_CTRL */
	void setCTRL5_INT2_PAD_CTRL(uint8_t value)
	{
		write(CTRL5_INT2_PAD_CTRL::__address, value, 8);
	}
	
	/* Get register CTRL5_INT2_PAD_CTRL */
	uint8_t getCTRL5_INT2_PAD_CTRL()
	{
		return read8(CTRL5_INT2_PAD_CTRL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG CTRL6                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL6:
	 * 8.9
	 * Control register 6.
	 */
	struct CTRL6
	{
		static const uint16_t __address = 37;
		
		/* Bits BW_FILT: */
		/* Bandwidth selection  */
		struct BW_FILT
		{
			/* MODE rw */
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t ODR_2 = 0b00; // ODR/2 (up to ODR = 800 Hz, 400 Hz when ODR = 1600 Hz)
			static const uint8_t ODR_4 = 0b01; // ODR/4 (HP/LP)
			static const uint8_t ODR_10 = 0b10; // ODR/10 (HP/LP
			static const uint8_t ODR_20 = 0b11; // ODR/20 (HP/LP
		};
		/* Bits FS: */
		/* Full-scale selection.  */
		struct FS
		{
			/* MODE rw */
			static const uint8_t mask = 0b00110000; // [4,5]
			static const uint8_t SCALE_2_G = 0b00; // ±2 g
			static const uint8_t SCALE_4_G = 0b01; // ±4 g
			static const uint8_t SCALE_8_G = 0b10; // ±8 g
			static const uint8_t SCALE_16_G = 0b11; // ±16 g §
		};
		/* Bits FDS: */
		/* Filtered data type selection.  */
		struct FDS
		{
			/* MODE rw */
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t LOW_PASS = 0b0; // low-pass filter path selected
			static const uint8_t HIGH_PASS = 0b1; // high-pass filter path selected)
		};
		/* Bits LOW_NOISE: */
		/* Low-noise configuration.  */
		struct LOW_NOISE
		{
			/* MODE rw */
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
	};
	
	/* Set register CTRL6 */
	void setCTRL6(uint8_t value)
	{
		write(CTRL6::__address, value, 8);
	}
	
	/* Get register CTRL6 */
	uint8_t getCTRL6()
	{
		return read8(CTRL6::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG OUT_T2                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OUT_T2:
	 * 8.10
	 * Temperature output register in 8-bit resolution (r)
	 * The value is expressed as two’s complement sign. Sensitivity = 1°C/LSB
	 * 0 LSB represents T=25 °C ambient.
	 */
	struct OUT_T2
	{
		static const uint16_t __address = 38;
		
		/* Bits OUT_T2: */
		struct OUT_T2_
		{
			/* MODE - */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_T2 */
	void setOUT_T2(uint8_t value)
	{
		write(OUT_T2::__address, value, 8);
	}
	
	/* Get register OUT_T2 */
	uint8_t getOUT_T2()
	{
		return read8(OUT_T2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG STATUS                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS:
	 * 8.11
	 * Status register (r).
	 */
	struct STATUS
	{
		static const uint16_t __address = 39;
		
		/* Bits FIFO_THS: */
		/* FIFO threshold status flag.  */
		struct FIFO_THS
		{
			/* MODE r */
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t BELOW_TRESHOLD = 0b0; // FIFO filling is lower than threshold level
			static const uint8_t AT_OR_ABOVE_THRESHOLD = 0b1; // FIFO filling is equal to or higher than the threshold level.
		};
		/* Bits WU_IA: */
		/* Wakeup event detection status.  */
		struct WU_IA
		{
			/* MODE r */
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NOT_DETECTED = 0b0; // Wakeup event not detected
			static const uint8_t DETECTED = 0b1; // Wakeup event detected
		};
		/* Bits SLLEP_STATE: */
		/* Sleep event status.  */
		struct SLLEP_STATE
		{
			/* MODE r */
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t NOT_DETECTED = 0b0; // Sleep event not detected
			static const uint8_t DETECTED = 0b1; // Sleep event detected
		};
		/* Bits DOUBLE_TAP: */
		/* Double-tap event status  */
		struct DOUBLE_TAP
		{
			/* MODE r */
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t NOT_DETECTED = 0b0; // Double-tap event not detected
			static const uint8_t DETECTED = 0b1; // Double-tap event detected
		};
		/* Bits SINGLE_TAP: */
		/* Single-tap event status  */
		struct SINGLE_TAP
		{
			/* MODE r */
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t NOT_DETECTED = 0b0; // Single-tap event not detected
			static const uint8_t DETECTED = 0b1; // Single-tap event detected
		};
		/* Bits D6_IA: */
		/* Source of change in position portrait/landscape/face-up/face-down.  */
		struct D6_IA
		{
			/* MODE r */
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NOT_DETECTED = 0b0; // no event detected
			static const uint8_t DETECTED = 0b1; // a change in position detected
		};
		/* Bits FF_IA: */
		/* Free-fall event detection status.  */
		struct FF_IA
		{
			/* MODE r */
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NOT_DETECTED = 0b0; // free-fall event not detected
			static const uint8_t DETECTED = 0b1; // free-fall event detected
		};
		/* Bits DRDY: */
		/* Data-ready status.  */
		struct DRDY
		{
			/* MODE r */
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NOT_READY = 0b0; // not ready
			static const uint8_t DATA_AVAILABLE = 0b1; // X-, Y- and Z-axis new data available
		};
	};
	
	/* Set register STATUS */
	void setSTATUS(uint8_t value)
	{
		write(STATUS::__address, value, 8);
	}
	
	/* Get register STATUS */
	uint8_t getSTATUS()
	{
		return read8(STATUS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_X                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_X:
	 * X-axis output register (r).
	 * It forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_X
	{
		static const uint16_t __address = 40;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE r */
			static const uint16_t dflt = 0b00; // 2'd0
			static const uint16_t mask = 0b1100000000000000; // [14,15]
		};
		/* Bits OUT_X: */
		/* NOTE: If Low-Power Mode 1 is enabled, this bit2 15..14 are set to 0.  */
		struct OUT_X_
		{
			/* MODE r */
			static const uint16_t mask = 0b0011111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13]
		};
	};
	
	/* Set register OUT_X */
	void setOUT_X(uint16_t value)
	{
		write(OUT_X::__address, value, 16);
	}
	
	/* Get register OUT_X */
	uint16_t getOUT_X()
	{
		return read16(OUT_X::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_Y                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Y:
	 * Y-axis output register (r).
	 * It forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_Y
	{
		static const uint16_t __address = 42;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE r */
			static const uint16_t dflt = 0b00; // 2'd0
			static const uint16_t mask = 0b1100000000000000; // [14,15]
		};
		/* Bits OUT_Y: */
		/* NOTE: If Low-Power Mode 1 is enabled, this bit2 15..14 are set to 0.  */
		struct OUT_Y_
		{
			/* MODE r */
			static const uint16_t mask = 0b0011111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13]
		};
	};
	
	/* Set register OUT_Y */
	void setOUT_Y(uint16_t value)
	{
		write(OUT_Y::__address, value, 16);
	}
	
	/* Get register OUT_Y */
	uint16_t getOUT_Y()
	{
		return read16(OUT_Y::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG OUT_Z                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Z:
	 * Z-axis output register (r).
	 * It forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_Z
	{
		static const uint16_t __address = 44;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			/* MODE r */
			static const uint16_t dflt = 0b00; // 2'd0
			static const uint16_t mask = 0b1100000000000000; // [14,15]
		};
		/* Bits OUT_Z: */
		/* NOTE: If Low-Power Mode 1 is enabled, this bit2 15..14 are set to 0.  */
		struct OUT_Z_
		{
			/* MODE r */
			static const uint16_t mask = 0b0011111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13]
		};
	};
	
	/* Set register OUT_Z */
	void setOUT_Z(uint16_t value)
	{
		write(OUT_Z::__address, value, 16);
	}
	
	/* Get register OUT_Z */
	uint16_t getOUT_Z()
	{
		return read16(OUT_Z::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_X_L                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_X_L:
	 * 8.12
	 * X-axis LSB output register (r).
	 * 1.   If Low-Power Mode 1 is enabled, this bit is set to 0.
	 * The 8 least significant bits of linear acceleration sensor X-axis output. Together with the
	 * OUT_X_H (29h) register, it forms the output value expressed as a 16-bit word in 2's complement.
	 * X_H7	X_H6	X_H5	X_H4	X_H3	X_H2	X_H1	X_H0
	 * The 8 most significant bits of linear acceleration sensor X-axis output. Together with the
	 * OUT_X_L (28h) register, it forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_X_L
	{
		static const uint16_t __address = 40;
		
		/* Bits OUT_X_L: */
		struct OUT_X_L_
		{
			/* MODE - */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_X_L */
	void setOUT_X_L(uint8_t value)
	{
		write(OUT_X_L::__address, value, 8);
	}
	
	/* Get register OUT_X_L */
	uint8_t getOUT_X_L()
	{
		return read8(OUT_X_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_Y_L                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Y_L:
	 * 8.14
	 * Y-axis LSB output register (r).
	 * 1.   If Low-Power Mode 1 is enabled, this bit is set to 0.
	 * The 8 least significant bits of linear acceleration sensor Y-axis output. Together with the
	 * OUT_Y_H (2Bh) register, it forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_Y_L
	{
		static const uint16_t __address = 42;
		
		/* Bits OUT_Y_L: */
		struct OUT_Y_L_
		{
			/* MODE - */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_Y_L */
	void setOUT_Y_L(uint8_t value)
	{
		write(OUT_Y_L::__address, value, 8);
	}
	
	/* Get register OUT_Y_L */
	uint8_t getOUT_Y_L()
	{
		return read8(OUT_Y_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_Y_H                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Y_H:
	 * 8.15
	 * Y-axis MSB output register (r).
	 * OUT_Y_L (2Ah) register, it forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_Y_H
	{
		static const uint16_t __address = 43;
		
		/* Bits OUT_Y_H: */
		struct OUT_Y_H_
		{
			/* MODE - */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_Y_H */
	void setOUT_Y_H(uint8_t value)
	{
		write(OUT_Y_H::__address, value, 8);
	}
	
	/* Get register OUT_Y_H */
	uint8_t getOUT_Y_H()
	{
		return read8(OUT_Y_H::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG OUT_Z_L                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG OUT_Z_L:
	 * 8.16
	 * Z-axis LSB output register (r).
	 * Z_L7	Z_L6	Z_L5	Z_L4	Z_L3(1)	Z_L2(1)	0	0
	 * 1.   If Low-power Mode 1 is enabled, this bit is set to 0.
	 * The 8 least significant bits of linear acceleration sensor Z-axis output. Together with the
	 * OUT_Z_H (2Dh) register, it forms the output value expressed as a 16-bit word in 2's complement.
	 * Z_H7	Z_H6	Z_H5	Z_H4	Z_H3	Z_H2	Z_H1	Z_H0
	 * The 8 most significant bits of linear acceleration sensor Z-axis output. Together with the
	 * OUT_Z_L (2Ch) register, it forms the output value expressed as a 16-bit word in 2's complement.
	 */
	struct OUT_Z_L
	{
		static const uint16_t __address = 44;
		
		/* Bits OUT_Z_L: */
		struct OUT_Z_L_
		{
			/* MODE - */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OUT_Z_L */
	void setOUT_Z_L(uint8_t value)
	{
		write(OUT_Z_L::__address, value, 8);
	}
	
	/* Get register OUT_Z_L */
	uint8_t getOUT_Z_L()
	{
		return read8(OUT_Z_L::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG FIFO_CTRL                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_CTRL:
	 * 8.18
	 * FIFO control register
	 */
	struct FIFO_CTRL
	{
		static const uint16_t __address = 46;
		
		/* Bits FMODE: */
		/* FIFO mode selection bits.  */
		struct FMODE
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t BYPASS = 0b00; // Bypass mode: FIFO turned off
			static const uint8_t FIFO = 0b01; // FIFO mode: Stops collecting data when FIFO is full.
			static const uint8_t reserved_0 = 0b10; // 
			static const uint8_t CONTINUOUS_TO_FIFO = 0b11; // Continuous-to-FIFO: Stream mode until trigger is deasserted, then FIFO mode
			static const uint8_t BYPASS_TO_CONTINUOUS = 0b100; // Bypass-to-Continuous: Bypass mode until trigger is deasserted, then FIFO mode
			static const uint8_t reserved_1 = 0b101; // 
			static const uint8_t CONTINUOUS = 0b110; // Continuous mode: If the FIFO is full, the new sample overwrites the older sample.
			static const uint8_t reserved_2 = 0b111; // 
		};
		/* Bits FTH: */
		/* FIFO threshold level setting.  */
		struct FTH
		{
			/* MODE rw */
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_CTRL */
	void setFIFO_CTRL(uint8_t value)
	{
		write(FIFO_CTRL::__address, value, 8);
	}
	
	/* Get register FIFO_CTRL */
	uint8_t getFIFO_CTRL()
	{
		return read8(FIFO_CTRL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG FIFO_SAMPLES                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_SAMPLES:
	 * 8.19
	 * FIFO_SAMPLES control register.
	 */
	struct FIFO_SAMPLES
	{
		static const uint16_t __address = 47;
		
		/* Bits FIFO_FTH: */
		/* FIFO threshold status flag.  */
		struct FIFO_FTH
		{
			/* MODE r */
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t BELOW_THRESHOLD = 0b0; // FIFO filling is lower than threshold level
			static const uint8_t AT_OR_ABOVE_THRESHOLD = 0b1; // FIFO filling is equal to or higher than the threshold level.)
		};
		/* Bits FIFO_OVR: */
		/* FIFO overrun status.  */
		struct FIFO_OVR
		{
			/* MODE r */
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t NOT_FILLED = 0b0; // FIFO is not completely filled
			static const uint8_t FILLED = 0b1; // FIFO is completely filled and at least one sample has been overwritten
		};
		/* Bits DIFF: */
		/*
		 * Represents the number of unread samples stored in FIFO.
		 * (000000 = FIFO empty; 100000 = FIFO full, 32 unread samples.
		 */
		struct DIFF
		{
			/* MODE r */
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
		};
	};
	
	/* Set register FIFO_SAMPLES */
	void setFIFO_SAMPLES(uint8_t value)
	{
		write(FIFO_SAMPLES::__address, value, 8);
	}
	
	/* Get register FIFO_SAMPLES */
	uint8_t getFIFO_SAMPLES()
	{
		return read8(FIFO_SAMPLES::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG TAP_THS_X                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TAP_THS_X:
	 * 8.20
	 * 4D configuration enable and TAP threshold configuration.
	 */
	struct TAP_THS_X
	{
		static const uint16_t __address = 48;
		
		/* Bits D4_EN: */
		/* 4D detection portrait/landscape position enable.  */
		struct D4_EN
		{
			/* MODE rw */
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t NO_DETECTION = 0b0; // no position detected
			static const uint8_t DETECTION = 0b1; // portrait/landscape detection and face-up/face-down position enabled).
		};
		/* Bits D6_THS: */
		/* Thresholds for 4D/6D function @ FS = ±2 g  */
		struct D6_THS
		{
			/* MODE rw */
			static const uint8_t mask = 0b01100000; // [5,6]
			static const uint8_t THRESHOLD_6 = 0b00; // 6 (80 degrees)
			static const uint8_t THRESHOLD_11 = 0b01; // 11 (70 degrees)
			static const uint8_t THRESHOLD_16 = 0b10; // 16 (60 degrees)
			static const uint8_t THRESHOLD_21 = 0b11; // 21 (50 degrees
		};
		/* Bits TAP_THSX: */
		/* Threshold for TAP recognition @ FS = ±2 g on X direction  */
		struct TAP_THSX
		{
			/* MODE rw */
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register TAP_THS_X */
	void setTAP_THS_X(uint8_t value)
	{
		write(TAP_THS_X::__address, value, 8);
	}
	
	/* Get register TAP_THS_X */
	uint8_t getTAP_THS_X()
	{
		return read8(TAP_THS_X::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG TAP_THS_Y                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TAP_THS_Y:
	 * 8.21
	 */
	struct TAP_THS_Y
	{
		static const uint16_t __address = 49;
		
		/* Bits TAP_PRIOR: */
		/*
		 * Selection  of axis priority for tap detection.
		 * Max priority / Mid priority / Min priority
		 */
		struct TAP_PRIOR
		{
			static const uint8_t mask = 0b11100000; // [5,6,7]
			static const uint8_t XYZ = 0b00; // 
			static const uint8_t YXZ = 0b01; // 
			static const uint8_t XZY = 0b10; // 
			static const uint8_t ZYX = 0b11; // 
			static const uint8_t XYZ_2 = 0b100; // 
			static const uint8_t YZX_2 = 0b101; // 
			static const uint8_t ZXY_2 = 0b110; // 
			static const uint8_t ZYX_2 = 0b111; // 
		};
		/* Bits TAP_THSY: */
		/* Threshold for tap recognition @ FS = ±2 g on Y direction.  */
		struct TAP_THSY
		{
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register TAP_THS_Y */
	void setTAP_THS_Y(uint8_t value)
	{
		write(TAP_THS_Y::__address, value, 8);
	}
	
	/* Get register TAP_THS_Y */
	uint8_t getTAP_THS_Y()
	{
		return read8(TAP_THS_Y::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG TAP_THS_Z                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TAP_THS_Z:
	 * 8.22
	 */
	struct TAP_THS_Z
	{
		static const uint16_t __address = 50;
		
		/* Bits TAP_X_EN: */
		/* Enables X direction in tap recognition.  */
		struct TAP_X_EN
		{
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits TAP_Y_EN: */
		/* Enables Y direction in tap recognition.  */
		struct TAP_Y_EN
		{
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits TAP_Z_EN: */
		/* Enables Z direction in tap recognition.  */
		struct TAP_Z_EN
		{
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits TAP_THSZ: */
		/* Threshold for tap recognition @ FS = ±2 g on Z direction.  */
		struct TAP_THSZ
		{
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register TAP_THS_Z */
	void setTAP_THS_Z(uint8_t value)
	{
		write(TAP_THS_Z::__address, value, 8);
	}
	
	/* Get register TAP_THS_Z */
	uint8_t getTAP_THS_Z()
	{
		return read8(TAP_THS_Z::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG INT_DUR                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT_DUR:
	 * Interrupt duration register
	 */
	struct INT_DUR
	{
		static const uint16_t __address = 51;
		
		/* Bits LATENCY: */
		/*
		 * Duration of maximum time gap for double-tap recognition. When double-tap recognition is enabled, this
		 * register expresses the maximum time between two successive detected taps to determine a double-tap event.
		 * Default value is LATENCY = 0000 (which is 16 * 1/ODR)
		 * 1 LSB = 32 * 1/ODR.
		 */
		struct LATENCY
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0000; // 4'd0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits QUIET: */
		/*
		 * Expected quiet time after a tap detection: this register represents the time after the first detected
		 * tap in which there must not be any overthreshold event.
		 * Default value is QUIET[1:0] = 00 (which is 2 * 1/ODR)
		 * 1 LSB = 4 * 1/ODR
		 */
		struct QUIET
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'd0
			static const uint8_t mask = 0b00001100; // [2,3]
		};
		/* Bits SHOCK: */
		/*
		 * Maximum duration of over-threshold event: this register represents the maximum time of an
		 * over-threshold signal detection to be recognized as a tap event.
		 * Default value is SHOCK[1:0] = 00 (which is 4 * 1/ODR)
		 * 1 LSB = 8 *1/ODR
		 */
		struct SHOCK
		{
			/* MODE rw */
			static const uint8_t dflt = 0b00; // 2'd0
			static const uint8_t mask = 0b00000011; // [0,1]
		};
	};
	
	/* Set register INT_DUR */
	void setINT_DUR(uint8_t value)
	{
		write(INT_DUR::__address, value, 8);
	}
	
	/* Get register INT_DUR */
	uint8_t getINT_DUR()
	{
		return read8(INT_DUR::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG WAKE_UP_THS                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG WAKE_UP_THS:
	 * 8.24
	 * Wakeup threshold register.
	 */
	struct WAKE_UP_THS
	{
		static const uint16_t __address = 52;
		
		/* Bits SINGLE_DOUBLE_TAP: */
		/* Enable single/double-tap event.  */
		struct SINGLE_DOUBLE_TAP
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t ONLY_SINGLE = 0b0; // only single-tap event is enabled
			static const uint8_t SINGLE_AND_DOUBLE = 0b1; // single and double-tap events are enabled
		};
		/* Bits SLEEP_ON: */
		/* Sleep (inactivity) enable.  */
		struct SLEEP_ON
		{
			/* MODE rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t DISABLED = 0b0; // 
			static const uint8_t ENABLED = 0b1; // 
		};
		/* Bits WK_THS: */
		/* Wakeup threshold, 6-bit unsigned 1 LSB = 1/64 of FS.  */
		struct WK_THS
		{
			/* MODE rw */
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
		};
	};
	
	/* Set register WAKE_UP_THS */
	void setWAKE_UP_THS(uint8_t value)
	{
		write(WAKE_UP_THS::__address, value, 8);
	}
	
	/* Get register WAKE_UP_THS */
	uint8_t getWAKE_UP_THS()
	{
		return read8(WAKE_UP_THS::__address, 8);
	}
	
};
