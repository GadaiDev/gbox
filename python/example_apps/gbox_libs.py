import tkinter as tk
import requests

class gb_tk():
    def __init__(self,title:str,size:tuple,resizable:bool):
        self.app = tk.Tk()
        self.app.title(title)
        self.app.geometry(f"{size[0]}x{size[1]}")
        self.app.resizable(resizable,resizable,)
        self.vars = {}
    
    def button(self,text:str,target,pos:tuple):
        tk.Button(self.app,text=text,command=target).place(x=pos[0],y=pos[1])
    
    def inputbox(self,varname:str,placeholder,pos:tuple):
        if varname == None:
            varname = ""
        self.vars[varname] = tk.Entry(self.app,textvariable=placeholder)
        self.vars[varname].place(x=pos[0],y=pos[1])
    
    def get_inputbox(self,varname):
        return self.vars[varname].get()
    
    def label(self,text,font,pos:tuple):
        tk.Label(self.app,text=text,font=font).place(x=pos[0],y=pos[1])

    def mainloop(self):
        self.app.mainloop()
        