/********************************************************************
 FileName:     	HardwareProfile - PICDEM FSUSB K50.h
 Dependencies:  See INCLUDES section
 Processor:     PIC18 USB Microcontrollers
 Hardware:      PICDEM FSUSB populated with PIC18F45K50
 Compiler:      Microchip C18
 Company:       Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC� Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
  2.9f  06/25/2012   Initial release
********************************************************************/

#ifndef HARDWARE_PROFILE_PICDEM_FSUSB_K50_H
#define HARDWARE_PROFILE_PICDEM_FSUSB_K50_H

    /*******************************************************************/
    /******** USB stack hardware selection options *********************/
    /*******************************************************************/
    //This section is the set of definitions required by the MCHPFSUSB
    //  framework.  These definitions tell the firmware what mode it is
    //  running in, and where it can find the results to some information
    //  that the stack needs.
    //These definitions are required by every application developed with
    //  this revision of the MCHPFSUSB framework.  Please review each
    //  option carefully and determine which options are desired/required
    //  for your application.

    //The PICDEM FS USB Demo Board platform supports the USE_SELF_POWER_SENSE_IO
    //and USE_USB_BUS_SENSE_IO features.  Uncomment the below line(s) if
    //it is desireable to use one or both of the features.
    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #if defined(USE_SELF_POWER_SENSE_IO)
    #define self_power          PORTAbits.RA2
    #else
    #define self_power          1
    #endif

    //#define USE_USB_BUS_SENSE_IO
    #define tris_usb_bus_sense  TRISAbits.TRISA1    // Input
    #if defined(USE_USB_BUS_SENSE_IO)
    #define USB_BUS_SENSE       PORTAbits.RA1
    #else
    #define USB_BUS_SENSE       1
    #endif


    //Uncomment the following line to make the output HEX of this  
    //  project work with the MCHPUSB Bootloader    
    //#define PROGRAMMABLE_WITH_USB_MCHPUSB_BOOTLOADER
	
    //Uncomment the following line to make the output HEX of this 
    //  project work with the HID Bootloader
    #define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER		

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.
    #define DEMO_BOARD PICDEM_FS_USB_K50
    #define PICDEM_FS_USB_K50
    #define PIC18F45K50_FAMILY
    #define CLOCK_FREQ 48000000


    /** LED ************************************************************/
    #define mInitAllLEDs()      LATD &= 0xF0; TRISD &= 0xF0;
    
    #define mLED_1              LATDbits.LATD0
    #define mLED_2              LATDbits.LATD1
    #define mLED_3              LATDbits.LATD2
    #define mLED_4              LATDbits.LATD3
    
    #define mGetLED_1()         mLED_1
    #define mGetLED_2()         mLED_2
    #define mGetLED_3()         mLED_3
    #define mGetLED_4()         mLED_4

    #define mLED_1_On()         mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    #define mLED_3_On()         mLED_3 = 1;
    #define mLED_4_On()         mLED_4 = 1;
    
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;
    #define mLED_3_Off()        mLED_3 = 0;
    #define mLED_4_Off()        mLED_4 = 0;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    #define mLED_3_Toggle()     mLED_3 = !mLED_3;
    #define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    #define mInitAllSwitches()  TRISBbits.TRISB4=1;TRISBbits.TRISB5=1;
    #define mInitSwitch2()      TRISBbits.TRISB4=1;
    #define mInitSwitch3()      TRISBbits.TRISB5=1;
    #define sw2                 PORTBbits.RB4
    #define sw3                 PORTBbits.RB5
    
    /** POT ************************************************************/
    #define mInitPOT()          {TRISAbits.TRISA0=1;ANSELAbits.ANSA0=1;ADCON1=0;ADCON2=0xBE;ADCON0=0x01;}

   
    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0

    #define SetUsbInterruptToLowPriority()  IPR2bits.USBIP = 0;
	/*** Audio    ************************************************/
	#ifdef AUDIO_SAMPLING_FREQUENCY_48000
   		#define NO_OF_SAMPLES_IN_A_USB_FRAME 48
   		#define PWM_PERIOD	(CLOCK_FREQ/48000)-1
	#elif defined AUDIO_SAMPLING_FREQUENCY_32000
   		#define NO_OF_SAMPLES_IN_A_USB_FRAME 32
   		#define PWM_PERIOD	(CLOCK_FREQ/32000)-1
	#elif defined AUDIO_SAMPLING_FREQUENCY_44100
   		#define NO_OF_SAMPLES_IN_A_USB_FRAME 44
   		#define PWM_PERIOD	(CLOCK_FREQ/44100)-1
	#endif 	

    /*** Intialize Audio Driver on the Speech Playback Card *********************************************/
 	#define mInitAudioDriver()  {TRISAbits.TRISA4=OUTPUT_PIN; LATAbits.LATA4 = 1; } 
	#define mAudioDriverON()	LATAbits.LATA4 = 0;    
	#define mAudioDriverOFF()	LATAbits.LATA4 = 1;
	
	/****** PWM Intialization************************************/ 
	// configure RC2 as output for PWM  
	// PWM mode, Single output, Active High
	#define mInitPWM() 			{TRISCbits.TRISC2 = OUTPUT_PIN;  PR2 = PWM_PERIOD; CCPR1L = 0; CCP1CON = 0x0c;}
	#define DUTY_CYCLE CCPR1L  // Duty Cycle register of the PWM Peripheral. 
	
	/****** Timer2 Intialization************************************/ 	
	// Enable Interrupt priority
	// Enable all unmasked low priority interrupts
	// Enable all unmasked high priority interrupts	
	// Timer2 interrupt is low priority 							
	#define mInitTimerInterrupt() {RCONbits.IPEN = 1; IPR1bits.TMR2IP = 1; INTCONbits.GIEL = 1; INTCONbits.GIEH = 1;}
	
	// Timer 2 on, Prescaler is 1, Postscaler is 1
	// unmask timer 2 interrupt
	#define mInitTimer() {TMR2 = 0; T2CON = 0x00; PIE1bits.TMR2IE = 0; T2CONbits.TMR2ON =1;}
	
	#define PWM_INTERRUPT_FLAG PIR1bits.TMR2IF
	
	#define TimerInterruptEnable PIE1bits.TMR2IE

    /****** Unmask Timer2 Interrupt ************************************/
    #define mStartAudio()  {PIE1bits.TMR2IE = 1;} // unmask timer 2 interrupt
    
    /******* Mask Timer2 Interrupt  ***********************************/
    #define mStopAudio()   {PIE1bits.TMR2IE = 0;}// mask timer 2 interrupt
	
#endif  //HARDWARE_PROFILE_PICDEM_FSUSB_K50_H