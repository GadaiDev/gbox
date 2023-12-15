#include<iostream>
#include<string>
#include<vector>
#include<filesystem>
#include<fstream>
#include <cstring>


int main(int argc, char **argv) {

    if(strcmp(argv[1], "-m") == 0){
        std::filesystem::path folderPath = "./python/New-Project";
        try {
            if (std::filesystem::create_directory(folderPath)) {
                std::cout << "フォルダが作成されました。\n";
            } else {
                std::cout << "フォルダの作成に失敗しました。\n";
            }
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "エラー: " << e.what() << '\n';
        }
        std::ofstream file("./python/New-Project/main.py");
        if (file.is_open()) {
            file << "import gbox_libs as gbox_libs\n\nclass Example():\n   def __init__(self) -> None:\n       super().__init__()\n       # スクリプトをここに書いてください\n\nExample()";
            file.close();
            std::cout << "ファイルに書き込みました。\n";
        } else {
            std::cerr << "ファイルが開けませんでした。\n";
        }
        std::ofstream file2("./python/New-Project/gbox_libs.py");
        if (file2.is_open()) {
            file2 << "import tkinter as tk\nimport requests\n\n#gbox_libs 1.0\n\nclass gb_tk():\n    def __init__(self,title:str,size:tuple,resizable:bool):\n        self.app = tk.Tk()\n        self.app.title(title)\n        self.app.geometry(f'{size[0]}x{size[1]}')\n        self.app.resizable(resizable,resizable,)\n        self.vars = {}\n    \n    def button(self,text:str,target,pos:tuple):\n        tk.Button(self.app,text=text,command=target).place(x=pos[0],y=pos[1])\n    \n    def inputbox(self,varname:str,placeholder,pos:tuple):\n        if varname == None:\n            varname = ''\n        self.vars[varname] = tk.Entry(self.app,textvariable=placeholder)\n        self.vars[varname].place(x=pos[0],y=pos[1])\n    \n    def get_inputbox(self,varname):\n        return self.vars[varname].get()\n    \n    def label(self,text,font,pos:tuple):\n        tk.Label(self.app,text=text,font=font).place(x=pos[0],y=pos[1])\n\n    def mainloop(self):\n        self.app.mainloop()";
            file2.close();
            std::cout << "ファイルに書き込みました。\n";
        } else {
            std::cerr << "ファイルが開けませんでした。\n";
        }
        
    }else{
        std::string appname;
        std::cout << "フォルダ名を入力:";
        std::cin >> appname;

        std::string com1 = "./bin/python3 ./python/";
        std::string com2 = "/main.py";
        std::string com3 = com1 + appname + com2;

        // +1 は null 終端文字('\0') のために必要です
        char *com_r = new char[com3.length() + 1];

        for (size_t i = 0; i < com3.length(); ++i) {
            com_r[i] = com3[i];
        }

        // null 終端文字を追加
        com_r[com3.length()] = '\0';

        std::system(com_r);

        // メモリを解放
        delete[] com_r;
        
        return 0;
    }
}