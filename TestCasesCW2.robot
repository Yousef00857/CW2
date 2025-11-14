*** Settings ***
Documentation    Embedded Systems Project Test Cases - ADC, LCD, LED, Buttons

*** Test Cases ***

Test Case 1: Initialize System
[Documentation]      Make sure the ADC, LCD, LED, and buttons are configured and the system initializes correctly.
     # Turn the board on.
     # Act: Watch as the system boots up.
     # The LCD displays the initial LL, LH, and Sensor values. LED is off.
[Status]    SUCCESS

Test Case 2: ADC Reading Validity
[Documentation]      Make sure ADC reads values within the expected range (0–1023).
     # Connect a variable sensor (e.g., potentiometer) to ADC channel 0.
     # Act: Read ADC values from the system.
     # The value displayed on LCD is between 0 and 1023.
[Status]    SUCCESS

Test Case 3: LED ON Outside Limits
[Documentation]      Make sure the LED illuminates when the sensor value is outside LL–LH range.
     # Arrange: Set LL = 200, LH = 900. Adjust sensor below 200 or above 900.
     # Act: Observe the LED.
     # LED turns on.
[Status]    SUCCESS

Test Case 4: LED OFF Inside Limits
[Documentation]      Make sure the LED turns off when the sensor value is within LL–LH range.
     # Arrange: Set LL = 200, LH = 900. Adjust sensor to a value within range.
     # Act: Observe the LED.
     # LED turns off.
[Status]    SUCCESS

Test Case 5: Increase Upper Limit Using Button1
[Documentation]      Make sure pressing Button1 increases LH by 10, respecting MAX_LIMIT.
     # Arrange: Set LH = 890.
     # Act: Press Button1.
     # LH increases by 10 (to 900) and is displayed on LCD.
[Status]    SUCCESS

Test Case 6: Decrease Upper Limit Using Button2
[Documentation]      Make sure pressing Button2 decreases LH by 10, respecting MIN_LIMIT.
     # Arrange: Set LH = 910.
     # Act: Press Button2.
     # LH decreases by 10 (to 900) and is displayed on LCD.
[Status]    SUCCESS

Test Case 7: Increase Lower Limit Using Button3
[Documentation]      Make sure pressing Button3 increases LL by 10, respecting MAX_LIMIT.
     # Arrange: Set LL = 190.
     # Act: Press Button3.
     # LL increases by 10 (to 200) and is displayed on LCD.
[Status]    SUCCESS

Test Case 8: Decrease Lower Limit Using Button4
[Documentation]      Make sure pressing Button4 decreases LL by 10, respecting MIN_LIMIT.
     # Arrange: Set LL = 210.
     # Act: Press Button4.
     # LL decreases by 10 (to 200) and is displayed on LCD.
[Status]    SUCCESS

Test Case 9: Smooth ADC Reading Update
[Documentation]      Make sure the LCD updates sensor value only when the difference is greater than 5.
     # Arrange: Keep sensor value stable at 200.
     # Act: Change sensor value slightly (<5 difference).
     # LCD does not update. Change sensor value (>5 difference). LCD updates to new value.
[Status]    SUCCESS

Test Case 10: LCD Display Format
[Documentation]      Make sure LCD displays LL, LH, and Sensor correctly.
     # Arrange: Set LL = 200, LH = 900, Sensor = 450.
     # Act: Observe LCD.
     # First row shows "LDR: 450 ON/OFF" and second row shows "LL: 200   LH: 900".
[Status]    SUCCESS

Test Case 11: Debounce Validation
[Documentation]      Make sure button presses are properly debounced to avoid multiple triggers.
     # Arrange: Press and release button quickly several times.
     # Act: Observe the LCD/LED updates.
     # Each press/release pair produces exactly one response.
[Status]    SUCCESS

Test Case 12: Continuous Button Press
[Documentation]      Make sure holding a button continuously doesn't increment/decrement repeatedly.
     # Arrange: Hold down Button1 for three seconds.
     # Act: Observe the LCD updates.
     # Only one increment occurs during the hold.
[Status]    SUCCESS

Test Case 13: LED State Consistency
[Documentation]      Make sure LED maintains state until sensor changes outside limits.
     # Arrange: Set sensor outside limits to turn LED on.
     # Act: Keep sensor constant within the same range for 10 seconds.
     # LED stays on without flickering.
[Status]    SUCCESS

