#include "LSTR_Types.h"
#include "LUTILS.h"


#include "HSW_Interface.h"
#include "HSW_Private.h"
#include"MDIO_interface.h"

typedef struct 
{
    Switch_State    SW_State;
    u8              SW_Samples[SW_SAMPLES];
    u16             Press_Times;
    u16             Release_Times;
}SWITCHES_INFO;



static		SWITCHES_INFO	SW_INFO 	[Number_Of_Switches];

void HSwitch_voidInit(Switch_Number SW_No,Switch_State SW_State)
{
    u8 Sample_Index=0;
    //intializa corresponing SW GPIO Pins as inputs
    switch (SW_No)
    {
        case SW_0:  MDIO_SetDirection(SW_0_DIO_PORT,SW_0,INPUT_PULLUP);          break;
        case SW_1:  MDIO_SetDirection(SW_1_DIO_PORT,SW_1,INPUT_PULLUP);          break;
        case SW_2:  MDIO_SetDirection(SW_2_DIO_PORT,SW_2,INPUT_PULLUP);          break;
        case SW_3:  MDIO_SetDirection(SW_3_DIO_PORT,SW_3,INPUT_PULLUP);          break;
        case SW_4:  MDIO_SetDirection(SW_4_DIO_PORT,SW_4,INPUT_PULLUP);          break;
        case SW_5:  MDIO_SetDirection(SW_5_DIO_PORT,SW_5,INPUT_PULLUP);          break;
        case SW_6:  MDIO_SetDirection(SW_6_DIO_PORT,SW_6,INPUT_PULLUP);          break;
        case SW_7:  MDIO_SetDirection(SW_7_DIO_PORT,SW_7,INPUT_PULLUP);          break;
        default:        /*report errors  */    									 break;
    }

    //Set SW_State and Set Corresponding SW_Samples Correspondingly

    SW_INFO[SW_No].SW_State	        =   SW_Released;

    SW_INFO[SW_No].Press_Times      =   0       ;
    
    SW_INFO[SW_No].Release_Times    =   0       ;

    for (Sample_Index=0; Sample_Index < SW_SAMPLES; Sample_Index++)
    {
        switch (SW_State)
        {
        case SW_Released:        SW_INFO[SW_No].SW_Samples[Sample_Index]= SW_Released_Level;                break;

        case SW_Pre_Pressed:
                        if(  Sample_Index  <=  ( SW_SAMPLES / 2 )    )
                        {
                                 SW_INFO[SW_No].SW_Samples[Sample_Index]= SW_Released_Level;  
                        }
                        else
                        {
                                 SW_INFO[SW_No].SW_Samples[Sample_Index]= SW_Pressed_Level;  
                        }
                            
                        break;
        case SW_Pressed:         SW_INFO[SW_No].SW_Samples[Sample_Index]= SW_Pressed_Level;                  break;

        case SW_Pre_Released:    
                        if(  Sample_Index  <=  ( SW_SAMPLES / 2 )    )
                        {
                                 SW_INFO[SW_No].SW_Samples[Sample_Index]= SW_Pressed_Level;  
                        }
                        else
                        {
                                 SW_INFO[SW_No].SW_Samples[Sample_Index]= SW_Released_Level;  
                        }
                            
                                                                                                            break;
        
        default:            /*Report Errors */                                                              break;
        }
    }
    

}
void HSwitch_voidUpdateState(Switch_Number SW_No)
{
    static u8 SW_Time_Counter_MS=0;
    u8 Sample_Index=0;
    //check it's period has come 

    SW_Time_Counter_MS   +=   OS_TIME_TICK_MS;


    if(  SW_Time_Counter_MS   < SW_Update_Period_ms )
    {
        return;
    }
    SW_Time_Counter_MS=0;


    //shifting the samples in the queue and drop the first entered one 
    for (Sample_Index=1; Sample_Index < SW_SAMPLES; Sample_Index++)
    {
     SW_INFO[SW_No].SW_Samples[Sample_Index-1]=SW_INFO[SW_No].SW_Samples[Sample_Index];
    }

    //take new Samples For SW

    switch (SW_No)
    {
        case SW_0:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_0_DIO_PORT,SW_No);              break;
        case SW_1:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_1_DIO_PORT,SW_No);              break;
        case SW_2:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_2_DIO_PORT,SW_No);              break;
        case SW_3:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_3_DIO_PORT,SW_No);              break;
        case SW_4:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_4_DIO_PORT,SW_No);              break;
        case SW_5:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_5_DIO_PORT,SW_No);              break;
        case SW_6:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_6_DIO_PORT,SW_No);              break;
        case SW_7:  SW_INFO[SW_No].SW_Samples[SW_SAMPLES-1]=MDIO_GetPinValue(SW_7_DIO_PORT,SW_No);              break;
        default:        /*report errors  */    break;
    }

    //Changing the SW_State Based on the last samples 

    switch (SW_INFO[SW_No].SW_State)
        {
        case SW_Released: 
                    //Switch to SW_Pre_Pressed State
                        if(     ( ( SW_INFO[SW_No].SW_Samples[0] )      ==      SW_Released_Level     )      && 
                                ( ( SW_INFO[SW_No].SW_Samples[1] )      ==      SW_Released_Level     )      &&
                                ( ( SW_INFO[SW_No].SW_Samples[3] )      ==      SW_Pressed_Level      )      &&
                                ( ( SW_INFO[SW_No].SW_Samples[4] )      ==      SW_Pressed_Level      )              )
                        {
                                    SW_INFO[SW_No].SW_State        		=   SW_Pre_Pressed;
                                    SW_INFO[SW_No].Release_Times        =       0;
                        }
                    //update Release_Times
                        else
                        {
                            if(SW_INFO[SW_No].Release_Times < SW_RELEASE_TIME_MAX_MS)
                            {
                               SW_INFO[SW_No].Release_Times  += SW_Update_Period_ms; 
                            }
                            
                        }
                        
                      break;

        case SW_Pre_Pressed:
                    //Switch to SW_Pressed State
                        if(     ( ( SW_INFO[SW_No].SW_Samples[2] )      ==      SW_Pressed_Level      )      && 
                                ( ( SW_INFO[SW_No].SW_Samples[3] )      ==      SW_Pressed_Level      )      &&
                                ( ( SW_INFO[SW_No].SW_Samples[4] )      ==      SW_Pressed_Level      )              )
                        {
                                    SW_INFO[SW_No].SW_State         	=   SW_Pressed;
                                    SW_INFO[SW_No].Press_Times          =       0;
                        }
                        else
                        {
                            /*Do Nothing */
                        }
                        
                            
                       break;
        case SW_Pressed:        
                    //Switch to SW_Pre_Released State
                        if(     ( ( SW_INFO[SW_No].SW_Samples[0] )      ==      SW_Pressed_Level       )      && 
                                ( ( SW_INFO[SW_No].SW_Samples[1] )      ==      SW_Pressed_Level       )      &&
                                ( ( SW_INFO[SW_No].SW_Samples[3] )      ==      SW_Released_Level      )      &&
                                ( ( SW_INFO[SW_No].SW_Samples[4] )      ==      SW_Released_Level      )              )
                        {
                                    SW_INFO[SW_No].SW_State         =   SW_Pre_Released;
                                    SW_INFO[SW_No].Press_Times          =       0;
                        }
                    //update Press_Times
                        else
                        {
                            if(SW_INFO[SW_No].Press_Times   < SW_PRESS_TIME_MAX_MS)
                            {
                               SW_INFO[SW_No].Press_Times   += SW_Update_Period_ms; 
                            }
                            
                        }
                        
                      break;

        case SW_Pre_Released:    
                    //Switch to SW_Released State
                        if(     ( ( SW_INFO[SW_No].SW_Samples[2] )      ==      SW_Released_Level      )      && 
                                ( ( SW_INFO[SW_No].SW_Samples[3] )      ==      SW_Released_Level      )      &&
                                ( ( SW_INFO[SW_No].SW_Samples[4] )      ==      SW_Released_Level      )              )
                        {
                                    SW_INFO[SW_No].SW_State         	=   SW_Released;
                                    SW_INFO[SW_No].Release_Times        =       0;
                        }
                        else
                        {
                            /*Do Nothing */
                        }
                        
                            
                       break;
        
        default:            /*Report Errors */                                                              break;
        }

}
Switch_State   HSwitch_u8GetState(Switch_Number SW_No)
{   

    //return the Switch's State

    return  SW_INFO[SW_No].SW_State;

}  




u16 HSwitch_u8PressedTime(Switch_Number SW_No)
{
    return  SW_INFO[SW_No].Press_Times;
}

u16 HSwitch_u8ReleasedTime(Switch_Number SW_No)
{
    return  SW_INFO[SW_No].Release_Times;
}
