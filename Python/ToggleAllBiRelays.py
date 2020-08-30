import time
import serial
from helper import SetResetRelays, GetRelays 

ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1 )
print(ser.portstr)

RELAY_COUNT = 4 

for idx in range(1):

   SetResetRelays( ser, 'SetResetBirelayK', 'SET', RELAY_COUNT )
   GetRelays(ser, 'GetBirelayK', RELAY_COUNT )
   time.sleep(3)

   SetResetRelays( ser, 'SetResetBirelayK', 'RESET', RELAY_COUNT  )
   GetRelays(ser, 'GetBirelayK', RELAY_COUNT )

ser.close()
