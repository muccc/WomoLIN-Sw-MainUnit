# install python3 and pyserial
import serial

ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1 )
print(ser.portstr)


ser.write(b'^GetBme680Humidity;GET$')
print(ser.readline())

ser.write(b'^GetBme680Pressure;GET$')
print(ser.readline())

ser.write(b'^GetBme680Temperature;GET$')
print(ser.readline())


ser.close()
