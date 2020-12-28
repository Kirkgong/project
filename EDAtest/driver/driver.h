#ifndef __DRIVER_H
#define __DRIVER_H

#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */
	
#define bool _Bool

#ifndef _INT32_T_DECLARED
typedef signed int      				int32_t;
#define _INT32_T_DECLARED
#endif

#ifndef _UINT32_T_DECLARED
typedef unsigned int    				uint32_t;
#define _UINT32_T_DECLARED
#endif

typedef unsigned short  				uint16_t;
typedef signed short    				int16_t;
typedef unsigned char  			 		uint8_t;
typedef signed  char 					int8_t;
typedef char    						char_t;
typedef bool    						bool_t;

  

typedef enum 
{
  ERROR = 0U, 
  SUCCESS = !ERROR
} ErrorStatus;

typedef enum {
	DISABLE = 0,
	ENABLE = 1
}FunctionalState;

typedef bool_t FlagStatus;
typedef bool_t ITStatus;

#define RESET 	(bool_t)0
#define SET 	(bool_t)1

void SystemReset(void);
void HAL_IncTick(void);
uint32_t Get_PeripheralClock(void);
int driver_write_reg(unsigned int address, unsigned int data);
unsigned int driver_read_reg(unsigned int address);

int XL6600PortToEDAInit(void);
int XL6600DataWriteToEDA(uint8_t* buf, uint32_t len);
void XL6600DataReadFromEDA(void);
#endif
