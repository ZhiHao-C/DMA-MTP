#include "bps_DMA_MTP.h"

// Ҫ���͵����ݴ�С


/* ����aSRC_Const_Buffer������ΪDMA��������Դ
 * const�ؼ��ֽ�aSRC_Const_Buffer�����������Ϊ��������
 * ��ʾ���ݴ洢���ڲ���FLASH��
 */
const uint32_t aSRC_Const_Buffer[BUFFER_SIZE]= {
                                    0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};
/* ����DMA����Ŀ��洢��
 * �洢���ڲ���SRAM��																		
 */
uint32_t aDST_Buffer[BUFFER_SIZE];
uint8_t SendBuffer[5000];
																		

//typedef struct
//{
//  uint32_t DMA_PeripheralBaseAddr;   // �����ַ
//  uint32_t DMA_MemoryBaseAddr;       // �洢����ַ
//  uint32_t DMA_DIR;                  // ���䷽��
//  uint32_t DMA_BufferSize;           // ������Ŀ
//  uint32_t DMA_PeripheralInc;        // �����ַ����ģʽ
//  uint32_t DMA_MemoryInc;            // �洢����ַ����ģʽ
//  uint32_t DMA_PeripheralDataSize;   // �������ݿ��
//  uint32_t DMA_MemoryDataSize;       // �洢�����ݿ��
//  uint32_t DMA_Mode;                 // ģʽѡ��
//  uint32_t DMA_Priority;             // ͨ�����ȼ�
//  uint32_t DMA_M2M;                  // �洢�����洢��ģʽ
//}DMA_InitTypeDef;
																													
																		
void MtP_DMA_Config(void)
{
	DMA_InitTypeDef DMA_InitStruct;
	RCC_AHBPeriphClockCmd(MTP_DMA_CLK,ENABLE);
	DMA_InitStruct.DMA_PeripheralBaseAddr=(uint32_t)USART_DR_ADDRESS;//��M���͵�P(����)
	DMA_InitStruct.DMA_MemoryBaseAddr=(uint32_t) SendBuffer;//
	DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralDST ;//ѡ��������ΪĿ�ĵ�
	DMA_InitStruct.DMA_BufferSize=5000;
	DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	DMA_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
	DMA_InitStruct.DMA_Mode=DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority=DMA_Priority_High;
	DMA_InitStruct.DMA_M2M=DMA_M2M_Disable;
	DMA_Init(MTP_DMA_USART_TX_CHANNEL,&DMA_InitStruct);
	DMA_Cmd(MTP_DMA_USART_TX_CHANNEL,ENABLE);
	DMA_ClearFlag(DMA1_FLAG_TC4);
}


/* �ж�ָ�����ȵ���������Դ�Ƿ���ȫ��ȣ�
  * �����ȫ��ȷ���1��ֻҪ����һ�����ݲ���ȷ���0
  */
//uint8_t Buffercmp(const uint32_t* pBuffer, 
//                  uint32_t* pBuffer1, uint16_t BufferLength);
//{
//  /* ���ݳ��ȵݼ� */
//  while(BufferLength--)
//  {
//    /* �ж���������Դ�Ƿ��Ӧ��� */
//    if(*pBuffer != *pBuffer1)
//    {
//      /* ��Ӧ����Դ����������˳�������������0 */
//      return 0;
//    }
//    /* ������������Դ�ĵ�ַָ�� */
//    pBuffer++;
//    pBuffer1++;
//  }
//  /* ����жϲ��Ҷ�Ӧ������� */
//  return 1;  
//}


