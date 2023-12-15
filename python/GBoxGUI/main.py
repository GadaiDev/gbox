import tkinter as tk
import os
def on_button_click():
    os.system(f"./gbox {entry.get()}")
# Tkinterウィンドウの作成
root = tk.Tk()
root.title("GBox UI")

# ラベル（大きな文字）の作成
label = tk.Label(root, text="GBox", font=("Helvetica", 24))
label.pack(pady=10)

# 入力ボックスの作成
entry = tk.Entry(root, width=30)
entry.pack(pady=10)

# ボタンの作成
button = tk.Button(root, text="Click Me", command=on_button_click)
button.pack(pady=10)

# Tkinterループの開始
root.mainloop()
