#ifndef _SBY_TASKS_
#define _SBY_TASKS_

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include <stdio.h>

/* ----------------------- Defines ------------------------------------------*/
#define PUB_TYPE_AGENT 								0
#define PUB_TYPE_DHT 									1
#define PUB_TYPE_HISTORY_DHT					2
#define PUB_TYPE_INV 									3

/*task*/
extern void MQTTWork(void *argu);
extern void DHT11_Task(void *argu);
extern void MBTask(void *argu);

extern xQueueHandle xPubQueue;

/*Private variables*/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

/*func*/
extern void HAL_CalTick(void);
extern void HAL_DelayUs(int nDelay);

extern unsigned int BitHign_Count(unsigned char *v, int size);
extern unsigned int BitLow_Count(unsigned char *v, int size);
extern void LED_On(int Led);
extern void LED_Off(int Led);
extern void LED_Toggle(int Led);

/*DHT11 12byte*/
struct DHT11
{
	int pickTem;		//Temperature integer part
	int pickHum;		//Humidity integer part
	int pickTime;
	
};
/*42byte offset = 341 * DHT_DATA_BYTE_SIZE = 4KB data */
#define DHT_Flash_Base_Addr						0
#define DHT_Flash_Write_Offset_Addr		0x002A00
#define DHT_Flash_Read_Offset_Addr		0x002B00
#define DHT_DATA_BYTE_SIZE 						(3*4)

extern struct DHT11 gDHT[1];
extern void wDHT(int pickTime, int pickTem, int pickHum);
extern void initDHT(void);
extern unsigned int getAddrOffset(unsigned int addr);
extern int modifyAddrOffset(unsigned int addr);
extern int WriteDHTFlash(unsigned char *pTxData);
extern int ReadDHTFlash(unsigned char *pRxData);

extern int gConnect;
#endif
