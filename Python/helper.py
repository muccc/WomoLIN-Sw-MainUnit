# install python3 and pyserial

def SetResetRelays( attSer, attRelay, attSetReset, attCount ):
   for k in range( 1, attCount+1 ):
      sendString = '^' + attRelay + '%d;' % k + attSetReset + '$'
      attSer.write( sendString.encode("utf-8") )
   attSer.readline()

def GetRelays( attSer, attRelay, attCount ):
   for k in range( 1, attCount+1 ):
      sendString = '^' + attRelay + '%d;GET$' % k 
      attSer.write( sendString.encode("utf-8") )
      print(attSer.readline())
 

