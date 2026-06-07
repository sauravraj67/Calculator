# Calculator

<img width="708" height="609" alt="Screenshot 2026-05-21 195812" src="https://github.com/user-attachments/assets/1bf8f770-f237-4b7c-a875-192ada2aee45" />

I made a simple Calculator design. The concept is based on Raspberry Pi Pico , It has 19  Mechanical switches directly attached to the raspberry Pi Pico. A rotor encoder whose rotor would be used to change position the position of the cursor and it's button would be used to clean the screen And The Screen would be a 16X2 LCD Display with I2C

## Features
parentheses
decimals
operator precedence
Error Handling
divide by zero
syntax checking
UI Features
boot screen
expression rendering
result rendering
Input Features
matrix scanning
debounce
encoder support
delete key
clear key
Planned Future Features
scientific functions
USB keyboard mode
EEPROM memory
cursor blinking
full LCD drive

## Firmware

The firmware was written in C using the Raspberry Pi Pico SDK.

 ### Schematic<br><br>
 <img width="756" height="751" alt="Screenshot 2026-05-22 164100" src="https://github.com/user-attachments/assets/1c9f1527-c3e3-41a7-8eea-a993872943e1" />

###  PCB Design 

<img width="674" height="688" alt="Screenshot 2026-05-20 072845" src="https://github.com/user-attachments/assets/590d093a-d305-48d4-bbea-352f4f7eed54" />

### 3D Design <br><br>

<img width="725" height="625" alt="Screenshot 2026-05-21 192533" src="https://github.com/user-attachments/assets/53392847-34e8-43af-a0bf-77c8bca09c03" />
<img width="708" height="609" alt="Screenshot 2026-05-21 195812" src="https://github.com/user-attachments/assets/2801696b-cd18-475b-b60c-11531992bc97" />
<img width="973" height="350" alt="Screenshot 2026-05-21 192857" src="https://github.com/user-attachments/assets/2ef0a34f-af7e-4acc-b4c7-6b0954d93f0c" />

# Bill of Materials (BOM)
# Bill of Materials (BOM)

| Index | Quantity | Part Description | Link | Cost |
|---|---:|---|---|---:|
| 1 | 1 | PCB + 3D Printed Case + Shipping | https://jlcpcb.com | $16.2 |
| 2 | 1 | Screws Kit | https://www.amazon.in/gp/product/B0C394FK9B/ref=ewc_pr_img_1?smid=A31OPLJ1CRU4J5&th=1 | $3.87 |
| 3 | 1 | M3 × 6 mm Brass Heat Inserts | https://www.amazon.in/gp/product/B0BB86CQSJ/ref=ewc_pr_img_2?smid=A2JDRZEGU1IDE2&psc=1 | $0.79 |
| 4 | 2 | Keycap Set | https://www.amazon.in/gp/product/B0F13YK4D6/ref=ewc_pr_img_3?smid=AH0KEO6T9U8SH&psc=1 | $9.20 |
| 5 | 1 | Mechanical Keyboard Switches | https://www.amazon.in/gp/product/B0G39H2G4H/ref=ewc_pr_img_4?smid=ANH0PBBCLPM1Q&psc=1 | $5.37 |
| 6 | 1 | Rotary Encoder Module | https://www.amazon.in/gp/product/B0888RWNM1/ref=ewc_pr_img_5?smid=A34QREQHZ8C5B0&psc=1 | $1.84 |
| 7 | 1 | LCD Display Module with I2C Interface | https://www.amazon.in/gp/product/B08THCDP8L/ref=ewc_pr_img_6?smid=AJ6SIZC8YQDZX&psc=1 | $3.87 |
| 8 | 1 | Raspberry Pi Pico | https://www.amazon.in/gp/product/B08WPNM7JB/ref=ewc_pr_img_7?smid=AJ6SIZC8YQDZX&psc=1 | $7.51 |

## Total Cost

**$48.68 USD**

---

## Notes

- Prices may vary depending on region, taxes, shipping, and seller availability so i used 1USD= 93 Inr for conversion.
- PCB fabrication and shipping costs were estimated using JLCPCB.
- The keycap cost is calculated for 2 sets (`$4.60 × 2 = $9.20`).

