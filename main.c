#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>  /* for sei() */
#include <util/delay.h>     /* for _delay_ms() */

#include <avr/pgmspace.h>   /* required by usbdrv.h */
#include "usbdrv.h"
#include "HID_KEYCODES.h"

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */

const PROGMEM char usbHidReportDescriptor[65] = {
    0x05, 0x01,     // Usage Page (Generic Desktop Page)
    0x09, 0x06,     // Usage (Keyboard)
    0xA1, 0x01,     // Collection (Application)
    0x05, 0x07,         // Usage Page (Keyboard)
    0x19, 0xE0,         // Usage Minimum (Left Ctrl)
    0x29, 0xE7,         // Usage Maximum (Right GUI)
    0x15, 0x00,         // Logical Min (0)
    0x25, 0x01,         // Logical Max (1)
    0x75, 0x01,         // Report Size (1)
    0x95, 0x08,         // Report Count (8)
    0x81, 0x02,         // Input(Data, Var, Abs)

    0x75, 0x08,         // Report Size (8)
    0x95, 0x01,         // Report Count (1)
    0x81, 0x01,         // Input (Const, Array, Abs) -> 1 byte reserved

    0x19, 0x00,         // Usage Minimum (0)
    0x29, 0x65,         // Usage Maximum (0x65)
    0x15, 0x00,         // Logical Min (0)
    0x25, 0x65,         // Logical Max (0x65)
    0x75, 0x08,         // Report Size (8)
    0x95, 0x06,         // Report Count (6)
    0x81, 0x00,         // Input(Data, Array, Abs)

    0x05, 0x08,         // Usage Page (LED)
    0x19, 0x01,         // Usage Minimum (Num Lock)
    0x29, 0x03,         // Usage Maximum (Scroll Lock)
    0x15, 0x00,         // Logical Min (0)
    0x25, 0x01,         // Logical Max (1)
    0x75, 0x01,         // Report Size (1)
    0x95, 0x03,         // Report Count (3)
    0x91, 0x02,         // Output(Data, Var, Abs)
    0x75, 0x01,         // Report Size (1)
    0x95, 0x05,         // Report Count (5)
    0x91, 0x03,         // Output (Const, Var, Abs) ; padding
    0xC0            // End Collection
};

typedef struct{
    uchar   modifier;
    char    reserved;
    char    key1;
    char    key2;
    char    key3;
    char    key4;
    char    key5;
    char    key6;
}report_t;

static report_t reportBuffer;
static uchar    idleRate;

static void sendKey(void)
{
    reportBuffer.modifier = 0x00;
    reportBuffer.reserved = 0x00;
    reportBuffer.key1 = KEY_A;
    reportBuffer.key2 = 0x00;
    reportBuffer.key3 = 0x00;
    reportBuffer.key4 = 0x00;
    reportBuffer.key5 = 0x00;
    reportBuffer.key6 = 0x00;
    usbSetInterrupt((void *)&reportBuffer, sizeof(reportBuffer));
}

/* ------------------------------------------------------------------------- */

usbMsgLen_t usbFunctionSetup(uchar data[8])
{
    usbRequest_t    *rq = (void *)data;

    /* The following requests are never used. But since they are required by
     * the specification, we implement them in this example.
     */
    if((rq->bmRequestType & USBRQ_TYPE_MASK) == USBRQ_TYPE_CLASS){    /* class request type */
        if(rq->bRequest == USBRQ_HID_GET_REPORT){  /* wValue: ReportType (highbyte), ReportID (lowbyte) */
            /* we only have one report type, so don't look at wValue */
            usbMsgPtr = (void *)&reportBuffer;
            return sizeof(reportBuffer);
        }else if(rq->bRequest == USBRQ_HID_GET_IDLE){
            usbMsgPtr = &idleRate;
            return 1;
        }else if(rq->bRequest == USBRQ_HID_SET_IDLE){
            idleRate = rq->wValue.bytes[1];
        }
    }else{
        /* no vendor specific requests implemented */
    }
    return 0;   /* default for not implemented requests: return no data back to host */
}

/* ------------------------------------------------------------------------- */

int __attribute__((noreturn)) main(void)
{
    wdt_disable();
    /* Even if you don't use the watchdog, turn it off here. On newer devices,
     * the status of the watchdog (on/off, period) is PRESERVED OVER RESET!
     */
    /* RESET status: all port bits are inputs without pull-up.
     * That's the way we need D+ and D-. Therefore we don't need any
     * additional hardware initialization.
     */
    usbInit();
    usbDeviceDisconnect();  /* enforce re-enumeration, do this while interrupts are disabled! */
    _delay_ms(250);
    usbDeviceConnect();
    sei();
    while(1){                /* main event loop */
        usbPoll();
        if(usbInterruptIsReady()){
            /* called after every poll of the interrupt endpoint */
            sendKey();
        }
    }
}

/* ------------------------------------------------------------------------- */
