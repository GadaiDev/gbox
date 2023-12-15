import gbox_libs as gbox_libs

class Example():
    def __init__(self) -> None:
        super().__init__()
        self.app = gbox_libs.gb_tk("Example",(500,100),False)
        self.app.label("Gbox example",("menlo",25),pos=(0,0))
        self.app.mainloop()

Example()