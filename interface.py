import wx
import serial

portaUSB = serial.Serial("COM5",9600)

class janelaPrincipal(wx.Frame):
    def __init__(self):
        super().__init__(parent=None, title='Para querida professora que queria uma interface')
        panel = wx.Panel(self)
        bt_Up = wx.Button(panel, label='Frente', pos=(100, 55))
        bt_Up.Bind(wx.EVT_BUTTON,self._pressUp)
        bt_L = wx.Button(panel, label='Esquerda', pos=(5, 100))
        bt_L.Bind(wx.EVT_BUTTON, self._pressL)
        bt_R = wx.Button(panel, label='Direita', pos=(195, 100))
        bt_R.Bind(wx.EVT_BUTTON, self._pressR)
        bt_Dw = wx.Button(panel, label='Trás', pos=(100, 150))
        bt_Dw.Bind(wx.EVT_BUTTON, self._pressDw)
        bt_acenderFarol = wx.Button(panel, label='Farol on', pos=(400, 100))
        bt_acenderFarol.Bind(wx.EVT_BUTTON, self._pressFarolOn)
        bt_apagarFarol = wx.Button(panel, label='Farol off', pos=(500, 100))
        bt_apagarFarol.Bind(wx.EVT_BUTTON, self._pressFarolOff)
        self.Show()

    def _pressUp(self, event):
        portaUSB.write(b'f')
        print("Carrinho deve está andando para Cima")

    def _pressDw(self, event):
        portaUSB.write(b'b')
        print("Carrinho deve está andando para Trás")

    def _pressL(self, event):
        portaUSB.write(b'l')
        print("Carrinho deve está andando para Esquerda")

    def _pressR(self, event):
        portaUSB.write(b'r')
        print("Carrinho deve está andando para Direita")

    def _pressFarolOn(self, event):
        print("Farol Ligado")
        portaUSB.write(b'a')

    def _pressFarolOff(self, event):
        portaUSB.write(b'p')
        print("Farol Desligado")





app = wx.App()
frame = janelaPrincipal()
app.MainLoop()
