/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TSS1.c
**     Project     : touch
**     Processor   : MKL05Z32VLF4
**     Component   : TSS_Library
**     Version     : Component 03.001, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-07-24, 18:43, # CodeGen: 2
**     Contents    :
**         Configure - byte TSS1_Configure(void);
**
**     (c) Copyright Freescale Semiconductor, Inc. 2013
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TSS1.c
** @version 01.00
*/         
/*!
**  @addtogroup TSS1_module TSS1 module documentation
**  @{
*/         

/* MODULE TSS1. */

#include "Events.h"
#include "TSS1.h"

/*
** ===================================================================
**     Function    :  TSS1_InitDevices
**     Description :
**         The function is intended for implementation of peripherals
**         initialization. TSS Component automatically enables clock
**         for all used TSS peripherals, setup pin multiplexors,
**         installs RTOS interrupt service routines etc.
**         This function is generated always and depends on user if
**         it is used.
**         This function is automatically called during the
**         TSS1_fOnInit callback execution.
**     Parameters  : None
**     Returns     : None
** ===================================================================
*/

void TSS1_InitDevices(void)
{
  /* Modules Clock support */

  /* SIM_SCGC5: PORTB=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
  /* SIM_SCGC5: TSI=1 */
  SIM_SCGC5 |= SIM_SCGC5_TSI_MASK;

  /* TSI Module MUX Settings */

  PORTB_PCR10 = PORT_PCR_MUX(0);
}

/*
** ===================================================================
**     Method      :  TSS1_Configure (component TSS_Library)
**     This method can be used also under name "Configure"
**
**     Description :
**         Whole TSS initialization and configuration of registers.
**         Contains main TSS_Init() function, TSS System Config
**         registers and all Control Config registers initialization
**         according to setting of Component properties. The user have
**         to place this function into the proper location in the
**         source code.
**     Parameters  : None
**     Returns     :
**         ---             - Error status code of Configure method. If
**                           the configuration is successful the
**                           TSS_STATUS_OK is reported, otherwise is
**                           reported one of error status codes
**                           described in TSSAPIRM document.
** ===================================================================
*/
byte TSS1_Configure(void)
{
  byte u8Result = TSS_STATUS_OK;

  /* Main TSS Initialization */
  u8Result |= TSS_Init();

  /* Electrode dc-tracker enablers */
  u8Result |= TSS_SetSystemConfig(System_DCTrackerEnablers_Register+0, 0x01);

  /* Sets Trigger Mode */
  u8Result |= TSS_SetSystemConfig(System_SystemTrigger_Register, TSS_TRIGGER_MODE_ALWAYS);
  /* Sets the Number of samples for all electrodes */
  u8Result |= TSS_SetSystemConfig(System_NSamples_Register, 0x08);
  /* Configures the DC Tracker value */
  u8Result |= TSS_SetSystemConfig(System_DCTrackerRate_Register, 0x64);
  /* Configures the Slow DC Tracker Factor value */
  u8Result |= TSS_SetSystemConfig(System_SlowDCTrackerFactor_Register, 0x64);
  /* Configures the Response Time */
  u8Result |= TSS_SetSystemConfig(System_ResponseTime_Register, 0x04);
  /* Configures the Stuck-key Timeout */
  u8Result |= TSS_SetSystemConfig(System_StuckKeyTimeout_Register, 0x00);
  /* Configures System SystemConfig Register */
  u8Result |= TSS_SetSystemConfig(System_SystemConfig_Register, TSS_SYSTEM_EN_MASK | TSS_DC_TRACKER_EN_MASK);

  return u8Result;
}

/* END TSS1. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/