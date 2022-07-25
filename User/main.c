#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_DMA_MTP.h"
#include "bps_usart.h"
//extern const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];
//extern uint32_t aDST_Buffer[BUFFER_SIZE];
extern uint8_t SendBuffer[5000];
void delay_ms(int n)//ÑÓÊ±º¯Êý
{
	int i;
	while (n--)
	{
		for(i=0;i<5520;i++);
	}
}




int main()
{
	uint32_t i;
	for(i=0;i<5000;i++)
	{
		SendBuffer[i]='P';
	}
	MtP_DMA_Config(); 
	 USART_Config();
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
	
	while(1)
	{
		LED_G_GPIO_Config();
		led_G(on);
		delay_ms(2000);
		led_G(off);
		GPIO_DeInit(GPIOB);
		LED_R_GPIO_Config();
		led_R(on);
		delay_ms(2000);
		led_R(off);
		GPIO_DeInit(GPIOB);
	}
	
	
	
}

