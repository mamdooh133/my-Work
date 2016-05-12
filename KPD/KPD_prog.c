
#include "KPD_interface.h"
#include "KPD_config.h"
#include "DIO-interface.h"
#include "Delay.h"
#include "DIO-utilites.h"
u8 KPD_State ;
const u8  KPD_Btns[]={0,
		KPD_u8SW1_IDX ,KPD_u8SW2_IDX ,KPD_u8SW3_IDX ,KPD_u8SW4_IDX ,
		KPD_u8SW5_IDX ,KPD_u8SW6_IDX ,KPD_u8SW7_IDX ,KPD_u8SW8_IDX ,
		KPD_u8SW9_IDX ,KPD_u8SW10_IDX,KPD_u8SW11_IDX,KPD_u8SW12_IDX,
		KPD_u8SW13_IDX,KPD_u8SW14_IDX,KPD_u8SW15_IDX,KPD_u8SW16_IDX
         };
const u8 KPD_MAP[5]={1,2,3,0,4};
const u8 ChkErr[2]={error,ok};
extern void KPD_voidInit()
{
	KPD_State=0 ;
}

extern void KPD_u8Read(u8 *Copy_PtrToBtnIdx)
{
	u8 Local_LoopCount;
	u8 Local_OutCount=0 ;
u8 local_temp=0 ;


	for(Local_LoopCount=1;Local_LoopCount<=8;Local_LoopCount*=2)
	{

		    DIO_u8WritePinVal(KPD_u8Pin1,~ get_bit(Local_LoopCount,0));
		    DIO_u8WritePinVal(KPD_u8Pin2,~ get_bit(Local_LoopCount,1));
		    DIO_u8WritePinVal(KPD_u8Pin3,~ get_bit(Local_LoopCount,2));
		    DIO_u8WritePinVal(KPD_u8Pin4,~ get_bit(Local_LoopCount,3));

		    DIO_u8ReadPinVal(KPD_u8Pin5,& local_temp);
		    KPD_State+=(!local_temp);
		    DIO_u8ReadPinVal(KPD_u8Pin6,& local_temp);
		    KPD_State+=(!local_temp)*2;
		    DIO_u8ReadPinVal(KPD_u8Pin7,& local_temp);
		    KPD_State+=(!local_temp)*4;
		    DIO_u8ReadPinVal(KPD_u8Pin8,& local_temp);
		    KPD_State+=(!local_temp)*8;

		    if(KPD_State)
         {
		    	//DIO_u8WritePinVal(16,1);
        	 *Copy_PtrToBtnIdx=KPD_Btns[KPD_MAP[KPD_State/2]+(Local_OutCount*2)];
        	 KPD_State=0;
        	 break ;

         }
         else
         {
        	 *Copy_PtrToBtnIdx=0;
         }

    Local_OutCount+=2 ;
	}
	return ;
}

extern u8 KPD_GetBtn(u8 Copy_u8BtnIdx,u8 *Copy_u8BtnVal)
{
	u8 Local_PrsdBtn ;
	KPD_u8Read(&Local_PrsdBtn);

	*Copy_u8BtnVal=(Local_PrsdBtn==Copy_u8BtnIdx);
	return ChkErr[Copy_u8BtnIdx<16];
}



