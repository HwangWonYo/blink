# Blink Practice for Capstone Design Class
- purpose: Make Blink Class for blinking LED

## Blink
> Args:
>   - pin: pin port connected to LED
>
> Functions:
>   - on : turn on LED
>   - off: turn off LED

### Functions

#### on
- turn on LED
- recieve integer parameter for delay time
- example
  ```cpp
  blink.on(500);
  // delay 500ms.
  // means light on for 500ms.
  ```

#### off
- turn off LED
- recieve integer parameter for delay time
- example
  ```cpp
    blink.off(300);
    // delay 300ms.
    // means light off for 300ms.
  ```

### NOTICE
- Temporarily Blink class uses built in LED. ([See Issue](https://github.com/HwangWonYo/blink/issues/1))
