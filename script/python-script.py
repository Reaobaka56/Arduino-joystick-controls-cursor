import serial
import pyautogui

arduino = serial.Serial('COM3', 9600, timeout=0.1)

while True:
    try:
        data = arduino.readline().decode('utf-8').strip()
        if data:
           
            x_move, y_move, click = data.split(',')
            
           
            pyautogui.moveRel(int(x_move), int(y_move))
            
            
            if click == "1":
                pyautogui.click()
    except Exception as e:
        pass
