/*
 * my_code.c
 *
 *  Created on: Aug 2, 2019
 *      Author: pl
 */
#include "my_code.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}

void my_init(){
	HAL_UART_Transmit(&huart1, (uint8_t*)"1", 1, 1000);
	HAL_UART_Transmit(&huart2, (uint8_t*)"2", 1, 1000);
}

void my_loop(){
//	HAL_StatusTypeDef res;
	char buff[128];

	sprintf(buff, "uart%d\n", 2);
	HAL_UART_Transmit(&huart2, (uint8_t*)buff, strlen(buff), 1000);
	sprintf(buff, "uart%d\n", 1);
	HAL_UART_Transmit(&huart1, (uint8_t*)buff, strlen(buff), 1000);
	//res = HAL_UART_Receive_IT(&huart1, buff, 1);
//	switch(res){
//	case HAL_OK:
//		HAL_UART_Transmit_IT(&huart2, (uint8_t*)"2", 1);
//		printf("hello world! OK\n");
//		break;
//	case HAL_BUSY:
//		HAL_UART_Transmit_IT(&huart2, (uint8_t*)"3", 1);
//		printf("hello world! BUSY\n");
//		break;
//	default:
//		// fail
//		break;
//	}
}



