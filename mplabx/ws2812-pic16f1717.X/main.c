/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1717
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

#define writePixel(r,g,b)\
do{\
    SSP1BUF = g;\
    while(!SSP1STATbits.BF);\
    SSP1BUF = r;\
    while(!SSP1STATbits.BF);\
    SSP1BUF = b;\
    while(!SSP1STATbits.BF);\
} while(0);
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    SPI_Open(SPI_DEFAULT);
    //SSP1CON1bits.SSPEN = 1;
    
    // PWM4 70%   
    //PWM4DCH = 0x03;   // PWM4DCH 3; 
    //PWM4DCL = 0x40;   // PWM4DCL 1; 
    // PWM4 50%   
    //PWM4DCH = 0x02;   // PWM4DCH 2; 
    //PWM4DCL = 0x40;   // PWM4DCL 1; 
    // PWM4 40%   
    //PWM4DCH = 0x01;   // PWM4DCH 1; 
    //PWM4DCL = 0xC0;   // PWM4DCL 3; 
    
    // Clear all the pixels
    for(int i = 0; i < 8; i++) {
        writePixel(0,0,0);  // Black  
    }
    __delay_ms(1);          // Reset delay
    
    while (1)
    {
        // Show the color red in the 8 pixels
        for(int i = 0; i < 8; i++) {
            writePixel(255, 0, 0);  // Red           
        }
        __delay_ms(2);              // Reset
    }
}
/**
 End of File
*/