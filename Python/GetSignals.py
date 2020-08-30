# install python3 and pyserial
import serial

ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1 )
print(ser.portstr)

ser.write(b'^GetSignals;GET$')

response = ser.readline()
print(response)

#TODO use range value from response 

for idx in range(1,35):
   ser.write(b'^GetSignals;GET,%d$' % idx)
   print(ser.readline())
   

ser.close()
