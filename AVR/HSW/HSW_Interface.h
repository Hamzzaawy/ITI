#ifndef HSwitch_INTERFACE_H
#define HSwitch_INTERFACE_H



#define OS_TIME_TICK_MS			1000

#define SW_Pressed_Level        1
#define SW_Released_Level       0


#define SW_Update_Period_ms     5

#define SW_SAMPLES              10


#define Number_Of_Switches      8

//max SW Press and Release Time

#define SW_PRESS_TIME_MAX_MS            2000
#define SW_RELEASE_TIME_MAX_MS          2000


#define     SW_0_DIO_PORT            PORTA
#define     SW_1_DIO_PORT            PORTA
#define     SW_2_DIO_PORT            PORTA
#define     SW_3_DIO_PORT            PORTA
#define     SW_4_DIO_PORT            PORTA
#define     SW_5_DIO_PORT            PORTA
#define     SW_6_DIO_PORT            PORTA
#define     SW_7_DIO_PORT            PORTA

typedef enum
{
    SW_0=0,
    SW_1=1,
    SW_2=2,
    SW_3,
    SW_4,
    SW_5,
    SW_6,
    SW_7

}Switch_Number;


typedef enum
{
    SW_Released=0,
    SW_Pre_Pressed,
    SW_Pressed,
    SW_Pre_Released
    
}Switch_State;

void HSwitch_voidInit(Switch_Number SW_No,Switch_State SW_State);


void HSwitch_voidUpdateState(Switch_Number SW_No);


u8   HSwitch_u8GetState(Switch_Number SW_No);   

u16 HSwitch_u8PressedTime(Switch_Number SW_No);

u16 HSwitch_u8ReleasedTime(Switch_Number SW_No);


#endif
