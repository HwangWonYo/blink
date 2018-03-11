# Blink Practice for Capstone Design Class
- purpose: Make Blink Class for blinking LED

## Blink
> Args:
>   - pin: pin port connected to LED
> functions:
>   - on : turn on LED
>   - off: turn off LED

### Functions

#### on
- turn on LED
- recive integer parameter for delay time
- example
  ```cpp
  blink.on(500);
  // delay 500ms.
  // means light on for 500ms.
  ```

#### off
- turn off LED
- recevie integer parameter for delay time
- example
  ```cpp
  blink.off(300);
  // delay 300ms.
  // means light off for 300ms.
  ```
