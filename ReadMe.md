# Dynamic-LED-Brightness-Control-with-ARM-LPC2148 💡
This project involves designing and utilizing the ARM7-LPC2148 microcontroller with LDR and IR sensor integration to showcase Pulse Width Modulation (PWM) for LED brightness control.

 Below are the detailed steps for configuring the LPC2148 microcontroller for PWM (Pulse Width Modulation) and ADC (Analog-to-Digital Conversion). Each step is explained, covering aspects such as configuring the PLL, setting up PWM, configuring ADC, and interfacing with an LCD display.

## Here's a summary of the main steps involved:

> PWM Configuration
### Initialize PLL for Clock Generation:

- Set up the PLL for clock generation.
- Wait for PLL to lock. ⏳

### Select PWM Pins:

- Use PINSEL register to select PWM pins, in this case, P0.0. 📌

### Reset Timers:

- Use PWMTCR (Timer Control Register) to reset the timers.
- Set the prescale value.Configure PWM Match Control Register:
- Set up PWMMCR (PWM Match Control Register) for operations like reset and interrupts. 🔄

### Set PWM Period (Maximum Value):

- Set the maximum period for the PWM channel using PWMMR0. 🕒

### Enable PWM Latch:

- Set the Latch Enable for the corresponding match registers using PWMLER. 🔒

### Enable PWM Output:

- Use PWMTCR to enable PWM Timer counters and PWM modes. 🚀
- ADC Configuration

### Configure ADC Pins:

- Use PINSEL1 to select the ADC pin (P0.28 in this case). 📊

### Capture ADC Values:

- Configure ADC settings in AD0CR (ADC Control Register).
- Start ADC conversion and wait for it to complete.
- Convert ADC values to the desired range (0-255). 🔄

### Set PWM Duty Cycle:

- Set PWMMR1 with the calculated duty cycle value.
- Enable PWM output with the duty cycle value using PWMLER. 🎚️
- LCD Display Configuration

### Initialize LCD:

- Set up the GPIO pins for the LCD.
- Send initialization commands to the LCD. 🖥️

### Display ADC and PWM Values on LCD:

- Use LCD_DISPLAY function to print ADC and PWM values on the LCD. 📺


Overall, these steps provide a comprehensive guide for configuring PWM, ADC, and interfacing with an LCD display on the LPC2148 microcontroller. 🛠️
