import time
import serial
from helper import SetResetRelays, GetRelays 

ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1 )
print(ser.portstr)

RELAY_COUNT = 8 

for idx in range(1):

   SetResetRelays( ser, 'SetResetExtRelay', 'SET', RELAY_COUNT )
   GetRelays(ser, 'GetExtRelay', RELAY_COUNT )
   time.sleep(3)

   SetResetRelays( ser, 'SetResetExtRelay', 'RESET', RELAY_COUNT  )
   GetRelays(ser, 'GetExtRelay', RELAY_COUNT )

ser.close()
