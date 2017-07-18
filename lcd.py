from ctypes import cdll,c_bool
lib = cdll.LoadLibrary('./liblcd.so')

class LCD(object):
    def __init__(self):
        self.obj = lib.LCD_new()

    def setRW(self, _RW):
        lib.LCD_setRW(self.obj, _RW)

    def setA0(self, _A0):
        lib.LCD_setA0(self.obj, _A0)
        
    def setE1(self, _E1):
        lib.LCD_setE1(self.obj, _E1)
        
    def setE2(self, _E2):
        lib.LCD_setE2(self.obj, _E2)
    
    def setE(self, _E):
        lib.LCD_setE(self.obj, _E)
        
    def setRES(self, _RES):
        lib.LCD_setRES(self.obj, _RES)
        
    def setD(self, _D):
        lib.LCD_setD(self.obj, _D)
        


    def getRW(self):
        return lib.LCD_getRW(self.obj)
        
    def getA0(self):
        return lib.LCD_getA0(self.obj)
        
    def getE1(self):
        return lib.LCD_getE1(self.obj)
        
    def getE2(self):
        return lib.LCD_getE2(self.obj)
        
    def getE(self):
        return lib.LCD_getE(self.obj)
        
    def getRES(self):
        return lib.LCD_getRES(self.obj)
        
    def getD(self):
        return lib.LCD_getD(self.obj)
        

    def LCDinit(self):
        return lib.LCD_LCDinit(self.obj)

    def WaitReady(self, l, r):
        lib.LCD_WaitReady(self.obj,l,r)

    def nanosleep(self, time):
        lib.LCD_nanosleep(self.obj, time)

    def getPixel(self, x, y):
        func = lib.LCD_getPixel
        func.restype = c_bool
        return func(self.obj,x,y)

